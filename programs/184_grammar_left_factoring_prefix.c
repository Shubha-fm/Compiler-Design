/* Find longest common prefix between two alternative right-hand sides. */
#include <stdio.h>
int main(void){char a[128],b[128];if(scanf("%127s %127s",a,b)!=2)return 1;int i=0;while(a[i]&&b[i]&&a[i]==b[i])i++;printf("common_prefix=%.*s length=%d\n",i,a,i);return 0;}