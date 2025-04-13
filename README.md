# Navigation Assistant

A smart navigation assistant that combines obstacle detection using ultrasonic sensors and object recognition using computer vision.

## Project Overview

This project integrates hardware sensors with computer vision to create an assistive navigation tool. The system can:
- Detect obstacles in the proximity using ultrasonic sensors
- Provide audio feedback with different tones based on distance
- Recognize objects using computer vision (YOLO)
- Announce detected objects using speech synthesis

## Components

### Hardware
- Arduino board (for sensor integration)
- 2 Ultrasonic sensors (HC-SR04 or similar)
- Buzzer for audio feedback
- Emergency button
- Camera ( Raspberry Pi camera)
- Raspberry Pi for running the vision system

### Software
- Arduino code for sensor management
- Python script for computer vision using YOLO

## Hardware Setup

The Arduino part handles the distance sensing with the following pins:
- Ultrasonic Sensor 1: Trig on pin 2, Echo on pin 3
- Ultrasonic Sensor 2: Trig on pin 5, Echo on pin 4
- Buzzer: pin 6
- Emergency button: pin 7


## Features

### Obstacle Detection (Arduino)
- Monitors distance from obstacles using ultrasonic sensors
- Provides audible feedback with different tones based on distance and direction
- Emergency alert mode with rapid beeping

### Object Recognition (Python)
- Detects and identifies objects using YOLO computer vision
- Displays bounding boxes and confidence levels
- Counts the number of detected objects
- Announces detected objects via speech synthesis
- Can process images, videos, or real-time camera feeds

## Project Structure
- `Sensors.ino`: Arduino code for distance sensing and audio feedback
- `computer_vision.py`: Python script for object detection using YOLO

## Future Improvements
- Integration of the two systems for more intelligent obstacle avoidance
- Vibration feedback for tactile alerts
- Mobile app integration for settings and feedback
- Custom object detection for specific navigation assistance needs
