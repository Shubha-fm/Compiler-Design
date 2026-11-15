#!/usr/bin/env bash
set -euo pipefail
cd "$(dirname "$0")/.."
tmp="$(mktemp -d)"
trap 'rm -rf "$tmp"' EXIT
for source in games/0{6,7,8,9}_*.c games/10_*.c; do
  name="$(basename "$source" .c)"
  gcc -std=c11 -Wall -Wextra -Werror -pedantic "$source" -o "$tmp/$name"
  echo "COMPILED $name"
done
check() {
  local binary="$1" input="$2" expected="$3" output
  shift 3
  output="$(printf '%s\n' "$input" | "$tmp/$binary" "$@")"
  if [[ "$output" != *"$expected"* ]]; then
    printf 'FAIL %s: expected [%s], received [%s]\n' "$binary" "$expected" "$output" >&2
    exit 1
  fi
  printf 'PASS %s\n' "$binary"
}
check 06_battleship q "Game ended."
check 06_battleship $'2 2\n2 3\n2 4\n4 4' "You sank all ships"
check 07_wordle logic "You win!"
check 07_wordle q "Game ended."
check 08_snake_turn_based q "Game ended." 42
check 08_snake_turn_based $'d\nd' "Food eaten!" 42
check 09_minesweeper q "Game ended."
check 09_minesweeper $'1 1' "BOOM!"
check 10_rock_paper_scissors q "Game ended." 42
echo 'Nine scripted checks complete.'
