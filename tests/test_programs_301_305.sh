#!/usr/bin/env bash
set -euo pipefail
cd "$(dirname "$0")/.."
tmp="$(mktemp -d)"
trap 'rm -rf "$tmp"' EXIT
check() {
  local name="$1" data="$2" expected="$3" actual
  gcc -std=c11 -Wall -Wextra -Werror -pedantic "programs/$name.c" -o "$tmp/example"
  actual="$(printf '%s\n' "$data" | "$tmp/example")"
  if [[ "$actual" != *"$expected"* ]]; then
    printf 'FAIL %s expected [%s], observed [%s]\n' "$name" "$expected" "$actual" >&2
    exit 1
  fi
  printf 'PASS %s\n' "$name"
}
check 301_lexer_string_escapes '"hello"' "VALID"
check 301_lexer_string_escapes '"bad\q"' "INVALID"
check 302_regex_infix_to_postfix 'a.(b|c)*' 'abc|*.'
check 302_regex_infix_to_postfix 'a|' 'INVALID'
check 303_cfg_cyclomatic_complexity $'3 3\n0 1\n1 2\n2 0' 'complexity=2'
check 303_cfg_cyclomatic_complexity $'3 2\n0 1\n1 2' 'complexity=1'
check 304_tac_constant_propagation $'4\nCONST a 4\nCONST b 5\nADD c a b\nPRINT c' 'c=9'
check 304_tac_constant_propagation $'2\nCOPY b a\nPRINT b' 'b=?'
check 305_bytecode_stack_verifier $'4\nPUSH\nPUSH\nADD\nHALT' 'STACK SAFE'
check 305_bytecode_stack_verifier $'2\nPOP\nHALT' 'UNDERFLOW at 0'
echo '10 compiler sample checks passed.'
