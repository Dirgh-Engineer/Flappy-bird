# Flappy Bird

A modern take on the classic Flappy Bird game, built using Raylib. The game features dynamic weather effects, a challenging Hell Mode, and a polished menu system for seamless navigation.

![image alt](https://github.com/Dirgh-Engineer/Flappy-bird/blob/e8f609a9f2675cc8570730f9b159d0b6d7cb91a9/menu.png)

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [How to Play](#how-to-play)
- [Installation](#installation)
- [Controls](#controls)
- [Code Overview](#code-overview)
  - [main.cpp](#maincpp)
  - [Bird.cpp](#birdcpp)
  - [Pipe.cpp](#pipecpp)
  - [Background.cpp](#backgroundcpp)
  - [Weather.cpp](#weathercpp)
  - [Menu.cpp](#menucpp)
  - [ParticleSystem.cpp](#particlesystemcpp)
  - [GameConfig.h](#gameconfigh)
- [Contributing](#contributing)
- [License](#license)

[🎯 Go to Table of Contents](#table-of-contents)

---

## Introduction

Flappy Bird is a modern reimagining of the beloved classic game that captivated millions worldwide. This version is built using Raylib, a lightweight yet powerful graphics library, and brings a host of new features designed to enhance the player experience. With dynamic weather effects that create a visually immersive environment, a challenging Hell Mode for seasoned players, and smooth animations, this game delivers both nostalgia and novelty. 

The game is designed with a polished menu system, ensuring seamless navigation and ease of use for players of all skill levels. Its customizable gameplay allows developers and enthusiasts to expand its features effortlessly, making it an excellent choice for both casual gaming and coding practice. Whether you're reliving the classic or exploring its new challenges, this iteration of Flappy Bird promises hours of engaging gameplay.

![video alt](https://github.com/Dirgh-Engineer/Flappy-bird/blob/407536644478be609c9940c6c63ae6b875bbbecf/Normal.gif)

[🎯 Go to Table of Contents](#table-of-contents) | [Next: Features](#features)

---

## Features

- **Dynamic Weather:** Realistic weather effects add variety to gameplay.
- **Hell Mode:** Activates after scoring 10 points, increasing the difficulty.
- **Smooth Animations:** Responsive controls and seamless transitions.
- **Customizable Gameplay:** Easily extendable codebase for adding new features.
- **Modern Graphics:** Built using Raylib for a lightweight yet powerful experience.

[🎯 Go to Table of Contents](#table-of-contents) | [Next: How to Play](#how-to-play)

---

## How to Play

Navigate the bird through a series of pipes without colliding. Earn points for each pipe successfully passed. Reach 10 points to activate Hell Mode and test your skills!

[🎯 Go to Table of Contents](#table-of-contents) | [Next: Installation](#installation)

---

## Installation

### Prerequisites

- Raylib library installed on your system.
- C++ compiler (e.g., GCC, Clang, or MSVC).

### Steps

1. Clone the repository:
   ```bash
   git clone https://github.com/Dirgh-Engineer/Flappy-bird
   ```
2. Navigate to the project directory:
   ```bash
   cd "D:\Flappy Bird"
   ```
3. Compile the game:
   ```bash
   g++ -o flappybird main.cpp Bird.cpp Pipe.cpp Background.cpp Weather.cpp Menu.cpp ParticleSystem.cpp -lraylib
   ```
4. Run the game:
   ```bash
   ./flappybird
   ```

[🎯 Go to Table of Contents](#table-of-contents) | [Next: Controls](#controls)

---

## Controls

- **SPACE:** Flap the bird to fly.
- **R:** Restart the game after a Game Over.
- **M:** Return to the main menu.

[🎯 Go to Table of Contents](#table-of-contents) | [Next: Code Overview](#code-overview)

---

## Code Overview

### main.cpp

The `main.cpp` file serves as the entry point of the game, managing the game loop and state transitions.

- **Menu System:** Handles user input and transitions between menu and gameplay states.
- **Gameplay Logic:** Spawns pipes, updates bird and background, and checks for collisions.
- **Hell Mode:** Activates when the score reaches 10, making the game more challenging.

### Bird.cpp

Manages the bird's behavior, including its movement, animations, and collision handling.

- **Physics-Based Movement:** Simulates gravity and allows the bird to jump.
- **Dynamic Animations:** Adjusts animation speed based on the bird's velocity.
- **Collision Box:** Implements a tighter collision box for accurate hit detection.
- **Wind Force:** Supports external wind forces for added gameplay dynamics.

### Pipe.cpp

Handles the obstacles the bird must navigate.

- **Dynamic Spawning:** Randomizes pipe height and gap for each obstacle.
- **Collision Detection:** Checks for collisions with the top or bottom pipes.
- **Visual Effects:** Draws pipes with gradient shadows and rounded edges.
- **Hell Mode Enhancements:** Adds visual effects and challenges in Hell Mode.

### Background.cpp

Manages the visual backdrop of the game.

- **Day-Night Cycle:** Adjusts overlay color based on the time of day.
- **Hell Mode Background:** Adds glowing effects when Hell Mode is active.
![video alt](https://github.com/Dirgh-Engineer/Flappy-bird/blob/6525b69e52ec229fae941af59c02630df50ddda2/Hell.gif)
- **Seamless Scrolling:** Ensures smooth background transitions.

### Weather.cpp

Adds dynamic weather effects for enhanced realism.

- **Rain Effects:** Simulates raindrops with motion and removal once offscreen.
- **Day-Night Cycle:** Creates transitions between day, night, sunrise, and sunset.
- **Toggleable Weather:** Allows enabling or disabling rain.

### Menu.cpp

Implements the game's main menu.

- **Title Animation:** A wave effect applied to the game title.
- **Interactive Buttons:** Includes Play, Settings, and Quit with hover effects.
- **Custom Fonts:** Uses external fonts for a polished interface.

### ParticleSystem.cpp

Manages particle effects for the game.

- **Crash Effects:** Emits particles when the bird crashes.
- **Particle Lifecycle:** Manages creation, motion, and fading of particles.
- **Customization:** Allows adjustment of particle properties.

### GameConfig.h

Contains core configurations for the game.

- **Screen Dimensions:** Defines the screen width (`SCREEN_WIDTH`) and height (`SCREEN_HEIGHT`).
- **Wind Settings:** Specifies maximum wind force for dynamic effects.

[🎯 Go to Table of Contents](#table-of-contents) | [Next: Contributing](#contributing)

---

## Contributing

Currently, this project has no external contributors. Contributions are welcome!

### Steps

1. Fork the repository.
2. Create a new branch for your feature:
   ```bash
   git checkout -b feature-name
   ```
3. Commit your changes:
   ```bash
   git commit -m "Add feature-name"
   ```
4. Push to the branch:
   ```bash
   git push origin feature-name
   ```
5. Open a pull request.

[🎯 Go to Table of Contents](#table-of-contents) | [Next: License](#license)

---

## License

This project is licensed under the MIT License. See the LICENSE file for details.
