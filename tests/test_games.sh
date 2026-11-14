#!/usr/bin/env bash
set -euo pipefail
cd "$(dirname "$0")/.."
tmp="$(mktemp -d)"
trap 'rm -rf "$tmp"' EXIT

for source in games/*.c; do
  name="$(basename "$source" .c)"
  gcc -std=c11 -Wall -Wextra -Werror -pedantic "$source" -o "$tmp/$name"
  printf 'COMPILED %s\n' "$name"
done

assert_contains() {
  local program="$1" input="$2" expected="$3" output
  shift 3
  output="$(printf '%s\n' "$input" | "$tmp/$program" "$@")"
  if [[ "$output" != *"$expected"* ]]; then
    printf 'FAIL %s expected [%s], got [%s]\n' "$program" "$expected" "$output" >&2
    exit 1
  fi
  printf 'PASS %s: %s\n' "$program" "$expected"
}

assert_contains 01_tic_tac_toe_ai q "Game ended."
assert_contains 02_connect_four q "Game ended."
assert_contains 02_connect_four $'1\n2\n1\n2\n1\n2\n1' "X wins!"
assert_contains 03_hangman q "Game ended."
assert_contains 03_hangman $'c\no\nm\np\ni\nl\ne\nr' "You win!" 0
assert_contains 04_game_2048 q "Game ended." 42
assert_contains 05_maze_escape q "Game ended."
assert_contains 05_maze_escape "$(printf '%s' 'ddssaassddddwwwwdddssss' | fold -w1)" "You escaped!"
echo 'Eight scripted game checks completed.'
