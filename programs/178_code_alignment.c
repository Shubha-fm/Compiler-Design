/* Round instruction offset up to alignment, requiring positive power of two. */
#include <stdio.h>
#include <stdint.h>
int main(void){unsigned long long pos,a;if(scanf("%llu%llu",&pos,&a)!=2||!a||(a&(a-1)))return 1;if(pos>UINT64_MAX-(a-1))return 1;printf("aligned=%llu\n",(pos+a-1)&~(a-1));return 0;}