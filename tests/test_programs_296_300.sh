#!/usr/bin/env bash
set -euo pipefail
cd "$(dirname "$0")/.."
tmp="$(mktemp -d)"
trap 'rm -rf "$tmp"' EXIT
check() {
  local name="$1" data="$2" expected="$3" actual
  gcc -std=c11 -Wall -Wextra -Werror -pedantic "programs/$name.c" -o "$tmp/program"
  actual="$(printf '%s\n' "$data" | "$tmp/program")"
  if [[ "$actual" != *"$expected"* ]]; then
    printf 'FAIL %s: expected [%s], got [%s]\n' "$name" "$expected" "$actual" >&2
    exit 1
  fi
  printf 'PASS %s\n' "$name"
}
check 296_lexer_token_frequency 'int x = 42 + y;' 'identifiers=3 integers=1 operators=2 other=1'
check 296_lexer_token_frequency 'a1 _b 2' 'identifiers=2 integers=1 operators=0 other=0'
check 297_regex_thompson_nfa 'ab.' 'states=4 transitions=3'
check 297_regex_thompson_nfa 'a*' 'states=4 transitions=5'
check 298_cfg_strong_components $'4 4\n0 1\n1 0\n1 2\n2 3' 'components=3'
check 298_cfg_strong_components $'2 2\n0 1\n1 0' 'components=1'
check 299_grammar_first_follow $'3\nS AB\nA a\nB b' 'S FIRST: a'
check 299_grammar_first_follow $'3\nS AB\nA a\nB b' 'A FOLLOW: b'
check 300_stack_bytecode_vm $'5\nPUSH 7\nPUSH 5\nADD\nPRINT\nHALT' 'OUTPUT 12'
check 300_stack_bytecode_vm $'2\nADD\nHALT' 'STACK ERROR'
echo '10 compiler sample checks passed.'
