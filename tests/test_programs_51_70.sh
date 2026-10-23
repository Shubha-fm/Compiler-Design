#!/usr/bin/env bash
set -euo pipefail
cd "$(dirname "$0")/.."
tmp="$(mktemp -d)"
trap 'rm -rf "$tmp"' EXIT
passed=0
check() {
 local file="$1" input="$2" expected="$3" actual
 gcc -std=c11 -Wall -Wextra -pedantic "programs/$file.c" -o "$tmp/program"
 actual="$(printf '%s\n' "$input" | "$tmp/program")"
 if [[ "$actual" != *"$expected"* ]]; then
   echo "FAIL $file expected [$expected] got [$actual]" >&2
   exit 1
 fi
 printf 'PASS %s\n' "$file"
 passed=$((passed+1))
}
check '51_character_frequency' 'a' '97 1'
check '52_keyword_case_sensitivity' 'int' 'KEYWORD'
check '53_binary_to_decimal' '1011' '11'
check '54_escape_sequence_scanner' '\\n' 'VALID'
check '55_scientific_number' '1.2e3' 'VALID'
check '56_binary_even_parity' '1011' 'REJECT'
check '57_mealy_parity' '101' '110'
check '58_moore_parity' '101' '0110'
check '59_regex_alternation' 'ba' 'ACCEPT'
check '60_dfa_contains_101' '11011' 'ACCEPT'
check '61_nullable_sequence' '' 'nullable(S)=1'
check '62_parse_tree_depth' '(()())' '2'
check '63_ast_postorder' '' 'ab+c*'
check '64_tac_temporaries' 'a b c d' 't3 = t2 + d'
check '65_indirect_triples' '' '0 -> 0'
check '66_boolean_short_circuit' '' 'ifFalse x goto Lfalse'
check '67_dag_common_expression' '' 'expression 3 -> node 0'
check '68_control_flow_dominators' '4 4
0 1
0 2
1 3
2 3' '3: 0 3'
check '69_reaching_definitions' '2
a b
c a' 'stmt 1: use a from 0'
check '70_live_variable_analysis' '2
a b
c a' 'before 0: b'
echo "Completed $passed checks."
