#!/usr/bin/env bash
set -euo pipefail
cd "$(dirname "$0")/.."
tmp="$(mktemp -d)"
trap 'rm -rf "$tmp"' EXIT
check() {
  local name="$1" input="$2" expected="$3" output
  gcc -std=c11 -Wall -Wextra -pedantic "programs/$name.c" -o "$tmp/example"
  output="$(printf '%s\n' "$input" | "$tmp/example")"
  if [[ "$output" != *"$expected"* ]]; then
    printf 'FAIL %s expected [%s], got [%s]\n' "$name" "$expected" "$output" >&2
    exit 1
  fi
  printf 'PASS %s\n' "$name"
}
check '211_lexer_string_escape_checker' '"hello\\n"' 'VALID'
check '212_regex_character_class_union' 'abc bdf' 'union:abcdf'
check '213_nfa_epsilon_reachability' '4 3
0 1
1 2
2 3
2 0 2' 'closure: 0 1 2 3'
check '214_grammar_first_first_conflict_pairs' '3
ab
bc
d' 'conflict 0 1 b'
check '215_cfg_dominator_query' '4 4
0 1
0 2
1 3
2 3
0 3' 'DOMINATES'
check '216_ir_dead_assignment_liveness' 'x abc' 'DEAD'
check '217_register_interval_peak' '3
0 4
1 3
2 5' 'peak=3'
check '218_tac_use_def_sets' 't = a + b' 'USE: a b'
check '219_parser_parenthesis_depth' 'a+(b*(c+d))' 'max_depth=2'
check '220_symbol_table_duplicate_scope' '3
0 a
1 a
0 a' 'DUPLICATE scope=0 name=a'
echo "10 smoke checks completed"
