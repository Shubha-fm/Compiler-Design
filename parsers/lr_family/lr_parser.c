/* SLR(1), canonical LR(1) (CLR), LALR(1) parser generator.
   Usage: gcc -std=c11 -O2 lr_parser.c -o lr_parser
          ./lr_parser slr|clr|lalr grammar.txt input
   Grammar lines: A->rhs, A-># (epsilon); uppercase nonterminals,
   one-character terminals. First LHS is start symbol; $ reserved. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define P 64
#define I 512
#define S 256
#define C 128
typedef struct{int lhs,n;unsigned char rhs[32];} Rule;
typedef struct{short p,d;unsigned char la;} Item;
typedef struct{Item v[I];int n;} Set;
typedef struct{int kind,arg;} Act;
static Rule rule[P];static int nr,mode,ns,edges[S][C],go[S][C],bad;
static Set states[S];
static Act table[S][C];
static unsigned char first[C][C],follow[C][C],nullable[C];
static int has(const Set *s,Item a){for(int i=0;i<s->n;i++)if(s->v[i].p==a.p&&s->v[i].d==a.d&&(mode==0||s->v[i].la==a.la))return 1;return 0;}
static void add(Set *s,Item a){if(has(s,a))return;if(s->n==I){fputs("item limit\n",stderr);exit(2);}s->v[s->n++]=a;}
static int equal(const Set *a,const Set *b){if(a->n!=b->n)return 0;for(int i=0;i<a->n;i++)if(!has(b,a->v[i]))return 0;return 1;}
static int core(const Set *a,const Set *b){for(int i=0;i<a->n;i++){int yes=0;for(int j=0;j<b->n;j++)if(a->v[i].p==b->v[j].p&&a->v[i].d==b->v[j].d)yes=1;if(!yes)return 0;}for(int j=0;j<b->n;j++){int yes=0;for(int i=0;i<a->n;i++)if(a->v[i].p==b->v[j].p&&a->v[i].d==b->v[j].d)yes=1;if(!yes)return 0;}return 1;}
static void grammar(const char *name){FILE *f=fopen(name,"r");if(!f){perror(name);exit(2);}int n;if(fscanf(f,"%d",&n)!=1||n<1||n>=P){fputs("invalid rule count\n",stderr);exit(2);}char b[128];fgets(b,sizeof b,f);nr=n+1;
for(int i=1;i<nr;i++){if(!fgets(b,sizeof b,f)){fputs("missing rule\n",stderr);exit(2);}b[strcspn(b,"\r\n")]=0;int z=(int)strlen(b);if(z<4||z>35||!isupper((unsigned char)b[0])||b[1]!='-'||b[2]!='>'){fputs("bad rule\n",stderr);exit(2);}rule[i].lhs=b[0];if(z==4&&b[3]=='#')continue;for(int j=3;j<z;j++){unsigned char ch=b[j];if(ch>=C||ch=='#'||ch=='$'||isspace(ch)){fputs("bad symbol\n",stderr);exit(2);}rule[i].rhs[rule[i].n++]=ch;}}
fclose(f);int aug=0;for(int c='A';c<='Z';c++){int used=0;for(int i=1;i<nr;i++)if(rule[i].lhs==c)used=1;if(!used){aug=c;break;}}if(!aug){fputs("no augmentation symbol\n",stderr);exit(2);}rule[0].lhs=aug;rule[0].rhs[0]=rule[1].lhs;rule[0].n=1;}
static void compute(void){int changed=1;while(changed){changed=0;for(int p=0;p<nr;p++){Rule *r=&rule[p];int all=1;for(int j=0;j<r->n;j++){int x=r->rhs[j];if(!isupper(x)){if(!first[r->lhs][x])first[r->lhs][x]=changed=1;all=0;break;}for(int t=0;t<C;t++)if(first[x][t]&&!first[r->lhs][t])first[r->lhs][t]=changed=1;if(!nullable[x]){all=0;break;}}if(all&&!nullable[r->lhs])nullable[r->lhs]=changed=1;}}
follow[rule[1].lhs]['$']=1;changed=1;while(changed){changed=0;for(int p=1;p<nr;p++){Rule *r=&rule[p];for(int j=0;j<r->n;j++){int B=r->rhs[j];if(!isupper(B))continue;int all=1;for(int k=j+1;k<r->n;k++){int x=r->rhs[k];if(!isupper(x)){if(!follow[B][x])follow[B][x]=changed=1;all=0;break;}for(int t=0;t<C;t++)if(first[x][t]&&!follow[B][t])follow[B][t]=changed=1;if(!nullable[x]){all=0;break;}}if(all)for(int t=0;t<C;t++)if(follow[r->lhs][t]&&!follow[B][t])follow[B][t]=changed=1;}}}}
static void closure(Set *s){for(int i=0;i<s->n;i++){Item a=s->v[i];Rule *r=&rule[a.p];if(a.d==r->n)continue;int B=r->rhs[a.d];if(!isupper(B))continue;unsigned char la[C]={0};if(mode==0)la['$']=1;else{int nullable_tail=1;for(int k=a.d+1;k<r->n;k++){int x=r->rhs[k];if(!isupper(x)){la[x]=1;nullable_tail=0;break;}for(int t=0;t<C;t++)if(first[x][t])la[t]=1;if(!nullable[x]){nullable_tail=0;break;}}if(nullable_tail)la[a.la]=1;}for(int p=1;p<nr;p++)if(rule[p].lhs==B){if(mode==0)add(s,(Item){p,0,0});else for(int t=0;t<C;t++)if(la[t])add(s,(Item){p,0,(unsigned char)t});}}}
static void construct(void){memset(edges,-1,sizeof edges);ns=1;add(&states[0],(Item){0,0,(unsigned char)(mode? '$':0)});closure(&states[0]);for(int s=0;s<ns;s++)for(int c=0;c<C;c++){Set next={0};for(int j=0;j<states[s].n;j++){Item x=states[s].v[j];if(x.d<rule[x.p].n&&rule[x.p].rhs[x.d]==c){x.d++;add(&next,x);}}if(!next.n)continue;closure(&next);int id=-1;for(int j=0;j<ns;j++)if(equal(&states[j],&next)){id=j;break;}if(id<0){if(ns==S){fputs("state limit\n",stderr);exit(2);}id=ns++;states[id]=next;}edges[s][c]=id;}}
static void merge(void){static Set newstates[S];static int newedges[S][C];int map[S],n=0;memset(newedges,-1,sizeof newedges);for(int i=0;i<ns;i++){int id=-1;for(int j=0;j<i;j++)if(core(&states[i],&states[j])){id=map[j];break;}if(id<0)id=n++;map[i]=id;for(int k=0;k<states[i].n;k++)add(&newstates[id],states[i].v[k]);}for(int i=0;i<ns;i++)for(int c=0;c<C;c++)if(edges[i][c]>=0){int target=map[edges[i][c]],*slot=&newedges[map[i]][c];if(*slot>=0&&*slot!=target){fputs("bad merged edge\n",stderr);exit(2);}*slot=target;}memcpy(states,newstates,sizeof states);memcpy(edges,newedges,sizeof edges);ns=n;}
static void install(int s,int c,int type,int val){Act *a=&table[s][c];if(a->kind&&(a->kind!=type||a->arg!=val)){fprintf(stderr,"Conflict in state %d on %c\n",s,c);bad=1;return;}a->kind=type;a->arg=val;}
static void make_table(void){for(int s=0;s<ns;s++){for(int c=0;c<C;c++)if(edges[s][c]>=0){if(isupper(c))go[s][c]=edges[s][c]+1;else install(s,c,1,edges[s][c]);}for(int j=0;j<states[s].n;j++){Item x=states[s].v[j];if(x.d!=rule[x.p].n)continue;if(x.p==0){install(s,'$',3,0);continue;}if(mode==0){for(int c=0;c<C;c++)if(follow[rule[x.p].lhs][c])install(s,c,2,x.p);}else install(s,x.la,2,x.p);}}}
static int parse(const char *word){int stack[2048]={0},top=0;size_t n=strlen(word),pos=0;for(int step=0;step<100000;step++){int c=pos<n?(unsigned char)word[pos]:'$';if(c>=C||(c=='$'&&pos<n))return 0;Act a=table[stack[top]][c];if(a.kind==1){if(top==2047)return 0;stack[++top]=a.arg;pos++;}else if(a.kind==2){Rule *r=&rule[a.arg];if(top<r->n)return 0;top-=r->n;int dest=go[stack[top]][r->lhs];if(!dest||top==2047)return 0;stack[++top]=dest-1;}else if(a.kind==3)return pos==n;else return 0;}return 0;}
int main(int argc,char **argv){if(argc!=4){fprintf(stderr,"Usage: %s slr|clr|lalr grammar.txt input\n",argv[0]);return 2;}if(!strcmp(argv[1],"slr"))mode=0;else if(!strcmp(argv[1],"clr")||!strcmp(argv[1],"lalr"))mode=1;else return 2;grammar(argv[2]);compute();construct();if(!strcmp(argv[1],"lalr"))merge();make_table();if(bad){puts("CONFLICT");return 3;}puts(parse(argv[3])?"ACCEPT":"REJECT");return 0;}
