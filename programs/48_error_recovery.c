/* Panic-mode recovery through semicolon. Educational, limited-scope lab example. */
#include <stdio.h>
#include <string.h>
int main(void){char s[512];if(!fgets(s,sizeof s,stdin))return 1;char *p=strchr(s,';');if(!p){puts("NO SYNCHRONIZATION TOKEN");return 0;}printf("Recovered after %ld characters\n",(long)(p-s+1));return 0;}
