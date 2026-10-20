#include <stdio.h>
int main(void){
 long a,b;char op;
 puts("Enter constant expression: number operator number");
 if(scanf("%ld %c %ld",&a,&op,&b)!=3)return 1;
 if(op=='/'&&b==0){puts("Division by zero");return 1;}
 long v;switch(op){case '+':v=a+b;break;case '-':v=a-b;break;case '*':v=a*b;break;case '/':v=a/b;break;default:puts("Unsupported operator");return 1;}
 printf("Folded constant = %ld\n",v);return 0;
}