# New Compiler Design Programs 71–80

Ten C11 lab exercises added to the existing repository.

| Program | Topic |
|---|---|
| 71 | Whitespace normalization |
| 72 | Octal integer literal recognition |
| 73 | Simplified string literal validation |
| 74 | Token positions and spans |
| 75 | DFA rejecting adjacent ones |
| 76 | Infix to postfix translation for + and * |
| 77 | Constant-condition branch pruning |
| 78 | Control-flow graph successor lists |
| 79 | Stack-frame local variable offsets |
| 80 | Three-address code to stack-machine pseudocode |

Build one program at a time:

```bash
gcc -std=c11 -Wall -Wextra programs/75_dfa_no_consecutive_ones.c -o dfa
echo 1010 | ./dfa
bash tests/test_programs_71_80.sh
```

These are bounded educational examples, not full language implementations. The test script contains ten smoke tests. It does not establish exhaustive correctness.
