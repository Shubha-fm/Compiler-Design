#!/usr/bin/env bash
# Compile with strict warnings and run positive/negative smoke tests.
set -euo pipefail
cd "$(dirname "$0")/.."
tmp="$(mktemp -d)"
trap 'rm -rf "$tmp"' EXIT
count=0
current=''
check() {
 local file="$1" input="$2" expected="$3" output
 if [[ "$file" != "$current" ]]; then
  gcc -std=c11 -Wall -Wextra -Werror -pedantic "parsers/$file.c" -o "$tmp/parser"
  current="$file"
 fi
 output="$(printf '%s\n' "$input" | "$tmp/parser")"
 if [[ "$output" != "$expected" ]]; then
  printf 'FAIL %s input=%s expected=%s actual=%s\n' "$file" "$input" "$expected" "$output" >&2
  exit 1
 fi
 printf 'PASS %-42s %-10s %s\n' "$file" "$input" "$expected"
 count=$((count+1))
}
check 'top_down/01_recursive_descent' 'a+b*c' 'ACCEPT'
check 'top_down/01_recursive_descent' 'a+*b' 'REJECT'
check 'top_down/02_predictive_ll1' 'aaab' 'ACCEPT'
check 'top_down/02_predictive_ll1' 'aaba' 'REJECT'
check 'top_down/03_backtracking_parser' 'ac' 'ACCEPT'
check 'top_down/03_backtracking_parser' 'aa' 'REJECT'
check 'top_down/04_precedence_climbing' 'x+(y*z)' 'ACCEPT'
check 'top_down/04_precedence_climbing' 'x+*y' 'REJECT'
check 'top_down/05_pratt_parser' '-a^b+c' 'ACCEPT'
check 'top_down/05_pratt_parser' 'a^^b' 'REJECT'
check 'top_down/06_peg_ordered_choice' 'ab' 'ACCEPT'
check 'top_down/06_peg_ordered_choice' 'abc' 'REJECT'
check 'bottom_up/01_shift_reduce' 'i+i+i' 'ACCEPT'
check 'bottom_up/01_shift_reduce' 'i++i' 'REJECT'
check 'bottom_up/02_operator_precedence' '2*(3+4)' 'ACCEPT'
check 'bottom_up/02_operator_precedence' '2+*3' 'REJECT'
check 'bottom_up/03_lr0' 'aaab' 'ACCEPT'
check 'bottom_up/03_lr0' 'aaba' 'REJECT'
check 'bottom_up/04_slr1' 'cdd' 'ACCEPT'
check 'bottom_up/04_slr1' 'cdc' 'REJECT'
check 'bottom_up/05_cyk' 'baaba' 'ACCEPT'
check 'bottom_up/05_cyk' 'bbb' 'REJECT'
check 'bottom_up/06_earley' 'aaab' 'ACCEPT'
check 'bottom_up/06_earley' 'aba' 'REJECT'
echo "$count parser tests passed"
