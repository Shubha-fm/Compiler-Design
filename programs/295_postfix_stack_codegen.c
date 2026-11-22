/* Translate a single-character postfix arithmetic expression to
   illustrative stack bytecode. Operands are digits or letters. */
#include <stdio.h>
#include <ctype.h>
int main(void){char expression[256];int depth=0;if(scanf("%255s",expression)!=1)return 1;
for(int i=0;expression[i];i++){unsigned char c=(unsigned char)expression[i];
if(isalnum(c)){printf("PUSH %c\n",c);depth++;}
else if(c=='+'||c=='-'||c=='*'||c=='/'){if(depth<2){puts("INVALID EXPRESSION");return 0;}depth--;printf("%s\n",c=='+'?"ADD":c=='-'?"SUB":c=='*'?"MUL":"DIV");}
else{puts("INVALID EXPRESSION");return 0;}}
puts(depth==1?"HALT":"INVALID EXPRESSION");return 0;}
