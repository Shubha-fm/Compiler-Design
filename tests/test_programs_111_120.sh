#!/usr/bin/env bash
set -euo pipefail
cd "$(dirname "$0")/.."
tmp="$(mktemp -d)"
trap 'rm -rf "$tmp"' EXIT
check() {
 local name="$1" input="$2" expected="$3" output
 gcc -std=c11 -Wall -Wextra -pedantic "programs/$name.c" -o "$tmp/program"
 output="$(printf '%s\n' "$input" | "$tmp/program")"
 if [[ "$output" != *"$expected"* ]]; then
  echo "FAIL $name: expected [$expected], observed [$output]" >&2
  exit 1
 fi
 echo "PASS $name"
}
check '111_lexer_line_column' 'abc 123 def' '1:1 abc'
check '112_lexer_longest_operator' '<=' 'OPERATOR <='
check '113_regex_postfix_validation' 'ab.|' 'INVALID'
check '114_first_follow_ll1_conflict' 'abc cd' 'CONFLICT c'
check '115_parse_tree_node_count' 'a(b(c))' 'nodes=3'
check '116_expression_constant_range' '1 3 2 5' '[3,8]'
check '117_cfg_transitive_reachability' '3 2
0 1
1 2' '1 1 1'
check '118_cfg_strongly_connected_components' '3 3
0 1
1 0
1 2' 'SCC=2'
check '119_ir_three_address_swap' 'x y' 'y = tmp'
check '120_register_pressure_estimate' '3
0 4
1 3
2 5' 'pressure=3'
echo '10 smoke tests passed'
