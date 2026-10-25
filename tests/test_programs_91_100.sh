#!/usr/bin/env bash
set -euo pipefail
cd "$(dirname "$0")/.."
tmp="$(mktemp -d)"
trap 'rm -rf "$tmp"' EXIT
check() {
 local name="$1" data="$2" expected="$3" actual
 gcc -std=c11 -Wall -Wextra -pedantic "programs/$name.c" -o "$tmp/test"
 actual="$(printf '%s\n' "$data" | "$tmp/test")"
 if [[ "$actual" != *"$expected"* ]]; then
   echo "FAIL $name: wanted $expected, got $actual" >&2; exit 1
 fi
 echo "PASS $name"
}
check '91_grammar_productivity' '' 'S=1'
check '92_dfa_complement' '110' 'ACCEPT'
check '93_dfa_symmetric_difference' '10' 'REJECT'
check '94_grammar_nullable_fixedpoint' '' 'S=1 A=1 B=1 C=1'
check '95_cfg_predecessor_list' '3 2
0 2
1 2' '2: 0 1'
check '96_cfg_back_edges' '3 3
0 1
1 2
2 0' 'BACK 2 0'
check '97_tac_dead_store' 'x 2 x 3' 'x = 3'
check '98_ssa_versioning' '3 x y x' 'x_2'
check '99_stack_machine_interpreter' 'PUSH 3
PUSH 4
ADD
PRINT
HALT' '7'
check '100_expression_type_checker' 'int + float' 'float'
echo 'Completed 10 smoke tests'
