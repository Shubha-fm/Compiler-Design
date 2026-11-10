/* Report inclusive-exclusive byte spans of identifiers on one input line. */
#include <stdio.h>
#include <ctype.h>
int main(void){char s[1024];if(!fgets(s,sizeof s,stdin))return 1;
for(int i=0;s[i];){unsigned char c=(unsigned char)s[i];
if(isalpha(c)||c=='_'){int a=i++;while(isalnum((unsigned char)s[i])||s[i]=='_')i++;printf("ID %.*s [%d,%d)\n",i-a,s+a,a,i);}
else if(isdigit(c)){do{i++;}while(isdigit((unsigned char)s[i]));}
else i++;}return 0;}