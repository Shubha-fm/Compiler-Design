#!/usr/bin/env bash
set -euo pipefail
cd "$(dirname "$0")/.."
tmp="$(mktemp -d)"
trap 'rm -rf "$tmp"' EXIT
check() {
  local name="$1" input="$2" expected="$3" actual
  gcc -std=c11 -Wall -Wextra -Werror -pedantic "programs/$name.c" -o "$tmp/program"
  actual="$(printf '%s\n' "$input" | "$tmp/program")"
  if [[ "$actual" != *"$expected"* ]]; then
    printf 'FAIL %s expected [%s] got [%s]\n' "$name" "$expected" "$actual" >&2
    exit 1
  fi
  echo "PASS $name"
}
check 311_lexer_line_comment_tokens $'int x=3; // ignore 21\nreturn x;' "identifiers=4 integers=1"
check 311_lexer_line_comment_tokens $'// comments\nabc 4' "identifiers=1 integers=1"
check 312_regex_dot_star_match 'a*b aaab' 'MATCH'
check 312_regex_dot_star_match 'a*b aaac' 'NO MATCH'
check 313_cfg_topological_order $'3 2\n0 1\n1 2' 'topological: 0 1 2'
check 313_cfg_topological_order $'2 2\n0 1\n1 0' 'CYCLE'
check 314_ir_strength_reduction $'2\nx y 8\nz x 3' 'x = y << 3'
check 314_ir_strength_reduction $'1\nz x 3' 'z = x * 3'
check 315_ll1_first_follow_table 'A b' 'A -> b'
check 315_ll1_first_follow_table 'A $' 'A -> #'
echo "10 compiler smoke tests completed."
