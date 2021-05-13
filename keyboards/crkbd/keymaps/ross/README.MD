![Layout](files/Layout.png)

This layout was inspired by the [Miryoku layout](https://github.com/qmk/qmk_firmware/tree/master/users/manna-harbour_miryoku) and my modified Miryoku layout that I used on my Alix40 board. That writeup can be found [here](../../alix40/ross/README.md).

The main difference with the corne is that as well as being ortholinear, the corne is lacking the two pinky keys on both bottom corners of the board. This isn't a big issue since the keys there on the Alix (ctrl, alt, gui) are already elsewhere on the board, but it helps with muscle memory such as with commands like (ctrl + s).
To get around that issue, I'm using tap dancing to provide alternate functions for keys when they are double tapped. For instance, the leftmost key on the third layer will act as ctrl when tapped or held, but act as shift when double tapped or tapped and then held (this is inverted on the game layer). This is also used on the rightmost key on the third layer which acts as a gui key by default and a layer switch when double tapped.



Use the included [keyboard-layout-editor_corne.json](files/keyboard-layout-editor_corne.json) file on [keyboard-layout-editor.com](http://www.keyboard-layout-editor.com) to edit the layout shown above.

A pre-compiled .hex file of this firmware has also been included in the files directory.

Created by [Ross Nelson](https://rossnelson.me)