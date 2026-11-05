#!/usr/bin/env bash
set -euo pipefail
cd "$(dirname "$0")/.."
tmp="$(mktemp -d)"
trap 'rm -rf "$tmp"' EXIT
check() {
  local program="$1" input="$2" expected="$3" actual
  gcc -std=c11 -Wall -Wextra -pedantic "programs/$program.c" -o "$tmp/program"
  actual="$(printf '%b\n' "$input" | "$tmp/program")"
  if [[ "$actual" != *"$expected"* ]]; then
    printf 'FAIL %s: expected [%s], got [%s]\n' "$program" "$expected" "$actual" >&2
    exit 1
  fi
  printf 'PASS %s\n' "$program"
}
check '201_lexer_tab_columns' 'ab\tcd' 'next_column=11'
check '202_nfa_acceptance' '3 2 0 1 2
0 a 1
1 b 2
ab' 'ACCEPT'
check '203_grammar_nullable_sequence' 'AB BA' 'NULLABLE'
check '204_ll1_table_lookup' '2
S a aS
S b b
S b' 'production=b'
check '205_cfg_unreachable_blocks' '4 2
0 1
1 2' 'unreachable: 3'
check '206_ir_copy_propagation' 'x y z = x + a' 'z = y + a'
check '207_peephole_push_pop' '3
PUSH a
POP a
ADD b' 'ADD b'
check '208_live_interval_interference_matrix' '2
0 3
2 4' '0 1'
check '209_ast_preorder' '3
+ 1 2
a -1 -1
b -1 -1' '+ a b'
check '210_ir_jump_threading' '3
1 2 -1' '0 -> 2'
echo "Completed ten smoke tests."
