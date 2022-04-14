# tasmota-poe
Custom firmware for Tube-CC2652-PoE

Come installare TASMOTA su Tube ZB CC2652-PoE

1) Bisogna compilare un bin su gitpod.io, modificando 2 files:

a)

'Platformio_override.ini' is located in the root directory – /workspace/Tasmota. Open the file, scroll to the bottom, and add:

[env:tasmota32-CC2652P2-POE]
extends                 = env:tasmota32
build_flags             = ${env:tasmota32_base.build_flags} -DFIRMWARE_CC2652P2_POE

b)

'user_config_override.h' file which is located in the tasmota subdirectory (/workspace/Tasmota/tasmota). Open that file, erase all its contents and replace with the file in repository


2) Flashare il compilato: tasmota32-CC2652P2-POE-BRIDGE.bin
3) Dare il seguente comando: backlog wifi 0 ; Template 0, rule1 1 
4) Restart
