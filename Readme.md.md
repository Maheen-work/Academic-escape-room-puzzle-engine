# Escape Room Puzzle Engine

A console-based escape room game written in C for Windows. Clear three themed rooms, each with three levels of multiple-choice questions, to escape.

Made for the **Programming Fundamentals** course at FAST-NUCES, Karachi (Section BSCY-B1).

<!-- Add screenshots here, for example: ![Title screen](screenshots/title.png) -->

## How the game works

- Enter your player name at startup—if a saved game (`savegame.dat`) is found, you can resume from your last cleared level or start fresh.
- There are **3 rooms**, and each room has **3 levels** (Easy, Medium, Hard) with **5 questions** per level, so 45 questions in total.
- You need **at least 3 correct answers out of 5** to clear a level. A failed level must be replayed.
- Progress is automatically saved after every cleared level.
- Rooms open in order: clear all three levels of a room to unlock the next one.
- After Room 3, a victory screen, your final leaderboard, and the persistent **Top 5 Players** high-score board (`highscores.txt`) are displayed.

| Room | Theme | Help available |
|------|-------|----------------|
| 1 | Riddles | Hints: 1 in Easy, 1 in Normal, 2 in Difficult |
| 2 | Mathematics | One 50-50 lifeline per level, first attempt only |
| 3 | C Programming | 50-50 lifeline, up to 2 uses per level |

## Features

- Multi-room, multi-level progression with a 3/5 pass mark
- **Save & Resume system** (`savegame.dat`) via custom header `lib.h`
- **Persistent Top 5 High-Score Leaderboard** (`highscores.txt`) across sessions
- Hint system (Room 1) and 50-50 lifeline (Rooms 2 and 3)
- Colour-coded feedback: green for correct, red for incorrect
- ASCII art title, locked and open doors, key and trophy
- Score bar after every level, for example `[###--]  3/5`
- Room results screen and a final leaderboard with room totals and a grand total out of 45

## Requirements

- Windows (the game uses `windows.h` and `conio.h`)
- Standard C libraries (`stdio.h`, `stdlib.h`, `string.h`)
- GCC, for example through [MinGW-w64](https://www.mingw-w64.org/) or MSYS2
- Command Prompt or Windows Terminal, with the window tall enough to show about 30 lines

## Build and run

Ensure `final_game.c` and `lib.h` are in the same directory, then compile and run:

```bash
gcc final_game.c -o escape_room.exe
escape_room.exe
```

If you rename the source file, use its name in the `gcc` command.

## Controls

| Key | Action |
|-----|--------|
| `A` `B` `C` `D` | Choose an answer (not case-sensitive) |
| `L` | Use the 50-50 lifeline, where available |
| `Y` / `N` | Use a hint or skip it (Room 1), or choose to resume a saved game |
| Any key / `Enter` | Continue past a screen |

## Project structure

```text
.
|-- final_game.c     # main game loop: Room 1, Room 2, Room 3, graphics and leaderboard
|-- lib.h            # save/load progress (savegame.dat) and Top 5 high scores (highscores.txt)
|-- savegame.dat     # auto-generated save file while a run is in progress
|-- highscores.txt   # auto-generated persistent leaderboard file
`-- README.md
```

### Inside `final_game.c` & `lib.h`

- `main()` handles startup, checks for existing saves via `loadProgress()`, and runs `intro()`, `room1()`, `room2()`, `room3()`, the victory screen, the final leaderboard, and `showHighScores()`.
- `saveProgress()`, `loadProgress()`, and `deleteSave()` in `lib.h` manage persistent checkpoint saving in `savegame.dat` and clean up completed runs.
- `saveHighScore()` and `showHighScores()` in `lib.h` append finished scores to `highscores.txt` and sort/display the Top 5 players.
- `room1AskMCQ()` and `room2AskMCQ()` ask a question and check the answer. Room 3 asks its questions inside `room3level1()`, `room3level2()` and `room3level3()`.
- `printFinalLeaderboard()` builds the final table from 2D arrays of level score counters.
- Functions starting with `gfx` draw the title, doors, key, score bars and trophy.

## Limitations and ideas for the future

- Questions and answers are fixed in the code, so every playthrough uses the same question bank.
- Windows only, and text-only (no graphical window).
- Planned improvements: track completion time and attempt counts in `highscores.txt`, load and randomise questions from an external file, and add collectible key items that unlock later rooms.

## Authors

- Maheen Shafiq (26K-2050)
- Faaleha Haq (26K-2052)
- Shanzay Siddiqui (26K-2059)

## License

This project was created for academic purposes at FAST-NUCES, Karachi. Free to use and modify for educational purposes.