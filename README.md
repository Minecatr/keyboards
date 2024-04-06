# Building firmware with QMK MSYS
- Install [QMK MSYS](https://msys.qmk.fm/)
- Setup QMK MSYS
- Clone this project into `qmk_firmware/keyboards/minecatr` *this means this repositories content go in here
- Copy the build folder of the desired keyboard into the QMK MSYS directory
- Run `qmk compile -e CONVERT_TO=promicro_rp2040 -kb /build -km default` in QMK MSYS
