/* DAG node reuse by structural hash for a+b+a+b. */
#include <stdio.h>
#include <string.h>
typedef struct{char op,a,b;}Node;
int main(void){Node n[4]={{'+','a','b'},{'+','a','b'},{'*','a','b'},{'+','a','b'}};for(int i=0;i<4;i++){int found=-1;for(int j=0;j<i;j++)if(!memcmp(&n[i],&n[j],sizeof(Node))){found=j;break;}printf("expression %d -> node %d\n",i,found>=0?found:i);}return 0;}