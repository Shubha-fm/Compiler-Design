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
    printf 'FAIL %s expected [%s], got [%s]\n' "$name" "$expected" "$actual" >&2
    exit 1
  fi
  printf 'PASS %s\n' "$name"
}
check '131_token_stream_rle' 'IIINNO' 'I:3'
check '132_regex_anchored_identifier' '_value42' 'ACCEPT'
check '133_dfa_distinguishing_word' '1 1
1
0
0 0
0 0
0 0' 'DISTINGUISHING: epsilon'
check '134_grammar_cnf_checker' 'S->AB' 'CNF'
check '135_ll1_stack_trace' 'aab' 'ACCEPT'
check '136_postfix_stack_peak' 'ab+c*' 'peak=2'
check '137_cfg_entry_exit_count' '3 2
0 1
1 2' 'entries=1 exits=1'
check '138_ir_label_duplicate_detection' '3 L1 L2 L1' 'DUPLICATE L1'
check '139_dataflow_bitvector_union' '5 3' 'join=7 intersection=1'
check '140_three_address_constant_substitution' 'a 10 t = a + b' 't = 10 + b'
echo '10 sample tests completed'
