/* Compute visual column of a position after tab expansion (tab stops every 8). */
#include <stdio.h>
int main(void){int c,col=1;while((c=getchar())!=EOF&&c!='\n'){if(c=='\t')col+=8-(col-1)%8;else col++;}printf("next_column=%d\n",col);return 0;}