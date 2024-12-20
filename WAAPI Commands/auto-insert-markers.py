from waapi import WaapiClient, CannotConnectToWaapiException
from pprint import pprint
import argparse
from scipy.io import wavfile

# Define arguments for the script
parser = argparse.ArgumentParser(description='Automatically Add a marker at start and end of the source (ID).')
parser.add_argument('ids', metavar='GUID', nargs='*', help='One or many guid of the form {01234567-89ab-cdef-0123-4567890abcde}. The script retrieves the current selected if no GUID specified.')

args = parser.parse_args()

convert_sample_functions = {
    "int16" : lambda s : s / 32767,
    "int32" : lambda s : s / 2147483647,
    "float32" : lambda s : s
}

def get_convert_sample_function(data):
    # return a function converting the raw data to a single float value
    base_convert = convert_sample_functions[data.dtype.name]
    if len(data.shape) == 1:
        return base_convert
    return lambda a : base_convert(a.max())

try:

    # Connecting to Waapi using default URL
    with WaapiClient() as client:

        selected = []
        
        # if no ID is passed as argument, use the selected object from the project
        if args.ids is None or len(args.ids) == 0:
            selected  = client.call("ak.wwise.ui.getSelectedObjects")['objects']
        else:
            selected = map(lambda id: {"id": id}, args.ids)

        set_args = {
            "objects": []
        }

        for obj in selected:

            # Use WAQL to obtain all audio sources under the object
            call_args = { "waql": f"$ \"{obj['id']}\" select this, descendants where type = \"AudioFileSource\""}
            options = { "return": ["originalWavFilePath", "type", "id", "parent.id"]}

            sources = client.call("ak.wwise.core.object.get", call_args, options=options)

            for source in sources['return']:

                # Open the WAV file
                sample_rate, data = wavfile.read(source['originalWavFilePath'])
                print(f"Processing {source['originalWavFilePath']}...")

                channels =  data.shape[1] if len(data.shape) == 2 else 1
                num_samples = int(data.size/channels)
                
                marker_end_pos = (num_samples - 1) / sample_rate

                marker_begin_pos = 0

                # Set properties on the source object
                set_sound = { "object":source['parent.id'] }
                set_source = { "object":source['id'] }
    
                args_markers = {
                    "objects": [{
                            "object":source['id'],
                            "@Markers": [
                                {
                                "type": "Marker",
                                "name": "",
                                "@Time": marker_begin_pos,
                                "@Label": "ShowSub"
                                },
                                {
                                "type": "Marker",
                                "name": "",
                                "@Time": marker_end_pos, 
                                "@Label": "HideSub"
                                }
                            ],
                            "listMode": "append",
                            "@MarkerInputMode": 2
                        }   
                    ]   
                }
                
                client.call("ak.wwise.core.object.set", args_markers)               

                # Store changes
                set_args["objects"].append(set_source)
                set_args["objects"].append(set_sound)

        client.call("ak.wwise.core.undo.beginGroup")
        client.call("ak.wwise.core.object.set", set_args)
        client.call("ak.wwise.core.undo.endGroup", { 'displayName': 'Auto Insert Markers'})


except Exception as e:
    print(str(e))