# Train Station Scheduler

This is a C++ project that simulates the scheduling of trains at different stations. The program allows you to schedule trains with two types: **Stoppage** and **Through**, ensuring that the scheduling follows specific time constraints for each station type. The system checks if the train can be scheduled based on the type of train previously scheduled at a specific station.

## Key Components

The code is modularized into three header files, each responsible for defining different aspects of the system, along with their corresponding `.cpp` implementations:

- **`Platform.h`**: 
  - Contains the declaration and method prototypes for the `Platform` class.
  - Responsible for scheduling trains on a specific platform while maintaining appropriate time gaps between consecutive trains based on the train type (`Stoppage` or `Through`).

- **`Line.h`**: 
  - Contains the declaration and method prototypes for the `Line` class.
  - Represents a railway line associated with a platform and manages multiple trains on that line.

- **`Station.h`**: 
  - Contains the declaration and method prototypes for the `Station` class.
  - The `Station` class is templated to accept either an integer or string as the station ID.
  - Manages multiple lines and is responsible for scheduling trains on the corresponding platform.

- **`main.cpp`**: 
  - Implements the main logic of the program.
  - Provides an interface for user interaction, including selecting stations, choosing train types, and specifying scheduling times.

## Libraries

The project is designed to demonstrate the use of both **static** and **dynamic** libraries:

- **Static Library**: `libstatIRlib.a`
  - Contains compiled code for the `Station`, `Line`, and `Platform` classes.
  - Included in the program at compile-time, creating a standalone executable.

- **Dynamic Library**: `libdynIRlib.so`
  - Contains compiled code for the `Station`, `Line`, and `Platform` classes.
  - Linked at runtime, reducing the size of the executable but requiring the library file to be present at runtime.

## Prerequisites

- A C++ compiler such as `g++` (GNU Compiler Collection).
- The `make` utility for automating the build process.

## How to Build and Run the Project

### Step 1: Clone the Repository

Clone the repository to your local machine:

```bash
git clone https://github.com/gkdey17cse/OOPD_Assignment3A.git
