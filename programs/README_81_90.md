# Compiler Design programs 81–90

Ten additional C11 educational examples, located in this directory.

| File | Topic | Scope |
|---|---|---|
| 81_nullable_first_symbol.c | FIRST of a sequence | Given nullable flags and one FIRST terminal per nonterminal |
| 82_eliminate_unit_productions.c | Unit productions | Hardcoded transitive chain illustration |
| 83_remove_unreachable_nonterminals.c | Reachable grammar symbols | Hardcoded production graph |
| 84_dfa_product_intersection.c | DFA intersection | Ends in zero and has even one parity |
| 85_dfa_minimization_equivalence.c | DFA partition refinement | Fixed four-state example |
| 86_postfix_to_prefix.c | Expression conversion | Space-delimited binary operators |
| 87_tac_use_def.c | Intermediate-code analysis | Single-character variables |
| 88_constant_folding_ir.c | TAC constant folding | One integer operation; may overflow |
| 89_cfg_reverse_postorder.c | CFG DFS | Vertices reachable from entry 0 |
| 90_basic_block_partition.c | Basic block partitioning | User-supplied leader positions |

## Build and test

```bash
gcc -std=c11 -Wall -Wextra -pedantic programs/84_dfa_product_intersection.c -o dfa
echo 110 | ./dfa
bash tests/test_programs_81_90.sh
```

The test script provides one representative case per program. Fixed examples are labeled and do not implement arbitrary grammar transformations.
