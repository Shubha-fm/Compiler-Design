#include <stdio.h>
#include <ctype.h>
int main(void){
 char s[256];puts("Enter identifier:");if(scanf("%255s",s)!=1)return 1;
 if(!(isalpha((unsigned char)s[0])||s[0]=='_')){puts("Invalid");return 0;}
 for(int i=1;s[i];i++)if(!(isalnum((unsigned char)s[i])||s[i]=='_')){puts("Invalid");return 0;}
 puts("Valid identifier");return 0;
}