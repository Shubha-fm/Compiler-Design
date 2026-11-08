/* Reconstruct fully parenthesized infix form of single-character postfix expressions. */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(void){char input[128],stack[128][512];int top=0;if(scanf("%127s",input)!=1)return 1;
for(int i=0;input[i];i++){unsigned char c=(unsigned char)input[i];if(isalnum(c)){stack[top][0]=c;stack[top][1]=0;top++;}
else if(strchr("+-*/",c)){if(top<2){puts("INVALID");return 0;}char right[512],left[512];strcpy(right,stack[--top]);strcpy(left,stack[--top]);int size=snprintf(stack[top],sizeof stack[top],"(%s%c%s)",left,c,right);if(size<0||size>=(int)sizeof stack[top]){puts("TOO LONG");return 0;}top++;}
else{puts("INVALID");return 0;}}
if(top!=1)puts("INVALID");else puts(stack[0]);return 0;}