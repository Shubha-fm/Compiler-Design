# C Terminal Games

Five playable console games written in standard C11. These examples exercise algorithms, arrays, graphs, dynamic search, strings, input validation, and game state.

| Game | Source | Players | Main concepts |
|---|---|---|---|
| Tic-Tac-Toe with AI | [01_tic_tac_toe_ai.c](01_tic_tac_toe_ai.c) | 1 vs computer | Minimax search, recursion, game trees |
| Connect Four | [02_connect_four.c](02_connect_four.c) | 2 local players | Board representation, directional win detection |
| Hangman | [03_hangman.c](03_hangman.c) | 1 | Strings, character processing, guess tracking |
| 2048 | [04_game_2048.c](04_game_2048.c) | 1 | Grid transformations, tile merging, seeded pseudorandomness |
| Maze Escape | [05_maze_escape.c](05_maze_escape.c) | 1 | Grid navigation, collision detection, reachability |

## Compile and play

Requires GCC or another C11-compatible compiler and a terminal.

```bash
gcc -std=c11 -Wall -Wextra -pedantic games/01_tic_tac_toe_ai.c -o tic
./tic
```

To play the other games:

```bash
gcc -std=c11 -Wall -Wextra -pedantic games/02_connect_four.c -o connect4
./connect4

gcc -std=c11 -Wall -Wextra -pedantic games/03_hangman.c -o hangman
./hangman 0

gcc -std=c11 -Wall -Wextra -pedantic games/04_game_2048.c -o game2048
./game2048 42

gcc -std=c11 -Wall -Wextra -pedantic games/05_maze_escape.c -o maze
./maze
```

**Controls:** Tic-Tac-Toe accepts positions 1–9; Connect Four accepts columns 1–7; Hangman accepts one letter at a time; 2048 and Maze Escape use `w`, `a`, `s`, `d`. Type `q` to quit. On Windows, build using GCC/MinGW and run the resulting `.exe` files.

For 2048, the optional numeric argument selects a reproducible pseudorandom seed. For Hangman, the optional word index is 0–5. Neither feature provides cryptographic randomness.

## Check builds and example games

```bash
bash tests/test_games.sh
```

The script compiles all five games using `gcc -std=c11 -Wall -Wextra -Werror -pedantic`, then executes eight basic scripted checks, including a Connect Four victory, a Hangman victory, and a maze escape. The checks are representative, not exhaustive. They are **manual tests**, and no C/C++ GitHub Actions workflow is added.

The original 290 numbered compiler design programs and parser examples remain unchanged.
