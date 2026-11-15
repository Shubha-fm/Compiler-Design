# C Terminal Games

Ten independent console games written in C11. The games supplement the compiler-design examples and demonstrate recursion, game-state design, arrays, search, validation, and terminal input handling.

| Game | Source | Main concepts |
|---|---|---|
| Tic-Tac-Toe vs AI | [01_tic_tac_toe_ai.c](01_tic_tac_toe_ai.c) | Minimax recursion, adversarial search |
| Connect Four | [02_connect_four.c](02_connect_four.c) | Board operations, directional pattern checking |
| Hangman | [03_hangman.c](03_hangman.c) | String processing, guess tracking |
| 2048 | [04_game_2048.c](04_game_2048.c) | Grid transformations, tile merging |
| Maze Escape | [05_maze_escape.c](05_maze_escape.c) | Grid movement, boundaries |
| Mini Battleship | [06_battleship.c](06_battleship.c) | Grid coordinates, hidden information |
| Word Guess (Wordle-style) | [07_wordle.c](07_wordle.c) | Exact/partial letter feedback, duplicate letters |
| Turn-based Snake | [08_snake_turn_based.c](08_snake_turn_based.c) | Snake body tracking, collision, food |
| Minesweeper | [09_minesweeper.c](09_minesweeper.c) | Neighborhood counting, reveal logic |
| Rock Paper Scissors | [10_rock_paper_scissors.c](10_rock_paper_scissors.c) | Game rounds, simple seeded pseudorandomness |

## Compile and run a game

Install GCC (or another C11 compiler), then run:

```bash
gcc -std=c11 -Wall -Wextra -pedantic games/08_snake_turn_based.c -o snake
./snake
```

For the new games:

```bash
gcc -std=c11 games/06_battleship.c -o battleship
./battleship

gcc -std=c11 games/07_wordle.c -o wordguess
./wordguess

gcc -std=c11 games/09_minesweeper.c -o minesweeper
./minesweeper

gcc -std=c11 games/10_rock_paper_scissors.c -o rps
./rps 42
```

On Windows with MinGW GCC, run the resulting `.exe` files. The Snake and Rock-Paper-Scissors games accept an optional integer seed, making their pseudo-random choices reproducible.

## Controls and goals

- **Battleship:** Guess row and column (1–5) to find all four ship cells.
- **Word Guess:** Enter a five-letter word. `+` means a letter in the right position, `?` means elsewhere, and `-` means absent. You get six guesses.
- **Snake:** Use `w`, `a`, `s`, `d` to move one cell at a time, eat food and avoid collisions.
- **Minesweeper:** Enter row and column (1–5), uncover all 21 safe squares and avoid four hidden mines. No flags or automatic flood-fill.
- **Rock Paper Scissors:** Enter `r`, `p`, `s` or full names. First to three wins.

Type `q` to quit any game.

## Manual checks

```bash
bash tests/test_games.sh
bash tests/test_games_06_10.sh
```

The second script builds the five new games with `-Wall -Wextra -Werror -pedantic` and runs nine scripted checks. These are representative cases, not exhaustive quality assurance. The repository's C/C++ GitHub Actions workflow remains removed.

These examples are meant for learning. The games run in a standard terminal, not a graphical game engine. Word Guess uses a fixed secret, Battleship and Minesweeper use fixed boards, and Snake uses turn-based movement.
