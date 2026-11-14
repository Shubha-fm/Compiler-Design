/* Minimal terminal 2048. Use WASD to slide tiles, q to quit.
   Deterministic pseudorandom generator, optional numeric seed argument. */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
static int b[4][4];static uint32_t seed=123456789u;static int score=0;
static uint32_t rnd(void){seed^=seed<<13;seed^=seed>>17;seed^=seed<<5;return seed;}
static int empty_count(void){int n=0;for(int r=0;r<4;r++)for(int c=0;c<4;c++)if(!b[r][c])n++;return n;}
static void spawn(void){int n=empty_count();if(!n)return;int target=(int)(rnd()%(unsigned)n);for(int r=0;r<4;r++)for(int c=0;c<4;c++)if(!b[r][c]&&target--==0){b[r][c]=(rnd()%10u==0u)?4:2;return;}}
static void show(void){printf("\nScore: %d\n",score);for(int r=0;r<4;r++){for(int c=0;c<4;c++)printf("%5d",b[r][c]);putchar('\n');}}
static int move(char direction){int changed=0;
for(int axis=0;axis<4;axis++){int old[4],v[4]={0},len=0;
for(int k=0;k<4;k++){int r=(direction=='w')?k:(direction=='s')?3-k:axis;int c=(direction=='a')?k:(direction=='d')?3-k:axis;if(direction=='w'||direction=='s')c=axis;else r=axis;old[k]=b[r][c];if(old[k])v[len++]=old[k];}
int out[4]={0},j=0;for(int i=0;i<len;i++){if(i+1<len&&v[i]==v[i+1]){out[j]=v[i]*2;score+=out[j];i++;}else out[j]=v[i];j++;}
for(int k=0;k<4;k++){int r=(direction=='w')?k:(direction=='s')?3-k:axis;int c=(direction=='a')?k:(direction=='d')?3-k:axis;if(direction=='w'||direction=='s')c=axis;else r=axis;if(old[k]!=out[k])changed=1;b[r][c]=out[k];}}
return changed;}
static int moves_available(void){if(empty_count())return 1;for(int r=0;r<4;r++)for(int c=0;c<4;c++)if((r<3&&b[r][c]==b[r+1][c])||(c<3&&b[r][c]==b[r][c+1]))return 1;return 0;}
int main(int argc,char **argv){if(argc>2)return 1;if(argc==2){char *end;unsigned long s=strtoul(argv[1],&end,10);if(end==argv[1]||*end)return 1;seed=(uint32_t)s;if(!seed)seed=1u;}
spawn();spawn();puts("2048: WASD to move, q to quit.");char input[32];
while(1){show();if(!moves_available()){puts("No moves left. Game over.");break;}printf("Move: ");fflush(stdout);
if(scanf("%31s",input)!=1||input[0]=='q'){puts("Game ended.");break;}if(input[1]||!((input[0]=='w')||(input[0]=='a')||(input[0]=='s')||(input[0]=='d'))){puts("Use w/a/s/d.");continue;}
if(move(input[0])){spawn();}else puts("No tiles moved.");}
return 0;}