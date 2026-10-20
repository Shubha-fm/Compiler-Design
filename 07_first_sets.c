#include <stdio.h>
#include <ctype.h>
#include <string.h>
/* Grammar: E->TR, R->+TR|#, T->FY, Y->*FY|#, F->(E)|i ; # epsilon */
const char *rhs[]={"TR","+TR","#","FY","*FY","#","(E)","i"};
const char lhs[]={'E','R','R','T','Y','Y','F','F'};
int first[26][128],busy[26];
void compute(char x){
 int a=x-'A';if(busy[a])return;busy[a]=1;
 for(int i=0;i<8;i++)if(lhs[i]==x){
  const char *p=rhs[i];int nullable=1;
  for(int j=0;p[j]&&nullable;j++){
   nullable=0;
   if(!isupper((unsigned char)p[j])){first[a][(unsigned char)p[j]]=1;if(p[j]=='#')nullable=1;}
   else{compute(p[j]);int b=p[j]-'A';for(int k=0;k<128;k++)if(k!='#'&&first[b][k])first[a][k]=1;nullable=first[b]['#'];}
  }
  if(nullable)first[a]['#']=1;
 }
}
int main(void){
 const char *nt="ERTYF";for(int i=0;nt[i];i++)compute(nt[i]);
 for(int i=0;nt[i];i++){printf("FIRST(%c) = { ",nt[i]);for(int k=0;k<128;k++)if(first[nt[i]-'A'][k])printf("%c ",k);puts("}");}return 0;
}