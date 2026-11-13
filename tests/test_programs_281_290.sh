#!/usr/bin/env bash
set -euo pipefail
cd "$(dirname "$0")/.."
tmp="$(mktemp -d)"
trap 'rm -rf "$tmp"' EXIT
check() {
  local name="$1" input="$2" expected="$3" actual
  gcc -std=c11 -Wall -Wextra -Werror -pedantic "programs/$name.c" -o "$tmp/program"
  actual="$(printf '%s\n' "$input" | "$tmp/program")"
  if [[ "$actual" != *"$expected"* ]]; then
    printf 'FAIL %s: expected [%s], received [%s]\n' "$name" "$expected" "$actual" >&2
    exit 1
  fi
  printf 'PASS %s\n' "$name"
}
check '281_lexer_hex_literal' '0x1A7f' 'VALID'
check '282_dfa_binary_word_trace' '2 0
0 1
1 0
101' 'trace: 0 1 1 0'
check '283_grammar_indirect_left_recursion' '3
A Bx
B Cy
C Az' 'left_recursive: A B C'
check '284_operator_precedence_table' '' '+ : > > < <'
check '285_cfg_reverse_reachability' '4 2 2
0 1
1 2' 'can_reach_exit: 0 1 2'
check '286_ssa_phi_predecessor_listing' '4 4 3 x
0 1
0 2
1 3
2 3' 'x = phi(x@1, x@2)'
check '287_ir_constant_branch_elimination' '3 < 9 L1' 'JMP L1'
check '288_register_interference_edges' '3
0 2
1 3
3 5' 'edges=1'
check '289_three_address_quadruples' '1
t = a + b' '(+, a, b, t)'
check '290_lr_reduce_goto_transition' '3
0 2 5
2 7' 'stack: 0 7'
echo '10 representative smoke tests completed.'
