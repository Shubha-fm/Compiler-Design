/* Insert keywords into an ASCII lowercase trie and query membership.
   Input: n, n words, q, q lookup words. Bounded to 2000 trie nodes. */
#include <stdio.h>
static int next[2000][26],terminal[2000],nodes=1;
static int walk(const char *s,int insert){int at=0;for(int i=0;s[i];i++){int c=s[i]-'a';if(c<0||c>=26)return -1;
if(!next[at][c]){if(!insert)return 0;if(nodes==2000)return -1;next[at][c]=nodes++;}at=next[at][c];}
if(insert)terminal[at]=1;return terminal[at];}
int main(void){int n,q;char word[128];if(scanf("%d",&n)!=1||n<0||n>100)return 1;
for(int i=0;i<n;i++){if(scanf("%127s",word)!=1||walk(word,1)<0)return 1;}
if(scanf("%d",&q)!=1||q<0||q>100)return 1;
for(int i=0;i<q;i++){if(scanf("%127s",word)!=1)return 1;int found=walk(word,0);printf("%s: %s\n",word,found==1?"KEYWORD":"IDENTIFIER");}
return 0;}
