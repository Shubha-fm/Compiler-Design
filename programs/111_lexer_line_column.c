/* Track identifier tokens with one-based line and column numbers. */
#include <stdio.h>
#include <ctype.h>
int main(void){int c,line=1,col=1;while((c=getchar())!=EOF){if(isalpha((unsigned char)c)||c=='_'){int start=col,n=0;char name[128];do{if(n<127)name[n++]=(char)c;col++;c=getchar();}while(c!=EOF&&(isalnum((unsigned char)c)||c=='_'));name[n]=0;printf("%d:%d %s\n",line,start,name);if(c==EOF)break;ungetc(c,stdin);continue;}if(c=='\n'){line++;col=1;}else col++;}return 0;}