/* Convert up to 32-bit binary literal to decimal; reject bad digits. */
#include <stdio.h>
#include <string.h>
int main(void){char s[34];if(scanf("%33s",s)!=1)return 1;size_t n=strlen(s);if(n>32){puts("INVALID");return 0;}unsigned long long v=0;for(size_t i=0;i<n;i++){if(s[i]!='0'&&s[i]!='1'){puts("INVALID");return 0;}v=v*2+(s[i]-'0');}printf("%llu\n",v);return 0;}