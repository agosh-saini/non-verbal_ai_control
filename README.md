# Non-Verbal AI Control

**An exploration into a new paradigm of human-AI interaction.**

## Overview

This project is a proof of concept demonstration for using near real-time Vision-Language Models (VLM) combined with physiological signals—specifically EEG (Electroencephalography) and Facial EMG (Electromyography)—to control and interact with AI systems.

The goal is to move beyond traditional text or voice interfaces and explore how AI can respond to non-verbal cues and states of being.

## Project Structure

The project is organized into hardware and software components:

- **Hardware**
  - `hardware/arduino`: Logic and code for signal acquisition devices (EEG/EMG sensors).

- **Software**
  - `software/backend`: Processing pipeline for VLM inference and signal interpretation.
  - `software/frontend`: Interface for visualization and feedback.

## Technology Stack

- **Sensors**: EEG & EMG (Arduino-based acquisition - first iteration using facial EMG)
- **AI Models**: Vision-Language Models (VLM)
- **Frontend**: Web-based visualization
- **Backend**: Python-based inference engine

---
*Note: This is an experimental barebones proof of concept.*
