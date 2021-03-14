#!/bin/sh

# PI_PICO_PATH is just my setup to store all Pico-related tools

$PI_PICO_PATH/tools/openocd/src/openocd -f interface/picoprobe.cfg -f target/rp2040.cfg -s $PI_PICO_PATH/tools/openocd/tcl -c "program build/EICarStatePico.elf verify reset exit"