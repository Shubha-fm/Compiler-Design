/* Row-major offset for a 2D array: rows cols i j element_size. */
#include <stdio.h>
int main(void){long rows,cols,i,j,size;if(scanf("%ld%ld%ld%ld%ld",&rows,&cols,&i,&j,&size)!=5||rows<1||cols<1||size<1||i<0||i>=rows||j<0||j>=cols)return 1;printf("offset=%ld\n",(i*cols+j)*size);return 0;}