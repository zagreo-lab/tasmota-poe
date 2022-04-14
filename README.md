# tasmota-poe
Custom firmware for Tube-CC2652-PoE

How to install TASMOTA firmware on Tube-ZB-CC2652-PoE

Even though Tasmota offers several pre-compiled firmware variants, sometimes the ready-to-flash binaries aren't enough. If you need to enable or disable some features, or simply change some parameters, then you need to compile a firmware binary yourself.

Gitpod is a web browser based online IDE. All you need to use it is to link your GitHub account. Gitpod will take care of all the necessary software package dependencies for you.

1) You need to compile a bin on gitpod.io, in the workspace /workspace/Tasmota master, modifying 2 files:

* 'Platformio_override.ini' file which is located in the root directory – /workspace/Tasmota. Open the file, scroll to the bottom, and add:
```
[env:tasmota32-CC2652P2-POE]
extends                 = env:tasmota32
build_flags             = ${env:tasmota32_base.build_flags} -DFIRMWARE_CC2652P2_POE
```


* 'user_config_override.h' file which is located in the tasmota subdirectory (/workspace/Tasmota/tasmota). Open that file, erase all its contents and replace with the file in repository

* In the terminal at the bottom of the screen, while in the /workspace/Tasmota directory, type the following:
```
platformio run -e tasmota32-CC2652P2-POE
```

Once it does, the bin file can be found in /workspace/Tasmota/build_output/firmware

2) Flashare il compilato: tasmota32-CC2652P2-POE-BRIDGE.bin
3) Dare il seguente comando: backlog wifi 0 ; Template 0, rule1 1 
4) Restart
