#include <stdio.h>
#include <ctype.h>
int main(void){
 char s[2048];int words=0,numbers=0,symbols=0;
 puts("Enter text:");if(!fgets(s,sizeof s,stdin))return 1;
 for(int i=0;s[i];){
  if(isspace((unsigned char)s[i])){i++;continue;}
  if(isalpha((unsigned char)s[i])||s[i]=='_'){words++;while(isalnum((unsigned char)s[i])||s[i]=='_')i++;}
  else if(isdigit((unsigned char)s[i])){numbers++;while(isdigit((unsigned char)s[i]))i++;}
  else{symbols++;i++;}
 }
 printf("Identifiers/words: %d\nNumbers: %d\nSymbols: %d\n",words,numbers,symbols);return 0;
}