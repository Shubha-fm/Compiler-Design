/* LL(1) recognizer for grammar S -> (S)S | epsilon.
Print ACCEPT or REJECT; arbitrary whitespace is ignored. */
#include <stdio.h>
int main(void){char src[512],stack[1024];int n=0,top=0;
if(!fgets(src,sizeof src,stdin))return 1;
for(int i=0;src[i];i++)if(src[i]!=' '&&src[i]!='\t'&&src[i]!='\r'&&src[i]!='\n'){if(src[i]!='('&&src[i]!=')'){puts("REJECT");return 0;}src[n++]=src[i];}
src[n]=0;stack[top++]='$';stack[top++]='S';int pos=0,steps=0;
while(top&&steps++<2048){char x=stack[--top],c=pos<n?src[pos]:'$';
if(x=='S'){if(c=='('){if(top+4>=1024)return 1;stack[top++]='S';stack[top++]=')';stack[top++]='S';stack[top++]='(';}else if(c==')'||c=='$'){}else{puts("REJECT");return 0;}}
else if(x==c){if(x!='$')pos++;}
else{puts("REJECT");return 0;}}
puts(!top&&pos==n?"ACCEPT":"REJECT");return 0;}