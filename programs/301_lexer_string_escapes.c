/* Validate one double-quoted ASCII string literal, including common escapes.
   Input is one whole line. Accepts \\, \", \n, \t and \r escapes. */
#include <stdio.h>
#include <string.h>
int main(void){char s[1024];if(!fgets(s,sizeof s,stdin))return 1;
size_t n=strcspn(s,"\r\n");s[n]=0;
if(n<2||s[0]!='"'||s[n-1]!='"'){puts("INVALID");return 0;}
for(size_t i=1;i+1<n;i++){unsigned char c=(unsigned char)s[i];
if(c=='"'){puts("INVALID");return 0;}
if(c=='\\'){if(i+2>=n){puts("INVALID");return 0;}char esc=s[++i];
if(esc!='\\'&&esc!='"'&&esc!='n'&&esc!='t'&&esc!='r'){puts("INVALID");return 0;}}
else if(c<32){puts("INVALID");return 0;}}
puts("VALID");return 0;}
