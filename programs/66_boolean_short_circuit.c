/* Generate short-circuit pseudo-code for x && y. */
#include <stdio.h>
int main(void){puts("ifFalse x goto Lfalse");puts("ifFalse y goto Lfalse");puts("result = 1");puts("goto Lend");puts("Lfalse: result = 0");puts("Lend:");return 0;}