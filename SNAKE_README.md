# Snake Game

A simple terminal-based Snake game written in C++ using the ncurses library.

## Features

- Classic Snake gameplay
- Terminal-based graphics with ASCII characters
- Score tracking
- Collision detection (walls and self)
- Smooth movement and responsive controls

## Requirements

- C++11 compatible compiler (g++)
- ncurses library

## Installation

1. Install dependencies (Ubuntu/Debian):
   ```bash
   make install-deps
   ```

2. Compile the game:
   ```bash
   make
   ```

3. Run the game:
   ```bash
   make run
   ```
   
   Or directly:
   ```bash
   ./snake_game
   ```

## How to Play

- Use **arrow keys** to control the snake direction
- Eat the food (*) to grow and increase your score
- Avoid hitting the walls (#) or the snake's own body
- Press **'q'** to quit the game at any time

## Game Elements

- `O` - Snake head
- `o` - Snake body
- `*` - Food
- `#` - Wall/border

## Controls

- ↑ - Move up
- ↓ - Move down
- ← - Move left
- → - Move right
- q/Q - Quit game

## Scoring

- Each food item eaten gives you 10 points
- The snake grows longer with each food consumed
- Try to achieve the highest score possible!

## Clean Up

To remove the compiled executable:
```bash
make clean
```