/* Print word token spans (zero-based half-open offsets). */
#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main(void){char s[512];if(!fgets(s,sizeof s,stdin))return 1;for(size_t i=0;s[i];){if(!isalnum((unsigned char)s[i])&&s[i]!='_'){i++;continue;}size_t b=i;while(isalnum((unsigned char)s[i])||s[i]=='_')i++;printf("%zu:%zu %.*s\n",b,i,(int)(i-b),s+b);}return 0;}