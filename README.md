# Autonomous Drone Lab

## Overview

Welcome to the Drone-Lab project — an autonomous drone development journey inspired by the designs of Carbon Aeronautics.

This project begins with the design, assembly, and flight testing of a quadcopter based on Carbon Aeronautics’ drone model. The goal of this phase is to build a stable flight platform and implement core flight control firmware using the Teensy 4.0 microcontroller.

At this stage, the drone uses real-time sensor feedback from an onboard gyroscope and barometer to control and stabilize flight. The system interprets receiver inputs using the PulsePosition library and applies PID control loops for Roll, Pitch, and Yaw stabilization. Motor control is handled through PWM signals.

While GPS navigation and obstacle avoidance are planned for future phases, this repository currently focuses on:
-	Mechanical assembly & wiring
-	Sensor calibration and real-time data processing
-	PID control loop implementation for flight stabilization
-	Teensy 4.0-based firmware development
-	Basic motor test routines and receiver input integration

Future extensions will explore full autonomy, GPS navigation, and obstacle avoidance.
> 🚧 This repository is a work in progress — new parts and updates will be added continuously as the project develops.
---

## Purpose

To learn the fundamentals of drone design and control, including hardware integration, sensor fusion using a Kalman filter, and PID-based flight stabilization using a Teensy 4.0 microcontroller.

---

## Technology Stack


This project is built using the following tools and technologies:
- Teensy 4.0: ARM Cortex-M7-based microcontroller used as the flight controller core.
-	Arduino IDE / PlatformIO: Development environments used to write, upload, and debug firmware for the Teensy.
-	PulsePosition Library: Used to decode receiver input signals (PPM/SBUS) with precise timing.
-	MPU6050 / IMU Sensor: Provides gyroscope and accelerometer data for orientation feedback.
-	Kalman Filter: Sensor fusion algorithm used to estimate drone orientation from noisy sensor inputs.
-	PID Control: Algorithm used to stabilize Roll, Pitch, and Yaw by adjusting motor outputs.
-	PWM Control: Used to send speed signals to brushless motors via ESCs.
---

## Table of Contents

- [Overview](#overview)
- [Purpose](#purpose)
- [Technology Stack](#technology-stack)
- [Table of Contents](#table-of-contents)
- [Project Modules](#project-modules)
    - [Part 1 – Getting to know the Teensy 4.0 and Arduino IDE](#part-1--getting-to-know-the-teensy-40-and-arduino-ide)
    - [Part 2 – Controlling external LEDs](#part-2--controlling-external-leds)
    - [Part 3 – Measure battery lifetime with a voltage divider](#part-3--measure-battery-lifetime-with-a-voltage-divider)
    - [Part 4 – MPU6050 sensor](#part-4--mpu6050-sensor)
    - [Part 5 – Calibration of MPU6050](#part-5--calibration-of-mpu6050)
    - [Part 6 – Checking the motor](#part-6--checking-the-motor)
    - [Part 7 – Connecting the receiver to the Teensy](#part-7--connecting-the-receiver-to-the-teensy)
    - [Part 8 – Control motor with Teensy](#part-8--control-motor-with-teensy)

## Project Modules

### [Part 1 – Getting to know the Teensy 4.0 and Arduino IDE](./Part%201%20-%20Getting%20to%20know%20the%20Teensy%204.0%20and%20Arduino%20IDE)

Summary: Initial setup of the development environment, exploring the Teensy board and uploading basic code. 

In the detailed README:
-	Installing Teensyduino/PlatformIO
-	Connecting Teensy to PC
-	Uploading a basic “Hello World” sketch (e.g. blinking LED)
-	Teensy pinout overview

---

### [Part 2 – Controlling external LEDs](./Part%202%20-%20controling%20external%20LEDs)

Summary: Learn digital output by controlling external LEDs connected to Teensy.
In the detailed README:
-	Wiring diagram (LEDs + resistors)
-	Digital output code example
-	Explanation of HIGH/LOW states
-	Troubleshooting common issues

---

### [Part 3 – Measure battery lifetime with a voltage divider](./Part%203%20-%20Measure%20battery%20lifetime%20with%20a%20voltage%20divider)

Summary: Measure voltage using an analog pin and calculate battery level.
In the detailed README:
-	Voltage divider circuit diagram
-	Explanation of analogRead and mapping voltage
-	Safety tips for measuring LiPo batteries
-	Code to log or display voltage

---

### [Part 4 – MPU6050 sensor](./Part%204%20-%20MPU6050%20sensor)

Summary: Connect and read raw data from the gyroscope and accelerometer.
In the detailed README:
-	I2C wiring and setup
-	Reading raw values from MPU6050
-	Basic filtering concepts
-	Code examples for printing gyro/accel data

---

### [Part 5 – Calibration of MPU6050](./Part%205%20-%20Calibration%20of%20MPU6050)

Summary: Remove offset and noise from raw sensor data for more accurate readings.
In the detailed README:
-	Explanation of why calibration is needed
-	Method for calculating gyro bias
-	How to save and apply calibration values
-	Graphs or plots showing before/after calibration

---

### [Part 6 – Checking the motor](./part%206%20-%20checking%20the%20motor)

Summary: Test a single motor with PWM signals to ensure wiring and ESC setup are correct.
In the detailed README:
-	Wiring diagram (ESC → motor → Teensy)
-	PWM signal explanation
-	Simple motor test code
-	Safety precautions for motor testing

---

### [Part 7 – Connecting the receiver to the Teensy](./Part%207%20-%20Conection%20the%20reciver%20to%20the%20Teensy)

Summary: Read RC transmitter input using PulsePosition library.
In the detailed README:
-	Receiver wiring (PPM/SBUS setup)
-	PulsePosition library usage
-	Code to read and print channel values
-	Interpreting stick movements as signals

---

### [Part 8 – Control motor with Teensy](./Part%208%20-%20Control%20motor%20with%20Teensy)

Summary: Combine RC input and motor control to vary motor speed based on throttle stick.
In the detailed README:
-	Reading throttle input
-	Mapping input to motor PWM output
-	Safety logic (e.g. arming/disarming)
-	Real-time test results and tuning tips
