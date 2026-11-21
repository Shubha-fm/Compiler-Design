/* Tiny Sokoban: push one box onto a goal. WASD moves, q quits.
   Walls #; player @; box $; goal .; a box on goal is *. */
#include <stdio.h>
#include <string.h>
static const char *walls[]={"#######","#     #","#     #","#     #","#######"};
static int pr=2,pc=1,br=2,bc=3,gr=2,gc=5;
static void show(void){for(int r=0;r<5;r++){for(int c=0;c<7;c++){char ch=walls[r][c];if(r==gr&&c==gc)ch='.';if(r==br&&c==bc)ch=r==gr&&c==gc?'*':'$';if(r==pr&&c==pc)ch='@';putchar(ch);}putchar('\n');}}
static int freecell(int r,int c){return r>=0&&r<5&&c>=0&&c<7&&walls[r][c]!='#';}
int main(void){char input[32];int moves=0;puts("Sokoban: push the box $ onto goal .; WASD and q.");
while(1){show();if(br==gr&&bc==gc){printf("Puzzle solved in %d moves!\n",moves);return 0;}
printf("Move: ");fflush(stdout);if(scanf("%31s",input)!=1||!strcmp(input,"q")){puts("Game ended.");return 0;}
int dr=0,dc=0;if(input[1]){puts("One direction only.");continue;}
if(input[0]=='w')dr=-1;else if(input[0]=='s')dr=1;else if(input[0]=='a')dc=-1;else if(input[0]=='d')dc=1;else{puts("Use w/a/s/d.");continue;}
int nr=pr+dr,nc=pc+dc;if(!freecell(nr,nc)){puts("Wall.");continue;}
if(nr==br&&nc==bc){int rr=br+dr,cc=bc+dc;if(!freecell(rr,cc)){puts("Cannot push box.");continue;}br=rr;bc=cc;}
pr=nr;pc=nc;moves++;}}
