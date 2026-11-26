/* Count C-like identifiers and integers; // comments are ignored.
   Handles ASCII and digits only; string literals are not parsed. */
#include <stdio.h>
#include <ctype.h>
int main(void){int c,ids=0,nums=0;while((c=getchar())!=EOF){
if(c=='/' ){int d=getchar();if(d=='/'){while((c=getchar())!=EOF&&c!='\n'){}continue;}if(d!=EOF)ungetc(d,stdin);}
if(isalpha((unsigned char)c)||c=='_'){ids++;while((c=getchar())!=EOF&&(isalnum((unsigned char)c)||c=='_')){}if(c!=EOF)ungetc(c,stdin);}
else if(isdigit((unsigned char)c)){nums++;while((c=getchar())!=EOF&&isdigit((unsigned char)c)){}if(c!=EOF)ungetc(c,stdin);}
}printf("identifiers=%d integers=%d\n",ids,nums);return 0;}