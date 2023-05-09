# C.A.R.S. Senior Design
## Rapid Tower Deployer

### Pinouts:
#### GPS (Start from left):
1. Empty
2. TX -> 1
3. RX -> 0
4. GND -> GND
5. Vcc -> 5v

#### Pressure Sensor:
1. Vout -> A0
2. GND -> GND
3. Vcc -> 5v

#### Relay Module:
1. GND -> GND
2. IN1 -> 9
3. IN2 -> 8
4. IN3 -> 7
4. IN4 -> 6
5. Vcc -> 5v

#### ToF Sensor (Pin 1 starts on brown wire):
1. SCL -> SCL (17)
2. SDA -> SDA (16)
3. GND_LED -> GND
4. Vcc_LED -> 5v
5. Empty
6. Empty
7. GND -> GND
8. Vcc -> 5v

#### WiFi Tranceiver (Pinouts the same for Transmitter and Receiver, last pin is unused)
1. VCC -> 3.3v
2. GND -> GND
3. CE -> 9
4. CSN -> 8
5. SCK -> 13
6. MOSI -> 11
7. MISO -> 12

## Plan for final version:
1. Initialize GPS, Relay, ToF, and Pressure, WiFi connection
2. Deployment:
  -Set solenoids to fill
  -Start compressor
  -Run for x amount of time
  -Check pressure:
    -Close solenoid, turn off compressor, read analog, check against set value, continue with fill or stop.
  -loop until deployed
 3. Start antenna serial port, pull data, transmit, close port. 
 4. Close antenna serial port
 5. Open drain for tube
 6. Wait for pressure to normalize
 7. End
