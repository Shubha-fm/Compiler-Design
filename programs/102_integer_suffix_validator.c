/* Check simplified decimal C integer suffix: u, l, ll, ul, ull, lu, llu (case-insensitive). */
#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main(void){char s[128],tail[8];if(scanf("%127s",s)!=1)return 1;int i=0,j=0;while(isdigit((unsigned char)s[i]))i++;if(!i){puts("INVALID");return 0;}while(s[i]&&j<7)tail[j++]=tolower((unsigned char)s[i++]);tail[j]=0;const char *allowed[]={"","u","l","ll","ul","ull","lu","llu"};int ok=!s[i];for(int k=0;k<8;k++)if(!strcmp(tail,allowed[k])&&ok){puts("VALID");return 0;}puts("INVALID");return 0;}