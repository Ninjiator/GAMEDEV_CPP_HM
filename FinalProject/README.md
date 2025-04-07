# CupHead-Inspired Game Documentation
---
> This project is entirely non-commercial and is not intended to infringe on intellectual property rights of Studio MDHR. All rights to the original CupHead remain with Studio MDHR.
---
This document provides a concise overview of my CupHead-like game project developed in C++ with SFML

---
![image](https://github.com/user-attachments/assets/c8b87180-0f1b-4501-aa68-7320d1f10d1d)

## 1. Overview

The project is a CupHead-inspired game built using C++ and the SFML library. It features a player character, a boss enemy, and various animated objects and effects. The game includes multiple states such as the title screen, gameplay, pause, game over, and victory screens.

---

## 2. Architecture and Structure

The project is modular, with each major functionality implemented in separate classes (with their corresponding header and source files):

- **main.cpp**  
  Initializes the SFML window and runs the main game loop by processing events, updating, and rendering the current game state.

- **GameWorld**  
  Combines all key game components—background, player, boss, weapons, HUD—and implements the `IEffectSpawner` interface to spawn visual effects.

- **GameState & GameStateManager**  
  Handle the various game states (title screen, gameplay, pause, game over, victory) and allow smooth transitions between them.

- **PhysicsEngine**  
  Detects collisions between objects (e.g., projectiles with the player or boss) and triggers appropriate responses (reducing health, spawning effects)

- **SoundManager**  
  A singleton that manages sound effects and music, including jump, shoot, hit, and background music playback

- **GameConfig**  
  Contains constants for configuring speeds, jump impulses, boss health thresholds, and other game parameters.

---

## 3. Main Components and Responsibilities

### 3.1 Main Game Loop (main.cpp)
- **Initialization:** Creates the SFML window and initializes the `GameWorld` and `GameStateManager`.
- **Loop:** Processes system events, updates the current game state, renders game objects, and displays the final frame.

### 3.2 Game World (GameWorld)
- **Components:** Integrates the background (`Background`), player (`Player`), boss (`Boss`), weapons (`Weapon`, `BossWeapon`), HUD (`PlayerHealthHUD`), and the physics engine.
- **Effect Spawning:** Implements the `IEffectSpawner` interface to spawn visual effects like explosions and spark effects.

### 3.3 Physics Engine (PhysicsEngine)
- **Collision Detection:** Uses SFML’s `FloatRect` to check for collisions between projectiles and game objects.
- **Collision Response:** Calls `onCollision` methods in the relevant objects and spawns effects accordingly 

### 3.4 Game Objects
![image](https://github.com/user-attachments/assets/f2bcab5b-916a-45b8-834b-d580896534ce)
![image](https://github.com/user-attachments/assets/26c2f1bf-1912-4139-98b1-bb80808ab128)
![image](https://github.com/user-attachments/assets/88c476cd-f905-4623-b30a-7a91ff014691)


- **Player**  
  Manages movement, jumping, collision handling, and animations. It reduces health when hit and updates its sprite accordingly 

- **Boss**  
  Features multiple phases (Phase_1, Phase_2, Phase_3) based on its health. The boss moves along predefined waypoints and changes orientation and animation depending on its phase 

- **Projectile**  
  Represents projectiles fired by both the player and the boss. Each projectile has its own animation, movement logic, and destruction criteria (leaving the screen or colliding with objects) 

- **Weapon & BossWeapon**  
  Create projectiles. The player’s weapon fires basic projectiles, while the boss’s weapon includes both standard shooting and a falling bombs ability 
- **PlayerHealthHUD**  
  Displays the player's health status via an animated indicator 

- **Background**  
  It is not a part of the game objects, but creates magic with its liveliness, contains several layers of static and animated sprites that accurately recreate the arena from the DLC CupHead bossfight - Mortimer Freeze
  
### 3.5 Animations and Effects

- **Animation**  
  Splits textures into frames and updates sprites by changing texture rectangles based on elapsed time 

- **Effect**  
  Handles temporary visual effects (e.g., explosions, spark effects) using the `Animation` class and automatically stops when the animation is complete.

### 3.6 Sound Manager (SoundManager)
- **Sound Playback:**  
  Loads and plays sound effects (e.g., jump, shoot, hit) and background music.
- **Singleton Pattern:**  
  Ensures a single instance is used throughout the project, allowing sounds to be played from anywhere 

### 3.7 Game States (GameState & GameStateManager)

- **GameState:**  
  A base class for different states such as Title Screen, Playing, Pause, Victory, and Game Over.
  ![image](https://github.com/user-attachments/assets/bc59ec8a-fa1f-4ec9-83cd-3bcad9e1dd96)
  ![image](https://github.com/user-attachments/assets/63f1a368-261d-4cd3-9627-9126e6e15547)

- **GameStateManager:**  
  Manages the current state, transitions between states, and can reset the game world as needed 

### 3.8 Configuration (GameConfig)
- **Constants:**  
  Defines game physics parameters (gravity, projectile speeds, jump impulses) and boss behavior thresholds.

### 3.9 Additional Components
- **FontManager:**  
  A singleton that loads and provides access to fonts.
- **IEffectSpawner:**  
  An interface for spawning visual effects, used by the `PhysicsEngine`.

---

## 4. Key Algorithms and Game Logic

- **Sprite Animation:**  
  The `Animation` class manages frame-based animation by calculating time per frame and updating the sprite’s texture rectangle.

- **Collision Detection:**  
  Implemented with SFML’s `FloatRect`, detecting when projectiles intersect with game objects, triggering collision responses.

- **Movement and Physics:**  
  The player is influenced by gravity, can jump (using a jump impulse), and is constrained within the game arena.

- **Boss Logic:**  
  The boss moves between predefined waypoints and changes phases based on remaining HP. Orientation and animation are updated according to its current phase.

- **Game State Management:**  
  The `GameStateManager` controls state transitions based on user input (keyboard events) and game conditions (player or boss death).

---

## 5. Technologies Used

- **C++**  
  The programming language used for development.

- **SFML**  
  A multimedia library for graphics, audio, event handling, and timing.

- **ChatGpt**
For SpriteSheet generation from Cuphead sprites




