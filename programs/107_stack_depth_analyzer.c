/* Compute peak stack depth and detect underflow for PUSH/POP token stream. */
#include <stdio.h>
#include <string.h>
int main(void){char cmd[16];int d=0,max=0;while(scanf("%15s",cmd)==1){if(!strcmp(cmd,"PUSH")){d++;if(d>max)max=d;}else if(!strcmp(cmd,"POP")){if(!d){puts("UNDERFLOW");return 0;}d--;}else{puts("INVALID");return 0;}}printf("peak=%d final=%d\n",max,d);return 0;}