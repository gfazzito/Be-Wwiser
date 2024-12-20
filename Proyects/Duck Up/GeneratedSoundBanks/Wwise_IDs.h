/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Audiokinetic Wwise generated include file. Do not edit.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef __WWISE_IDS_H__
#define __WWISE_IDS_H__

#include <AK/SoundEngine/Common/AkTypes.h>

namespace AK
{
    namespace EVENTS
    {
        static const AkUniqueID GAMEOVER_PLAY = 3375146582U;
        static const AkUniqueID GAMEPLAY_PLAY = 4131219514U;
        static const AkUniqueID MENU_PLAY = 105544633U;
        static const AkUniqueID MUSICA_PLAY = 3508699412U;
        static const AkUniqueID PLAY_BOOST = 3783768423U;
        static const AkUniqueID PLAY_GAME_OVER = 725000905U;
        static const AkUniqueID PLAY_SALTO = 2695653357U;
        static const AkUniqueID PLAY_UI_POP = 2723271224U;
        static const AkUniqueID SET_MUSICA_OFF = 2390094378U;
        static const AkUniqueID SET_MUSICA_ON = 4162184204U;
        static const AkUniqueID SET_SONIDO_OFF = 1566631974U;
        static const AkUniqueID SET_SONIDO_ON = 241016520U;
    } // namespace EVENTS

    namespace STATES
    {
        namespace MUSICAENCENDIDO
        {
            static const AkUniqueID GROUP = 2692742118U;

            namespace STATE
            {
                static const AkUniqueID NONE = 748895195U;
                static const AkUniqueID OFF = 930712164U;
                static const AkUniqueID ON = 1651971902U;
            } // namespace STATE
        } // namespace MUSICAENCENDIDO

        namespace MUSICASECCIONES
        {
            static const AkUniqueID GROUP = 1980278377U;

            namespace STATE
            {
                static const AkUniqueID GAMEOVER = 4158285989U;
                static const AkUniqueID MENUYGAMEPLAY = 1145380229U;
                static const AkUniqueID NONE = 748895195U;
            } // namespace STATE
        } // namespace MUSICASECCIONES

        namespace SONIDOSENCENDIDO
        {
            static const AkUniqueID GROUP = 468995489U;

            namespace STATE
            {
                static const AkUniqueID NONE = 748895195U;
                static const AkUniqueID OFF = 930712164U;
                static const AkUniqueID ON = 1651971902U;
            } // namespace STATE
        } // namespace SONIDOSENCENDIDO

    } // namespace STATES

    namespace SWITCHES
    {
        namespace MUSICA
        {
            static const AkUniqueID GROUP = 1730564739U;

            namespace SWITCH
            {
                static const AkUniqueID GAMEOVER = 4158285989U;
                static const AkUniqueID GAMEPLAY = 89505537U;
                static const AkUniqueID MENU = 2607556080U;
            } // namespace SWITCH
        } // namespace MUSICA

        namespace TERRENO
        {
            static const AkUniqueID GROUP = 942072244U;

            namespace SWITCH
            {
                static const AkUniqueID TIERRA = 2565746006U;
                static const AkUniqueID ZEPPELIN = 1755348276U;
            } // namespace SWITCH
        } // namespace TERRENO

    } // namespace SWITCHES

    namespace BANKS
    {
        static const AkUniqueID INIT = 1355168291U;
        static const AkUniqueID AUDIOGENERAL = 4051723963U;
    } // namespace BANKS

    namespace BUSSES
    {
        static const AkUniqueID MASTER_AUDIO_BUS = 3803692087U;
        static const AkUniqueID M_SICA = 3315589229U;
        static const AkUniqueID SONIDOS = 3749328614U;
    } // namespace BUSSES

    namespace AUDIO_DEVICES
    {
        static const AkUniqueID NO_OUTPUT = 2317455096U;
        static const AkUniqueID SYSTEM = 3859886410U;
    } // namespace AUDIO_DEVICES

}// namespace AK

#endif // __WWISE_IDS_H__
