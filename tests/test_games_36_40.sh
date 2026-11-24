#!/usr/bin/env bash
set -euo pipefail
cd "$(dirname "$0")/.."
tmp="$(mktemp -d)"
trap 'rm -rf "$tmp"' EXIT
for src in games/{36,37,38,39,40}_*.c; do
  name="$(basename "$src" .c)"
  gcc -std=c11 -Wall -Wextra -Werror -pedantic "$src" -o "$tmp/$name"
  printf 'COMPILED %s\n' "$name"
done
check() {
  local binary="$1" input="$2" expected="$3" output
  output="$(printf '%s\n' "$input" | "$tmp/$binary")"
  if [[ "$output" != *"$expected"* ]]; then
    printf 'FAIL %s: expected [%s], observed [%s]\n' "$binary" "$expected" "$output" >&2
    exit 1
  fi
  printf 'PASS %s\n' "$binary"
}
check 36_hexapawn q "Game ended."
check 36_hexapawn $'3 1 2 1\nq' "B move"
check 37_word_ladder q "Game ended."
check 37_word_ladder $'COT\nCOG\nDOG' "Ladder solved in 3 steps!"
check 38_codebreaker_binary q "Game ended."
check 38_codebreaker_binary 10110 "Code cracked in 1 guesses!"
check 39_nim_three_piles q "Game ended."
check 39_nim_three_piles $'1 1\nq' "Computer removes"
check 40_grid_treasure_hunt q "Game ended."
check 40_grid_treasure_hunt $'d\nd\nd\nd\ns\ns\ns\ns' "Treasure found in 8 moves!"
echo 'Ten game tests passed.'
