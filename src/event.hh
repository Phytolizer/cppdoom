//
// Created by kyle on 9/24/20.
//

#ifndef EZ_BOOM_EVENT_HH
#define EZ_BOOM_EVENT_HH

namespace event
{

enum class ButtonCode
{
    BT_ATTACK = 1,
    BT_USE = 2,

    /// Game event, not really a button
    BT_SPECIAL = 128,
    /// Game event, not really a button
    BT_SPECIALMASK = 3,

    /// Weapon change pending
    BT_CHANGE = 4,

    /// 4-bit weapon mask/shift, for convenience
    BT_WEAPONMASK = (8 + 16 + 32 + 64),
    BT_WEAPONSHIFT = 3,

    // Special events

    /// Load a game
    BTS_LOADGAME = 0,
    /// Pause the game
    BTS_PAUSE = 1,
    /// Save the game
    BTS_SAVEGAME = 2,
    /// Restart the current level
    BTS_RESTARTLEVEL = 3,
    /// Second byte of buttons contains savegame slot numbers
    BTS_SAVEMASK = (4 + 8 + 16),
    /// Demo joined
    BT_JOIN = 64,
};

}

#endif // EZ_BOOM_EVENT_HH
