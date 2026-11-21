/* Five-question compiler design quiz with explanations and scoring. */
#include <stdio.h>
#include <ctype.h>
static const char *questions[]={
"Which phase groups characters into tokens?\nA. Lexer  B. Linker  C. Optimizer",
"Which structure is usually used in predictive parsing?\nA. Queue  B. Stack  C. Heap",
"What does SSA require for ordinary variables?\nA. One use  B. One definition  C. No branches",
"Which analysis computes variables needed in the future?\nA. Liveness  B. Dead code  C. Lexing",
"Which automaton permits epsilon transitions?\nA. DFA  B. Epsilon-NFA  C. None"
};
static const char answers[]={'A','B','B','A','B'};
static const char *explain[]={
"The lexer performs tokenization.","Predictive parsers use a stack.",
"Static single assignment gives each defined value one assignment.",
"Liveness tracks variables whose current values may be used later.",
"Epsilon-NFAs may change states without consuming input."
};
int main(void){char entry[32];int score=0;puts("Compiler Quiz: answer A, B or C; q quits.");
for(int i=0;i<5;){printf("\nQuestion %d/5\n%s\nYour answer: ",i+1,questions[i]);fflush(stdout);
if(scanf("%31s",entry)!=1||entry[0]=='q'){printf("Game ended. Score %d/%d\n",score,i);return 0;}
if(entry[1]||!(entry[0]=='a'||entry[0]=='A'||entry[0]=='b'||entry[0]=='B'||entry[0]=='c'||entry[0]=='C')){puts("Choose A, B, or C.");continue;}
char a=(char)toupper((unsigned char)entry[0]);if(a==answers[i]){score++;puts("Correct!");}else printf("Incorrect. Answer: %c\n",answers[i]);
puts(explain[i]);i++;}
printf("Final score: %d/5\n",score);return 0;}
