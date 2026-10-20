/* Backtracking recursive descent: S -> ab | ac; full-input recognition. */
#include <stdio.h>
#include <string.h>
static const char *input;static size_t pos;
static int terminal(char c){if(input[pos]==c){pos++;return 1;}return 0;}
static int S(void){size_t save=pos;if(terminal('a')&&terminal('b'))return 1;pos=save;if(terminal('a')&&terminal('c'))return 1;pos=save;return 0;}
int main(void){char s[256];if(scanf("%255s",s)!=1)return 1;input=s;pos=0;int ok=S();puts(ok&&!s[pos]?"ACCEPT":"REJECT");return 0;}
