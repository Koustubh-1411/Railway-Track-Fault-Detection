#  Railway Track Fault Detection System

## Project Description

The Railway Track Fault Detection System is an IoT-based solution designed to improve railway safety by continuously monitoring track conditions in real time. The system detects faults such as cracks, gaps, and abnormal vibrations using multiple sensors and provides instant alerts to concerned authorities.
The ESP32 microcontroller acts as the central unit, collecting and processing data from the ultrasonic and vibration sensors. The ultrasonic sensor measures the distance between the sensor and the track surface to identify structural defects, while the vibration sensor detects unusual movements that may indicate internal damage.
To enhance accuracy, the system uses sensor fusion, meaning a fault is confirmed only when both sensors detect abnormal conditions. This reduces false alarms and ensures reliable fault detection.

##  Key Features

* Real-time railway track monitoring
* Accurate fault detection using sensor fusion
* GPS-based location tracking
* GSM-based SMS alert system
* Instant buzzer alert for local warning
* Low-cost and energy-efficient design
* Suitable for remote and inaccessible areas

## System Working

1. The ESP32 continuously reads data from ultrasonic and vibration sensors.
2. Distance is measured and compared with a predefined normal value.
3. Vibration sensor detects abnormal movement.
4. If both conditions are satisfied, a fault is confirmed.
5. The buzzer is activated for immediate alert.
6. GPS module provides location coordinates.
7. GSM module sends an SMS alert with fault details and location.
8. The system continues monitoring in real time.

## Hardware Components

* ESP32 Microcontroller
* Ultrasonic Sensor (HC-SR04)
* Vibration Sensor
* GPS Module (NEO-6M)
* GSM Module (SIM800L)
* LM2596 Buck Converter
* Buzzer
* Rechargeable Battery
* Push Button
* Jumper Wires

## Pin Configuration

| Component             | ESP32 Pin |
| --------------------- | --------- |
| Ultrasonic TRIG       | GPIO 5    |
| Ultrasonic ECHO       | GPIO 18   |
| Vibration Sensor (DO) | GPIO 19   |
| Buzzer                | GPIO 23   |
| GPS TX                | GPIO 16   |
| GPS RX                | GPIO 17   |
| GSM TX                | GPIO 26   |
| GSM RX                | GPIO 27   |


## Power Management

* Battery is used as the main power source
* LM2596 buck converter regulates voltage
* GPS and GSM modules are powered through LM2596
* Sensors and buzzer are powered directly from ESP32
* Common ground is maintained across all components

## Applications

* Railway track fault detection and monitoring
* Preventive maintenance systems
* Smart railway infrastructure
* Remote and inaccessible area monitoring
* Emergency alert and safety systems

## Repository Contents

*  Source Code (.ino)
*  Block Diagram
*  Circuit Diagram
*  Project Documentation
*  Components List and Cost Analysis

## Future Enhancements

* Integration with IoT cloud platforms
* Real-time monitoring dashboard
* AI-based predictive maintenance
* Mobile application for live tracking
* Solar-powered system for remote areas

## Author

**Ishika Bharti And Koustubh Tiwari**


##  Conclusion
The proposed system provides a reliable, cost-effective, and efficient solution for real-time railway track fault detection. By combining sensor data, location tracking, and instant communication, it significantly enhances railway safety and reduces the risk of accidents.
