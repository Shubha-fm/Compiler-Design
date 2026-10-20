#include <stdio.h>
int main(void){
 puts("Original: A -> A a | b");
 puts("After eliminating immediate left recursion:");
 puts("A -> b A'");
 puts("A' -> a A' | epsilon");
 return 0;
}