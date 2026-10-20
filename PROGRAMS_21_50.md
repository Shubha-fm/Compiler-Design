# Programs 21–50

30 additional standalone educational C programs. The original programs 01–20 remain at the repository root. Compile each file separately.

```sh
gcc -std=c11 -Wall -Wextra -pedantic programs/21_keyword_lookup.c -o keyword_lookup
echo int | ./keyword_lookup
bash tests/test_new_programs.sh
```

**Coverage:** keyword and literal recognition (21–24); delimiters, text preprocessing (25–27); NFA/DFA and language recognition (28–33); expression parsing and intermediate representations (34–38, 50); elementary optimization demonstrations (39–41, 46–47); control-flow and data-flow examples (42–45); error recovery (48); nullability (49).

| No. | Program | Input format | Purpose |
|---|---|---|---|
| 21 | `21_keyword_lookup.c` | `int` | Expected output includes `KEYWORD` |
| 22 | `22_integer_literal.c` | `-123` | Expected output includes `VALID` |
| 23 | `23_floating_literal.c` | `3.14` | Expected output includes `VALID` |
| 24 | `24_hex_literal.c` | `0xAF` | Expected output includes `VALID` |
| 25 | `25_balanced_delimiters.c` | `{([])}` | Expected output includes `BALANCED` |
| 26 | `26_line_statistics.c` | `hello world` | Expected output includes `11 2 1` |
| 27 | `27_whitespace_normalizer.c` | `a   b  c` | Expected output includes `a b c` |
| 28 | `28_nfa_ends_ab.c` | `aab` | Expected output includes `ACCEPT` |
| 29 | `29_dfa_even_zeros.c` | `001` | Expected output includes `ACCEPT` |
| 30 | `30_dfa_binary_divisible_by_three.c` | `110` | Expected output includes `ACCEPT` |
| 31 | `31_regex_ab_star.c` | `abbb` | Expected output includes `ACCEPT` |
| 32 | `32_grammar_anbn.c` | `aabb` | Expected output includes `ACCEPT` |
| 33 | `33_grammar_palindrome.c` | `abba` | Expected output includes `ACCEPT` |
| 34 | `34_prefix_evaluator.c` | `+ 2 * 3 4` | Expected output includes `14` |
| 35 | `35_tac_for_arithmetic.c` | `a + b * c` | Expected output includes `t1 = b * c` |
| 36 | `36_quadruples.c` | `a + b` | Expected output includes `op=+ arg1=a arg2=b result=t1` |
| 37 | `37_triples.c` | `x * y` | Expected output includes `(0) (*, x, y)` |
| 38 | `38_assembly_generation.c` | `t1 = a + b` | Expected output includes `LOAD R0, a` |
| 39 | `39_algebraic_simplifier.c` | `x * 1` | Expected output includes `x` |
| 40 | `40_strength_reduction.c` | `x 8` | Expected output includes `x << 3` |
| 41 | `41_copy_propagation.c` | `x = 5` | Expected output includes `copy(x) = 5` |
| 42 | `42_unreachable_code.c` | `4 2\n0 1\n1 2` | Expected output includes `Unreachable: 3` |
| 43 | `43_basic_block_leaders.c` | `5 1\n1 4` | Expected output includes `Leaders: 0 2 4` |
| 44 | `44_liveness_sets.c` | `x = y + z` | Expected output includes `DEF={x} USE={y,z}` |
| 45 | `45_register_allocation.c` | `3 2` | Expected output includes `v0 -> R0` |
| 46 | `46_constant_propagation.c` | `4 5` | Expected output includes `y = 9` |
| 47 | `47_loop_invariant_motion.c` | `t = 2 + 3` | Expected output includes `HOISTABLE` |
| 48 | `48_error_recovery.c` | `oops;ok` | Expected output includes `Recovered after 5 characters` |
| 49 | `49_nullable_nonterminal.c` | `ignored` | Expected output includes `A=1 B=1 S=1` |
| 50 | `50_expression_ast.c` | `a + b * c` | Expected output includes `ROOT(+)` |

## Testing

Run `bash tests/test_new_programs.sh` from any directory with GCC and Bash installed. The script builds all 30 programs and checks one representative output per program. Tests are smoke tests, not exhaustive correctness proofs. The examples are purposefully restricted, not production compilers or complete C language implementations.

## Known educational limitations

Programs 35 and 50 accept only three single-character operands; 49 uses a fixed illustrative grammar; 41 and 46 demonstrate copy/constant propagation without full data-flow analysis; 45 reports round-robin assignments but does not implement interference graph coloring; 47 only detects literal-constant expressions rather than arbitrary loop invariants. Invalid expressions, very large inputs, arithmetic overflow, and quoted strings are not comprehensively handled throughout the collection.
