/* Run-length encoding of a sequence of one-character token categories. */
#include <stdio.h>
int main(void){char s[512];if(scanf("%511s",s)!=1)return 1;for(int i=0;s[i];){int j=i+1;while(s[j]&&s[j]==s[i])j++;printf("%c:%d\n",s[i],j-i);i=j;}return 0;}