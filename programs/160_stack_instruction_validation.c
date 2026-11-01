/* Validate stack bytecode: PUSH integer, ADD, SUB, MUL, PRINT, HALT. */
#include <stdio.h>
#include <string.h>
int main(void){char op[32];int depth=0;while(scanf("%31s",op)==1){if(!strcmp(op,"PUSH")){long x;if(scanf("%ld",&x)!=1)return 1;(void)x;depth++;}else if(!strcmp(op,"ADD")||!strcmp(op,"SUB")||!strcmp(op,"MUL")){if(depth<2){puts("STACK UNDERFLOW");return 0;}depth--;}else if(!strcmp(op,"PRINT")){if(!depth){puts("STACK UNDERFLOW");return 0;}}else if(!strcmp(op,"HALT")){puts("VALID");return 0;}else{puts("INVALID OPCODE");return 0;}}puts("MISSING HALT");return 0;}