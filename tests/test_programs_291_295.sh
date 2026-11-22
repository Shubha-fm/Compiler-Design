#!/usr/bin/env bash
set -euo pipefail
cd "$(dirname "$0")/.."
tmp="$(mktemp -d)"
trap 'rm -rf "$tmp"' EXIT
check() {
  local name="$1" data="$2" expected="$3" output
  gcc -std=c11 -Wall -Wextra -Werror -pedantic "programs/$name.c" -o "$tmp/$name"
  output="$(printf '%s\n' "$data" | "$tmp/$name")"
  if [[ "$output" != *"$expected"* ]]; then
    printf 'FAIL %s expected [%s], got [%s]\n' "$name" "$expected" "$output" >&2
    exit 1
  fi
  printf 'PASS %s: %s\n' "$name" "$expected"
}
check 291_lexer_token_positions 'sum_2 = 17;' 'IDENT sum_2 col=1'
check 291_lexer_token_positions 'sum_2 = 17;' 'INT 17 col=9'
check 292_postfix_regex_nullable '#a|' 'NULLABLE'
check 292_postfix_regex_nullable 'ab.' 'NOT NULLABLE'
check 293_grammar_unit_closure $'3\nA B\nB C\nD E\nA' 'closure(A): A B C'
check 294_cfg_immediate_dominators $'4 4\n0 1\n0 2\n1 3\n2 3' 'idom(3)=0'
check 294_cfg_immediate_dominators $'3 2\n0 1\n1 2' 'idom(2)=1'
check 295_postfix_stack_codegen 'ab+c*' 'MUL'
check 295_postfix_stack_codegen 'ab+' 'HALT'
check 295_postfix_stack_codegen 'a+' 'INVALID EXPRESSION'
echo '10 compiler smoke checks passed.'
