/* C keyword comparison is case-sensitive. */
#include <stdio.h>
#include <string.h>
int main(void){char w[64];if(scanf("%63s",w)!=1)return 1;puts(!strcmp(w,"while")||!strcmp(w,"return")||!strcmp(w,"int")?"KEYWORD":"IDENTIFIER");return 0;}