/* Build register interference edges from one live-variable set. */
#include <stdio.h>
#include <string.h>
int main(void){char names[27];if(scanf("%26s",names)!=1)return 1;int n=strlen(names);for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)if(names[i]!=names[j])printf("%c-%c\n",names[i],names[j]);return 0;}