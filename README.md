# Johnny552 USB Character Driver Demo

A minimal USB character driver demo for the Johnny552 board, featuring CH552 firmware and a Linux driver to control GPIO via USB.

## Overview

This project demonstrates USB-controlled GPIO toggling on the Johnny552 development board. It includes:

- CH552 firmware
- Linux USB character device driver
- Documentation and examples

## Repository Structure
johnny552-usb-demo/
├── firmware/               # CH552 firmware source code
│   ├── include/            # Header files
│   ├── src/                # Source files
│   ├── Makefile            # Build script for firmware
│   └── README.md           # Firmware documentation
├── driver/                 # Linux USB character device driver
│   ├── src/                # Driver source files
│   ├── include/            # Driver header files
│   ├── Makefile            # Build script for driver
│   └── README.md           # Driver documentation
├── docs/                   # Project documentation
│   ├── architecture.md     # Architecture overview
│   ├── setup_guide.md      # Setup instructions
│   └── usage.md            # Usage examples
├── examples/               # Example applications and scripts
│   ├── user_app/           # User-space applications
│   └── test_scripts/       # Test scripts
├── LICENSE                 # Project license
└── README.md               # Project overview

## Getting Started

### Prerequisites

- Johnny552 development board
- SDCC compiler
- Linux system

### Building Firmware

```bash
cd firmware
make
