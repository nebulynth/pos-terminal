# POS Terminal API Demo (C Project)

## 📌 Overview
This project is a Linux-based POS terminal simulation written in C. It demonstrates:
- Performing GET and POST requests to REST APIs
- Parsing JSON using `json-c`
- Simulated card reader integration
- Configuration via `config.json` (no hardcoding)

## 📁 Project Structure
include/ → Header files
src/ → Implementations
config.json → Central configuration (URLs, static data)
main.c → Entry point, coordinates logic
Makefile → Simple build automation


## ⚙️ Build Instructions

Prerequisite:
sudo apt-get update
sudo apt-get install libjson-c-dev

make
./pos_terminal