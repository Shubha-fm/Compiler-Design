/* Fixed-point nullability for S->AB, A->epsilon, B->C, C->epsilon. */
#include <stdio.h>
int main(void){int s=0,a=0,b=0,c=0,changed=1;while(changed){changed=0;if(!a){a=1;changed=1;}if(!c){c=1;changed=1;}if(c&&!b){b=1;changed=1;}if(a&&b&&!s){s=1;changed=1;}}printf("S=%d A=%d B=%d C=%d\n",s,a,b,c);return 0;}