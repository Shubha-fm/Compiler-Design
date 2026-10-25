/* Transitive unit productions for a chain A->B, B->C, C->a.
   Demonstrates removal with resulting terminal rules. */
#include <stdio.h>
int main(void){puts("Before: A->B; B->C; C->a");puts("After: A->a; B->a; C->a");return 0;}