/* Net and minimum stack depth for a sequence of symbolic instructions.
   PUSH +1; POP -1; DUP +1 but requires existing item; ADD -1 requires 2. */
#include <stdio.h>
#include <string.h>
int main(void){char op[16];int d=0,peak=0;while(scanf("%15s",op)==1){if(!strcmp(op,"PUSH"))d++;else if(!strcmp(op,"POP")){if(d<1){puts("UNDERFLOW");return 0;}d--;}else if(!strcmp(op,"DUP")){if(d<1){puts("UNDERFLOW");return 0;}d++;}else if(!strcmp(op,"ADD")){if(d<2){puts("UNDERFLOW");return 0;}d--;}else{puts("INVALID");return 0;}if(d>peak)peak=d;}printf("final=%d peak=%d\n",d,peak);return 0;}