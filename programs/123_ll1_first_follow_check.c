/* Check LL(1) alternatives using FIRST sets and nullable/FOLLOW intersections. */
#include <stdio.h>
#include <string.h>
int main(void){char x[128],y[128],follow[128];int nx,ny;if(scanf("%127s %d %127s %d %127s",x,&nx,y,&ny,follow)!=5||nx<0||nx>1||ny<0||ny>1)return 1;for(int i=0;x[i];i++)if(strchr(y,x[i])){puts("CONFLICT");return 0;}if(nx)for(int i=0;y[i];i++)if(strchr(follow,y[i])){puts("CONFLICT");return 0;}if(ny)for(int i=0;x[i];i++)if(strchr(follow,x[i])){puts("CONFLICT");return 0;}puts(nx&&ny?"CONFLICT":"LL1");return 0;}