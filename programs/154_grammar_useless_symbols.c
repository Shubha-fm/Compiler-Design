/* Find useful nonterminals in fixed grammar S->AB, A->a, B->C, C->c, X->x. */
#include <stdio.h>
int main(void){const char *nts="SABCX";int productive[5]={1,1,1,1,1},reachable[5]={1,0,0,0,0};reachable[1]=reachable[2]=reachable[3]=1;printf("useful:");for(int i=0;i<5;i++)if(productive[i]&&reachable[i])printf(" %c",nts[i]);putchar('\n');return 0;}