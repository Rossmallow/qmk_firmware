![Layout](files/Layout.png)

This layout was inspired by the [Miryoku layout](https://github.com/qmk/qmk_firmware/tree/master/users/manna-harbour_miryoku).

I have swapped the mods from the home row to the thumb-cluster, though because this reduces the amount of use of the pinky while maintaining the same amount of use from the thumb.
Having the shift mod in the thumb-cluster rather than in the home row removes the need to switch which finger holds shift depending on which side of the board the key is.
In the Miryoku layout, the layer-shift key is always on the opposite side of the board from the functions on that layer. Losing range of motion on one's left index finger when all functions for that layer are on the right side of the board is less disruptive than holding a modifier and losing range on an entire side of the board.

The Alix40 is conducive to these modifications because of the inclusion of four extra keys on the bottom left and right of the board which can house additional modifier keys which make up for the fact that certain combinations such as 'ctrl+alt+del' can be difficult or even impossible when all three mods are in the thumb-cluster, which is a drawback of this modified layout.



Use the included [keyboard-layout-editor_alix40.json](files/keyboard-layout-editor_alix40.json) file on [keyboard-layout-editor.com](http://www.keyboard-layout-editor.com) to edit the layout shown above.

Use the included [tokyokeyboard_alix40_layout_mine_formatted.json](files/tokyokeyboard_alix40_layout_mine_formatted.json) file on [config.qmk.fm](https://config.qmk.fm) to edit the layout with the QMK online QUI editor.
Note: This will compile the firmware using the default configuration settings located [here](https://github.com/qmk/qmk_firmware/blob/master/keyboards/tokyokeyboard/alix40/config.h), which at the time of writing, has settings for underglow and mouse_keys turned off.

A pre-compiled .hex file of this firmware has also been included in the files directory.
If settings like underglow and mouse_keys are important to you, use this firmware instead of compiling in QMK's web UI.



Created by [Ross Nelson](https://rossnelson.me)