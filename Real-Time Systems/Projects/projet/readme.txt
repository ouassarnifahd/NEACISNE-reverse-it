Realtime Systems study project:
console based temperature sensor manager

console exemple:

    freertos:~# Hello World
    freertos:~# read
    35.5°C
    freertos:~# exit
    command not found!
    freertos:~# help
    read      return last converted value
    dump      return hundred last converted values
    stream    return last converted value and update display
              press ENTER to quit stream mode
    reset     software processor reset
    baudrate  update serial communication baudrate of processor
    help      return supported commands
    freertos:~#


this directory contains mplab ide configuration files (Makefile, nbproject),
this make it easier to add the project in mplab ide.

DOCUMENTATION
doc/ contains the project diagram. Also the source code has doxygen comments
(TODO doxyfile)

CODE organised like shown below
inc/ headers of the project.
src/ source code of the project.
lib/ all third party code (FreeRTOS, and drivers)
