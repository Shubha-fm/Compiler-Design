/* Count identifiers, integers and punctuation in a single source line. */
#include <stdio.h>
#include <ctype.h>
int main(void){char s[1024];if(!fgets(s,sizeof s,stdin))return 1;int id=0,number=0,punc=0;for(int i=0;s[i];){unsigned char x=s[i];if(isspace(x)){i++;continue;}if(isalpha(x)||x=='_'){id++;do{i++;x=(unsigned char)s[i];}while(isalnum(x)||x=='_');}else if(isdigit(x)){number++;do{i++;x=(unsigned char)s[i];}while(isdigit(x));}else{punc++;i++;}}printf("identifiers=%d numbers=%d punctuation=%d\n",id,number,punc);return 0;}