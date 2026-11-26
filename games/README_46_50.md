# C terminal games 46–50

Five new standalone C11 terminal games.

| No. | Game | Concepts |
|---|---|---|
| 46 | [Morse Quiz](46_morse_quiz.c) | Character recognition, scoring |
| 47 | [Subtraction Nim](47_subtraction_nim.c) | Optimal modulo-4 strategy |
| 48 | [Color Code Puzzle](48_color_code_puzzle.c) | Code-breaking feedback, duplicate accounting |
| 49 | [Timed Grid Escape](49_grid_escape_timer.c) | Grid traversal and move budgets |
| 50 | [Binary Search Adventure](50_binary_search_adventure.c) | Binary search hints and narrowed ranges |

Compile and play:

```bash
gcc -std=c11 -Wall -Wextra -pedantic games/50_binary_search_adventure.c -o binary_game
./binary_game
```

Controls: Morse Quiz takes A–E; Subtraction Nim takes 1–3 stones; Color Code uses four R/G/B/Y letters; Grid Escape uses W/A/S/D; Binary Search Adventure takes integer guesses. Type `q` to quit.

Each example uses a fixed game setup and is designed for learning C rather than production game development. To compile and run ten representative checks:

```bash
bash tests/test_games_46_50.sh
```

The previously removed C/C++ GitHub Actions workflow remains removed.
