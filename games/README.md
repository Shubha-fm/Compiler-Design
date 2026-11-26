# C Terminal Games

Forty-five independent console games written in C11. The games supplement the compiler-design examples and demonstrate recursion, game-state design, arrays, search, validation, and terminal input handling.

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

| Mastermind | [11_mastermind.c](11_mastermind.c) | Code-breaking, constrained guesses, seeded pseudorandomness |
| Blackjack | [12_blackjack.c](12_blackjack.c) | Hand scoring, dealer rules, state transitions |
| Mini Sudoku | [13_sudoku.c](13_sudoku.c) | Constraint validation, 4×4 puzzle grid |
| Dungeon Quest | [14_dungeon_quest.c](14_dungeon_quest.c) | Exploration, inventory, locked doors |
| Nim vs Computer | [15_nim_ai.c](15_nim_ai.c) | Combinatorial game strategy, modulo arithmetic |

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

## Games 11–15: more strategy and puzzles

- **Mastermind:** Guess four distinct digits between 1 and 6. You receive counts of exact and misplaced digits, with up to ten attempts. Optional numeric seed.
- **Blackjack:** Try to beat the dealer without exceeding 21. Enter `h` to hit, `s` to stand, or `q` to quit. This is a card-scoring teaching example without betting; optional numeric seed.
- **Mini Sudoku:** Fill a fixed 4×4 puzzle. Enter `row column value` using numbers 1–4. The game checks rows, columns, and 2×2 boxes.
- **Dungeon Quest:** Navigate using `w`, `a`, `s`, `d`, find a key, unlock a door, and reach treasure.
- **Nim:** Remove one to three stones per turn against a strategy-based computer. The default pile contains 21 stones; optionally supply a starting pile count between 1 and 100.

Compile and play an example:

```bash
gcc -std=c11 -Wall -Wextra -pedantic games/14_dungeon_quest.c -o dungeon
./dungeon
```

The additional manual tests are located in [`tests/test_games_11_15.sh`](../tests/test_games_11_15.sh):

```bash
bash tests/test_games_11_15.sh
```

All five games compiled with GCC in strict C11 mode and passed ten scripted checks before upload. Tests are examples rather than exhaustive verification. The games run in a terminal, not a graphical engine. No C/C++ GitHub Actions workflow was added.

## New games 16–20

| Game | Source | Core concepts |
|---|---|---|
| 8-Puzzle | [16_eight_puzzle.c](16_eight_puzzle.c) | Sliding puzzle, state transitions, move validity |
| Compiler Quiz | [17_compiler_quiz.c](17_compiler_quiz.c) | Five questions about compiler phases, parsing, SSA, liveness, NFAs |
| Tower of Hanoi | [18_tower_of_hanoi.c](18_tower_of_hanoi.c) | Stacks, legal moves, three-disk puzzle |
| Lights Out | [19_lights_out.c](19_lights_out.c) | Grid toggling, adjacency, binary state |
| Memory Match | [20_memory_match.c](20_memory_match.c) | Pair matching, hidden state, turn counting |

These five games have **fixed starting conditions** to make them easy to understand and test. The quiz uses a fixed set of five questions; the puzzles use small fixed boards.

### Build and play

```bash
gcc -std=c11 -Wall -Wextra -pedantic games/16_eight_puzzle.c -o eight_puzzle
./eight_puzzle

gcc -std=c11 -Wall -Wextra -pedantic games/17_compiler_quiz.c -o compiler_quiz
./compiler_quiz

gcc -std=c11 -Wall -Wextra -pedantic games/18_tower_of_hanoi.c -o hanoi
./hanoi

gcc -std=c11 -Wall -Wextra -pedantic games/19_lights_out.c -o lights_out
./lights_out

gcc -std=c11 -Wall -Wextra -pedantic games/20_memory_match.c -o memory_match
./memory_match
```

Use `w`, `a`, `s`, `d` for 8-Puzzle; `A`, `B`, or `C` for Compiler Quiz; peg numbers 1–3 for Tower of Hanoi; row/column numbers 1–3 for Lights Out; and positions 1–8 for Memory Match. Enter `q` to quit each game.

### Manual game tests

```bash
bash tests/test_games_16_20.sh
```

This test script compiles the five games with strict C11 compiler warnings and checks both quitting and solving/winning paths. It has not been executed in the ChatGPT environment. No C/C++ GitHub Actions workflow has been restored.

## Games 21–25

Five more C11 terminal games have been added. They use no third-party dependencies.

| Game | Source | What you learn |
|---|---|---|
| Mini Reversi | [21_reversi.c](21_reversi.c) | Two-player strategy, directional captures, legal moves |
| Sokoban | [22_sokoban.c](22_sokoban.c) | Push-box grid puzzles and collision checking |
| Typing Challenge | [23_typing_challenge.c](23_typing_challenge.c) | Exact text comparisons and input handling |
| Bulls and Cows | [24_bulls_and_cows.c](24_bulls_and_cows.c) | Four-digit deduction with bulls/cows feedback |
| Knight's Tour | [25_knight_tour.c](25_knight_tour.c) | Recursive backtracking on a chessboard |

### Compile and play

```bash
gcc -std=c11 -Wall -Wextra -pedantic games/21_reversi.c -o reversi
./reversi

gcc -std=c11 -Wall -Wextra -pedantic games/22_sokoban.c -o sokoban
./sokoban

gcc -std=c11 -Wall -Wextra -pedantic games/23_typing_challenge.c -o typing
./typing

gcc -std=c11 -Wall -Wextra -pedantic games/24_bulls_and_cows.c -o bulls
./bulls

gcc -std=c11 -Wall -Wextra -pedantic games/25_knight_tour.c -o knight
./knight
```

Use row and column numbers 1–4 in Reversi, W/A/S/D in Sokoban, complete sentences in Typing Challenge, distinct four-digit guesses in Bulls and Cows, and a 1–5 starting square in Knight's Tour. Enter `q` at any game's main prompt to quit.

### Manual smoke tests

```bash
bash tests/test_games_21_25.sh
```

The test script compiles all five games using strict C11 warning settings and checks ten input sequences. It is intended to run locally; uploading the test script is not evidence that it passed. A full Knight's Tour may take substantial time because the search uses straightforward backtracking. The games use intentionally fixed starting boards and/or secrets.

The C/C++ GitHub Actions CI workflow remains removed.

## Games 26–30: new terminal collection

Five new games extend the C11 game collection from 25 to 30:

- [26: Mini Checkers](26_checkers_mini.c): local two-player movement and captures
- [27: 15-Puzzle](27_fifteen_puzzle.c): slide numbered tiles into order
- [28: Dungeon Battle](28_dungeon_battle.c): deterministic turn-based combat with attack, defend, heal
- [29: Conway's Game of Life](29_game_of_life.c): step through cellular automaton generations
- [30: Simon Says](30_simon_sequence.c): repeat a growing digit pattern

For build instructions, game controls, design limitations, and the scripted checks, see [games 26–30 guide](README_26_30.md).

```bash
bash tests/test_games_26_30.sh
```

Tests are provided for manual execution, and the removed C/C++ CI workflow remains removed.

## New games 31–35

Five games extend the collection from 30 to 35:

- [Number Guess](31_number_guess.c): higher/lower feedback for guesses 1–100
- [Word Search](32_word_search.c): find three words in a 6×6 letter grid
- [Line Peg Solitaire](33_peg_solitaire.c): legal jumps and peg removal
- [Dots and Boxes](34_dots_and_boxes.c): draw grid edges and claim completed boxes
- [Robot Arena](35_robot_arena.c): five-round tactical combat

Find controls, compilation commands, and limitations in the [games 31–35 guide](README_31_35.md). Run the example tests manually:

```bash
bash tests/test_games_31_35.sh
```

The removed C/C++ CI workflow has not been reinstated.

## New games 36–40

Five further playable C11 terminal games have been added:

- [36 Hexapawn](36_hexapawn.c): pawn-only chess on a 3×3 board
- [37 Word Ladder](37_word_ladder.c): form a chain of valid three-letter words
- [38 Binary Codebreaker](38_codebreaker_binary.c): guess a five-bit secret using Hamming-distance clues
- [39 Three-Pile Nim](39_nim_three_piles.c): compete with a computer using XOR strategy
- [40 Grid Treasure Hunt](40_grid_treasure_hunt.c): navigate a map and avoid traps

[Read the new games guide](README_36_40.md) for controls and build instructions. Test script:

```bash
bash tests/test_games_36_40.sh
```

All games remain separate from the compiler examples. The deleted C/C++ CI workflow was not restored.

## Games 41–45

Five more standalone terminal games extend the collection to **45**:

- [41 Lane Runner](41_lane_runner.c): dodge obstacles across three lanes
- [42 Anagram Challenge](42_anagram_challenge.c): solve scrambled compiler terms
- [43 Robot Labyrinth](43_robot_labyrinth.c): explore a maze with a BFS hint
- [44 Dice Duel](44_dice_duel.c): risk-versus-reward dice game
- [45 Binary Path Puzzle](45_binary_path_puzzle.c): choose a binary path to treasure

See the [games 41–45 guide](README_41_45.md) for controls, build instructions and limitations.

```bash
bash tests/test_games_41_45.sh
```

The C/C++ CI workflow remains removed.
