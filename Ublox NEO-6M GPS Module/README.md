# NEO-6M GPS Module Test with TinyGPS++  

This Code is designed to test the **NEO-6M GPS module** using an **Arduino board**. It utilizes the `TinyGPS++` library for parsing GPS data and `SoftwareSerial` to establish communication with the module.

## Components Required  
- **Arduino Board** (Uno, Mega, etc.)  
- **NEO-6M GPS Module**  
- **Jumper Wires**  

## 🛑🛑 Warning 🛑🛑
**Do NOT connect the GPS module's VCC to 5V directly!**  
The NEO-6M module operates at **3.3V logic levels**, and connecting it to 5V may damage it.  
Use a **3.3V power supply** or a level shifter if needed.

## Wiring Diagram  
| GPS Module Pin | Arduino Pin |
|---------------|------------|
| VCC          | 3V  - Don't connect to 5V       |
| GND          | GND        |
| TX           | D4 (RX)    |
| RX           | D3 (TX)    |

## Installation  
1. Install the **TinyGPS++** library in Arduino IDE:  
   - Go to **Sketch** → **Include Library** → **Manage Libraries**  
   - Search for `TinyGPS++` and install it.  
2. Upload the provided **Arduino sketch** to your board.  

## Code Explanation  
- The `SoftwareSerial` library is used to communicate with the GPS module.  
- The `TinyGPS++` library extracts **latitude, longitude, date, and time**.  
- The loop continuously checks for available GPS data and prints it to the **Serial Monitor**.  
- If no GPS data is detected within 5 seconds, it displays an error message.

## Expected Serial Monitor Output  
* When the GPS module is functioning correctly, you will see output similar to this:

```
Test Your NEO-6M GPS Module  
Testing TinyGPS++ library v. 1.0.3  
by ASKI001  

Location: 37.774929,-122.419416  Date/Time: 03/29/2025 12:45:30.05  
Location: 37.774930,-122.419418  Date/Time: 03/29/2025 12:45:31.07  
Location: 37.774932,-122.419420  Date/Time: 03/29/2025 12:45:32.10  
```

* If GPS module is not connected with satelights, You may see: 

```
Location: INVALID  Date/Time: 0/0/2000 00:00:00.00
Location: INVALID  Date/Time: 0/0/2000 00:00:00.00
Location: INVALID  Date/Time: 0/0/2000 00:00:00.00
Location: INVALID  Date/Time: 0/0/2000 00:00:00.00
Location: INVALID  Date/Time: 0/0/2000 00:00:00.00
Location: INVALID  Date/Time: 0/0/2000 00:00:00.00
Location: INVALID  Date/Time: 0/0/2000 00:00:00.00
```
* In such case , go to an outdoor location and wait 2-4 minutes until the satel;ite module connects, Point the antenna toward the sky.
* if the module is corectly connected to the satelight,the Blue or Red LED on the GPS module will blink. <br><br>


* If GPS module is not properly connected to pins on the Arduino board, you may see:  

```
No GPS detected: check wiring.
```

## Troubleshooting  
1. **Ensure GPS module wiring is correct.**  
2. **Check that the module has a clear view of the sky** (for satellite signal).  
3. **Increase the timeout** in the code if the signal is weak.  
4. **Try a different baud rate** if data isn't displaying correctly.  

## License  
This project is open-source and can be freely modified.  

by ASKI001

---

Enjoy testing your GPS module! 🚀  
