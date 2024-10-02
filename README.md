# Theft Monitoring System

## Project Overview
This project involves designing and developing a Theft Monitoring System that detects and alerts users to potential theft scenarios using a variety of sensors and components. The system is capable of detecting motion, the opening/closing of doors or windows, and triggering alarms when a potential theft event occurs. Additionally, it sends real-time notifications to the user and offers a web-based monitoring dashboard for visualizing system status and configuration.

## Features
* Motion Detection: Uses a PIR sensor to detect movement.
* Door/Window Monitoring: Monitors door/window activities using magnetic sensors.
* Alarm System: Triggers a buzzer alarm upon detecting unauthorized activity.
* Real-time Notifications: Sends notifications via email, SMS, or a mobile app.
* Web Dashboard: A web-based interface to monitor and configure the system in real time.
* User Control: Allows users to arm/disarm the system via the Arduino Uno's reset button.

## Components
* Arduino Uno
* PIR Sensor (for motion detection)
* Magnetic Sensors (for monitoring doors/windows)
* Buzzer (for alarm)
* LED (for visual status indicator)
* Servo Motor (for controlling doors)
* Keypad (for user input)

## Circuit Diagram
![image](https://github.com/user-attachments/assets/806e70a2-9b67-4920-b1f7-85a68dde5b7c)

## How It Works
1. Motion or Door/Window Activity: When the PIR sensor detects motion or the door/window sensor detects activity, the system triggers an alarm.
2. Alarm and Notifications: The system activates a buzzer and sends a notification to the user (via email/SMS or app).
3. Monitoring: A web dashboard allows users to monitor the system in real-time and configure settings.
4. User Control: Users can enter a password on the keypad to disarm the system or reset it using the Arduino’s reset button.

## How to Run the Project
1. Connect the components as described in the circuit diagram.
2. Upload the code to the Arduino Uno using the Arduino IDE.
3. Monitor the system via the web dashboard, and receive real-time notifications for any detected activity.

## Future Enhancements
* Integrate additional sensors for enhanced security.
* Add support for mobile notifications using a dedicated mobile app.
* Implement cloud-based storage for logging events.
