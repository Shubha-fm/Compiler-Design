/* Count instructions by opcode in a simple IR token stream. */
#include <stdio.h>
#include <string.h>
int main(void){char op[32];int load=0,store=0,add=0,other=0;while(scanf("%31s",op)==1){if(!strcmp(op,"LOAD"))load++;else if(!strcmp(op,"STORE"))store++;else if(!strcmp(op,"ADD"))add++;else other++;}printf("LOAD=%d STORE=%d ADD=%d OTHER=%d\n",load,store,add,other);return 0;}