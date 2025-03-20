# Snake Game in C++

A simple Snake Game built in C++ using object-oriented design. The project includes two main classes:  
- **Snake**: Contains the snake's state (head, tail, direction, and color) and methods for movement and collision detection.  
- **Game**: Manages overall game logic (rendering the field, processing input, updating state, handling collisions, and spawning fruit).

The game runs in the Windows console and uses the Windows API (e.g., `conio.h`, `windows.h`) for console handling and input.

## Features

- **Object-Oriented Design:**  
  The project is organized into separate classes (`Snake` and `Game`) for clear separation of concerns.

- **Dynamic Snake Color:**  
  Each time the snake eats a fruit, its color changes randomly.

- **Customizable Game Speed:**  
  Allow the user to choose between slow, medium, or fast speeds.

## Prerequisites

- A C++ compiler that supports C++11 or later (e.g., GCC, MinGW, or Visual Studio).
- Windows operating system (due to usage of Windows-specific headers and functions).

## Installation & Build Instructions

1. **Clone the Repository:**

   ```bash
   git clone https://github.com/yourusername/SnakeGame.git
   cd SnakeGame

2. **Build the Project:**

   If you are using g++ (for example, via MinGW on Windows), compile with the following command:
```bash
g++ main.cpp Game.cpp Snake.cpp -o SnakeGame
```
This will produce an executable named SnakeGame.exe.
Running the Game
After building the project:

Launch the executable from the command prompt or by double-clicking SnakeGame.exe.
Controls:
Press W to move up.
Press A to move left.
Press S to move down.
Press D to move right.
Press X to exit the game.
Follow the on-screen instructions to set your game speed and enter your name.
Project Structure
reasonml

SnakeGame/

├── Game.cpp         // Implementation of the game engine (rendering, input, updates)

├── Game.hpp         // Declaration of the Game class

├── Snake.cpp        // Implementation of the Snake entity (movement, growth, collision)

├── Snake.hpp        // Declaration of the Snake class and helper structs

├── main.cpp         // Program entry point and main game loop

└── README.md        // This file
