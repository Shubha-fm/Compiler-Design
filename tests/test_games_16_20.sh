#!/usr/bin/env bash
set -euo pipefail
cd "$(dirname "$0")/.."
tmp="$(mktemp -d)"
trap 'rm -rf "$tmp"' EXIT
for src in games/{16,17,18,19,20}_*.c; do
  name="$(basename "$src" .c)"
  gcc -std=c11 -Wall -Wextra -Werror -pedantic "$src" -o "$tmp/$name"
  echo "COMPILED $name"
done
check() {
  local game="$1" data="$2" expected="$3" output
  output="$(printf '%s\n' "$data" | "$tmp/$game")"
  if [[ "$output" != *"$expected"* ]]; then
    printf 'FAIL %s: expected [%s], got [%s]\n' "$game" "$expected" "$output" >&2
    exit 1
  fi
  printf 'PASS %s\n' "$game"
}
check 16_eight_puzzle q "Game ended."
check 16_eight_puzzle $'d\ns' "Solved in 2 moves!"
check 17_compiler_quiz q "Game ended."
check 17_compiler_quiz $'a\nb\nb\na\nb' "Final score: 5/5"
check 18_tower_of_hanoi q "Game ended."
check 18_tower_of_hanoi $'1 3\n1 2\n3 2\n1 3\n2 1\n2 3\n1 3' "Solved in 7 moves!"
check 19_lights_out q "Game ended."
check 19_lights_out "2 2" "All lights out in 1 moves!"
check 20_memory_match q "Game ended."
check 20_memory_match $'1 6\n2 5\n3 8\n4 7' "All pairs matched in 4 turns!"
echo "All 10 scripted checks passed."
