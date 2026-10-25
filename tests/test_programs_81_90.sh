#!/usr/bin/env bash
set -euo pipefail
cd "$(dirname "$0")/.."
tmp="$(mktemp -d)"
trap 'rm -rf "$tmp"' EXIT
check() {
 local name="$1" input="$2" expected="$3" result
 gcc -std=c11 -Wall -Wextra -pedantic "programs/$name.c" -o "$tmp/program"
 result="$(printf '%s\n' "$input" | "$tmp/program")"
 if [[ "$result" != *"$expected"* ]]; then
  printf 'FAIL %s expected [%s] received [%s]\n' "$name" "$expected" "$result" >&2
  exit 1
 fi
 printf 'PASS %s\n' "$name"
}
check 81_nullable_first_symbol '2 A a 1 B b 0 AB' 'FIRST: a b'
check 82_eliminate_unit_productions '' 'After: A->a; B->a; C->a'
check 83_remove_unreachable_nonterminals '' 'Reachable: S A B'
check 84_dfa_product_intersection '110' 'ACCEPT'
check 85_dfa_minimization_equivalence '' 'Classes: 0 1 0 1'
check 86_postfix_to_prefix 'a b + c *' '* + a b c'
check 87_tac_use_def 't = x + y' 'USE: x y'
check 88_constant_folding_ir 't = 3 * 7' 't = 21'
check 89_cfg_reverse_postorder $'3 2\n0 1\n1 2' 'RPO: 0 1 2'
check 90_basic_block_partition '6 2 2 4' 'B2: [4,5]'
echo '10 sample checks completed'
