/* Turn-based Snake on 8x8 grid. WASD moves once; q quits.
   Seeded deterministic food placement; initial snake occupies (4,3),(4,2). */
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
static int x[64]={3,2},y[64]={4,4},length=2,foodx=5,foody=4,score=0;
static uint32_t rng=1234567u;
static uint32_t next(void){rng^=rng<<13;rng^=rng>>17;rng^=rng<<5;return rng;}
static int occupied(int a,int b){for(int i=0;i<length;i++)if(x[i]==a&&y[i]==b)return 1;return 0;}
static int place_food(void){int freecount=64-length;if(!freecount)return 0;int index=(int)(next()%(unsigned)freecount);
for(int r=0;r<8;r++)for(int c=0;c<8;c++)if(!occupied(c,r)&&index--==0){foodx=c;foody=r;return 1;}return 0;}
static void show(void){printf("\nScore: %d\n",score);for(int r=0;r<8;r++){for(int c=0;c<8;c++){char ch='.';if(c==foodx&&r==foody)ch='*';for(int i=length-1;i>=0;i--)if(x[i]==c&&y[i]==r)ch=i?'o':'@';putchar(ch);}putchar('\n');}}
int main(int argc,char **argv){if(argc>2)return 1;if(argc==2){char *end;unsigned long v=strtoul(argv[1],&end,10);if(end==argv[1]||*end)return 1;rng=(uint32_t)v;if(!rng)rng=1;}
char input[32];puts("Snake: WASD to move, eat *, avoid walls and body; q quits.");
while(1){show();printf("Move: ");fflush(stdout);if(scanf("%31s",input)!=1||input[0]=='q'){puts("Game ended.");return 0;}
int dx=0,dy=0;if(input[1]){puts("Use one key.");continue;}
if(input[0]=='w')dy=-1;else if(input[0]=='s')dy=1;else if(input[0]=='a')dx=-1;else if(input[0]=='d')dx=1;else{puts("Use w/a/s/d.");continue;}
int nx=x[0]+dx,ny=y[0]+dy,grow=(nx==foodx&&ny==foody);
if(nx<0||nx>=8||ny<0||ny>=8){puts("Game over: wall.");return 0;}
for(int i=0;i<length-(grow?0:1);i++)if(x[i]==nx&&y[i]==ny){puts("Game over: collision.");return 0;}
if(grow){length++;score++;}for(int i=length-1;i>0;i--){x[i]=x[i-1];y[i]=y[i-1];}x[0]=nx;y[0]=ny;
if(grow){if(!place_food()){show();puts("You filled the board!");return 0;}puts("Food eaten!");}}
}