/* Count C-style line and block comments outside quoted strings and characters.
   Simplified escape handling; reads standard input. */
#include <stdio.h>
int main(void){int c,d,state=0,line=0,block=0,escape=0;while((c=getchar())!=EOF){if(state==0){if(c=='"'){state=1;escape=0;}else if(c==39){state=2;escape=0;}else if(c=='/'){d=getchar();if(d=='/'){line++;state=3;}else if(d=='*'){block++;state=4;}else if(d!=EOF)ungetc(d,stdin);}}
else if(state==1||state==2){if(escape)escape=0;else if(c==92)escape=1;else if(c==(state==1?'"':39))state=0;}
else if(state==3){if(c==10)state=0;}else if(state==4){if(c=='*')state=5;}else if(state==5){if(c=='/')state=0;else if(c!='*')state=4;}}
printf("line=%d block=%d\n",line,block);return 0;}