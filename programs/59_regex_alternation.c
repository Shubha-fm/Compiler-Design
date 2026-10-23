/* Recognize exactly 'ab' or 'ba': regex ab|ba. */
#include <stdio.h>
#include <string.h>
int main(void){char s[128];if(scanf("%127s",s)!=1)return 1;puts(!strcmp(s,"ab")||!strcmp(s,"ba")?"ACCEPT":"REJECT");return 0;}