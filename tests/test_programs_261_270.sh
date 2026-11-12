#!/usr/bin/env bash
set -euo pipefail
cd "$(dirname "$0")/.."
tmp="$(mktemp -d)"
trap 'rm -rf "$tmp"' EXIT
check() {
  local program="$1" input="$2" expected="$3" output
  gcc -std=c11 -Wall -Wextra -Werror -pedantic "programs/$program.c" -o "$tmp/program"
  output="$(printf '%s\n' "$input" | "$tmp/program")"
  if [[ "$output" != *"$expected"* ]]; then
    printf 'FAIL %s: expected [%s], received [%s]\n' "$program" "$expected" "$output" >&2
    exit 1
  fi
  echo "PASS $program"
}
check '261_lexer_integer_underscore' '12_345' 'VALID'
check '262_dfa_complement_acceptance' '2 0
0 1
0 1
1 1
0' 'ACCEPT'
check '263_cfg_reachability_pairs' '3 2
0 1
1 2' 'reachable_pairs=6'
check '264_grammar_epsilon_removal_variants' 'AB A' 'AB'
check '265_parse_table_cell_count' '3
S a 1
S b 2
A a 3' 'filled_cells=3'
check '266_dataflow_very_busy_expressions' '2 1
0 1
1 0
2 0' '0 IN=3 OUT=2'
check '267_ir_three_address_to_triples' '2
t = a + b
u = t * c' '1: (*, (0), c)'
check '268_linear_scan_register_allocation' '3 2
0 4
1 3
2 5' 'v2 SPILL'
check '269_peephole_redundant_moves' '3
MOV x x
MOV a b
MOV a b' 'MOV a b'
check '270_lr_parse_action_decoder' 'r12' 'REDUCE 12'
echo '10 sample checks completed'
