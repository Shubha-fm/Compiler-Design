#!/usr/bin/env bash
set -euo pipefail
cd "$(dirname "$0")/.."
temp="$(mktemp -d)"
trap 'rm -rf "$temp"' EXIT
check() {
  local name="$1" data="$2" expected="$3" actual
  gcc -std=c11 -Wall -Wextra -Werror -pedantic "programs/$name.c" -o "$temp/exe"
  actual="$(printf '%s\n' "$data" | "$temp/exe")"
  if [[ "$actual" != *"$expected"* ]]; then
    printf 'FAIL %s: expected [%s], got [%s]\n' "$name" "$expected" "$actual" >&2
    exit 1
  fi
  printf 'PASS %s\n' "$name"
}
check '251_lexer_strip_comments' 'int x; /*gone*/ x++;' 'int x;  x++;'
check '252_dfa_minimize_partition_count' '2
0 1
0 1
1 1' 'classes=2'
check '253_nfa_epsilon_acceptance' '3 2 0 1
2
0 - 1
1 a 2
a' 'ACCEPT'
check '254_ll1_table_conflict_builder' '2
S a aS
S a b' 'CONFLICT S a'
check '255_cfg_immediate_postdominator' '3 2 2
0 1
1 2' 'ipdom(0)=1'
check '256_available_expressions' '2 1
0 1
1 0
2 0' '1 IN=1 OUT=3'
check '257_ir_algebraic_simplifier' 't = a - 0' 't = a'
check '258_greedy_register_spill' '3 3 2
0 1
1 2
0 2' 'spills=1'
check '259_assembler_two_pass_labels' 'LABEL start
NOP
JMP start
HALT
END' '1 JMP 0'
check '260_bytecode_stack_depth_merge' '3 2
PUSH POP HALT
0 1
1 2' 'SAFE'
echo 'Completed ten smoke tests.'
