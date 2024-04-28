# Remote-Controlled-Car-Embedded-Real-Time

## Image of the car

<img width="500" height="500" alt="image" src="https://github.com/mohamadd10/Remote-Controlled-Car-Embedded-Real-Time/assets/119814738/526e20f8-8bb9-4a1a-aed8-e1db8df51761">


## Overview

This project implements a remote-controlled car using an infrared (IR) remote control and ultrasonic sensor for obstacle detection. The car can be controlled wirelessly using an IR remote, with features such as forward, backward, left turn, right turn, speed adjustment, and emergency stop. The ultrasonic sensor ensures safe navigation by detecting obstacles and automatically stopping the car when the distance is too close.

## Features

- **IR Remote Control**: Enables wireless control of the car with an IR remote, offering intuitive commands for movement and speed adjustment.
- **Obstacle Detection**: Integrates an ultrasonic sensor to detect obstacles in the car's path, automatically stopping movement when an obstacle is detected within a specified range.
- **Dynamic Movement**: Provides versatile movement options, including forward, backward, left turn, and right turn, enhancing maneuverability in various scenarios.
- **Speed Adjustment**: Allows for real-time adjustment of the car's speed using dedicated buttons on the IR remote, providing flexibility in different environments.
- **Emergency Stop**: Implements an emergency stop feature that immediately halts all car movement in case of emergencies or unexpected obstacles.

## Hardware Requirements

- **Arduino Board**: Compatible with Arduino Uno or similar models.
- **IR Receiver**: Used to receive signals from the IR remote control.
- **IR Remote Control**: Provides wireless control commands to the car.
- **Ultrasonic Sensor**: Utilized for obstacle detection and distance measurement.
- **Motor Driver**: Required for controlling the motors that drive the car's wheels.
- **DC Motors**: Powers the car's movement, with separate motors for each wheel.

## Software Requirements

- Arduino IDE
- IRremote Library
- Arduino_FreeRTOS Library

## Setup Instructions

1. **Hardware Setup**: Connect the required components
2. **Software Setup**: Install necessary libraries in the Arduino IDE, including the IRremote library for IR remote communication.
3. **Upload Code**: Upload the provided Arduino sketch to the Arduino board using the Arduino IDE.
4. **IR Remote Configuration**: Ensure the IR remote is compatible and configured to transmit the specified IR control codes for the car's movement and speed adjustments.

## Operation

- **Wireless Control**: Use the IR remote to wirelessly control the car's movement and speed adjustments.
- **Obstacle Detection**: The ultrasonic sensor continuously monitors the car's surroundings for obstacles, automatically stopping movement when an obstacle is detected within the specified range.
- **Speed Adjustment**: Adjust the car's speed in real-time using dedicated buttons on the IR remote control.
- **Emergency Stop**: Press the emergency stop button on the IR remote to immediately halt all car movement in case of emergencies or unexpected obstacles.

## UML CLASS diagram
<img width="400" height="400" alt="image" src="https://github.com/mohamadd10/Remote-Controlled-Car-Embedded-Real-Time/assets/119814738/4ac06b5b-1b8a-4ff3-97ed-a3404bda366b">

## UML Sequence diagram

<img width="400" height="450" alt="image" src="https://github.com/mohamadd10/Remote-Controlled-Car-Embedded-Real-Time/assets/119814738/a8d3f31f-c137-4170-8d42-79309019e4e6">

