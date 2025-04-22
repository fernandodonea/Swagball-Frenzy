# oop-project-game2
 
# OOP Project Game 2

This is a simple 2D game built using the SFML (Simple and Fast Multimedia Library) framework. The game demonstrates object-oriented programming principles and includes features such as player movement, collision detection, and interactive objects.

## Features

- **Player Movement**: Control the player using keyboard inputs (W, A, S, D).
- **Swag Balls**: Randomly spawning objects with different effects:
  - Default: Increases points.
  - Damaging: Reduces player health.
  - Healing: Restores player health.
- **Collision Detection**: Detects interactions between the player and swag balls.
- **GUI**: Displays the player's points and health.
- **Game Over**: Ends the game when the player's health reaches zero.


## Project Structure

- **`src/`**: Contains the source code for the game.
- **`resources/fonts/`**: Includes font files used in the game.
- **`.vscode/`**: Configuration files for Visual Studio Code.
- **`bin/`**: Output directory for the compiled binary.

Files in the `src/` directory:
- **`Game.cpp`**: Main game loop and initialization.
- **`Player.cpp`**: Player class implementation.
- **`SwagBall.cpp`**: Swag ball class implementation.
- **`main.cpp`**: Entry point of the game.
