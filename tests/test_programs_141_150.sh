#!/usr/bin/env bash
set -euo pipefail
cd "$(dirname "$0")/.."
tmp="$(mktemp -d)"
trap 'rm -rf "$tmp"' EXIT
check() {
 local name="$1" input="$2" expected="$3" actual
 gcc -std=c11 -Wall -Wextra -pedantic "programs/$name.c" -o "$tmp/program"
 actual="$(printf '%s\n' "$input" | "$tmp/program")"
 if [[ "$actual" != *"$expected"* ]]; then
   printf 'FAIL %s: expected [%s], got [%s]\n' "$name" "$expected" "$actual" >&2
   exit 1
 fi
 printf 'PASS %s\n' "$name"
}
check '141_lexer_numeric_base' '0xAF' 'BASE 16'
check '142_regex_bracket_range' 'a z m' 'MATCH'
check '143_grammar_indirect_left_recursion' '3 3 A B B C C A' 'LEFT RECURSION A'
check '144_dfa_reachable_state_count' '3 0 1 1 1 2 2' 'reachable=2'
check '145_postfix_operand_count' 'ab+c*' 'operands=3 operators=2'
check '146_cfg_immediate_dominator' '3 2
0 1
1 2' 'idom(2)=1'
check '147_ir_constant_branch' '0 PASS FAIL' 'goto FAIL'
check '148_live_interval_overlap' '0 4 2 6' 'INTERFERE'
check '149_tac_instruction_counter' 'LOAD LOAD ADD STORE' 'LOAD=2 STORE=1 ADD=1 OTHER=0'
check '150_type_conversion_rules' 'int double' 'result=double'
echo "10 example checks completed"
