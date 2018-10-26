#include <stdio.h>
#include "y.tab.h"
extern "C" {
  char* yytext;
  int yyparse();
}
int main() {
  int token;
  Matrix a[5][5];
  yyparse();
  return 0;
}
