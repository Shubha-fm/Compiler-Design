#!/usr/bin/env bash
set -euo pipefail
cd "$(dirname "$0")/.."
tmp="$(mktemp -d)"
trap 'rm -rf "$tmp"' EXIT
check() {
  local name="$1" data="$2" expected="$3" got
  gcc -std=c11 -Wall -Wextra -Werror -pedantic "programs/$name.c" -o "$tmp/program"
  got="$(printf '%s\n' "$data" | "$tmp/program")"
  if [[ "$got" != *"$expected"* ]]; then
    printf 'FAIL %s expected [%s], received [%s]\n' "$name" "$expected" "$got" >&2
    exit 1
  fi
  echo "PASS $name"
}
check '241_lexer_identifier_spans' 'int x2 = foo;' 'ID x2 [4,6)'
check '242_regex_repeat_bounds' 'a{1,3}' 'aaa'
check '243_dfa_product_reachability' '2 2 0 0
0 1
1 1
0 1
1 1' 'reachable_product_states=2'
check '244_grammar_productive_solver' '4
S AB
A a
B C
C b' 'productive: A B C S'
check '245_ll1_stack_parser' '(()())' 'ACCEPT'
check '246_cfg_edge_profile' '3 5
0 1 2 1 2' '1->2: 2'
check '247_constant_lattice_meet' '4 5' 'NAC'
check '248_ssa_phi_arity' '4 4
0 1
0 2
1 3
2 3
3 2' 'predecessors=2 phi_args=2 VALID'
check '249_interference_degree' '3 2
0 1
1 2' 'v1 degree=2'
check '250_linker_relocation_resolver' '3
0 0 0
2
main 42
exit 99
2
0 main
2 exit' 'linked: 42 0 99'
echo 'Ten smoke tests completed.'
