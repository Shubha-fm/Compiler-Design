/* Sweep-line peak count of overlapping half-open live ranges.
   End events processed before start events at the same coordinate. */
#include <stdio.h>
#include <stdlib.h>
typedef struct{int t,delta;} Event;
static int cmp(const void *a,const void *b){const Event *x=a,*y=b;if(x->t!=y->t)return x->t<y->t?-1:1;return x->delta<y->delta?-1:x->delta>y->delta;}
int main(void){int n;if(scanf("%d",&n)!=1||n<0||n>100)return 1;Event e[200];int k=0;for(int i=0;i<n;i++){int a,b;if(scanf("%d%d",&a,&b)!=2||a<0||b<a)return 1;if(a==b)continue;e[k++]=(Event){a,1};e[k++]=(Event){b,-1};}qsort(e,k,sizeof e[0],cmp);int current=0,peak=0;for(int i=0;i<k;i++){current+=e[i].delta;if(current>peak)peak=current;}printf("peak=%d\n",peak);return 0;}