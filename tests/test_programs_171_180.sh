#!/usr/bin/env bash
set -euo pipefail
cd "$(dirname "$0")/.."
temp="$(mktemp -d)"
trap 'rm -rf "$temp"' EXIT
check() {
 local file="$1" input="$2" expected="$3" actual
 gcc -std=c11 -Wall -Wextra -pedantic "programs/$file.c" -o "$temp/example"
 actual="$(printf '%s\n' "$input" | "$temp/example")"
 if [[ "$actual" != *"$expected"* ]]; then
   printf 'FAIL %s: expected [%s], got [%s]\n' "$file" "$expected" "$actual" >&2
   exit 1
 fi
 echo "PASS $file"
}
check '171_lexer_comment_counter' 'int x; // hi
/* block */' 'line=1 block=1'
check '172_dfa_shortest_rejecting_word' '2 0
1 0
0 1
1 1' 'reject:0'
check '173_grammar_first_sequence' '2 A ab 1 B c 0 AB' 'FIRST: a b c'
check '174_cfg_bridge_detection' '3 2
0 1
1 2' 'bridge 1 2'
check '175_ast_node_height' '3
1 2
-1 -1
-1 -1' 'height=2'
check '176_tac_algebraic_identities' 't = a * 1' 't = a'
check '177_register_interval_coloring' '3 2
0 4
1 3
2 5' 'v2 spill'
check '178_code_alignment' '13 8' 'aligned=16'
check '179_lr_action_table_validator' '2
0 a s1
0 a r2' 'CONFLICT state=0 terminal=a'
check '180_cfg_edge_split_plan' '4 4
0 1
0 2
1 3
0 3' 'splits=1'
echo '10 sample checks completed'
