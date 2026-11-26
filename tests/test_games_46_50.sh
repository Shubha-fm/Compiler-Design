#!/usr/bin/env bash
set -euo pipefail
cd "$(dirname "$0")/.."
tmp="$(mktemp -d)"
trap 'rm -rf "$tmp"' EXIT
for source in games/{46,47,48,49,50}_*.c; do
  name="$(basename "$source" .c)"
  gcc -std=c11 -Wall -Wextra -Werror -pedantic "$source" -o "$tmp/$name"
  echo "COMPILED $name"
done
check() {
  local name="$1" input="$2" expected="$3" actual
  actual="$(printf '%s\n' "$input" | "$tmp/$name")"
  if [[ "$actual" != *"$expected"* ]]; then
    printf 'FAIL %s expected [%s] got [%s]\n' "$name" "$expected" "$actual" >&2
    exit 1
  fi
  echo "PASS $name"
}
check 46_morse_quiz q "Game ended."
check 46_morse_quiz $'A\nB\nC\nD\nE' "Score: 5/5"
check 47_subtraction_nim q "Game ended."
check 47_subtraction_nim 1 "Computer takes"
check 48_color_code_puzzle q "Game ended."
check 48_color_code_puzzle RGBY "Code cracked!"
check 49_grid_escape_timer q "Game ended."
check 49_grid_escape_timer $'d\nd\nd\nd\ns\ns\ns\ns' "Escaped in time!"
check 50_binary_search_adventure q "Game ended."
check 50_binary_search_adventure 73 "Found the treasure in 1 guesses!"
echo "10 game smoke tests completed."
