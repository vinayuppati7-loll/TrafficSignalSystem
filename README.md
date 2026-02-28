Traffic Signal System – Minor Project

##  Project Title & Objective

Traffic Signal System using Queue (Linked List)

The objective of this project is to simulate vehicle management at a traffic signal using the Queue data structure implemented with a Singly Linked List, following the FIFO (First-In-First-Out) principle.

## Description

This project simulates how vehicles are managed at a traffic signal. Vehicles arrive and wait in a queue. When the signal turns green, the first vehicle in the queue is allowed to pass.

The system follows the FIFO rule, meaning the vehicle that arrives first will leave first. Each vehicle is stored as a node containing vehicle number, vehicle type, and a pointer to the next vehicle.

The program is menu-driven and allows users to:

- Add a vehicle
- Allow a vehicle to pass (Green Signal)
- Display all waiting vehicles
- Exit the program safely

Proper memory management is handled by deleting nodes when vehicles leave the queue.

##  Technologies / DSA Concepts Used

- C++
- Queue Data Structure
- Singly Linked List
- FIFO Principle
- Object-Oriented Programming
- Dynamic Memory Allocation

##  Setup Instructions

1. Open the project in any C++ IDE (VS Code / CodeBlocks / Dev C++).
2. Compile using:
   `g++ main.cpp`
3. Run using:
   `./a.out`


##  Challenges Faced

- Managing front and rear pointers correctly
- Handling empty queue conditions
- Proper memory deallocation after dequeue
