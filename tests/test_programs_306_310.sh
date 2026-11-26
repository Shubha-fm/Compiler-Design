#!/usr/bin/env bash
set -euo pipefail
cd "$(dirname "$0")/.."
tmp="$(mktemp -d)"
trap 'rm -rf "$tmp"' EXIT
check() {
  local name="$1" input="$2" expected="$3" output
  gcc -std=c11 -Wall -Wextra -Werror -pedantic "programs/$name.c" -o "$tmp/program"
  output="$(printf '%s\n' "$input" | "$tmp/program")"
  if [[ "$output" != *"$expected"* ]]; then
    printf 'FAIL %s: expected [%s]; observed [%s]\n' "$name" "$expected" "$output" >&2
    exit 1
  fi
  printf 'PASS %s\n' "$name"
}
check 306_trie_keyword_lookup $'2\nwhile\nreturn\n3\nwhile\nidentifier\nreturn' 'identifier: IDENTIFIER'
check 306_trie_keyword_lookup $'1\nif\n1\nif' 'if: KEYWORD'
check 307_regex_brzozowski_derivative 'aaab' 'MATCH'
check 307_regex_brzozowski_derivative 'aba' 'NO MATCH'
check 308_cfg_basic_block_edges $'4\nNORMAL\nBR 3\nNORMAL\nHALT' 'blocks=3'
check 308_cfg_basic_block_edges $'4\nNORMAL\nBR 3\nNORMAL\nHALT' 'edge 0->2'
check 309_ir_dead_store_elimination $'4\nSET a\nSET a\nPRINT a\nUSE b' 'removed=1'
check 309_ir_dead_store_elimination $'2\nSET x\nPRINT x' 'removed=0'
check 310_lr0_item_closure $'3\nS AB\nA a\nB b\n0' 'A -> .a'
check 310_lr0_item_closure $'3\nS AB\nA a\nB b\n0' 'S -> .AB'
echo '10 compiler smoke checks completed.'
