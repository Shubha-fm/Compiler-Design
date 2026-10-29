/* Report duplicate labels in a small intermediate-code label table. */
#include <stdio.h>
#include <string.h>
int main(void){int n;char names[100][40];if(scanf("%d",&n)!=1||n<0||n>100)return 1;for(int i=0;i<n;i++){if(scanf("%39s",names[i])!=1)return 1;for(int j=0;j<i;j++)if(!strcmp(names[i],names[j])){printf("DUPLICATE %s\n",names[i]);return 0;}}puts("UNIQUE");return 0;}