#!/usr/bin/env bash
set -euo pipefail
cd "$(dirname "$0")/.."
tmp="$(mktemp -d)"
trap 'rm -rf "$tmp"' EXIT
test_one() {
 local name="$1" input="$2" expected="$3" actual
 gcc -std=c11 -Wall -Wextra -pedantic "programs/$name.c" -o "$tmp/program"
 actual="$(printf '%s\n' "$input" | "$tmp/program")"
 if [[ "$actual" != *"$expected"* ]]; then
  echo "FAILED $name: expected [$expected] actual [$actual]" >&2
  exit 1
 fi
 echo "PASS $name"
}
test_one '101_levenshtein_syntax_suggestion' 'kitten sitting' 'distance=3'
test_one '102_integer_suffix_validator' '123ULL' 'VALID'
test_one '103_utf8_byte_classifier' 'hello' 'codepoints=5'
test_one '104_grammar_direct_left_recursion' 'E->E+T' 'LEFT RECURSIVE'
test_one '105_automaton_transition_trace' '101' '0'
test_one '106_constant_condition_tac' '3 < 5' 'condition = 1'
test_one '107_stack_depth_analyzer' 'PUSH PUSH POP' 'peak=2 final=1'
test_one '108_cfg_topological_order' '3 2
0 1
1 2' 'ORDER: 0 1 2'
test_one '109_interference_graph' 'abc' 'a-b'
test_one '110_three_address_code_validator' 't = a + b' 'VALID'
echo 'All 10 sample tests passed'
