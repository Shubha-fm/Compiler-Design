/* Validate decimal integer tokens allowing separators only between digits. */
#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main(void){char s[256];if(scanf("%255s",s)!=1)return 1;size_t n=strlen(s);int valid=n>0;
for(size_t i=0;i<n;i++){unsigned char c=s[i];if(c=='_'){if(i==0||i+1==n||!isdigit((unsigned char)s[i-1])||!isdigit((unsigned char)s[i+1]))valid=0;}else if(!isdigit(c))valid=0;}
puts(valid?"VALID":"INVALID");return 0;}