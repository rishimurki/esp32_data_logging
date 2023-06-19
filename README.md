# esp_msd
logging temperature and humidity readings to a micro sd card using esp32

## Libraries

The following libraries are used in the project:

- DHT: Libraries for the DHT11 sensor.
- WiFi: Library for connecting to a WiFi network.
- NTPClient: Library for obtaining the current time from an NTP server.
- WiFiUdp: Library for handling UDP packets over WiFi.
- time: Library for manipulating time values.
- FS: Library for interacting with the file system.
- SD: Library for accessing SD cards.
- SPI: Library for communicating with devices using the Serial Peripheral Interface.
- LiquidCrystal_I2C: Library for controlling LCD displays using the I2C protocol.

## Hardware Required

- ESP32 development board: The ESP32 will serve as the main microcontroller for your project. It provides WiFi connectivity and has sufficient GPIO pins for connecting the required components.

- DHT11 temperature and humidity sensor: The DHT11 sensor will be used to measure temperature and humidity values. It is a low-cost sensor that provides reasonably accurate readings.

- LCD display: You'll need an LCD display to show the temperature and humidity values. An LCD with I2C interface (e.g., 16x2 LCD with I2C backpack) is recommended as it requires fewer pins to connect and is easier to set up.

- SD card module: To store the temperature and humidity data, you'll need an SD card module. This will allow you to save the data to an SD card for later analysis or use.

- Jumper wires: You'll require jumper wires to connect the ESP32, DHT11 sensor, LCD display, and SD card module together. Ensure you have appropriate male-to-male, male-to-female, or female-to-female jumper wires based on your specific requirements.

- Power supply: Provide a stable power supply for the ESP32 and other components. This can be done using a USB cable connected to a power source (e.g., computer, USB charger) or a separate power supply (e.g., batteries, DC adapter).

- Breadboard or prototyping board (optional): You may find it helpful to use a breadboard or prototyping board to facilitate the connections between the components. It allows for easy and temporary connections during the development phase.

Ensure you have all the required hardware components before starting your project.

## Instructions

To run the code for your tinkering project, follow these steps:

1. Connect the required hardware components, such as the DHT11 sensor, LCD display, and SD card module, to your microcontroller or development board.
2. Open the code in your preferred integrated development environment (IDE) or text editor.
3. Make sure you have the required libraries installed. If not, install them using the library manager in your IDE or manually download and install them.
4. Update the code with your specific details:
   - Replace `YOUR_SSID` with the name of your WiFi network.
   - Replace `YOUR_PASSWORD` with the password of your WiFi network.
5. Upload the code to your microcontroller or development board.
6. Open the serial monitor in your IDE to view the debug messages and ensure the board is successfully connected to the WiFi network.
7. Verify that the LCD display is showing the connection status and any relevant data from the sensors.
8. The code will continuously read sensor data, update the LCD display, and save the data to an SD card.
9. Monitor the serial output and LCD display to observe the sensor readings and data logging.

Make sure you have the necessary hardware components connected and powered appropriately before running the code.

## References

1. **ESP32 Documentation**: The official documentation for the ESP32 development board provides detailed information about the board's features, pinout, programming, and libraries. You can refer to the official documentation at [ESP32 Documentation](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/index.html).

2. **DHT Library**: The DHT library provides functions for interacting with DHT sensors. You can find more information about the library and its usage in the Arduino Library Manager or on the library's GitHub page at [DHT Library](https://github.com/adafruit/DHT-sensor-library).

3. **LiquidCrystal_I2C Library**: The LiquidCrystal_I2C library simplifies the control of LCD displays using the I2C protocol. You can find more information about the library and its usage in the Arduino Library Manager or on the library's GitHub page at [LiquidCrystal_I2C Library](https://github.com/fdebrabander/Arduino-LiquidCrystal-I2C-library).

4. **SD Card Library**: The SD library provides functions for reading and writing data to SD cards. You can find more information about the library and its usage in the Arduino Library Manager or on the library's GitHub page at [SD Library](https://github.com/arduino-libraries/SD).

5. **Official Arduino Website**: The official Arduino website provides a wealth of information, tutorials, and examples that can help you with various aspects of your project. You can explore their website at [Arduino](https://www.arduino.cc/).

6. **Online Forums & Communities**: Online forums and communities such as the Arduino Forum and ESP32 Community Forum are great places to seek help, ask questions, and share your project progress. You can find these forums at [Arduino Forum](https://forum.arduino.cc/) and [ESP32 Community Forum](https://esp32.com/).


