/* Operator-precedence evaluation by two stacks; syntax acceptance for digits and +,*,(). */
#include <stdio.h>
#include <ctype.h>
static int prec(char x){return x=='+'?1:x=='*'?2:0;}
int main(void){char s[256],op[256];int values=0,top=0,expect=1,ok=1;if(!fgets(s,sizeof s,stdin))return 1;
for(int i=0;s[i]&&ok;){char c=s[i];if(isspace((unsigned char)c)){i++;continue;}if(isdigit((unsigned char)c)&&expect){while(isdigit((unsigned char)s[i]))i++;values++;expect=0;}
else if(c=='('&&expect){op[top++]=c;i++;}
else if(c==')'&&!expect){while(top&&op[top-1]!='('){top--;values--;}if(!top||values<1)ok=0;else top--;i++;}
else if((c=='+'||c=='*')&&!expect){while(top&&op[top-1]!='('&&prec(op[top-1])>=prec(c)){top--;values--;if(values<1)ok=0;}op[top++]=c;expect=1;i++;}
else ok=0;}
while(top&&ok){if(op[--top]=='(')ok=0;else{values--;if(values<1)ok=0;}}
puts(ok&&!expect&&values==1?"ACCEPT":"REJECT");return 0;}
