#include <stdio.h>
#include <string.h>
int main(void){
 char op[8];const char *ops[]={"+","-","*","/","%","=","==","!=","<",">","<=",">=","&&","||","!","++","--","+=","-="};
 puts("Enter an operator:");if(scanf("%7s",op)!=1)return 1;
 for(size_t i=0;i<sizeof ops/sizeof ops[0];i++)if(!strcmp(op,ops[i])){puts("Recognized operator");return 0;}
 puts("Unknown operator");return 0;
}