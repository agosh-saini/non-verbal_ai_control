# Hardware / Arduino Code

This directory contains Arduino sketches for the Non-Verbal AI Control project.

## Projects

### 1. EEG/EMG Sketch (`eeg_sketch`)

**Path:** `eeg_sketch/eeg_sketch.ino`

This sketch is designed to read analog signals (Grove EMG Sensor) on pin `A0`, calibrate the signal for noise (no muscle movement) and maximum amplitude (jaw clenching muscle movement), and then stream the processed amplitude data over Serial.

#### Features

- **Oversampling:** Uses 32x oversampling on `A0` to reduce noise.
- **Auto-Calibration:**
  - **Baseline:** Measures ambient noise/silence for ~5 seconds on startup.
  - **Max Amplitude:** Measures maximum signal (e.g., while talking) for ~10 seconds.
- **Live Streaming:** Streams amplitude data at approximately 200Hz.

#### Serial Configuration

- **Baud Rate:** `115200`

#### Serial Protocol

| Event | Output Format | Description |
| :--- | :--- | :--- |
| **Calibration (Baseline)** | `CAL_BASELINE <int>` | The calculated zero-point offset. |
| **Calibration (Max)** | `CAL_MAX <int>` | The maximum amplitude observed during calibration. |
| **Data Stream** | `DATA <int>` | Real-time amplitude value (`abs(reading - baseline)`). |

#### Hardware Setup

- **Input:** Connect sensor Output to Analog Pin `A0`. VCC to 5V or 3.3V depending on sensor, GND to GND.
