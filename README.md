# ESP32-S3 Teacher 3+ Control Panel for CrowPanel Advance

## Project Overview

This project implements a control panel for the **Teacher 3+** educational game, built on the **ESP32-S3** microcontroller using **LVGL**.
It is designed to run on **CrowPanel Advance** touchscreens (5", and 7").

> ⚠️ This control panel works together with the [GRC-AI Robot Control Kit](https://www.elecrow.com/grc-ai-robot-control.html), which includes the **Teacher 3+** game as part of the software package.

---

## Features

The application provides a simple, touch-based interface with the following elements on the main screen:

* Timer or stopwatch (depending on selected mode)
* Correct answers counter
* Incorrect answers counter
* Game mode selector
* Timer mode selector
* Control buttons:

  * Reset
  * Pause
  * Continue
* “Time Over” panel
* Last result display (mode-dependent)
* Best result display (mode-dependent)

---

## How to Use

You can either **build the firmware manually** or **install a prebuilt image** using a graphical installer.

---

### Option 1: Install Prebuilt Firmware

A ready-to-use firmware archive is available for quick installation.

#### Steps:

1. Download the prebuilt firmware archive from the [Releases](Releases) section. *(Add actual link when available)*
2. Unzip the archive to any folder.
3. Run the installer tool:
   **`FlashTool.exe`**
4. Follow on-screen instructions to flash the firmware to your CrowPanel Advance device.

> Compatible with CrowPanel Advance 5" and 7" models.

---

### Option 2: Build and Flash Manually (via VSCode + ESP-IDF)

#### Prerequisites

* [Visual Studio Code](https://code.visualstudio.com/)
* [ESP-IDF Extension for VSCode](https://github.com/espressif/vscode-esp-idf-extension)
* ESP-IDF version: `v5.4`

---

#### Step 1: Build the Firmware

1. Open Visual Studio Code
2. Open the command palette (`F1` or `Ctrl+Shift+P`)
3. Run: `ESP-IDF: Build your project`
4. Wait for the build to complete

---

#### Step 2: Flash the Device

1. Run: `ESP-IDF: Select Flash Method` → choose `UART`
2. Run: `ESP-IDF: Select Port to use` → select your device port (e.g. `COM3`, `/dev/ttyUSB0`)
3. Run: `ESP-IDF: Flash your project`
4. Wait for flashing to complete

**Optional:**
Use `ESP-IDF: Monitor your device` to view real-time logs.
