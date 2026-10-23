/* Recognize decimal scientific notation using strtod and exponent requirement. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void){char s[128],*end;if(scanf("%127s",s)!=1)return 1;strtod(s,&end);puts(end!=s&&!*end&&strpbrk(s,"eE")?"VALID":"INVALID");return 0;}