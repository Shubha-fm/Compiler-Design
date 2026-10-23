/* Count frequency of ASCII characters in stdin. */
#include <stdio.h>
int main(void){int n[128]={0},c;while((c=getchar())!=EOF)if(c<128)n[c]++;for(int i=0;i<128;i++)if(n[i])printf("%d %d\n",i,n[i]);return 0;}