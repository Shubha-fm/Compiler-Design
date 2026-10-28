#!/usr/bin/env bash
set -euo pipefail
cd "$(dirname "$0")/.."
tmp="$(mktemp -d)"
trap 'rm -rf "$tmp"' EXIT
check() {
 local name="$1" input="$2" expected="$3" output
 gcc -std=c11 -Wall -Wextra -pedantic "programs/$name.c" -o "$tmp/program"
 output="$(printf '%b\n' "$input" | "$tmp/program")"
 if [[ "$output" != *"$expected"* ]]; then
  printf 'FAIL %s: expected [%s]; observed [%s]\n' "$name" "$expected" "$output" >&2
  exit 1
 fi
 printf 'PASS %s\n' "$name"
}
check '121_nfa_epsilon_closure' '4 3 0\n0 1\n1 2\n2 3' 'closure: 0 1 2 3'
check '122_dfa_equivalence' '1 1\n1\n1\n0 0\n0 0\n0 0' 'EQUIVALENT'
check '123_ll1_first_follow_check' 'ab 0 cd 0 z' 'LL1'
check '124_dangling_else_binding' 'if if else' 'else binds if2'
check '125_ast_constant_evaluator' '2 3 + 4 *' 'value=20'
check '126_constant_copy_environment' '2\na # 5\nb @ a' 'b=5'
check '127_cfg_natural_loop' '3 3\n0 1\n1 2\n2 1\n2 1' 'loop: 1 2'
check '128_dfa_shortest_accepted_word' '2 0\n0 1\n0 1\n1 1' 'word:1'
check '129_token_histogram' 'a = 12 + b' 'identifiers=2 numbers=1 punctuation=2'
check '130_intermediate_code_label_resolution' 'LABEL start\nJMP start\nEND' 'JMP start -> 0'
echo "10 sample tests completed."
