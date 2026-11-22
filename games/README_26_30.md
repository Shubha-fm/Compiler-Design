# Games 26–30

Five additional **terminal games in C11**, independent of the numbered compiler-design programs.

| Game | Source | Learning concepts |
|---|---|---|
| Mini Checkers | [26_checkers_mini.c](26_checkers_mini.c) | Two-player diagonal movement and captures |
| 15-Puzzle | [27_fifteen_puzzle.c](27_fifteen_puzzle.c) | Sliding tiles, state transitions |
| Dungeon Battle | [28_dungeon_battle.c](28_dungeon_battle.c) | Turn-based health, attacks, defense and potions |
| Game of Life | [29_game_of_life.c](29_game_of_life.c) | Cellular automata, neighbor counts, generation updates |
| Simon Says | [30_simon_sequence.c](30_simon_sequence.c) | Sequence recall, progressive difficulty |

## Build and play

```bash
gcc -std=c11 -Wall -Wextra -pedantic games/27_fifteen_puzzle.c -o fifteen
./fifteen
```

Compile a different game by substituting the source filename. Games 26–30 are playable in a standard terminal without external libraries.

**Controls:** Checkers takes four numbers `from-row from-col to-row to-col` on a 6x6 board; 15-Puzzle takes W/A/S/D; Dungeon Battle takes `attack`, `defend`, `heal`; Game of Life takes generation count 0–20; Simon takes a growing digit sequence. Enter `q` to quit at the prompt.

**Scope:** Checkers supports ordinary pieces and optional captures, without kings or forced captures. The 15-Puzzle starts from a solvable one-move configuration. Dungeon Battle has deterministic monster attacks. Game of Life has fixed, non-wrapping edges. Simon displays the sequence instead of clearing the terminal, so it is a basic memory exercise.

## Manual test script

```bash
bash tests/test_games_26_30.sh
```

Compiles five C11 examples with strict GCC warnings and runs ten representative checks. These tests are not exhaustive and have not been executed in this chat. No C/C++ CI workflow is installed.
