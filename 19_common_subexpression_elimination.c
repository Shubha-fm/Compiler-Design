#include <stdio.h>
int main(void){
 puts("Before optimization:");
 puts("t1 = a + b");
 puts("t2 = a + b");
 puts("c = t1 * t2");
 puts("\nAfter common-subexpression elimination:");
 puts("t1 = a + b");
 puts("c = t1 * t1");
 return 0;
}