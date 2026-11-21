#!/usr/bin/env bash
set -euo pipefail
cd "$(dirname "$0")/.."
tmp="$(mktemp -d)"
trap 'rm -rf "$tmp"' EXIT
for source in games/{21,22,23,24,25}_*.c; do
  name="$(basename "$source" .c)"
  gcc -std=c11 -Wall -Wextra -Werror -pedantic "$source" -o "$tmp/$name"
  echo "COMPILED $name"
done
check() {
  local game="$1" input="$2" expected="$3" output
  output="$(printf '%s\n' "$input" | "$tmp/$game")"
  if [[ "$output" != *"$expected"* ]]; then
    printf 'FAIL %s: expected [%s], observed [%s]\n' "$game" "$expected" "$output" >&2
    exit 1
  fi
  echo "PASS $game: $expected"
}
check 21_reversi q "Game ended."
check 21_reversi $'1 1\nq' "Illegal move."
check 22_sokoban q "Game ended."
check 22_sokoban $'d\nd\nd' "Puzzle solved in 3 moves!"
check 23_typing_challenge q "Game ended."
check 23_typing_challenge $'hello compiler\nlexical analysis\nfinite automata\nsyntax tree\ncode generation' "Typing score: 5/5"
check 24_bulls_and_cows q "Game ended."
check 24_bulls_and_cows 4271 "Code cracked in 1 guesses!"
check 25_knight_tour q "Game ended."
check 24_bulls_and_cows $'1122\nq' "Digits must be distinct."
echo "All 10 scripted game checks passed."
