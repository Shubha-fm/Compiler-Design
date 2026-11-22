/* Scan a single line into identifiers, integer numbers and punctuation tokens.
   Every token reports its starting byte column (one-based). */
#include <stdio.h>
#include <ctype.h>
int main(void){char line[1024];if(!fgets(line,sizeof line,stdin))return 1;
for(int i=0;line[i]&&line[i]!='\n';){unsigned char c=(unsigned char)line[i];if(isspace(c)){i++;continue;}
int start=i;if(isalpha(c)||c=='_'){i++;while(isalnum((unsigned char)line[i])||line[i]=='_')i++;printf("IDENT %.*s col=%d\n",i-start,line+start,start+1);}
else if(isdigit(c)){i++;while(isdigit((unsigned char)line[i]))i++;printf("INT %.*s col=%d\n",i-start,line+start,start+1);}
else{printf("PUNCT %c col=%d\n",line[i],i+1);i++;}}
return 0;}
