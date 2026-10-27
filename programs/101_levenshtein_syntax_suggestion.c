/* Edit distance between two token strings, useful for diagnostic suggestions. */
#include <stdio.h>
#include <string.h>
int main(void){char a[101],b[101];int d[102][102];if(scanf("%100s %100s",a,b)!=2)return 1;int n=strlen(a),m=strlen(b);for(int i=0;i<=n;i++)d[i][0]=i;for(int j=0;j<=m;j++)d[0][j]=j;for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){int x=d[i-1][j]+1,y=d[i][j-1]+1,z=d[i-1][j-1]+(a[i-1]!=b[j-1]);d[i][j]=x<y?(x<z?x:z):(y<z?y:z);}printf("distance=%d\n",d[n][m]);return 0;}