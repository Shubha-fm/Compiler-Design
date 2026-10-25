# Compiler Design Programs 91–100

Ten additional standalone C11 exercises, with one representative test each.

| Program | Description |
|---|---|
| 91 | Productive nonterminals for a fixed CFG |
| 92 | Complement of a binary DFA |
| 93 | Symmetric difference of two binary DFAs |
| 94 | Fixed-point grammar nullability example |
| 95 | Predecessor lists of a control-flow graph |
| 96 | DFS back-edge detection |
| 97 | Dead-store elimination for two constant assignments |
| 98 | Straight-line SSA-style assignment numbering |
| 99 | Small stack machine bytecode interpreter |
| 100 | Simple binary arithmetic type checker |

Run:

```bash
bash tests/test_programs_91_100.sh
```

For individual programs:

```bash
gcc -std=c11 -Wall -Wextra -pedantic programs/100_expression_type_checker.c -o typecheck
echo 'int + float' | ./typecheck
```

These are educational examples with deliberately narrow input languages. The test script includes representative smoke tests and is not an exhaustive correctness guarantee.
