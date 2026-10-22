# SLR(1), CLR(1), LALR(1) in C

The shared **lr_parser.c** engine constructs item automata and ACTION/GOTO tables to recognize inputs in three modes.

- SLR: LR(0) item closure and FOLLOW-based reductions.
- CLR: canonical LR(1) items and lookahead propagation.
- LALR: canonical LR(1) states merged by identical LR(0) cores, unioning lookaheads.

Conflicts are reported, not silently resolved.

## Compile and run

```sh
cd parsers/lr_family
gcc -std=c11 -Wall -Wextra -Werror -pedantic lr_parser.c -o lr_parser
./lr_parser slr grammars/slr.txt cdd
./lr_parser clr grammars/assignment.txt 'i=i'
./lr_parser lalr grammars/assignment.txt '*i=i'
./lr_parser slr grammars/assignment.txt 'i=i'  # expected CONFLICT, exit 3
bash test_lr_family.sh
```

## Grammar format

First line: number of productions. Each subsequent line: `A->rhs`; uppercase nonterminals, single-character terminals, and `A->#` for epsilon. First production's LHS is the start symbol. `$` is reserved.

```text
3
S->CC
C->cC
C->d
```

## Test coverage

25 checks across acceptance, rejection, empty strings, and expected SLR conflict. Three fixture grammars are included.

## Limits

Teaching implementation, not Bison/Yacc: max 63 productions, max RHS 31 symbols, max 256 states, max 512 items per state, single-character grammar symbols, no lexer, precedence directives, recovery rules, or generated AST. Checks are illustrative, not exhaustive.
