# ESP32 Bluetooth Master-Slave Communication

This project demonstrates a simple Bluetooth communication setup between two ESP32 devices, where one ESP32 acts as a Master and the other as a Slave. The Master device sends JSON-formatted commands to the Slave device to control various GPIO pins. This setup is ideal for remotely controlling hardware components connected to the Slave ESP32.

## Features

- **Bluetooth Communication:** The project uses the built-in Bluetooth capabilities of the ESP32 to establish a wireless communication link between the Master and Slave devices.
- **JSON Data Exchange:** Commands from the Master are sent in JSON format, making it easy to extend and modify the data structure for more complex applications.
- **GPIO Control:** The Slave ESP32 receives commands to control GPIO pins, enabling the toggling of connected devices such as LEDs, relays, etc.
- **Simple and Extensible:** The code is simple, making it easy to understand and extend for more advanced applications.

## Hardware Requirements

- Two ESP32 development boards
- Optional: Buttons, LEDs, or other peripherals for GPIO control

## Software Requirements

- Arduino IDE with ESP32 board support
- ArduinoJson library
- BluetoothSerial library (built-in with ESP32 Arduino core)

## Getting Started

### 1. Clone the Repository

```bash
git clone https://github.com/yourusername/esp32-bluetooth-master-slave.git
cd esp32-bluetooth-master-slave
```


## Upload the Code
- Open the esp32-bluetooth-master-slave.ino file in the Arduino IDE.
- Ensure you have selected the correct ESP32 board and port under Tools > Board and Tools > Port.
Upload the code to both ESP32 boards.
## Circuit Setup
Connect LEDs, relays, or other peripherals to the GPIO pins defined in the code.
Ensure the buttons are properly connected if using the example that includes buttons.
## Run the Project
- Power up both ESP32 boards.
- The Master ESP32 will automatically try to connect to the Slave ESP32.
- Once connected, the Master can send JSON commands to the Slave to control the connected devices.
## Example JSON Command
The Master device sends commands in JSON format to the Slave device. An example of a JSON command is:
```
{
  "pin_number": 4,
  "pin_status": true
}
```
This command instructs the Slave device to set GPIO pin 2 to HIGH.
## Contributing
Contributions are welcome! Please fork this repository and submit a pull request with your enhancements.

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

