# Autonomous Drone Lab

## Overview

Welcome to the Drone-Lab project — an autonomous drone development journey inspired by the designs of Carbon Aeronautics.

This project begins with the design, assembly, and flight testing of a quadcopter based on Carbon Aeronautics’ drone model. The goal of this phase is to build a stable flight platform and implement core flight control firmware using the Teensy 4.0 microcontroller.

At this stage, the drone uses real-time sensor feedback from an onboard gyroscope and barometer to control and stabilize flight. The system interprets receiver inputs using the PulsePosition library and applies PID control loops for Roll, Pitch, and Yaw stabilization. Motor control is handled through PWM signals.

While GPS navigation and obstacle avoidance are planned for future phases, this repository currently focuses on:
-	Mechanical assembly & wiring based on Carbon Aeronautics’ drone
-	Sensor calibration and real-time data processing
-	PID control loop implementation for flight stabilization
-	Teensy 4.0-based firmware development
-	Basic motor test routines and receiver input integration

Future extensions will explore full autonomy, GPS navigation, and obstacle avoidance.

---

## Purpose

To learn the fundamentals of drone design and control, including hardware integration, sensor fusion using a Kalman filter, and PID-based flight stabilization using a Teensy 4.0 microcontroller.

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
- [Theoretical Knowledge](#theoretical-knowledge)
    - [History](#history)
    - [Why Formal Verification?](#why-formal-verification)
    - [How Does Formal Verification Work?](#how-does-formal-verification-work)
    - [Formal Verification Results](#formal-verification-results)
    - [Formal Verification Methods](#formal-verification-methods)
    - [SystemVerilog (SV) and Its Role in Formal Verification](#systemverilog-sv-and-its-role-in-formal-verification)
- [Prerequisites](#prerequisites)
- [Running the code](#running-the-code)
- [Screenshots](#screenshots)

