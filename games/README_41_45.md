# Games 41–45

Five new **standard C11 terminal games**.

| Number | Game | Concepts |
|---|---|---|
| 41 | [Lane Runner](41_lane_runner.c) | Turn-based lane changes, obstacle avoidance |
| 42 | [Anagram Challenge](42_anagram_challenge.c) | Character case conversion, word puzzles |
| 43 | [Robot Labyrinth](43_robot_labyrinth.c) | Grid navigation, BFS shortest-path hint |
| 44 | [Dice Duel](44_dice_duel.c) | Dice rolls, bank-or-risk decisions, turn-based scoring |
| 45 | [Binary Path Puzzle](45_binary_path_puzzle.c) | Binary decision trees, branch selection |

## Play

```bash
gcc -std=c11 -Wall -Wextra -pedantic games/43_robot_labyrinth.c -o robot
./robot
```

Lane Runner uses `a`, `d`, `s` to change lanes or stay. Anagram Challenge accepts guessed words. Robot Labyrinth uses `w`, `a`, `s`, `d` and `h` for a shortest-route hint. Dice Duel uses `r` to roll or `h` to hold. Binary Path Puzzle accepts `0` or `1`. Enter `q` at the main prompt to quit.

The games are small teaching examples with fixed puzzles and obstacles; the Dice Duel uses a deterministic pseudo-random sequence, not a casino-grade random number generator.

## Compile and run sample checks

```bash
bash tests/test_games_41_45.sh
```

The script builds with strict compiler flags and checks ten representative input sequences. It is not a replacement for full interactive or edge-case testing. No C/C++ CI workflow has been added.
