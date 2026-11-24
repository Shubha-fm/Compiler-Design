# New C games 36–40

Five small interactive console games in C11, independent of the numbered compiler examples.

| No. | Game | Concepts |
|---|---|---|
| 36 | [Hexapawn](36_hexapawn.c) | Pawn-only chess variant, legal movement, capture and victory conditions |
| 37 | [Word Ladder](37_word_ladder.c) | Small dictionary, Hamming distance and valid single-letter changes |
| 38 | [Binary Codebreaker](38_codebreaker_binary.c) | Bit strings, Hamming distance and six-guess limit |
| 39 | [Three-Pile Nim](39_nim_three_piles.c) | XOR strategy, adversarial play and optimal computer choices |
| 40 | [Grid Treasure Hunt](40_grid_treasure_hunt.c) | Grid navigation, hazards, terminal controls and path planning |

## Build

```bash
gcc -std=c11 -Wall -Wextra -pedantic games/39_nim_three_piles.c -o nim
./nim
```

Games use simple terminal input. Hexapawn takes four 1-based board coordinates; Word Ladder takes three-letter words; Codebreaker takes five binary digits; Nim takes a pile number followed by a positive stone count; Treasure Hunt uses W/A/S/D. Type `q` to quit.

These educational games use fixed boards, dictionaries, and secret codes. The Word Ladder dictionary is deliberately small, and Nim follows normal-play rules (the last stone wins). No external libraries are required.

## Representative local checks

```bash
bash tests/test_games_36_40.sh
```

The script compiles all five examples and checks ten sample interaction sequences. Test results are not confirmed until the script is executed. The C/C++ GitHub Actions workflow remains removed.
