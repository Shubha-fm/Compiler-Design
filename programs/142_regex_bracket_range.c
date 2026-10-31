/* Recognize one ASCII lowercase character in an input bracket range [a-z]. */
#include <stdio.h>
int main(void){char lo,hi,value;if(scanf(" %c %c %c",&lo,&hi,&value)!=3)return 1;if(lo>'z'||lo<'a'||hi>'z'||hi<'a'||lo>hi){puts("INVALID");return 0;}puts(value>=lo&&value<=hi?"MATCH":"NO MATCH");return 0;}