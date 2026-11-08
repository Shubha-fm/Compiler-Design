#!/usr/bin/env bash
set -euo pipefail
cd "$(dirname "$0")/.."
tmp="$(mktemp -d)"
trap 'rm -rf "$tmp"' EXIT
check() {
 local program="$1" input="$2" expected="$3" actual
 gcc -std=c11 -Wall -Wextra -Werror -pedantic "programs/$program.c" -o "$tmp/program"
 actual="$(printf '%s\n' "$input" | "$tmp/program")"
 if [[ "$actual" != *"$expected"* ]]; then
   printf 'FAIL %s: expected [%s], received [%s]\n' "$program" "$expected" "$actual" >&2
   exit 1
 fi
 printf 'PASS %s\n' "$program"
}
check '231_postfix_to_infix' 'ab+c*' '((a+b)*c)'
check '232_grammar_nullable_solver' '4
S AB
A -
B C
C -' 'nullable: A B C S'
check '233_dfa_shortest_state_path' '3 0 2
0 1
1 2
2 2' 'word:11'
check '234_nfa_epsilon_move' '4 3
0 - 1
1 a 2
2 - 3
1 0
a' 'states: 2 3'
check '235_grammar_dependency_toposort' '3 2
A B
B C' 'order: C B A'
check '236_cfg_backedge_dominance' '3 3
0 1
1 2
2 1' 'backedge 2 1'
check '237_ir_commutative_cse' '2
t = a + b
u = b + a' 'u = t /* CSE */'
check '238_bytecode_stack_safety' '3 2
PUSH POP HALT
0 1
1 2' 'SAFE'
check '239_symbol_table_scope_stack' 'DECL x
ENTER
DECL y
FIND x
EXIT
FIND y
END' 'MISSING'
check '240_assembly_basic_block_labels' '5
NOP
JZ 4
NOP
JMP 0
HALT' 'leaders: 0 2 4'
echo "Completed 10 sample tests."
