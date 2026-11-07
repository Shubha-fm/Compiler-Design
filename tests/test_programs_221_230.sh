#!/usr/bin/env bash
set -euo pipefail
cd "$(dirname "$0")/.."
tmp="$(mktemp -d)"
trap 'rm -rf "$tmp"' EXIT
check() {
  local name="$1" sample="$2" expected="$3" actual
  gcc -std=c11 -Wall -Wextra -Werror -pedantic "programs/$name.c" -o "$tmp/program"
  actual="$(printf '%s\n' "$sample" | "$tmp/program")"
  if [[ "$actual" != *"$expected"* ]]; then
    printf 'FAIL %s: expected [%s], observed [%s]\n' "$name" "$expected" "$actual" >&2
    exit 1
  fi
  printf 'PASS %s\n' "$name"
}
check '221_dfa_intersection' '2 2 0 0
0 1
0 1
0 1
1 1
0 1
1 1
1' 'ACCEPT'
check '222_nfa_subset_move' '3 3
0 a 1
1 a 2
2 b 0
2 0 1
a' 'next: 1 2'
check '223_cyk_membership' '2
A a
B b
1
S A B
ab' 'ACCEPT'
check '224_expression_precedence_parser' '2+3*(4+1)' 'value=17'
check '225_cfg_articulation_points' '4 3
0 1
1 2
1 3' 'articulation: 1'
check '226_live_variables_fixedpoint' '2 1
0 1
0 1
1 0' '0 IN=1 OUT=1'
check '227_ir_constant_folding' 't = 7 * 6' 't = 42'
check '228_register_graph_coloring' '3 3
0 1
1 2
0 2' 'colors=3'
check '229_symbol_table_hash_lookup' 'ADD x
FIND x
FIND y
END' 'MISSING'
check '230_bytecode_control_flow_validator' '3
NOP
JMP 2
HALT' 'VALID TARGETS'
echo 'Completed ten sample checks.'
