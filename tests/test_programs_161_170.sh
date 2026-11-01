#!/usr/bin/env bash
set -euo pipefail
cd "$(dirname "$0")/.."
tmp="$(mktemp -d)"
trap 'rm -rf "$tmp"' EXIT
check() {
 local name="$1" sample="$2" expected="$3" actual
 gcc -std=c11 -Wall -Wextra -pedantic "programs/$name.c" -o "$tmp/program"
 actual="$(printf '%s\n' "$sample" | "$tmp/program")"
 if [[ "$actual" != *"$expected"* ]]; then
  echo "FAIL $name: expected [$expected], got [$actual]" >&2
  exit 1
 fi
 echo "PASS $name"
}
check '161_lexer_state_machine' 'a1 = 24' 'ID a1'
check '162_grammar_unit_closure' '3 2 A B B C' 'A: A B C'
check '163_cfg_post_dominator' '3 2 2
0 1
1 2' '0: 0 1 2'
check '164_dfa_transition_coverage' '2 0
0 1
0 1
010' 'covered=2'
check '165_lexical_scope_lookup' '3 a b a a' 'scope=2'
check '166_array_address_calculation' '3 4 1 2 8' 'offset=48'
check '167_register_spill_estimate' '3 2
0 4
1 3
2 5' 'minimum_spills_at_peak=1'
check '168_cfg_critical_edge' '4 4
0 1
0 2
1 3
0 3' 'critical 0 3'
check '169_three_address_codegen' 't = a * b' 'MUL R0, b'
check '170_stack_bytecode_trace' 'PUSH 2 PUSH 3 ADD HALT' 'result=5'
echo '10 representative checks completed'
