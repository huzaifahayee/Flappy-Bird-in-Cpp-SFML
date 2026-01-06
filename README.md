# Urta Parinda (Flappy Bird Clone) 🐦

A professional, object-oriented Flappy Bird clone built with **C++** and **SFML**. This project serves as a showcase of software engineering principles and real-time game development.

![Flappy Bird Gameplay Placeholder](https://via.placeholder.com/600x400?text=Flappy+Bird+Gameplay)

## Features 🚀
- **Smooth Physics:** Realistic gravity and flapping mechanics.
- **Infinite Generation:** Procedurally generated pipes with randomized heights.
- **State Management:** Sophisticated game loop handling (Idle, Running, Game Over).
- **Responsive UI:** Real-time score tracking and interactive "Restart" buttons.
- **Clean Architecture:** Modular design using Software Engineering best practices.

## Installation (Windows) 💻
This project is built using **Visual Studio 2022** and **SFML 2.6.2**.

1. **Clone the Repo:**
   ```bash
   git clone (https://github.com/huzaifahayee/Flappy-Bird-in-Cpp-SFML)
   ```
2. **Requirements:**
   - [SFML 2.6.2](https://www.sfml-dev.org/download/sfml/2.6.2/) (VC++ 17 64-bit).
   - Visual Studio 2022.
3. **Configuration:**
   - Link the SFML `include` and `lib` directories in Project Properties.
   - Copy the required `.dll` files from the SFML `bin` folder to your project's build directory (`x64/Debug` or `x64/Release`).
4. **Build:** Open the `.sln` file and press `F5`.

## How to Play 🎮
- **Enter:** Start the game / Return to life.
- **Space:** Flap the bird's wings to stay in the air.
- **Mouse Click:** Click the "Dobaara Aan Deyo!" (Restart) text to play again after a crash.

## Project Structure 📂
```text
├── assets/             # Textures, Fonts, and Audio
├── Bird.h/cpp          # Player physics and animation
├── Pipes.h/cpp         # Obstacle logic and movement
├── Game.h/cpp          # Game loop and collision handling
├── Globals.h           # Shared constants (Window size, Scale)
├── main.cpp            # Application Entry Point
└── README.md           # You are here!
```

## Software Engineering Principles 🛠️
- **Modularity:** Highly decoupled classes for Bird, Pipes, and Game logic.
- **Encapsulation:** Private data members with clean public APIs.
- **Anticipation of Change:** Centralized `Globals.h` for easy difficulty tuning.

## Future Improvements 🌟
- [ ] Add sound effects for flapping and crashing.
- [ ] Implement a Local High Score system.
- [ ] Add multiple difficulty levels.



---
Developed with ❤️ by Muhammad Huzaifa
