/*
  user_config_override.h - custom configuration for ESP32-S2 with USE_SCRIPT
  
  Copyright (C) 2026  Custom Tasmota Builds

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _USER_CONFIG_OVERRIDE_H_
#define _USER_CONFIG_OVERRIDE_H_

/*****************************************************************************************************\
 * USAGE:
 *   To modify the stock configuration without changing the my_user_config.h file:
 *   (1) copy this file to "user_config_override.h" (It will be ignored by Git)
 *   (2) define your own settings below
 *
 *****************************************************************************************************/

// Force the compiler to show a warning to confirm that this file is included
#warning **** user_config_override.h: Using Settings from this File ****

// -- Project info ----------------------
#undef PROJECT
#define PROJECT                "tasmota-theosaka-watermeter"

#undef FRIENDLY_NAME
#define FRIENDLY_NAME          "Tasmota Theosaka ESP32-S2 Script WaterMeter"

// -- OTA Configuration -----------------
// Point to custom GitHub releases
#undef OTA_URL
#define OTA_URL                "https://github.com/Theosakamg/tasmota-theosaka/releases/latest/download/tasmota32s2-script-watermeter.bin"

// -- Script Configuration --------------
#define USE_SCRIPT              // Enable Script support (+17k code, +2k mem)
#define USE_SCRIPT_FATFS 8      // Script: Enable FAT file system support
#define SCRIPT_LARGE_VNBUFF     // Enable large variable name buffer
#define USE_SCRIPT_GLOBVARS     // Enable global variables
#define SUPPORT_MQTT_EVENT      // Support for MQTT events in scripts
#define USE_SENDMAIL            // Support for sending emails from scripts
#define USE_SCRIPT_WEB_DISPLAY  // Enable web display for scripts

// Enable Counter support for water meter pulse counting
#define USE_COUNTER             // Enable counter support

// Keep essential integrations
#define USE_WEBSERVER           // Enable web interface for script management
#define USE_HOME_ASSISTANT      // Enable Home Assistant MQTT discovery

// Disable features not needed for Water Meter to save space
#undef USE_DOMOTICZ
#undef USE_KNX

// Keep only essential sensors
#undef USE_DHT
#undef USE_DS18x20
#undef USE_BMP
#undef USE_BME680
#undef USE_SHT
#undef USE_HTU
#undef USE_SI7021
#undef USE_LM75AD
#undef USE_AHT1x
#undef USE_AHT2x

// Disable display support (script web display is used instead)
#undef USE_DISPLAY

// Disable unnecessary light support
#undef USE_WS2812
#undef USE_LIGHT

#endif  // _USER_CONFIG_OVERRIDE_H_
