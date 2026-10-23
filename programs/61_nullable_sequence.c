/* Fixed grammar A -> epsilon, B -> epsilon, S -> AB. */
#include <stdio.h>
int main(void){int nullable_a=1,nullable_b=1;printf("nullable(S)=%d\n",nullable_a&&nullable_b);return 0;}