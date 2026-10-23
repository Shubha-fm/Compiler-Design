/* Postorder traversal of fixed expression tree (a+b)*c. */
#include <stdio.h>
typedef struct N{char value;struct N *left,*right;}N;
void post(N *p){if(!p)return;post(p->left);post(p->right);putchar(p->value);}
int main(void){N a={'a',0,0},b={'b',0,0},c={'c',0,0},plus={'+',&a,&b},mul={'*',&plus,&c};post(&mul);putchar('\n');return 0;}