#!/usr/bin/env bash
set -euo pipefail
cd "$(dirname "$0")/.."
tmp="$(mktemp -d)"
trap 'rm -rf "$tmp"' EXIT
check() {
  local name="$1" input="$2" expected="$3" actual
  gcc -std=c11 -Wall -Wextra -Werror -pedantic "programs/$name.c" -o "$tmp/example"
  actual="$(printf '%s\n' "$input" | "$tmp/example")"
  if [[ "$actual" != *"$expected"* ]]; then
    printf 'FAIL %s: expected [%s], got [%s]\n' "$name" "$expected" "$actual" >&2
    exit 1
  fi
  printf 'PASS %s\n' "$name"
}
check '271_lexer_floating_literal' '12.5e-2' 'VALID'
check '272_dfa_unreachable_pruning' '3 0
0 1
1 1
2 2' 'removed=1'
check '273_grammar_first_terminals' '3
S AB
A a
B b' 'S: a'
check '274_lr_stack_action_simulator' 'SHIFT a
SHIFT b
REDUCE 2 E
ACCEPT' 'stack_top=E depth=1'
check '275_cfg_loop_header_candidates' '3 3
0 1
1 2
2 1' 'headers: 1'
check '276_dataflow_gen_kill_transfer' '7 8 2' 'OUT=13'
check '277_ir_dag_expression_sharing' '3
+ a b
+ b a
* a b' 'unique_expressions=2'
check '278_register_pressure_timeline' '2 3
0 2
1 3' '1:2'
check '279_assembler_symbol_address' 'LABEL start
NOP
JMP start
LABEL end
HALT
END' 'end=3'
check '280_tac_identifier_validation' 't = a + b' 'VALID TAC'
echo '10 representative smoke tests completed'
