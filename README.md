# Tasmota Custom Builds

Automated GitHub Action for building custom Tasmota firmware variants for ESP32-S2.

## 🎯 Available Builds

### 📊 ESP32-S2 Téléinfo
Custom Tasmota build for French Téléinfo electricity meters.

**Features:**
- ✅ Téléinfo protocol support
- ✅ Energy monitoring
- ✅ Web interface for configuration
- ✅ MQTT support
- ✅ OTA updates

**Use cases:**
- Monitor Linky electricity meters
- Track power consumption in real-time
- Integration with Home Assistant, Domoticz, etc.

### 💧 ESP32-S2 Script WaterMeter
Custom Tasmota build with scripting support for water meter monitoring.

**Features:**
- ✅ Tasmota Scripting Language support
- ✅ Counter support for pulse counting
- ✅ FAT file system for script storage
- ✅ Web display for custom UI
- ✅ MQTT event support
- ✅ OTA updates

**Compatible with:**
- [TasmotaWaterMeter Script](https://github.com/XHunter74/TasmotaWaterMeter/blob/main/FlowMeter-script.txt)
- Any water meter with pulse output

## 🚀 How It Works

This repository uses GitHub Actions to:

1. **Monitor** the [Tasmota repository](https://github.com/arendst/Tasmota) for new releases (daily check at 2 AM UTC)
2. **Build** custom firmware variants with specific configurations
3. **Publish** compiled binaries as GitHub releases with OTA-compatible files

## 📦 Installation

### Option 1: OTA Update (Recommended)

If you already have Tasmota running on your ESP32-S2:

1. Go to your device web interface: `http://<device-ip>`
2. Navigate to **Firmware Upgrade**
3. Paste the URL of the `.bin` file from the [latest release](../../releases/latest)
4. Click **Start Upgrade**

Example OTA URL:
```
https://github.com/Theosakamg/tasmota-theosaka/releases/download/build-vX.X.X/tasmota32s2-teleinfo.bin
```

**Note:** The firmware is configured to automatically check for updates from this repository. The version is tracked by the release tag, not the filename.

### Option 2: First Flash via USB

For new devices or first-time installation:

#### Using Tasmota Web Installer (Easiest)
1. Visit [Tasmota Web Installer](https://tasmota.github.io/install/)
2. Connect your ESP32-S2 via USB
3. Select "Custom" and upload the `.bin` file from releases

#### Using ESPTool
```bash
# Install esptool
pip install esptool

# Erase flash
esptool.py --chip esp32s2 --port /dev/ttyUSB0 erase_flash

# Flash firmware
esptool.py --chip esp32s2 --port /dev/ttyUSB0 --baud 460800 \
  write_flash -z 0x0 tasmota32s2-<variant>-vX.X.X.bin
```

## 🔧 Configuration

### Téléinfo Variant

After flashing, configure your Téléinfo connection:

1. Go to **Configuration** → **Configure Module**
2. Set GPIO for serial communication (RX/TX)
3. Enable Téléinfo in **Configuration** → **Configure Téléinfo**

Recommended GPIOs for ESP32-S2:
- RX: GPIO 18
- TX: GPIO 17 (if needed)

### Script WaterMeter Variant

After flashing, install the water meter script:

1. Go to **Consoles** → **Edit Script**
2. Copy the script from [TasmotaWaterMeter](https://github.com/XHunter74/TasmotaWaterMeter/blob/main/FlowMeter-script.txt)
3. Paste and save
4. Enable script: `>D` → Check "Script enable"
5. Configure your pulse counter GPIO

## 🛠️ Development

### Repository Structure

```
.
├── .github/
│   └── workflows/
│       └── build.yml           # GitHub Actions workflow
├── configs/
│   ├── teleinfo/
│   │   └── user_config_override.h
│   └── script-watermeter/
│       └── user_config_override.h
├── platformio_override.ini     # PlatformIO configuration
├── README.md
└── .gitignore
```

### Modifying Configurations

To customize builds, edit the `user_config_override.h` files in the `configs/` directory.

#### Téléinfo Configuration
```c
// configs/teleinfo/user_config_override.h
#define USE_TELEINFO            // Enable Teleinfo
#define USE_ENERGY_SENSOR       // Energy monitoring
```

#### Script WaterMeter Configuration
```c
// configs/script-watermeter/user_config_override.h
#define USE_SCRIPT              // Enable scripting
#define USE_SCRIPT_FATFS 8      // Enable file system
#define USE_COUNTER             // Enable counter
```

### Manual Build Trigger

You can manually trigger a build for a specific Tasmota version:

1. Go to **Actions** tab
2. Select **Build Tasmota Custom Variants**
3. Click **Run workflow**
4. Enter the Tasmota version tag (e.g., `v13.4.0`) or leave empty for latest

## 📋 Build Information

Each release includes:
- ✅ `.bin` files for OTA updates
- ✅ `.factory.bin` files for initial flashing (when available)
- ✅ `.sha256` checksum files for verification

### Verifying Checksums

```bash
# Linux/macOS
sha256sum -c tasmota32s2-teleinfo-vX.X.X.sha256

# Windows PowerShell
Get-FileHash tasmota32s2-teleinfo-vX.X.X.bin -Algorithm SHA256
```

## 🔗 Links

- [Tasmota Official Documentation](https://tasmota.github.io/docs/)
- [Tasmota Scripting Language](https://tasmota.github.io/docs/Scripting-Language/)
- [TasmotaWaterMeter Project](https://github.com/XHunter74/TasmotaWaterMeter)
- [Tasmota GitHub Repository](https://github.com/arendst/Tasmota)
- [ESP32-S2 Documentation](https://docs.espressif.com/projects/esp-idf/en/latest/esp32s2/)

## 📄 License

This project is licensed under the GNU General Public License v3.0 - see the Tasmota project for details.

## 🤝 Contributing

Contributions are welcome! Please feel free to submit a Pull Request.

## ⚠️ Disclaimer

These are custom builds based on official Tasmota releases. While tested, use at your own risk. Always backup your configuration before updating firmware.

## 📧 Support

For issues specific to these custom builds, please open an issue in this repository.

For general Tasmota support, please refer to the [official Tasmota documentation](https://tasmota.github.io/docs/) and [community](https://discord.gg/Ks2Kzd4).
