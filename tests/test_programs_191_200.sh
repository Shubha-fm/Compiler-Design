#!/usr/bin/env bash
set -euo pipefail
cd "$(dirname "$0")/.."
temp="$(mktemp -d)"
trap 'rm -rf "$temp"' EXIT
check() {
 local program="$1" input="$2" expected="$3" actual
 gcc -std=c11 -Wall -Wextra -pedantic "programs/$program.c" -o "$temp/program"
 actual="$(printf '%s\n' "$input" | "$temp/program")"
 if [[ "$actual" != *"$expected"* ]]; then
   printf 'FAIL %s: expected [%s], got [%s]\n' "$program" "$expected" "$actual" >&2
   exit 1
 fi
 echo "PASS $program"
}
check '191_lexer_keyword_boundary' 'ifelse' 'IDENTIFIER'
check '192_regex_shunting_yard' 'a.(b|c)' 'abc|.'
check '193_nfa_move_set' '3 2
0 a 1
1 a 2
2 0 1
a' 'MOVE: 1 2'
check '194_grammar_follow_trailer' 'ab 1 cd' 'FOLLOW_B: a b c d'
check '195_cfg_dominance_frontier' '4 4
0 1
0 2
1 3
2 3' 'DF(1): 3'
check '196_dataflow_reaching_definitions' '2 1
0 1
1 0
2 0' '1 IN=1 OUT=3'
check '197_ir_strength_reduction' 't x 8' 't = x << 3'
check '198_stack_effect_analyzer' 'PUSH DUP ADD' 'final=1 peak=2'
check '199_basic_block_successor_matrix' '2 1
0 1' '0 1'
check '200_lr_shift_reduce_trace' 'aab' 'ACCEPT'
echo '10 smoke checks completed'
