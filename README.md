# 🌗 Smart Light Control System (LDR + Relay + LED)

This Arduino project automatically turns on a relay (big bulb) and adjusts LED brightness based on ambient light levels using an LDR sensor.

## 🛠️ Components Used
- Arduino UNO
- LDR (Light Dependent Resistor)
- Relay Module
- LED
- Resistors
- Jumper Wires

## ⚙️ Functionality
- **Relay** turns ON the bulb when it gets dark.
- **LED** brightness increases as it gets darker (PWM control).
- Uses `analogRead()` from LDR and controls `relayPin` and `ledPin`.

## 🧪 How It Works
- If light level drops (sensor > 1000): Relay turns ON.
- LED brightness is mapped from ambient light using `map()` and `constrain()`.

## 🔧 Customization
- Adjust the `sensorValue > 1000` threshold as per your room's lighting.
- Use `Serial Monitor` to observe real-time values and tune accordingly.

## 🧾 Output Example
```
LDR Sensor: 1052 -> LED Brightness: 255 | Relay: ON (Dark)
LDR Sensor: 200 -> LED Brightness: 45 | Relay: OFF (Bright)
```

## 📁 Files
- `ldr_relay_led.ino` – Arduino source code
- `README.md` – This file

## 🚫 Disclaimer
Ensure you connect the relay module safely. For high voltage AC loads, take necessary precautions or supervision.
