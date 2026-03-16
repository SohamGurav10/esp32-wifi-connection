# ESP32 Wi-Fi Connection using PlatformIO

This project demonstrates how to **connect an ESP32 (ESP-WROOM-32) to a Wi-Fi network** using the Arduino framework in PlatformIO.  
It prints the Wi-Fi connection status and IP address to the **Serial Monitor**, and automatically retries if the connection drops.

---

# Table of Contents

* [Overview](#overview)
* [Hardware Requirements](#hardware-requirements)
* [Wiring](#wiring)
* [Code Explanation](#code-explanation)
* [Running the Program](#running-the-program)
* [Example Output](#example-output)
* [Why Wi-Fi Connection Checking is Useful](#why-wi-fi-connection-checking-is-useful)
* [License](#license)

---

# Overview

This project uses the **WiFi library** to connect your ESP32 to a Wi-Fi network.  

The ESP32 will:

* Attempt to connect to the provided Wi-Fi credentials.  
* Print the connection status and IP address to the Serial Monitor.  
* Automatically retry if disconnected.  

This is useful for **IoT projects** where reliable network connectivity is required.

---

# Hardware Requirements

* ESP32 development board (ESP-WROOM-32)  
* USB cable to connect ESP32 to your computer  

---

# Wiring

No additional wiring is required.  
Just connect the ESP32 to your computer via USB.

---

# Code Explanation

- **Include Wi-Fi Library** – The `WiFi.h` library allows the ESP32 to connect to Wi-Fi networks.  
- **Setup Function** – Runs once when the ESP32 boots. Initializes serial communication and starts the Wi-Fi connection.  
- **Connect to Wi-Fi** – The program connects to the network using your SSID and password.  
- **Wait for Connection** – The ESP32 waits until a connection is established or a maximum retry count is reached.  
- **Print Connection Status** – Once connected, it prints the Wi-Fi status and the IP address assigned to the ESP32.  
- **Loop Function** – Continuously monitors Wi-Fi status every 10 seconds and automatically attempts to reconnect if disconnected.

---

# Running the Program

1. Replace the placeholders with your Wi-Fi credentials in the main code file.  
2. Connect the ESP32 to your computer via USB.  
3. Upload the project using PlatformIO:

```bash
pio run --target upload
```

4. Open the Serial Monitor to view connection messages:

```bash
pio device monitor
```

5. Set the baud rate to **115200**.

---

# Example Output

When the ESP32 connects successfully:

```
Connecting to WiFi...
..........
WiFi connected!
IP Address: 192.168.1.123
Connected, IP: 192.168.1.123
```

If the ESP32 disconnects, it will automatically retry:

```
WiFi disconnected, retrying...
Connected, IP: 192.168.1.123
```

---

# Why Wi-Fi Connection Checking is Useful

* IoT projects often rely on **continuous network access**.
* Ensures your ESP32 can **automatically reconnect** after power cycles or network drops.
* Helps in troubleshooting connectivity issues before adding more network-dependent functionality.

---

# License

This project is **open source** and free to use for learning and development.