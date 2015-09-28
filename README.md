teensy-keyboard-input
===========================

Features
--------

Teensy 3.0-based keyboard input device. Beginning project to get used to the build
environment and such.

Building and flashing
--------------------
Run the make file:

    make

Upload the generated `.hex` file to the teensy:

    teensy_loader_cli --mcu=mk20dx128 -w teensy-keyboard-input.hex 

Plug in your teensy and press the reset button.

Template
--------

This project was based off [teensy-template](https://github.com/apmorton/teensy-template).
