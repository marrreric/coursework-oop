# Distributed Traffic Control System

**Coursework for "Object-Oriented Programming"**

A distributed system simulation representing a smart crossroad with two traffic lights. Consists of two independent Qt applications (`Controller` and `Visualizer`) communicating over a local network using a custom point-to-point protocol.

## System Overview

The project implements a realistic traffic management system:
*   **Controller Application(Pult):** A control panel for managing traffic light modes and parameters.
*   **Visualizer Application(Svetofor):** A graphical display showing the real-time state of all traffic lights on the crossroad.

### Operating Modes:
*   **Off:** All lights are disabled.
*   **Autonomous (Flashing Yellow):** All lights blink yellow.
*   **Automatic:** Lights cycle automatically according to a user-defined timing protocol: `Green → Yellow → Red → Yellow → Green`.
*   **Manual:** Direct manual control of each light's state, bypassing timers.

## Tech Stack & Implementation

*   **Language:** C++17/20
*   **Framework:** Qt 6
*   **Network:** Qt Network Module (TCP/UDP Sockets)
*   **Concepts:** OOP, Client-Server Architecture, Event-Driven Programming, Multithreading

## Technical Implementation Details

*   **Communication Protocol:** Custom point-to-point protocol over local network
*   **State Management:** Finite-state machine implementation for light cycles
*   **Timer System:** `QTimer` and custom `TrafficTimer` class for precise timing control
*   **UI/UX:** Qt Widgets with intuitive control interface

## Screenshot

![Screenshot](https://github.com/marrreric/coursework-oop/blob/main/OOP.jpg?raw=true)

## Building and Running

### Before
*   Qt Creator and Qt development libraries
*   C++ compiler with C++17 support

### Steps
1.  Clone the repository:
    ```bash
    git clone https://github.com/marrreric/coursework-oop.git
    cd coursework-oop
    ```
2.  Open the `.pro` file in Qt Creator.
3.  Build both the **Controller** and **Visualizer** projects.
4.  Launch both applications to establish connection.