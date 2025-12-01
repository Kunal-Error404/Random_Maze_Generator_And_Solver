# Random Maze Game

A fun and challenging maze game where every level is different! Navigate through randomly generated mazes, find the exit, and try to beat your best time.

## What is this project?

This is a console-based maze game written in C where:
* A new random maze is created every time you play
* You control a player (@) using keyboard keys
* You need to find the exit (X) in the maze
* You can get hints showing the shortest path
* Your completion time is tracked and saved

## How to play

### Controls:
* `W` - Move Up
* `A` - Move Left
* `S` - Move Down
* `D` - Move Right
* `H` - Toggle Hint (shows/hides solution path)
* `Q` - Quit Game

### Game Symbols:
* `@` - You (the player) - Green
* `#` - Walls - Blue
* `X` - Exit - Red
* `*` - Hint path - Yellow (when enabled)
* ` ` (space) - Empty path

## How to run the game

### On Windows:
1. Open Command Prompt or PowerShell
2. Navigate to the project folder:
   ```
   cd path\to\Random_Maze_Game
   ```
3. Compile the game:
   ```
   gcc -o maze_game src/main.c -Iinclude
   ```
4. Run the game:
   ```
   maze_game.exe
   ```

### On Linux/Mac:
1. Open Terminal
2. Navigate to the project folder:
   ```
   cd /path/to/Random_Maze_Game
   ```
3. Compile the game:
   ```
   gcc -o maze_game src/main.c -Iinclude
   ```
4. Run the game:
   ```
   ./maze_game
   ```

## Project Structure

```
Random_Maze_Game/
├── src/
│   └── main.c              # Main game code
├── include/                # All header files
│   ├── display.h          # Colors and screen functions
│   ├── maze_generator.h   # Maze creation code
│   ├── maze_solver.h      # Maze solving algorithm
│   ├── game_display.h     # Maze drawing functions
│   ├── player_movement.h  # Player control functions
│   └── timer.h           # Time tracking functions
├── README.md              # This file
└── .gitignore            # Files to ignore in Git
```

## Features

✅ **Random Mazes** - Every game is different  
✅ **Colorful Display** - Easy to see different elements  
✅ **Hint System** - Press H to see the solution  
✅ **Timer** - See how fast you complete the maze  
✅ **Save Results** - Your times are saved to a file  
✅ **Simple Controls** - Easy to learn, hard to master

## What I Learned

While making this game, I learned about:
* **C Programming** - Functions, arrays, pointers, structures
* **File Handling** - Saving and loading data
* **Modular Programming** - Organizing code into separate files

## Future Ideas

Some cool things I might add later:
* Different maze sizes (easy/medium/hard)
* Collectible items in the maze
* Multiple levels
* High score table

## Note for Teachers

This project was created as a learning exercise in my first semester. It combines concepts from programming fundamentals,file handling and variety of other things. All code was written to understand practical applications of classroom concepts.

---

~ Made by Kunal

*"Every maze has a solution - just like every programming problem!"*