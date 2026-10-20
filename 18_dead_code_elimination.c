#include <stdio.h>
int main(void){
 puts("Original:");
 puts("x = 10;");
 puts("unused = 20;");
 puts("y = x + 5;");
 puts("print(y);");
 puts("\nAfter removing the unused assignment (demonstration):");
 puts("x = 10;");
 puts("y = x + 5;");
 puts("print(y);");
 return 0;
}