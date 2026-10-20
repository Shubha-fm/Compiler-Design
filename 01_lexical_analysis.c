#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main(void) {
 char s[1024]; const char *kw[]={"int","float","char","if","else","while","for","return","void"};
 puts("Enter a line:"); if(!fgets(s,sizeof s,stdin))return 1;
 for(size_t i=0;s[i];) {
  if(isspace((unsigned char)s[i])){i++;continue;}
  if(isalpha((unsigned char)s[i])||s[i]=='_'){
   char w[128];size_t j=0;while(isalnum((unsigned char)s[i])||s[i]=='_'){if(j<127)w[j++]=s[i];i++;}w[j]=0;
   int k=0;for(int a=0;a<9;a++)if(!strcmp(w,kw[a]))k=1;
   printf("%s: %s\n",k?"KEYWORD":"IDENTIFIER",w);
  }else if(isdigit((unsigned char)s[i])){
   size_t start=i;while(isdigit((unsigned char)s[i])||s[i]=='.')i++;
   printf("NUMBER: %.*s\n",(int)(i-start),s+start);
  }else printf("SYMBOL: %c\n",s[i++]);
 }return 0;
}