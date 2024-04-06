# Flashing firmware with QMK MSYS
- Install [QMK MSYS](https://msys.qmk.fm/)
- Setup QMK MSYS
- Clone this project into `qmk_firmware/keyboards/minecatr` *this means this repositories content go in here
- Copy the build folder of the desired keyboard into the QMK MSYS directory
- Run `qmk compile -e CONVERT_TO=promicro_rp2040 -kb /build -km default` in QMK MSYS
# Using VIA to change layout
- Install [VIA](https://github.com/the-via/releases/releases) or use the [web version](https://www.usevia.app/)
- Navigate to settings and enable show design tab
- Navigate to design and press load
- Select the the via.json file of the desired board
a preconfigured layout.json is in each complete board
