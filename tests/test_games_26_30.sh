#!/usr/bin/env bash
set -euo pipefail
cd "$(dirname "$0")/.."
tmp="$(mktemp -d)"
trap 'rm -rf "$tmp"' EXIT
check() {
  local game="$1" input="$2" expected="$3" output
  output="$(printf '%s\n' "$input" | "$tmp/$game")"
  if [[ "$output" != *"$expected"* ]]; then
    printf 'FAIL %s expected [%s], got [%s]\n' "$game" "$expected" "$output" >&2
    exit 1
  fi
  printf 'PASS %s: %s\n' "$game" "$expected"
}
for file in games/{26,27,28,29,30}_*.c; do
  game="$(basename "$file" .c)"
  gcc -std=c11 -Wall -Wextra -Werror -pedantic "$file" -o "$tmp/$game"
  printf 'COMPILED %s\n' "$game"
done
check 26_checkers_mini q "Game ended."
check 26_checkers_mini $'1 1\nq' "Illegal move."
check 27_fifteen_puzzle d "Solved in 1 moves!"
check 27_fifteen_puzzle q "Game ended."
check 28_dungeon_battle $'attack\nattack\nattack\nattack' "You defeated the monster!"
check 28_dungeon_battle q "Game ended."
check 29_game_of_life 1 "Generation 1:"
check 29_game_of_life q "Game ended."
check 30_simon_sequence q "Game ended."
check 30_simon_sequence $'1\n13\n132\n1324\n13241\n132413\n1324132\n13241324\n132413241\n1324132413' "Perfect memory"
echo '10 game smoke checks passed.'
