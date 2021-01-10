# dkjer's keymap for Durgod Taurus K320.

Layer 0 : Standard ANSI 87 Keys TKL layout (Windows)

Layer 1 : Media control and Windows lock key (Windows)
- Reusing Durgod's Original Media Control for Fn + F1 ~ Fn + F7
- Fn + Windows to toggle Windows lock key functionality

Layer 2 : System layer (Windows)
- Fn + Menu + Esc : Bootloader mode
- Fn + Menu + F1  : System Sleep
- Fn + Menu + F4  : Turning Off System
- Fn + Menu + F12 : Switch to Mac layout

Layer 3 : Mac 87 Keys TKL layout

Layer 4 : Media control and Media lock key (Mac)
- If Apple-Fn key is enabled:
 - Passthrough all Media/Function keys to let OS handle them.
- If no Apple-Fn key is enabled:
 - Standard Mac Media keys for Fn + F1 ~ Fn + F12.
 - Fn + F13 to toggle Media lock key functionality

Layer 5 : System layer (Mac)
- Fn + R-ALT + Esc : Bootloader mode
- Fn + R-ALT + F1  : System Sleep
- Fn + R-ALT + F4  : Turning Off System
- Fn + R-ALT + F12 : Switch to Windows layout

## Toggle between Mac and Windows layout

You can switch between Mac and Windows layout by doing the following:
- Hold down Fn + Menu (Windows Layout) or Fn + Right-Alt (Mac layout)  (These are the same physical keys)
- Press F12

The 'M' led will be lit when you are using the alternate layout.  By default Mac is the alternate layout.

You can change the default & alternate layout by setting the following flags to either '_WBL'(Windows) or '_MBL' (Mac)
- DEFAULT_LAYOUT (initial layout to use on boot)
- ALT_LAYOUT (layout that will light the 'M' LED when active)

For example, to configure Mac as the default layer, and Windows to be the alternate layout, compile with these flags:

    make CFLAGS="-DDEFAULT_LAYOUT=_MBL -DALT_LAYOUT=_WBL" k320:default

## Windows key lock

In windows layout, you can hold down Fn + Windows key to disable the Windows key while in locked mode.  The 'Lock' LED
indicates if the Windows key is locked.

This is similar to the stock K320 Windows key lock functionality.

## Apple Fn key

Note: This functionality only works if the 'QMK Apple Fn Key' patch has been applied:  https://gist.github.com/fauxpark/010dcf5d6377c3a71ac98ce37414c6c4

To enable the Apple Fn Key behavior, apply the 'QMK Apple Fn Key' patch, comment out 'NKRO_ENABLE' in rules.mk, and uncomment 'APPLE_FN_ENABLE' in rules.mk.

When Apple Fn Key is enabled, tapping the Fn key in Mac layout behaves like the native Fn key found on mac keyboards.  This also affects how the media row
behaves, since with the Apple Fn Key you rely on toggling System Preferences > Keyboard > 'Use F1, F2, etc. keys as standard keys' to control behavior.

## Mac Media Lock

Note: This functionality is disabled when the Apple Fn Key is enabled, since this behavior is controlled by the OS.

To switch between Function row and Media row in Mac layout, press Fn + PrtSc.  The 'Lock' LED indicator will be lit when in Media row mode.

When controlling Function/media row using this lock you should enable System Preferences > Keyboard > 'Use F1, F2, etc. keys as standard keys'.


