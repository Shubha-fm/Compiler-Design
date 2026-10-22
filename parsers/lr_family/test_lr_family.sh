#!/usr/bin/env bash
set -euo pipefail
cd "$(dirname "$0")"
tmp="$(mktemp -d)"
trap 'rm -rf "$tmp"' EXIT
gcc -std=c11 -Wall -Wextra -Werror -pedantic lr_parser.c -o "$tmp/parser"
check() {
 actual="$("$tmp/parser" "$1" "grammars/$2.txt" "$3")"
 if [[ "$actual" != "$4" ]]; then echo "FAILED $1 $2 $3 expected $4 got $actual"; exit 1; fi
 echo "PASS $1 $2"
}
for mode in slr clr lalr; do
 check "$mode" slr cdd ACCEPT
 check "$mode" slr cdcd ACCEPT
 check "$mode" slr cdc REJECT
 check "$mode" epsilon aabb ACCEPT
 check "$mode" epsilon "" ACCEPT
 check "$mode" epsilon abab REJECT
done
for mode in clr lalr; do
 check "$mode" assignment 'i=i' ACCEPT
 check "$mode" assignment '*i=i' ACCEPT
 check "$mode" assignment 'i==' REJECT
done
set +e
result="$("$tmp/parser" slr grammars/assignment.txt 'i=i' 2>/dev/null)"
status=$?
set -e
[[ "$status" -eq 3 && "$result" == "CONFLICT" ]] || exit 1
echo "PASS expected SLR conflict"
echo "All 25 checks passed"
