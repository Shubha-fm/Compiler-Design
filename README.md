# Compiler Design Programs in C

A collection of **270 numbered C programs** and **12 additional parser examples** for learning compiler construction. Topics include lexical analysis, automata, grammars, top-down and bottom-up parsing, intermediate code generation, optimization, and introductory code analysis.

> **Educational scope:** Each program is a standalone example. Several use fixed grammars or demonstrate a single transformation. This repository is not a complete C compiler or a general-purpose parser-generator toolkit.

## Repository structure

```text
Compiler-Design/
├── 01_lexical_analysis.c ... 20_dfa_binary_suffix.c   # Original programs 01–20
├── programs/
│   └── 21_keyword_lookup.c ... 270_lr_parse_action_decoder.c    # Additional programs 21–270
├── parsers/
│   ├── top_down/                                      # Six top-down examples
│   ├── bottom_up/                                     # Six bottom-up/chart examples
│   ├── test_parsers.sh
│   └── README.md
├── tests/
│   └── test_new_programs.sh
├── PROGRAMS_21_50.md
└── README.md
```

## Program catalog

| Programs | Topics | Location |
|---|---|---|
| 01–06 | Lexical analysis, tokens, identifiers, operators, comments, symbol tables | Repository root |
| 07–13 | FIRST/FOLLOW, recursive descent, LL(1), shift-reduce, left recursion, left factoring | Repository root |
| 14–20 | Postfix conversion/evaluation, TAC, optimization examples, DFA | Repository root |
| 21–27 | Keyword and literal recognition, delimiter checking, text processing | [programs/](programs/) |
| 28–33 | NFA, DFA, regular and context-free language recognition | [programs/](programs/) |
| 34–38 | Prefix expressions, TAC, quadruples, triples, pseudo-assembly | [programs/](programs/) |
| 39–47 | Algebraic simplification, strength reduction, control flow, register assignment, propagation | [programs/](programs/) |
| 48–50 | Error recovery, nullable nonterminals, expression AST | [programs/](programs/) |

See [Programs 21–50 guide](PROGRAMS_21_50.md) for example inputs and expected outputs.

## Parser collections

The dedicated [parsers/](parsers/) directory contains **12 implementations**.

### Top-down

| Parser | Source |
|---|---|
| Recursive descent | [01_recursive_descent.c](parsers/top_down/01_recursive_descent.c) |
| Predictive LL(1) | [02_predictive_ll1.c](parsers/top_down/02_predictive_ll1.c) |
| Backtracking recursive descent | [03_backtracking_parser.c](parsers/top_down/03_backtracking_parser.c) |
| Precedence climbing | [04_precedence_climbing.c](parsers/top_down/04_precedence_climbing.c) |
| Pratt / top-down operator precedence | [05_pratt_parser.c](parsers/top_down/05_pratt_parser.c) |
| PEG ordered-choice example | [06_peg_ordered_choice.c](parsers/top_down/06_peg_ordered_choice.c) |

### Bottom-up and chart-based

| Parser | Source |
|---|---|
| Shift-reduce | [01_shift_reduce.c](parsers/bottom_up/01_shift_reduce.c) |
| Operator precedence | [02_operator_precedence.c](parsers/bottom_up/02_operator_precedence.c) |
| LR(0) | [03_lr0.c](parsers/bottom_up/03_lr0.c) |
| SLR(1) | [04_slr1.c](parsers/bottom_up/04_slr1.c) |
| CYK (chart/dynamic programming) | [05_cyk.c](parsers/bottom_up/05_cyk.c) |
| Earley (chart parsing) | [06_earley.c](parsers/bottom_up/06_earley.c) |

CYK and Earley are **general chart-parsing approaches**, not LR shift-reduce algorithms. These examples use fixed grammars. SLR(1), canonical LR(1) (CLR), and LALR(1) table construction are now available in [parsers/lr_family/](parsers/lr_family/). GLR and general-purpose parser-generator features are not included.

Read [the parser guide](parsers/README.md) for the exact supported grammars.

## Requirements

- C11 compiler, such as GCC or Clang
- Bash for the included test scripts (Linux, macOS, or Git Bash/WSL on Windows)

## Compile and run

Each C source file has its own `main()` and should be compiled **individually**.

```bash
# Original lexical analyzer
gcc -std=c11 -Wall -Wextra 01_lexical_analysis.c -o lexer
./lexer

# Program 21: keyword lookup
gcc -std=c11 -Wall -Wextra programs/21_keyword_lookup.c -o keywords
echo "int" | ./keywords

# A top-down parser
gcc -std=c11 -Wall -Wextra parsers/top_down/01_recursive_descent.c -o rd_parser
echo "a+b*c" | ./rd_parser

# An LR(0) example
gcc -std=c11 -Wall -Wextra parsers/bottom_up/03_lr0.c -o lr0_parser
echo "aaab" | ./lr0_parser
```

On Windows, replace `./program` with `program.exe` as appropriate.

## Tests

Two Bash smoke-test scripts are provided:

```bash
bash tests/test_new_programs.sh   # 30 representative checks for programs 21–50
bash parsers/test_parsers.sh       # 24 positive/negative parser test cases
```

These tests compile sources and compare outputs for representative inputs. The tests are included in the repository; **a successful run is not claimed here**. They do not exhaustively validate every input or cover the original 20 programs.

## Limitations and learning goals

- Some examples implement a specific grammar or show fixed transformation steps rather than accept arbitrary grammar definitions.
- Parsers focus on recognizing input strings; most do not construct ASTs or provide detailed syntax diagnostics.
- Several optimizations illustrate a local rule rather than full control/data-flow optimization.
- Inputs have fixed buffer limits. Not all malformed inputs, overflow cases, strings, comments, or real C syntax are supported.
- The repository is best used for compiler-design coursework, experimenting with parsing techniques, and studying small, understandable C programs.

## Contributing

Contributions with new implementations, corrected algorithms, explanatory comments, and reproducible tests are welcome. Please document the grammar/input format, include at least one accepted and one rejected example where relevant, and compile with `-std=c11 -Wall -Wextra -pedantic`.

## Repository

Maintained at [Shubha-fm/Compiler-Design](https://github.com/Shubha-fm/Compiler-Design).

## SLR(1), CLR(1), and LALR(1) parser generator

The [LR-family C implementation](parsers/lr_family/README.md) includes ACTION/GOTO table construction, three example grammars, expected conflict detection, and 25 automated checks.

```bash
bash parsers/lr_family/test_lr_family.sh
```

## New programs 51–70

Twenty additional C11 examples cover scanner utilities, literal recognition, finite-state transducers, parsing-tree traversal, TAC, indirect triples, short-circuit code, DAG reuse, dominators, reaching definitions, and backward liveness.

- [Programs 51–70 catalog](programs/README_51_70.md)
- [Sample test script](tests/test_programs_51_70.sh)

```bash
bash tests/test_programs_51_70.sh
```

These are limited educational implementations. Passing representative sample tests is not a substitute for exhaustive validation.

## New programs 71–80

Ten further C11 examples have been added to [programs/](programs/):

- **71–74:** whitespace normalization, octal literals, string literal checking, and source token offsets.
- **75–76:** DFA avoiding consecutive ones and infix-to-postfix translation.
- **77–80:** constant branch pruning, CFG successor lists, stack-frame offsets, and TAC-to-stack-code translation.

Read the [71–80 program guide](programs/README_71_80.md) for scope and compilation examples.

### Test the latest programs

```bash
bash tests/test_programs_71_80.sh
```

The ten smoke tests cover representative inputs, but they have not been established as an exhaustive correctness guarantee.

## New programs 81–90

Ten additional C11 programs extend the grammar, automata, intermediate-code, and control-flow sections:

| Number | Topic |
|---|---|
| 81–83 | Nullable/FIRST sequence example, unit production elimination demonstration, unreachable nonterminal identification |
| 84–85 | DFA intersection and fixed-example partition-refinement minimization |
| 86–88 | Postfix-to-prefix conversion, TAC use/def extraction, TAC constant folding |
| 89–90 | CFG reverse postorder and basic-block partitioning |

- [Programs 81–90 documentation](programs/README_81_90.md)
- [Programs 81–90 tests](tests/test_programs_81_90.sh)

```bash
bash tests/test_programs_81_90.sh
```

Some new examples demonstrate **fixed** grammars and automata, rather than accepting arbitrary definitions. The test cases are illustrative; they do not establish exhaustive correctness.

## New programs 91–100

Ten additional C11 examples cover grammar productivity and nullability, DFA complement and symmetric difference, CFG predecessors and DFS back edges, dead-store elimination, SSA-style renaming, stack-machine interpretation, and arithmetic type checking.

- [Programs 91–100 guide](programs/README_91_100.md)
- [Programs 91–100 smoke tests](tests/test_programs_91_100.sh)

```bash
bash tests/test_programs_91_100.sh
```

The examples are educational, with restricted inputs. Test cases are provided but are not an exhaustive validation of compiler correctness.

## New programs 101–110

Ten additional C11 examples focus on source analysis, diagnostics, automata, intermediate code, and control-flow analysis.

| Numbers | Topics |
|---|---|
| 101–104 | Edit distance for diagnostic hints, literal suffixes, UTF-8 structure, direct left recursion |
| 105–107 | DFA execution trace, constant comparison folding, stack-depth analysis |
| 108–110 | CFG topological ordering, interference edges, and TAC validation |

- [Programs 101–110 documentation](programs/README_101_110.md)
- [Programs 101–110 test script](tests/test_programs_101_110.sh)

```bash
bash tests/test_programs_101_110.sh
```

All ten are educational examples with restricted input formats. The smoke tests are representative only.

## New programs 111–120

Ten additional C11 examples cover source-location tracking, operator recognition, postfix-regex validation, LL(1) FIRST-set conflict checks, parse-tree notation, interval analysis, graph reachability, strongly connected components, three-address swaps, and register pressure.

- [Programs 111–120 guide](programs/README_111_120.md)
- [Programs 111–120 test script](tests/test_programs_111_120.sh)

```bash
bash tests/test_programs_111_120.sh
```

These are focused teaching examples. Tests are illustrative rather than exhaustive.

## New programs 121–130

The latest ten C11 lab programs cover NFA epsilon closure, DFA equivalence, LL(1) conflict checking, dangling-else binding, postfix expression evaluation, constant-copy tracking, natural loops, shortest accepted DFA words, token histograms, and intermediate-code label resolution.

- [Programs 121–130 guide](programs/README_121_130.md)
- [Programs 121–130 smoke tests](tests/test_programs_121_130.sh)

```bash
bash tests/test_programs_121_130.sh
```

The C/C++ CI workflow was intentionally removed and has not been restored. Tests run manually. These examples are educational and use bounded input formats.

## New programs 131–140

Ten additional C11 examples cover token-class compression, identifier patterns, DFA distinguishing words, CNF production checks, LL(1) stack tracing, postfix stack usage, CFG entry/exit analysis, duplicate IR labels, bit-vector data flow, and constant substitution.

- [Programs 131–140 documentation](programs/README_131_140.md)
- [Programs 131–140 sample tests](tests/test_programs_131_140.sh)

```bash
bash tests/test_programs_131_140.sh
```

The removed C/C++ GitHub Actions workflow has not been restored. Run the tests manually. Example programs use restricted grammars and input sizes.

## New programs 141–150

Ten additional C11 examples cover numeric literal bases, regex character ranges, indirect left-recursion cycles, DFA reachable states, postfix expression statistics, immediate dominators, constant branches, live interval interference, IR instruction counting, and arithmetic type conversion.

- [Programs 141–150 documentation](programs/README_141_150.md)
- [Programs 141–150 smoke tests](tests/test_programs_141_150.sh)

```bash
bash tests/test_programs_141_150.sh
```

These are restricted educational examples; the provided smoke tests are not exhaustive. The previously removed C/C++ CI workflow remains absent.

## New programs 151–160

Ten additional C11 examples cover DFA emptiness and language finiteness, prefix-expression validation, useless grammar symbols (fixed demonstration), CFG edge classification, TAC quadruples, live intervals, SSA phi nodes, newline normalization, and stack bytecode validation.

- [Programs 151–160 documentation](programs/README_151_160.md)
- [Programs 151–160 smoke tests](tests/test_programs_151_160.sh)

```bash
bash tests/test_programs_151_160.sh
```

These are bounded teaching examples. The smoke tests are representative, not exhaustive. C/C++ GitHub Actions CI remains removed.

## New programs 161–170

The latest ten C11 exercises cover lexical token classification, unit-production transitive closure, post-dominators, DFA transition coverage, lexical scope lookup, row-major array offsets, register pressure/spill estimates, critical CFG edges, basic TAC code generation, and stack bytecode tracing.

- [Programs 161–170 catalog and examples](programs/README_161_170.md)
- [Programs 161–170 tests](tests/test_programs_161_170.sh)

```bash
bash tests/test_programs_161_170.sh
```

The tests require GCC and Bash and are illustrative; the removed C/C++ CI workflow is not restored.

## New programs 171–180

Ten more C11 examples cover lexical comment counting, DFA rejected-word search, grammar FIRST sequence calculation, undirected bridge analysis, AST height, TAC algebraic identities, interval register allocation, instruction alignment, LR ACTION conflicts, and critical-edge split planning.

- [Programs 171–180 catalog](programs/README_171_180.md)
- [Programs 171–180 test script](tests/test_programs_171_180.sh)

```bash
bash tests/test_programs_171_180.sh
```

These are bounded teaching examples. Smoke tests are included but do not establish exhaustive correctness. The C/C++ GitHub Actions workflow remains removed.

## New programs 181–190

These ten C11 examples cover nested-comment diagnostics, DFA state partition refinement, regex escape validation, grammar left factoring, graph cyclomatic complexity, local common-subexpression elimination, AST postorder traversal, constant comparisons, CFG reverse postorder, and simple code generation.

- [Programs 181–190 documentation](programs/README_181_190.md)
- [Programs 181–190 sample test script](tests/test_programs_181_190.sh)

```bash
bash tests/test_programs_181_190.sh
```

The examples use bounded inputs and simplified semantics. The C/C++ CI workflow remains removed; tests can be run manually.

## New programs 191–200

Ten additional C11 exercises cover keyword boundaries, regex infix/postfix conversion, NFA MOVE, FOLLOW-set contributions, CFG dominance frontiers, reaching definitions, strength reduction, stack effects, CFG adjacency matrices, and a restricted shift/reduce parser trace.

- [Programs 191–200 documentation](programs/README_191_200.md)
- [Programs 191–200 test script](tests/test_programs_191_200.sh)

```bash
bash tests/test_programs_191_200.sh
```

All examples are intended for learning and use deliberately restricted input formats. Tests are illustrative and must be run manually. The previously removed C/C++ CI workflow has not been recreated.

## New programs 201–210

Ten C11 examples cover tab-aware source columns, NFA acceptance, grammar nullability, LL(1) parse table lookups, unreachable CFG blocks, copy propagation, peephole instruction elimination, live-interval interference matrices, AST preorder traversal, and IR jump threading.

- [Programs 201–210 guide](programs/README_201_210.md)
- [Programs 201–210 sample tests](tests/test_programs_201_210.sh)

```bash
bash tests/test_programs_201_210.sh
```

These are bounded teaching examples with simplified semantics. The smoke tests are intended for manual execution. The C/C++ GitHub Actions workflow remains removed.

## New programs 211–220

Ten new C11 examples cover string-literal escape checking, ASCII character classes, multi-state epsilon closure, FIRST/FIRST conflicts, CFG domination queries, liveness-based dead assignment checks, register interval peaks, TAC USE/DEF analysis, parentheses nesting, and scope-aware duplicate declarations.

- [Programs 211–220 guide](programs/README_211_220.md)
- [Programs 211–220 smoke tests](tests/test_programs_211_220.sh)

```bash
bash tests/test_programs_211_220.sh
```

The programs use simplified, bounded inputs and are intended for learning. Tests run manually; the previously removed C/C++ GitHub Actions CI workflow has not been restored.

## New programs 221–230

Ten additional C11 examples cover DFA intersection, NFA subset transitions, CYK parsing, expression precedence, CFG articulation vertices, live-variable fixed-point analysis, constant folding, register graph coloring, hash-backed symbol tables, and bytecode jump-target validation.

- [Programs 221–230 documentation](programs/README_221_230.md)
- [Programs 221–230 manual test script](tests/test_programs_221_230.sh)

```bash
bash tests/test_programs_221_230.sh
```

All programs are bounded teaching examples. No C/C++ GitHub Actions CI workflow was restored. Tests are run manually.

## New programs 231–240

Ten C11 examples introduce postfix-to-infix conversion, generic grammar nullability, shortest DFA state paths, epsilon-expanded NFA moves, grammar dependency ordering, dominance-based back edges, commutative expression reuse, bytecode stack-height checks, nested symbol scopes, and basic-block leader detection.

- [Programs 231–240 documentation](programs/README_231_240.md)
- [Programs 231–240 manual tests](tests/test_programs_231_240.sh)

```bash
bash tests/test_programs_231_240.sh
```

Programs are intentionally bounded educational implementations. The removed C/C++ CI workflow has not been restored.

## New programs 241–250

Ten C11 examples cover source identifier spans, bounded regex repetition, product-DFA reachability, grammar productivity, predictive LL(1) parsing, edge-frequency profiling, constant-propagation lattices, SSA phi arity, register-interference degrees, and basic linker relocation.

- [Programs 241–250 documentation](programs/README_241_250.md)
- [Programs 241–250 sample tests](tests/test_programs_241_250.sh)

```bash
bash tests/test_programs_241_250.sh
```

The programs are teaching examples using bounded inputs, with a manual sample test for each. The C/C++ GitHub Actions CI workflow remains removed.

## New programs 251–260

Ten C11 examples cover comment removal, DFA equivalence classes, epsilon-NFA acceptance, LL(1) SELECT-set conflicts, immediate postdominators, available-expression analysis, algebraic TAC simplification, greedy register spilling, two-pass assembler labels, and bytecode stack-height checking.

- [Programs 251–260 documentation](programs/README_251_260.md)
- [Programs 251–260 sample tests](tests/test_programs_251_260.sh)

```bash
bash tests/test_programs_251_260.sh
```

These are bounded educational programs with simplified semantics. The removed C/C++ GitHub Actions CI workflow has not been restored.

## New programs 261–270

Ten new C11 exercises cover decimal digit separators, DFA complement, CFG reachability counts, nullable production variants, predictive table population, very-busy expressions, TAC triples, linear-scan register allocation, redundant moves, and LR ACTION decoding.

- [Programs 261–270 documentation](programs/README_261_270.md)
- [Programs 261–270 manual tests](tests/test_programs_261_270.sh)

```bash
bash tests/test_programs_261_270.sh
```

These are bounded educational examples, and sample tests should be executed manually. The previously removed C/C++ GitHub Actions workflow has not been restored.
