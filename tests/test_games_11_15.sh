#!/usr/bin/env bash
set -euo pipefail
cd "$(dirname "$0")/.."
tmp="$(mktemp -d)"
trap 'rm -rf "$tmp"' EXIT
for source in games/{11,12,13,14,15}_*.c; do
  name="$(basename "$source" .c)"
  gcc -std=c11 -Wall -Wextra -Werror -pedantic "$source" -o "$tmp/$name"
  echo "COMPILED $name"
done
check() {
  local program="$1" input="$2" expected="$3" output
  shift 3
  output="$(printf '%s\n' "$input" | "$tmp/$program" "$@")"
  if [[ "$output" != *"$expected"* ]]; then
    echo "FAIL $program: expected [$expected], observed [$output]" >&2
    exit 1
  fi
  echo "PASS $program: $expected"
}
check 11_mastermind q 'Game ended.' 42
check 11_mastermind 1111 'Digits must be distinct' 42
check 12_blackjack q 'Game ended.' 42
check 13_sudoku q 'Game ended.'
check 13_sudoku '1 1 1' 'This cell is fixed.'
check 14_dungeon_quest q 'Game ended.'
check 13_sudoku $'1 2 2\n1 3 3\n2 1 3\n2 4 2\n3 1 2\n3 4 3\n4 2 3\n4 3 2' 'Puzzle solved!'
check 14_dungeon_quest $'s\ns\nd\nd\nd\nd\nd\nd\nd\nw' 'You found the treasure! You win!'
check 15_nim_ai q 'Game ended.' 21
check 15_nim_ai 1 'You win!' 1
echo 'Ten game checks passed.'
