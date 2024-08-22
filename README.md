
Code Overview
This code is designed to read soil moisture levels using a sensor, calculate the moisture percentage, and display the result on an LCD screen. It also prints the raw sensor value and the calculated percentage to the Serial Monitor for debugging or logging purposes.

Workflow
1. Initialization:

- The LCD is initialized with specific pins for communication.
- Serial communication is set up to allow data to be printed to the Serial Monitor.
- Constants (AirValue and WaterValue) are defined to represent the sensor readings for completely dry and fully saturated soil, respectively.
  
2. Reading Soil Moisture:

- The soil moisture sensor is connected to an analog pin (A0). The analogRead(A0) function reads the sensor's raw value, which is an analog signal converted to a digital value (ranging from 0 to 1023).
 
3. Calculating Moisture Percentage:

- The map() function converts the raw sensor value to a percentage, where AirValue corresponds to 100% (very dry) and WaterValue corresponds to 0% (fully saturated).
  
4. Displaying and Logging Data:

- The calculated moisture percentage is printed to the Serial Monitor.
- The LCD displays either "100%" (very dry), "0%" (very wet), or the actual moisture percentage based on the sensor reading.
  
5. User Feedback:

- The LCD provides real-time visual feedback on the moisture level of the soil.
- The Serial Monitor allows the user to see raw sensor values and the calculated percentage, useful for debugging.

  
Communication Protocols
1. Analog-to-Digital Communication:

- Analog Pin (A0): The soil moisture sensor outputs an analog voltage proportional to the soil's moisture content. This analog signal is read by the Arduino using the analogRead() function, which converts it to a digital value (0-1023).
- Protocol: This is a basic analog-to-digital conversion where the Arduino’s built-in ADC (Analog-to-Digital Converter) converts the analog signal from the sensor into a digital value.
  
2. Serial Communication:

- Serial Monitor: The Arduino uses UART (Universal Asynchronous Receiver/Transmitter) to communicate with a computer via the Serial Monitor. This allows the code to print out sensor values and calculated percentages, which can be viewed in real-time.
- Protocol: The Serial communication uses a standard UART protocol, where data is transmitted bit by bit over a single wire (TX) to the connected computer.
  
3. Parallel Communication (LCD):

- LiquidCrystal Library: The LCD is controlled using the LiquidCrystal library, which allows the Arduino to send data and commands to the LCD. The library uses multiple digital pins (RS, EN, D4, D5, D6, D7) to interface with the LCD.
- Protocol: The communication with the LCD is parallel, meaning multiple bits are sent simultaneously across several wires (pins). This parallel protocol is typically used in simpler embedded systems for faster data transfer to devices like LCDs.

  Demo video - https://www.youtube.com/watch?v=0GFoafMM_r8
