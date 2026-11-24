/* Three-pile Nim against a perfect XOR-strategy computer.
   Choose pile (1..3) and number to remove; q quits. */
#include <stdio.h>
#include <string.h>
static int p[3]={3,4,5};
int main(void){char s[32];puts("Three-Pile Nim: take 1 or more stones from one pile. Last move wins.");
while(1){printf("Piles: %d %d %d\n",p[0],p[1],p[2]);if(!(p[0]|p[1]|p[2])){puts("Computer wins!");return 0;}
printf("Your pile (1-3, q quits): ");fflush(stdout);
if(scanf("%31s",s)!=1||!strcmp(s,"q")){puts("Game ended.");return 0;}
if(strlen(s)!=1||s[0]<'1'||s[0]>'3'){puts("Invalid pile.");continue;}
int i=s[0]-'1',count;if(scanf("%d",&count)!=1)return 1;
if(count<1||count>p[i]){puts("Invalid removal.");continue;}p[i]-=count;
if(!(p[0]|p[1]|p[2])){puts("You win!");return 0;}
int nim=p[0]^p[1]^p[2],j=-1,remove=0;
for(int k=0;k<3;k++)if((p[k]^nim)<p[k]){j=k;remove=p[k]-(p[k]^nim);break;}
if(j<0)for(int k=0;k<3;k++)if(p[k]>0){j=k;remove=1;break;}
p[j]-=remove;printf("Computer removes %d from pile %d.\n",remove,j+1);
if(!(p[0]|p[1]|p[2])){puts("Computer wins!");return 0;}}
}
