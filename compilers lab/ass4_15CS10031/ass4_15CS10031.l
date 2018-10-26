%option noyywrap
%{
  #include "ass4_15CS10031_translator.h"
  #include "y.tab.h"
  #include <math.h>
  void yyerror (char *);  /* prints grammar violation message */
  void count(void);
  void comment (void);
%}

unsigned "unsigned"
break "break"
return "return"
void "void"
case "case"
float "float"
for "for"
signed "signed"
bool "Bool"
continue "continue"
do "do"
int "int"
long "long"
else "else"
short "short"
char "char"
while "while"
goto "goto"
if "if"
default "default"
switch "switch"
double "double"
matrix "Matrix"
identifier_nondigit [_a-zA-Z]
identifier_digit [0-9]
identifier {identifier_nondigit}({identifier_nondigit}|{identifier_digit})*
nonzero_digit [1-9]
digit [0-9]
integer_constant {nonzero_digit}({digit})*
digit_sequence {digit}({digit})*
sign [+-]
exponent_part ([e]{sign}?{digit_sequence})|([E]{sign}?{digit_sequence})
fractional_constant ({digit_sequence}?[.]{digit_sequence})|({digit_sequence}[.])
floating_constant ({fractional_constant}{exponent_part}?)|({digit_sequence}{exponent_part})
escape_sequence \\['"?\\abfnrtv]
c_char [^'\\\n]|{escape_sequence}
c_charsequence {c_char}({c_char})*
character_constant ('{c_charsequence}')
zero_constant [0]
constant {integer_constant}|{floating_constant}|{character_constant}|{zero_constant}
s_char {c_char}
s_char_sequence {s_char}({s_char})*
string_literal \"{s_char_sequence}\"
single_line_comment "//"[^\n]*
%x MULTIPLE
ws [\t\v\f\n\r ] 

%%
{single_line_comment} { }
{unsigned} {return UNSIGNED;}
{break} {return BREAK;}
{return} {return RETURN;}
{void} {return VOID;}
{case} {return CASE;}
{float} {return FLOAT;}
{for} {return FOR;}
{signed} {return SIGNED;}
{bool} {return BOOL;}
{continue} {return CONTINUE;}
{do} {return DO;}
{int} {return INT;}
{long} {return LONG;}
{else} {return ELSE;}
{short} {return SHORT;}
{char} {return CHAR;}
{while} {return WHILE;}
{goto} {return GOTO;}
{if} {return IF;}
{default} {return DEFAULT;}
{switch} {return SWITCH;}
{double} {return DOUBLE;}
{matrix} {return MATRIX;}
{identifier}             { yylval.symp = table->lookup(yytext);;return IDENTIFIER;}
{integer_constant}         { yylval.intval = atoi(yytext); return INT_CONSTANT;}
{floating_constant}		{ yylval.strval = yytext; return FLOAT_CONSTANT;}
{character_constant}		{ return CHAR_CONSTANT;}
{string_literal}    { yylval.strval = yytext;;return STRING_LITERAL;}

"[" 			{ return BO; }
"]"				{ return BC; }
"("				{ return CO; }
")"				{ return CC; }
"{"				{ return BRO; }
"}"				{ return BRC; }
"."				{ return DOT; }
"->"			{ return PTR_OP; }
"++"			{ return INC_OP; }
"--"			{ return DEC_OP; }
"&"				{ return '&'; }
"*"				{ return '*'; }
"+"				{ return '+'; }
"-"				{ return '-'; }
"~"				{ return '~'; }
"!"				{ return '!'; }
"/"				{ return '/'; }
"%"				{ return '%'; }
"<<"			{ return LEFT_OP; }
">>"			{ return RIGHT_OP; }
"<"				{ return LET; }
">"				{ return GET; }
"<="			{ return LE_OP; }
">="			{ return GE_OP; }
"=="			{ return EQ_OP; }
"!="			{ return NE_OP; }
"^"				{ return POW; }
"|"				{ return UOR; }
"&&"			{ return AND_OP; }
"||"			{ return OR_OP; }
"?"				{ return Q; }
":"				{ return POL; }
";"				{ return SECOL; }
"="				{ return EQ; }
"*="			{ return MUL_ASSIGN; }
"/="			{ return DIV_ASSIGN; }
"%="			{ return MOD_ASSIGN; }
"+="			{ return ADD_ASSIGN; }
"-="			{ return SUB_ASSIGN; }
"<<="			{ return LEFT_ASSIGN; }
">>="			{ return RIGHT_ASSIGN; }
"&="			{ return AND_ASSIGN; }
"^="			{ return XOR_ASSIGN; }
"|="			{ return OR_ASSIGN; }
","				{ return COM; }
"#"				{ return HAS; }
".'"			{ return DCOMM;}
{ws}			{ /* whitespace separates tokens */ }

"/*" {BEGIN(MULTIPLE);}
                <MULTIPLE>[^\*]*      {;}
                <MULTIPLE>("*"+"/")    {BEGIN(0);}
%%

