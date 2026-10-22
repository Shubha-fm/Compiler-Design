# Top-down and bottom-up parser lab (C)

This folder adds **12 standalone parser examples**, separate from programs 01–50.

## Build and test

```bash
gcc -std=c11 -Wall -Wextra -pedantic parsers/top_down/01_recursive_descent.c -o parser
echo 'a+b*c' | ./parser
bash parsers/test_parsers.sh
```

Test script compiles with `-Werror` and checks 24 positive/negative input cases. Requires Bash and GCC or a compatible C11 compiler.

## Top-down parsing

| File | Technique | Supported grammar / language |
|---|---|---|
| 01_recursive_descent.c | Hand-written recursive descent | Standard arithmetic identifiers, parentheses, + - * / |
| 02_predictive_ll1.c | Stack/table LL(1) | S -> aS / b |
| 03_backtracking_parser.c | Backtracking descent | S -> ab / ac |
| 04_precedence_climbing.c | Precedence climbing | Arithmetic expressions, left-associative binary operators |
| 05_pratt_parser.c | Pratt top-down operator precedence | Arithmetic with unary -, + - * / ^ |
| 06_peg_ordered_choice.c | PEG recognition demonstration | 'a' ('b' / 'c') end-of-input |

## Bottom-up parsing and general chart recognition

| File | Technique | Supported grammar / language |
|---|---|---|
| 01_shift_reduce.c | Shift/reduce | E -> E + E / i, implemented as i(+i)* |
| 02_operator_precedence.c | Operator precedence stacks | Integers, +, *, parentheses |
| 03_lr0.c | LR(0) states and reductions | S -> aS / b |
| 04_slr1.c | SLR(1) action/goto table | S -> CC; C -> cC / d |
| 05_cyk.c | CYK dynamic programming (CNF) | S -> AB / BC; A -> BA / a; B -> CC / b; C -> AB / a |
| 06_earley.c | Earley chart recognition | S -> aS / b |

**Important:** The SLR(1) and LR(0) examples use fixed tables for stated grammars, not automatic parser-table construction. CYK and Earley are chart-based recognizers, not LR shift/reduce parsers. The PEG example is for one explicitly coded grammar, not a PEG generator.

A reusable **SLR(1), canonical LR(1) (CLR), and LALR(1)** table-building implementation is now available in [lr_family/](lr_family/), along with grammars and 25 automated checks. GLR and unrestricted parser-generator features remain outside scope. These examples are educational and do not claim complete coverage of every parser variant.
