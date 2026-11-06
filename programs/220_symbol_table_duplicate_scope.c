/* Detect duplicate variable declaration in the same numeric scope.
   Declarations in different scopes are allowed. */
#include <stdio.h>
#include <string.h>
int main(void){int n,scope[100];char name[100][40];if(scanf("%d",&n)!=1||n<0||n>100)return 1;for(int i=0;i<n;i++){if(scanf("%d %39s",&scope[i],name[i])!=2||scope[i]<0)return 1;for(int j=0;j<i;j++)if(scope[j]==scope[i]&&!strcmp(name[j],name[i])){printf("DUPLICATE scope=%d name=%s\n",scope[i],name[i]);return 0;}}puts("NO DUPLICATE");return 0;}