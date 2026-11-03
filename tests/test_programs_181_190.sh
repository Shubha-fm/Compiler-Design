#!/usr/bin/env bash
set -euo pipefail
cd "$(dirname "$0")/.."
tmp="$(mktemp -d)"
trap 'rm -rf "$tmp"' EXIT
check() {
  local program="$1" input="$2" expected="$3" actual
  gcc -std=c11 -Wall -Wextra -pedantic "programs/$program.c" -o "$tmp/program"
  actual="$(printf '%s\n' "$input" | "$tmp/program")"
  if [[ "$actual" != *"$expected"* ]]; then
    printf 'FAIL %s: expected [%s], got [%s]\n' "$program" "$expected" "$actual" >&2
    exit 1
  fi
  printf 'PASS %s\n' "$program"
}
check '181_lexer_nested_comment_warning' '/* outer /* nested */' 'nested_openers=1 unterminated=0'
check '182_dfa_state_partition' '2
0 1
0 1
0 1' 'equivalence_classes=2'
check '183_regex_escape_validator' 'a\\d+' 'VALID'
check '184_grammar_left_factoring_prefix' 'abc abd' 'common_prefix=ab length=2'
check '185_cfg_cyclomatic_complexity' '3 3
0 1
1 2
2 0' 'complexity=2 components=1'
check '186_tac_common_subexpression' '2
t = a + b
u = a + b' 'u = t /* reuse */'
check '187_ast_postorder' '3
+ 1 2
a -1 -1
b -1 -1' 'a b +'
check '188_ir_constant_comparison' '3 <= 5' 'constant_condition=1'
check '189_graph_reverse_postorder' '3 2
0 1
1 2' 'RPO: 0 1 2'
check '190_codegen_load_store' 'value 42' 'STORE value, R0'
echo "Completed 10 representative checks."
