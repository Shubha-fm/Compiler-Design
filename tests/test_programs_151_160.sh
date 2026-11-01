#!/usr/bin/env bash
set -euo pipefail
cd "$(dirname "$0")/.."
tmp="$(mktemp -d)"
trap 'rm -rf "$tmp"' EXIT
check() {
 local name="$1" data="$2" expected="$3" got
 gcc -std=c11 -Wall -Wextra -pedantic "programs/$name.c" -o "$tmp/program"
 got="$(printf '%s\n' "$data" | "$tmp/program")"
 if [[ "$got" != *"$expected"* ]]; then
  printf 'FAIL %s expected [%s], got [%s]\n' "$name" "$expected" "$got" >&2
  exit 1
 fi
 printf 'PASS %s\n' "$name"
}
check '151_dfa_empty_language' '2 0
0 1
0 1
1 1' 'NONEMPTY'
check '152_dfa_finite_language' '2 0
0 1
1 1
1 1' 'INFINITE'
check '153_prefix_expression_validation' '+a*bc' 'VALID'
check '154_grammar_useless_symbols' '' 'useful: S A B C'
check '155_control_flow_edge_classification' '2 2
0 1
1 0' '1->0 BACK'
check '156_ir_three_address_to_quadruple' 't = a + b' '(+,a,b,t)'
check '157_live_range_length' '2
0 4
2 5' 'total=7'
check '158_static_single_assignment_phi' 'x' 'x_3 = phi(x_1, x_2)'
check '159_lexer_newline_normalization' 'alpha' 'alpha'
check '160_stack_instruction_validation' 'PUSH 2 PUSH 3 ADD PRINT HALT' 'VALID'
echo 'Completed 10 smoke checks.'
