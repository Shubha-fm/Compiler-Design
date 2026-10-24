#!/usr/bin/env bash
set -euo pipefail
cd "$(dirname "$0")/.."
tmp="$(mktemp -d)"
trap 'rm -rf "$tmp"' EXIT
check(){
 local name="$1" input="$2" expected="$3" actual
 gcc -std=c11 -Wall -Wextra -pedantic "programs/$name.c" -o "$tmp/program"
 actual="$(printf '%s\n' "$input" | "$tmp/program")"
 if [[ "$actual" != *"$expected"* ]]; then
  printf 'FAIL %s: expected [%s], got [%s]\n' "$name" "$expected" "$actual" >&2
  exit 1
 fi
 echo "PASS $name"
}
check 71_remove_duplicate_spaces ' a   b  c ' 'a b c'
check 72_octal_literal 075 VALID
check 73_string_literal_checker '"hello"' VALID
check 74_token_position 'abc + def' '0:3 abc'
check 75_dfa_no_consecutive_ones 1010 ACCEPT
check 76_reverse_polish_generator 'a+b*c' 'abc*+'
check 77_constant_branch_pruning 0 'REACHABLE: else'
check 78_cfg_successor_list $'3 2\n0 1\n1 2' '1: 2'
check 79_stack_frame_offsets 3 'local2 offset=-12'
check 80_three_address_to_pseudocode 't = a + b' 'POP t'
echo '10 smoke tests passed'
