/* Tiny lexer: classify identifiers, integers, and single-character punctuation. */
#include <stdio.h>
#include <ctype.h>
int main(void){char s[512];if(!fgets(s,sizeof s,stdin))return 1;for(int i=0;s[i];){unsigned char c=s[i];if(isspace(c)){i++;continue;}int begin=i;if(isalpha(c)||c=='_'){do{i++;c=(unsigned char)s[i];}while(isalnum(c)||c=='_');printf("ID %.*s\n",i-begin,s+begin);}else if(isdigit(c)){do{i++;c=(unsigned char)s[i];}while(isdigit(c));printf("INT %.*s\n",i-begin,s+begin);}else{printf("PUNC %c\n",s[i]);i++;}}return 0;}