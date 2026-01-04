/*
  user_config_override.h - custom configuration for ESP32-S2 Téléinfo
  
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
#define PROJECT                "tasmota-theosaka-teleinfo"

#undef FRIENDLY_NAME
#define FRIENDLY_NAME          "Tasmota Theosaka ESP32-S2 Téléinfo"

// -- OTA Configuration -----------------
// Point to custom GitHub releases
#undef OTA_URL
#define OTA_URL                "https://github.com/Theosakamg/tasmota-theosaka/releases/latest/download/tasmota32s2-teleinfo.bin"

// -- Teleinfo Configuration ------------
#define USE_TELEINFO            // Enable Teleinfo support (+10k code, +1k mem)
#define USE_ENERGY_SENSOR       // Add support for Energy Monitors

// Keep essential integrations
#define USE_WEBSERVER           // Enable web interface for configuration and monitoring
#define USE_HOME_ASSISTANT      // Enable Home Assistant MQTT discovery

// Disable only heavy/unused features to save space
#undef USE_DOMOTICZ             // Disable Domoticz support
#undef USE_MQTT_TLS             // Disable TLS (can be re-enabled if needed)
#undef USE_KNX                  // Disable KNX protocol

// Keep temperature sensors (useful for combo setups)
// If you don't use these sensors, you can uncomment to save space:
// #undef USE_DHT
// #undef USE_DS18x20
// #undef USE_BMP
// #undef USE_BME680

// Disable display support (uncomment if you need displays)
#undef USE_DISPLAY
#undef USE_I2C

// Disable light control (uncomment if you need light features)
#undef USE_WS2812
#undef USE_LIGHT

#endif  // _USER_CONFIG_OVERRIDE_H_
