# GPS Point Real-Time Distance Calculator

This project is a GPS-based real-time distance calculator that determines the distance between the current GPS location and a predefined reference point using the <b>Haversine formula</b>. It utilizes the **TinyGPS++** library for GPS parsing and **SoftwareSerial** for communication with the GPS module.

## Features
- Reads GPS data from a GPS module (e.g., NEO-6M)
- Computes real-time latitude and longitude
- Calculates the distance from a predefined reference location
- Displays location coordinates and distance in meters
- Uses the Haversine formula for accurate distance computation

## Hardware Requirements
- Arduino board (e.g., Arduino Uno, Mega, etc.)
- GPS module (e.g., NEO-6M GPS module)
- Jumper wires

## Software Requirements
- Arduino IDE
- TinyGPS++ library (by Mikal Hart)
- SoftwareSerial library (built-in)

## Wiring Diagram
| GPS Module Pin | Arduino Pin |
|---------------|------------|
| VCC           | 3V         |
| GND           | GND        |
| TX            | Digital Pin 4 |
| RX            | Digital Pin 3 |

## Installation
1. Install the **TinyGPS++** library in the Arduino IDE:
   - Go to **Sketch** > **Include Library** > **Manage Libraries**.
   - Search for **TinyGPS++** and install it.
2. Connect the GPS module to the Arduino as per the wiring diagram.
3. Open the Arduino IDE and upload the `GPS_Distance_Calculator.ino` code.

## Code Overview
- **setup()**: Initializes serial communication and the GPS module.
- **loop()**: Reads and processes GPS data, calculates distance, and displays the results.
- **displayInfo()**: Displays the current GPS location and calculated distance.
- **calculateDistance()**: Uses the Haversine formula to compute the distance between two coordinates.
- **degToRad()**: Converts degrees to radians.

## Reference Location
Change `refLatitude` and `refLongitude` Value to asign Reference Location
```
const double refLatitude = 6.8092261029116345; // Example: ITUM latitude
const double refLongitude = 79.99088024017773; // Example: ITUM longitude
```

Modify these values in the code to set your own reference location.

## Expected Output (Example)
```
GPS Point RealTime Distance Calculator
Testing TinyGPS++ library v. 1.0.2
by ASKI001

Location: 6.808733397223537, 79.99314379222184  Distance from reference: 61091.80 meters
Location: 6.808733397223537, 79.99314379222184  Distance from reference: 61091.80 meters
```

## Troubleshooting
- If you see **`No GPS detected: check wiring.`**, ensure the GPS module is properly connected and powered.
- If you see **`Waiting for valid GPS fix...`**, move to an open area to get a better satellite signal.
- Ensure the correct baud rate (`9600`) is set for the GPS module.

## License
This project is open-source and can be freely used and modified.

## Author
Developed by **ASKI001**

