/* Evaluate integer literal comparisons in a conditional intermediate-code expression. */
#include <stdio.h>
#include <string.h>
int main(void){long a,b;char op[4];if(scanf("%ld %3s %ld",&a,op,&b)!=3)return 1;int v;if(!strcmp(op,"<"))v=a<b;else if(!strcmp(op,"<="))v=a<=b;else if(!strcmp(op,">"))v=a>b;else if(!strcmp(op,">="))v=a>=b;else if(!strcmp(op,"=="))v=a==b;else if(!strcmp(op,"!="))v=a!=b;else return 1;printf("constant_condition=%d\n",v);return 0;}