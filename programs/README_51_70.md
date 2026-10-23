# Compiler Design Programs 51–70

20 more standalone C11 lab examples. They extend the earlier 50 programs and parser collection without replacing them.

| No. | Source | Educational topic |
|---|---|---|
| 51 | [51_character_frequency.c](51_character_frequency.c) | ASCII character frequency |
| 52 | [52_keyword_case_sensitivity.c](52_keyword_case_sensitivity.c) | Keyword case sensitivity |
| 53 | [53_binary_to_decimal.c](53_binary_to_decimal.c) | Binary-to-decimal conversion |
| 54 | [54_escape_sequence_scanner.c](54_escape_sequence_scanner.c) | Escape sequence validation |
| 55 | [55_scientific_number.c](55_scientific_number.c) | Scientific notation recognition |
| 56 | [56_binary_even_parity.c](56_binary_even_parity.c) | Even-one parity DFA |
| 57 | [57_mealy_parity.c](57_mealy_parity.c) | Mealy parity transducer |
| 58 | [58_moore_parity.c](58_moore_parity.c) | Moore parity machine |
| 59 | [59_regex_alternation.c](59_regex_alternation.c) | Regular-expression alternation recognizer |
| 60 | [60_dfa_contains_101.c](60_dfa_contains_101.c) | Substring-matching DFA |
| 61 | [61_nullable_sequence.c](61_nullable_sequence.c) | Nullable production example |
| 62 | [62_parse_tree_depth.c](62_parse_tree_depth.c) | Parenthesis depth |
| 63 | [63_ast_postorder.c](63_ast_postorder.c) | AST postorder traversal |
| 64 | [64_tac_temporaries.c](64_tac_temporaries.c) | Three-address-code temporaries |
| 65 | [65_indirect_triples.c](65_indirect_triples.c) | Indirect triples |
| 66 | [66_boolean_short_circuit.c](66_boolean_short_circuit.c) | Short-circuit Boolean translation |
| 67 | [67_dag_common_expression.c](67_dag_common_expression.c) | DAG structural expression reuse |
| 68 | [68_control_flow_dominators.c](68_control_flow_dominators.c) | Control-flow dominators |
| 69 | [69_reaching_definitions.c](69_reaching_definitions.c) | Reaching definitions for linear assignments |
| 70 | [70_live_variable_analysis.c](70_live_variable_analysis.c) | Backward live-variable analysis for linear assignments |

## Compile

```bash
gcc -std=c11 -Wall -Wextra -pedantic programs/60_dfa_contains_101.c -o dfa
echo 11011 | ./dfa
```

## Automated sample checks

```bash
bash tests/test_programs_51_70.sh
```

The test suite compiles each source and checks one representative case. It is not an exhaustive proof of correctness. Some programs demonstrate fixed examples instead of general transformations. Control-flow and data-flow programs use small graphs or linear statements with explicit size restrictions. Full compiler frontends and production code generators are outside this collection's scope.
