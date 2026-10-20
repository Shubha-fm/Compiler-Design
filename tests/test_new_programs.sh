#!/usr/bin/env bash
# Compiles all 30 new standalone programs and checks representative outputs.
set -euo pipefail
cd "$(dirname "$0")/.."
tmp="$(mktemp -d)"
trap 'rm -rf "$tmp"' EXIT
passed=0
check() {
  local file="$1" input="$2" expected="$3" actual
  gcc -std=c11 -Wall -Wextra -pedantic "programs/$file.c" -o "$tmp/program"
  actual="$(printf '%b\n' "$input" | "$tmp/program")"
  if ! grep -Fq -- "$expected" <<< "$actual"; then
    printf 'FAIL %s: expected [%s], received [%s]\n' "$file" "$expected" "$actual" >&2
    exit 1
  fi
  printf 'PASS %s\n' "$file"
  passed=$((passed + 1))
}
check '21_keyword_lookup' 'int' 'KEYWORD'
check '22_integer_literal' '-123' 'VALID'
check '23_floating_literal' '3.14' 'VALID'
check '24_hex_literal' '0xAF' 'VALID'
check '25_balanced_delimiters' '{([])}' 'BALANCED'
check '26_line_statistics' 'hello world' '12 2 1'
check '27_whitespace_normalizer' 'a   b  c' 'a b c'
check '28_nfa_ends_ab' 'aab' 'ACCEPT'
check '29_dfa_even_zeros' '001' 'ACCEPT'
check '30_dfa_binary_divisible_by_three' '110' 'ACCEPT'
check '31_regex_ab_star' 'abbb' 'ACCEPT'
check '32_grammar_anbn' 'aabb' 'ACCEPT'
check '33_grammar_palindrome' 'abba' 'ACCEPT'
check '34_prefix_evaluator' '+ 2 * 3 4' '14'
check '35_tac_for_arithmetic' 'a + b * c' 't1 = b * c'
check '36_quadruples' 'a + b' 'op=+ arg1=a arg2=b result=t1'
check '37_triples' 'x * y' '(0) (*, x, y)'
check '38_assembly_generation' 't1 = a + b' 'LOAD R0, a'
check '39_algebraic_simplifier' 'x * 1' 'x'
check '40_strength_reduction' 'x 8' 'x << 3'
check '41_copy_propagation' 'x = 5' 'copy(x) = 5'
check '42_unreachable_code' '4 2\n0 1\n1 2' 'Unreachable: 3'
check '43_basic_block_leaders' '5 1\n1 4' 'Leaders: 0 2 4'
check '44_liveness_sets' 'x = y + z' 'DEF={x} USE={y,z}'
check '45_register_allocation' '3 2' 'v0 -> R0'
check '46_constant_propagation' '4 5' 'y = 9'
check '47_loop_invariant_motion' 't = 2 + 3' 'HOISTABLE'
check '48_error_recovery' 'oops;ok' 'Recovered after 5 characters'
check '49_nullable_nonterminal' 'ignored' 'A=1 B=1 S=1'
check '50_expression_ast' 'a + b * c' 'ROOT(+)'
echo "PASS: $passed sample tests and compilation checks."
