# tasmota-poe
Custom firmware for Tube-CC2652-PoE

# How to install TASMOTA firmware on Tube-ZB-CC2652-PoE

Even though Tasmota offers several pre-compiled firmware variants, sometimes the ready-to-flash binaries aren't enough. If you need to enable or disable some features, or simply change some parameters, then you need to compile a firmware binary yourself.

Gitpod is a web browser based online IDE. All you need to use it is to link your GitHub account. Gitpod will take care of all the necessary software package dependencies for you.

The proper method of customizing firmware compilation options is to use the user_config_override.h file. You should not change the my_user_config.h file.

> 1. You need to compile a bin on gitpod.io, in the workspace /workspace/Tasmota master, modifying 2 files:

* 'Platformio_override.ini' file which is located in the root directory – /workspace/Tasmota. Open the file, scroll to the bottom, and add:
```
; *** Zagreo 19.6.2022, 03.07.2022, 19.10.2022
[env:tasmota32-CC2652P2-POE-BRIDGE]
extends                 = env:tasmota32
build_flags             = ${env:tasmota32_base.build_flags} -DFIRMWARE_CC2652P2_POE_BRIDGE
```


* 'user_config_override.h' file which is located in the tasmota subdirectory (/workspace/Tasmota/tasmota). Open that file, erase all its contents and replace with the file in repository

* In the terminal at the bottom of the screen, while in the /workspace/Tasmota directory, type the following:
```
platformio run -e tasmota32-CC2652P2-POE-BRIDGE
```

Once it does, the bin file can be found in /workspace/Tasmota/build_output/firmware

Download tasmota32-CC2652P2-POE-BRIDGE.bin to your computer by right-clicking on the file and selecting 'Download'. You are now ready to flash your device.

> 2. Flash tasmota32-CC2652P2-POE-BRIDGE.bin

OTA Flash

If you already have Tasmota flashed on your device, you can use the File Upload OTA method to load the new firmware binary file.

Download tasmota-minimal.bin
Make a backup of the device configuration using the web UI Configuration menu option.
Upload tasmota-minimal.bin to your device using the web UI Firmware Upgrade selection. Choose Upgrade by file upload.
After tasmota-minimal.bin is successfully loaded, select Firmware Upgrade once again and upload the firmware file compiled using Gitpod.

> 3. Give the following commands: 

Add the template:

```backlog template {"NAME":"Tube CC2652-PoE Bridge","GPIO":[1,1,1,1,1,5504,0,0,5536,1,1,1,5472,0,5600,0,0,0,0,5568,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,1],"FLAG":0,"BASE":1}; module 0``` 

Start the server for zigbee2MQTT:

```backlog rule1 on system#boot do TCPStart 8888 endon; rule1 1```  

Stop the wifi:

```backlog rule2 on system#boot do Wifi 0 endon; rule2 1``` 

> 4. Restart

## Zigbee Module Firmware Updates:

**CC2652p based Gateways:**  
Firmware - use the **CC1352P2_CC2652P_launchpad_*.zip** based firmware available here:  
https://github.com/Koenkk/Z-Stack-firmware/tree/master/coordinator/Z-Stack_3.x.0/bin

**Be Sure to backup your device before updgrading as the update will erase the zigbee module completely** https://github.com/zigpy/zigpy-znp/blob/dev/TOOLS.md#backup-and-restore

Use the cc2538-bsl programmer available here: https://github.com/JelmerT/cc2538-bsl

Utilizzare il server OpenHab 3 in cui il programma è già installato:

> 1. Fermare il server zigbee2mqtt che crea conflitto con la porta di collegamento
```
sudo systemctl stop zigbee2mqtt
```
> 2. Entrare nella cartella /home/openhabian/cc2538-bsl
```
# Comandi da dare singolarmente:
virtualenv -p 3 venv # Comando per lanciare l'ambiente protetto pythyon
source venv/bin/activate # Comando per attivare l'ambiente protetto pythyon
# Per fare il backup:
# python -m zigpy_znp.tools.network_backup socket://192.168.5.52:8888 -i zigbee_network_backup.json
#
# Potrebbe essere necessario aggiornare le librerie
# pip3 install pyserial

# Dopo aver messo il device in BSL mode come sotto spiegato, dare il seguente comando:
# python3 cc2538-bsl.py -p socket://192.168.5.52:8888  -evw ./CC1352P2_CC2652P_launchpad_coordinator_20220219.hex
python3 cc2538-bsl.py -p socket://192.168.5.52:8888  -evw ./CC1352P2_CC2652P_launchpad_coordinator_20221226.hex
```

> 3. Deattivare l'amiente protetto pythyon:
```
deactivate
```
> 4. Per rimuovere completamente un virtual environment digita:
```
rm -r venv/
```

> 5. Riavviare il server zigbee2mqtt
```
sudo systemctl start zigbee2mqtt
```


**Ethernet version :**
1. Prep the Module for firmware update:

- Put your device in BSL mode
Please follow the following instructions to put your stick in BSL mode:
* Unplug your devicethe ethenet
* Press the BSL pushbutton and keep holding while plugging the device back into to ethernet

<img src="https://github.com/zagreo-lab/tasmota-poe/raw/main/zigbee.png" width="300">

Give it a few seconds for the device to settle and set up and release the BSL button
Your device should now be in ROM bootloader mode

2. Run the cc2538-bsl programmer:
```
cc2538-bsl.py -p socket://<tube_zb_gw_cc2652p2 IP address>:8888  -evw ../CC1352P2_CC2652P_launchpad_20210120.hex
Opening port socket://<tube_zb_gw_cc2652p2 IP address>:8888, baud 500000
Reading data from ../CC1352P2_CC2652P_launchpad_20210120.hex
Your firmware looks like an Intel Hex file
Connecting to target...
CC1350 PG2.0 (7x7mm): 352KB Flash, 20KB SRAM, CCFG.BL_CONFIG at 0x00057FD8
Primary IEEE Address: 00:12:4B:00:23:7D:FC:46
    Performing mass erase
Erasing all main bank flash sectors
    Erase done
Writing 360448 bytes starting at address 0x00000000
Write 104 bytes at 0x00057F980
    Write done
Verifying by comparing CRC32 calculations.
    Verified (match: 0xdb4192ef)
```

