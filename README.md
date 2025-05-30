# Auto Refresh Rate Switcher for Windows

This program monitors the power state of a Windows laptop and automatically switches the display refresh rate between **144Hz** (plugged in) and **60Hz** (on battery) to optimize performance and battery life.

## 🔧 Features

- Detects whether the laptop is plugged in or running on battery.
- Automatically sets the display refresh rate:
  - `144Hz` when the laptop is plugged in
  - `60Hz` when on battery
- Monitors power state changes every 5 seconds.
- Uses native Windows APIs via `windows.h`.

## 🧠 How It Works

- The program is designed to first determine the power source.
- It then checks the current screen refresh rate.
- A loop runs indefinitely and changes the refresh rate only when the power state changes.
- System was designed with 2 refresh rates on account of thaose being the only available refresh rates on the PC used (Acer Nitro 5).

## 💻 Requirements

- Windows OS
- A display that supports multiple refresh rates (e.g., 60Hz and 144Hz)
- A C compiler (e.g., MinGW, MSVC)

## 🚀 How to Build

1. Save the code as `refresh_rate_switcher.c`.
2. Compile using your C compiler:

### Using MinGW:

```bash
gcc refresh_rate_switcher.c -o refresh_rate_switcher.exe -lgdi32
```
## ⚠️ Notes
Refresh rate changes may cause brief screen flickers.

The refresh rate setting is persistent and saved in the Windows registry (CDS_UPDATEREGISTRY).

You can modify the frequencies (144 and 60) as needed to suit your system capabilities.

## Author
Baldo G. Otu-Quayson
