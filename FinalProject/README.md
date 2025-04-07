# CupHead-Inspired Game Documentation

> This project is entirely non-commercial and is not intended to infringe on the intellectual property rights of Studio MDHR. All rights to the original CupHead remain with Studio MDHR.

This document provides a detailed technical overview of a CupHead-inspired game project developed in C++ using the SFML library.

![CupHead-Inspired Banner](https://github.com/user-attachments/assets/c8b87180-0f1b-4501-aa68-7320d1f10d1d)

---

## 1. Overview

The project is a 2D game modeled after the aesthetics and gameplay of CupHead. It features:
- A player character with responsive controls and physics.
- A multi-phase boss enemy that follows preset waypoints.
- Dynamic background layers and animated effects.
- Multiple game states: title screen, gameplay, pause, game over, and victory screens.

---

## 2. Architecture and Structure

The project is organized into modular components, with each major functionality implemented in separate classes (headers and source files):

- **main.cpp**  
  Initializes the SFML window and drives the main game loop, handling system events, updating game state, and rendering.

- **GameWorld**  
  Aggregates core game components (background, player, boss, weapons, HUD) and implements the `IEffectSpawner` interface for spawning visual effects. It encapsulates the overall scene management.

- **GameState & GameStateManager**  
  Implement the state machine for the game, managing transitions between states such as the title screen, gameplay, pause, game over, and victory.

- **PhysicsEngine**  
  Detects and processes collisions between game objects (e.g., projectiles vs. player or boss) using SFML’s `FloatRect`. On collision, it triggers health reduction and spawns visual effects.

- **SoundManager**  
  A singleton class responsible for loading, playing, and managing sound effects and background music (e.g., jump, shoot, hit sounds).

- **GameConfig**  
  Contains constant definitions for game parameters such as movement speeds, jump impulses, projectile velocities, and boss health thresholds.

---

## 3. Main Components and Responsibilities

### 3.1 Main Game Loop (main.cpp)
- **Initialization:**  
  Creates the SFML window and instantiates `GameWorld` and `GameStateManager`.
- **Game Loop:**  
  Processes system events, updates the current game state, renders all game objects, and calls `window.display()` to present the frame.

### 3.2 Game World (GameWorld)
- **Components Integration:**  
  Combines the following subsystems:
  - **Background:** Manages multiple layered sprites and animations that simulate a dynamic arena environment.
  - **Player:** Handles user input, movement physics, collision responses, and animations.
  - **Boss:** Implements multi-phase behavior, movement along waypoints, orientation changes, and animations.
  - **Weapons:** Includes both player and boss weapon systems for spawning projectiles.
  - **HUD:** Displays player health and other game information.
  - **PhysicsEngine:** Integrates collision detection and response.
- **Effect Spawning:**  
  Implements the `IEffectSpawner` interface for triggering temporary visual effects such as explosions and spark animations.

### 3.3 Physics Engine (PhysicsEngine)
- **Collision Detection:**  
  Utilizes SFML’s `FloatRect` intersection functions to determine collisions between moving objects.
- **Collision Response:**  
  Invokes each object’s `onCollision()` method to handle health reduction or triggering visual effects.

### 3.4 Game Objects

#### Player
- **Responsibilities:**  
  - Processes user input for movement and jumping.
  - Updates position based on velocity and gravity.
  - Manages collision detection and health reduction.
  - Controls sprite animations based on current state.
  
#### Boss
- **Responsibilities:**  
  - Operates in multiple phases (Phase_1, Phase_2, Phase_3) depending on remaining health.
  - Moves along a series of predefined waypoints.
  - Adjusts orientation and animations dynamically.
  
#### Projectile
- **Responsibilities:**  
  - Represents bullets fired by both the player and the boss.
  - Contains its own animation cycle and movement logic.
  - Implements self-destruction criteria when leaving the screen or colliding with objects.
  
#### Weapon & BossWeapon
- **Responsibilities:**  
  - Instantiate and manage the lifecycle of projectiles.
  - The player’s weapon fires standard projectiles, while the boss’s weapon supports both direct shooting and a falling bombs ability.
  
#### PlayerHealthHUD
- **Responsibilities:**  
  - Renders an animated health indicator reflecting the player’s current health.
  
#### Background
- **Responsibilities:**  
  - Constructs a visually rich environment using multiple static and animated sprite layers.
  - Accurately recreates the aesthetic of the DLC CupHead bossfight – Mortimer Freeze.

### 3.5 Animations and Effects

#### Animation
- **Implementation:**  
  - Divides texture sheets into frames.
  - Calculates the time per frame and updates the sprite’s texture rectangle accordingly.
  
#### Effect
- **Implementation:**  
  - Utilizes the `Animation` class to drive temporary visual effects.
  - Automatically ceases once the animation sequence is complete.

### 3.6 Sound Manager (SoundManager)
- **Sound Playback:**  
  - Loads and plays sound effects (jump, shoot, hit) and background music.
- **Design Pattern:**  
  - Implements a singleton pattern to provide a global sound management instance.

### 3.7 Game States (GameState & GameStateManager)

#### GameState
- **Responsibilities:**  
  - Serves as a base class for various game states (Title Screen, Playing, Pause, Victory, Game Over).
  - Manages state-specific initialization, updates, and rendering.

  ![Game State Example 1](https://github.com/user-attachments/assets/bc59ec8a-fa1f-4ec9-83cd-3bcad9e1dd96)  
  ![Game State Example 2](https://github.com/user-attachments/assets/63f1a368-261d-4cd3-9627-9126e6e15547)

#### GameStateManager
- **Responsibilities:**  
  - Manages transitions between states.
  - Provides mechanisms to reset the game world when required.

### 3.8 Configuration (GameConfig)
- **Responsibilities:**  
  - Defines constants for physics parameters (gravity, jump impulse, projectile speed).
  - Sets thresholds for boss behavior and phase transitions.

### 3.9 Additional Components

#### FontManager
- **Responsibilities:**  
  - Loads and provides access to fonts via a singleton interface.

#### IEffectSpawner
- **Responsibilities:**  
  - Defines an interface for spawning visual effects, used primarily by the PhysicsEngine.

---

## 4. Key Algorithms and Game Logic

- **Sprite Animation:**  
  The `Animation` class computes time per frame and updates the sprite’s texture rectangle to animate characters and effects.

- **Collision Detection:**  
  Implemented with SFML’s `FloatRect`, triggering collision responses when projectiles intersect with other game objects.

- **Movement and Physics:**  
  The player is subject to gravity, and movement is constrained within the game arena. Jump impulses and horizontal movements are calculated based on time delta.

- **Boss Behavior:**  
  The boss transitions between multiple phases based on its health, moves along preset waypoints, and dynamically updates orientation and animations.

- **Game State Management:**  
  The `GameStateManager` uses input events and game conditions (e.g., player or boss death) to transition between states.

---

## 5. Technologies Used

- **C++:**  
  The primary programming language used for development.

- **SFML:**  
  A multimedia library for handling graphics, audio, events, and timing.

- **ChatGpt:**  
  Utilized for generating sprite sheets from CupHead sprites and assisting with documentation.

---
