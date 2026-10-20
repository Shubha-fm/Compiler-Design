#include <stdio.h>
int main(void){
 puts("Original: A -> a b | a c");
 puts("Left-factored:");
 puts("A -> a A'");
 puts("A' -> b | c");
 return 0;
}