# Compiler Design Programs in C

20 standalone educational C programs for compiler construction labs.

## Compile and run

```bash
gcc -std=c11 -Wall -Wextra 01_lexical_analysis.c -o lexer
./lexer
```

Replace the source filename and output name to build any other program. Each file has its own `main` function and is compiled separately.

## Contents

1. `01_lexical_analysis.c`
2. `02_count_tokens.c`
3. `03_identifier_validator.c`
4. `04_remove_comments.c`
5. `05_operator_recognition.c`
6. `06_symbol_table.c`
7. `07_first_sets.c`
8. `08_follow_sets.c`
9. `09_recursive_descent_parser.c`
10. `10_shift_reduce_parser.c`
11. `11_ll1_table_parser.c`
12. `12_left_recursion_elimination.c`
13. `13_left_factoring.c`
14. `14_postfix_conversion.c`
15. `15_postfix_evaluation.c`
16. `16_three_address_code.c`
17. `17_constant_folding.c`
18. `18_dead_code_elimination.c`
19. `19_common_subexpression_elimination.c`
20. `20_dfa_binary_suffix.c`

## Scope

These are introductory lab examples. Programs 08, 12, 13, 16, 18, and 19 demonstrate fixed grammars or transformations rather than fully general algorithms. The lexical analyzer and comment removal example are simplified and not complete C-language parsers.
