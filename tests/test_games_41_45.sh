#!/usr/bin/env bash
set -euo pipefail
cd "$(dirname "$0")/.."
tmp="$(mktemp -d)"
trap 'rm -rf "$tmp"' EXIT
for source in games/{41,42,43,44,45}_*.c; do
  exe="$(basename "$source" .c)"
  gcc -std=c11 -Wall -Wextra -Werror -pedantic "$source" -o "$tmp/$exe"
  echo "COMPILED $exe"
done
check() {
  local name="$1" input="$2" expected="$3" result
  result="$(printf '%s\n' "$input" | "$tmp/$name")"
  if [[ "$result" != *"$expected"* ]]; then
    printf 'FAIL %s: expected [%s]; observed [%s]\n' "$name" "$expected" "$result" >&2
    exit 1
  fi
  printf 'PASS %s\n' "$name"
}
check 41_lane_runner q "Game ended."
check 41_lane_runner $'s\ns\na\nd\ns\na' "Finished the race!"
check 42_anagram_challenge q "Game ended."
check 42_anagram_challenge $'parser\ntoken\nlexer' "Final score: 3/3"
check 43_robot_labyrinth q "Game ended."
check 43_robot_labyrinth $'h\nq' "Hint:"
check 44_dice_duel q "Game ended."
check 44_dice_duel $'h\nq' "Scores you="
check 45_binary_path_puzzle q "Game ended."
check 45_binary_path_puzzle $'1\n0\n1\n1' "Treasure discovered!"
echo '10 game smoke checks completed.'
