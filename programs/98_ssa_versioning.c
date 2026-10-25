/* SSA-style renaming for a straight-line list of assignments. */
#include <stdio.h>
int main(void){int n,v[26]={0};if(scanf("%d",&n)!=1||n<0||n>100)return 1;for(int i=0;i<n;i++){char c;if(scanf(" %c",&c)!=1||c<'a'||c>'z')return 1;printf("%c_%d\n",c,++v[c-'a']);}return 0;}