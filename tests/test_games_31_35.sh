#!/usr/bin/env bash
set -euo pipefail
cd "$(dirname "$0")/.."
tmp="$(mktemp -d)"
trap 'rm -rf "$tmp"' EXIT
for src in games/{31,32,33,34,35}_*.c; do
  name="$(basename "$src" .c)"
  gcc -std=c11 -Wall -Wextra -Werror -pedantic "$src" -o "$tmp/$name"
  echo "COMPILED $name"
done
check() {
  local name="$1" data="$2" expected="$3" actual
  actual="$(printf '%s\n' "$data" | "$tmp/$name")"
  if [[ "$actual" != *"$expected"* ]]; then
    printf 'FAIL %s: expected [%s], got [%s]\n' "$name" "$expected" "$actual" >&2
    exit 1
  fi
  printf 'PASS %s: %s\n' "$name" "$expected"
}
check 31_number_guess q "Game ended."
check 31_number_guess $'40\n80\n57' "Correct in 3 guesses!"
check 32_word_search q "Game ended."
check 32_word_search $'PARSER\nMODEL\nLOGIC' "All words found!"
check 33_peg_solitaire q "Game ended."
check 33_peg_solitaire $'2 4\nq' "Board:"
check 34_dots_and_boxes q "Game ended."
check 34_dots_and_boxes $'H 1 1\nq' "Player 2 move:"
check 35_robot_arena q "Game ended."
check 35_robot_arena $'attack\nattack\nattack' "You win!"
echo '10 sample game checks passed.'
