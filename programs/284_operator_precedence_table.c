/* Generate precedence relations for operators +,-,*,/ from levels.
Equal levels mean left associativity. '=' is not generated. */
#include <stdio.h>
int main(void){const char *ops="+-*/";int levels[]={1,1,2,2};
printf("    + - * /\n");
for(int i=0;i<4;i++){printf("%c : ",ops[i]);for(int j=0;j<4;j++)printf("%c%s",levels[i]<levels[j]?'<':'>',j==3?"":" ");putchar('\n');}
return 0;}