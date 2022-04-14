/*
  user_config_override.h - user configuration overrides my_user_config.h for Tasmota
  Zagreo 26.12.2021
*/

#ifndef _USER_CONFIG_OVERRIDE_H_
#define _USER_CONFIG_OVERRIDE_H_

#ifdef FIRMWARE_CC2652P2_POE
  #warning **** Build: FIRMWARE FOR CC2652P2-POE ****
  #undef CODE_IMAGE_STR
  #define CODE_IMAGE_STR "CC2652P2_POE"

  #undef  SERIAL_LOG_LEVEL
  #define SERIAL_LOG_LEVEL LOG_LEVEL_NONE

  #ifdef USE_DOMOTICZ
  #undef USE_DOMOTICZ //  disable Domoticz support (+6k code, +0.3k mem)
  #endif

  #ifdef USE_HOME_ASSISTANT
  #undef USE_HOME_ASSISTANT //  disable Home Assistant Discovery Support (+12k code, +6 bytes mem)
  #endif

  #define USE_ZIGBEE
  #define USE_ZIGBEE_ZNP
  #undef  USE_ZIGBEE_EZSP  // Ensure ZNP support and not EZSP
  #define USE_ZIGBEE_CHANNEL  11                 // Zigbee Channel (11-26)

  #define USE_UFILESYS

  #ifdef OTA_URL
  #undef OTA_URL
  #define OTA_URL "http://test/release/CC2652P2_POE.bin"  // [OtaUrl]
  #endif

  // Olimex ESP32-POE
  #define USE_ETHERNET
  #undef  ETH_TYPE
  #define ETH_TYPE 0 // ETH_PHY_LAN8720
  #undef  ETH_CLKMODE
  #define ETH_CLKMODE 3 // 3 = ETH_CLOCK_GPIO17_OUT 0 = ETH_CLOCK_GPIO0_IN
  #undef  ETH_ADDRESS
  #define ETH_ADDRESS 0 // PHY1
#endif

// platformio run -e tasmota32-CC2652P2-POE-BRIDGE 26.12.2021
#ifdef FIRMWARE_CC2652P2_POE_BRIDGE
  #warning **** Build: FIRMWARE FOR CC2652P2-POE-BRIDGE ****
  #undef CODE_IMAGE_STR
  #define CODE_IMAGE_STR "CC2652P2_POE_BRIDGE_1.1"

#undef  SERIAL_LOG_LEVEL
  #define SERIAL_LOG_LEVEL LOG_LEVEL_NONE

  #ifdef USE_DOMOTICZ
  #undef USE_DOMOTICZ //  disable Domoticz support (+6k code, +0.3k mem)
  #endif

  #ifdef USE_HOME_ASSISTANT
  #undef USE_HOME_ASSISTANT //  disable Home Assistant Discovery Support (+12k code, +6 bytes mem)
  #endif

  #undef USE_TCP_BRIDGE
  #define USE_TCP_BRIDGE

  #define USE_ZIGBEE
  #define USE_ZIGBEE_ZNP
  #undef  USE_ZIGBEE_EZSP  // Ensure ZNP support and not EZSP
  #define USE_ZIGBEE_CHANNEL  11                 // Zigbee Channel (11-26)

  #define USE_UFILESYS

  #ifdef OTA_URL
  #undef OTA_URL
  #define OTA_URL " "  // [OtaUrl]
  #endif

  // Olimex ESP32-POE
  #define USE_ETHERNET
  #undef  ETH_TYPE
  #define ETH_TYPE 0 // ETH_PHY_LAN8720
  #undef  ETH_CLKMODE
  #define ETH_CLKMODE 3 // 3 = ETH_CLOCK_GPIO17_OUT 0 = ETH_CLOCK_GPIO0_IN
  #undef  ETH_ADDRESS
  #define ETH_ADDRESS 0 // PHY1

  // -- Template Server TCP ---------------
  #undef  USER_TEMPLATE
  #define USER_TEMPLATE "{\"NAME\":\"Tube CC2652-PoE Bridge 1\",\"GPIO\":[1,1,1,1,1,5504,0,0,5536,1,1,1,5472,0,5600,0,0,0,0,5568,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,1],\"FLAG\":0,\"BASE\":1}"
  #define MODULE USER_MODULE

  // -- Default Rule 1 to start Server at boot ---------------
  #define USE_RULES
  #undef  USER_RULE1
  #define USER_RULE1 "ON system#boot DO TCPStart 8888 ENDON"


#endif

#endif  // _USER_CONFIG_OVERRIDE_H_
