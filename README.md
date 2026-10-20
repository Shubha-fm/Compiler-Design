# Compiler Design Programs in C

A collection of **50 numbered C programs** and **12 additional parser examples** for learning compiler construction. Topics include lexical analysis, automata, grammars, top-down and bottom-up parsing, intermediate code generation, optimization, and introductory code analysis.

> **Educational scope:** Each program is a standalone example. Several use fixed grammars or demonstrate a single transformation. This repository is not a complete C compiler or a general-purpose parser-generator toolkit.

## Repository structure

```text
Compiler-Design/
├── 01_lexical_analysis.c ... 20_dfa_binary_suffix.c   # Original programs 01–20
├── programs/
│   └── 21_keyword_lookup.c ... 50_expression_ast.c    # Additional programs 21–50
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

## Parser collection

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

CYK and Earley are **general chart-parsing approaches**, not LR shift-reduce algorithms. These examples use fixed grammars. Canonical LR(1), LALR(1), GLR, and automatic parse-table generation have **not** been added.

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
