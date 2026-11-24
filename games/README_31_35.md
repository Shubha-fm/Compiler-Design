# New Games 31–35

Five standalone games for a C11 terminal. They are independent of the numbered compiler examples.

| Game | File | Main programming concepts |
|---|---|---|
| Number Guess | [31_number_guess.c](31_number_guess.c) | Input validation and higher/lower feedback |
| Word Search | [32_word_search.c](32_word_search.c) | String comparison and discovery tracking |
| Line Peg Solitaire | [33_peg_solitaire.c](33_peg_solitaire.c) | Jump rules and board-state transitions |
| Dots and Boxes | [34_dots_and_boxes.c](34_dots_and_boxes.c) | Grid edges, scoring and extra turns |
| Robot Arena | [35_robot_arena.c](35_robot_arena.c) | Turn-based combat, defense and resources |

## Compile and play

```bash
gcc -std=c11 -Wall -Wextra -pedantic games/34_dots_and_boxes.c -o dots
./dots
```

Number Guess accepts a guess 1–100 and an optional integer secret argument (default 57). Word Search has three fixed words: PARSER, MODEL, LOGIC. Peg Solitaire uses seven slots and asks for source and destination positions. Dots and Boxes uses `H row col` and `V row col`. Robot Arena accepts `attack`, `guard`, or `repair`. All five support `q` at the main prompt.

These are intentionally small educational games with fixed levels or reproducible opponent actions.

## Run manual checks

```bash
bash tests/test_games_31_35.sh
```

The script compiles five games with strict C11 flags and runs ten representative checks. Uploaded tests are not evidence of passing execution. The previously removed C/C++ GitHub Actions workflow remains removed.
