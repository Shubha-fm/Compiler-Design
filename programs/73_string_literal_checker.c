/* Validate quoted one-line string with backslash escaping (simplified). */
#include <stdio.h>
#include <string.h>
int main(void){char s[512];if(!fgets(s,sizeof s,stdin))return 1;size_t n=strcspn(s,"\n");s[n]=0;if(n<2||s[0]!='"'||s[n-1]!='"'){puts("INVALID");return 0;}for(size_t i=1;i<n-1;i++){if(s[i]=='"'){puts("INVALID");return 0;}if(s[i]=='\\'){i++;if(i>=n-1){puts("INVALID");return 0;}}}puts("VALID");return 0;}