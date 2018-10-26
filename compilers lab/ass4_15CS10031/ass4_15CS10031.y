 %{ 
/*	
*	  parser.y
* 	  Author: PANKAJ DHURVE
*/
 	/* C Declarations and Definitions */
	#include <string.h>
	#include <stdio.h>
	#include "ass4_15CS10031_translator.h"
	extern	int yylex();
	void yyerror(const char *s);
	extern type_e TYPE;
	extern int gDebug;
	//sym* temporary = gentemp(_DOUBLE);

%}


%union {
	int instr;
	float floatval;
	sym* symp;
	expr* exp;
	int intval;
	unary* A;
	lint* nl;
	symtype* st;
	char* strval;
	statement* stat;
	char uop;	//unary operator
}

%token TYPEDEF EXTERN STATIC AUTO REGISTER INLINE RESTRICT MATRIX HAS POW UOR
%token CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE CONST VOLATILE VOID EQ COM
%token BOOL COMPLEX IMAGINARY DCOMM
%token STRUCT UNION ENUM DOT LET GET Q POL SECOL
%token BREAK CASE CONTINUE DEFAULT DO IF ELSE FOR GOTO WHILE SWITCH SIZEOF
%token RETURN BRO BRC CO CC BO BC

%token LEFT_ASSIGN ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN
%token INC_OP DEC_OP PTR_OP  GE_OP EQ_OP NE_OP ELLIPSIS RIGHT_ASSIGN
%token DIV_ASSIGN MOD_ASSIGN AND_ASSIGN XOR_ASSIGN OR_ASSIGN RIGHT_OP LEFT_OP AND_OP OR_OP LE_OP 

%token <symp>IDENTIFIER  PUNCTUATORS COMMENT
%token <intval>INT_CONSTANT 
%token <strval> STRING_LITERAL
	
%token <strval> FLOAT_CONSTANT
	ENU_CONSTANT 
%token <char>CHAR_CONSTANT

%start translation_unit
   	
// Expressions
%type <symp> constant initializer
%type <uop> unary_operator
%type <A> postfix_expression
	cast_expression
	unary_expression
%type <exp>
	multiplicative_expression
	equality_expression
	additive_expression
	shift_expression
	expression
	assignment_expression
	relational_expression
	and_expression
	exclusive_or_expression
	inclusive_or_expression
	logical_and_expression
	logical_or_expression
	primary_expression 
	conditional_expression
	expression_statement



%type <instr> M
%type <exp> N
%type <intval> argument_expression_list
%type <st> pointer
%type <symp> direct_declarator init_declarator declarator

%type <stat>  statement
	labeled_statement 
	compound_statement
	
	block_item_list
	iteration_statement
	jump_statement
	selection_statement
	block_item

%%
M 	: %empty{	// To store the address of the next instruction for further use.
		$$ = nextinstr();
	};

N 	: %empty { 	// Non terminal to prevent fallthrough by emitting a goto
		debug ("n");
		$$  = new expr();
		$$->nextlist = makelist(nextinstr());
		emit (GOTOOP,"");
		debug ("n2");
};
CST : %empty { // Used for changing to symbol table for a function
		if (currsym->nest==NULL) changeTable(new symtab(""));	// Function symbol table doesn't already exist
		else {
			changeTable (currsym ->nest);						// Function symbol table already exists
			emit (LABEL, table->tname);
		}
	}
	;
primary_expression
	: IDENTIFIER {
		//cout<<"primary_expression=> Identifier"<<endl;
		$$ = new expr();
		$$->symp = $1;
		$$->isbool = false;
	}
	
	| CO expression CC {
		$$ = $2;
	}
	
	| STRING_LITERAL {
		$$ = new expr();
		$$->symp = gentemp(PTR, $1);      // temp variable of type PTR
		$$->symp->initialize($1);         // initialise
		$$->symp->type->ptr = new symtype(_CHAR);
	}
	
	| constant {
		$$ = new expr();
		$$->symp = $1;
	}
	;

constant
	: INT_CONSTANT {
		$$ = gentemp(_INT, NumberToString($1));                 
		emit(EQUAL, $$->name, $1);                                // $$-name = $1
	}
	
	| CHAR_CONSTANT{
		$$ = gentemp(_CHAR);
		emit(EQUAL, $$->name, "a");                               // $$->name = a
	}
	
	| FLOAT_CONSTANT {
		$$ = gentemp(_DOUBLE, *new string ($1));
		emit(EQUAL, $$->name, *new string($1));
	}
	
	
	;

postfix_expression
	
	
	: postfix_expression DEC_OP {
	  //cout<<"post_fix++"<<endl;
		$$ = new unary();
		
		if($1->ismatrix ){
			$$->symp = gentemp(_DOUBLE);
			sym *temp = gentemp(_DOUBLE);
			
			emit(ARRR, temp->name , $1->symp->name , $1->loc->name);    // temp->name = $1->symp->name[$1->symp->loc]
			emit(EQUAL,$$->symp->name,temp->name);                      // $$->symp->name = temp->name
			emit( SUB, temp->name , temp->name , "1");	                // temp->name = temp->name -1 
			emit(ARRL, $1->symp->name,$1->loc->name,temp->name);	      // $1->symp->name[$1->symp->loc] = temp->name
		}
		else{
		                                                              // copy $1 to $$
			$$->symp = gentemp($1->symp->type->cat);
			string ss = $$->symp->name ; 
			emit (EQUAL, $$->symp->name, $1->symp->name);               // $$->symp->name = $1->symp->name

		                                                                // Decrement $1
			emit (SUB, $1->symp->name, $1->symp->name, "1");            // $1->symp->name = $1->symp->name - 1
		}
	}
	| postfix_expression DCOMM{                                     // calculate transpose
		$$ = new unary();
		$$->symp = gentemp(_DOUBLE);
		sym *temp = gentemp(_DOUBLE);
			
			emit(ARRR, temp->name , $1->symp->name , $1->loc->name);
			emit(EQUAL,$$->symp->name,temp->name);
		//$$->symp = gentemp(_DOUBLE);
		sym* t = gentemp(_DOUBLE);

		emit(MULT,t->name,NumberToString($1->symp->type->length),NumberToString($1->symp->type->width));    // calculate new offset
		emit(SUB,t->name,t->name,$1->loc->name);
		emit(ARRR,t->name,$1->symp->name,t->name);                    // t->name = $1->symp->name[t->name]
		emit(ARRL,$1->symp->name,$1->loc->name,t->name);              // $1->symp->name[$$->loc->name] = t->name
	}
	| postfix_expression CO CC
	| postfix_expression CO argument_expression_list CC {
		$$ = new unary();
		$$->symp = gentemp($1->type->cat);
		string ss = $$->symp->name;
		emit(CALL, $$->symp->name, $1->symp->name, tostr($3));
	}
	| postfix_expression DOT IDENTIFIER /* Ignored */
	| postfix_expression PTR_OP IDENTIFIER  /* Ignored */
	
	
	
	| primary_expression BO expression BC BO expression BC {
	  //	cout<<"postfix_expression => primary_expression [expression] [expression]\n";
    //int i=0;
    //cout<<i<<endl; i++;
		$$ = new unary();
    //cout<<i<<endl; i++;
		$$->ismatrix = true;
    //cout<<i<<endl; i++;
		$$->symp = $1->symp;
    //cout<<i<<endl; i++;
		sym* t = gentemp(_DOUBLE);
    //cout<<i<<endl; i++;
		emit(MULT, t->name, $3->symp->name, NumberToString(8));       // offset = rownumber * totalcolumns *8 
    //cout<<i<<endl; i++;
    	emit(MULT,t->name,t->name,NumberToString($1->symp->type->length));
    sym* temp = gentemp(_DOUBLE);
    	emit(MULT,temp->name, $6->symp->name, NumberToString(8));
 		emit(ADD, t->name, temp->name, t->name);                      // offset = offset + column * 8
    //cout<<i<<endl; i++;
    $$->loc=gentemp(_DOUBLE);
 		emit (EQUAL, $$->loc->name, t->name );                        // $$->loc = offset
 		//emit (EQUAL, temporary->name,$$->loc->name );
    //$$->loc->init = $3->symp->init * $3->symp->size * $6->symp->init;
    //cout<<"postfix_expression => primary_expression [expression] [expression]\n";
	}
	| primary_expression  {
		$$ = new unary ();
		//string ss = "null";
		$$->symp = $1->symp;
		$$->loc = $$->symp;
		//ss = "local";
		$$->type = $1->symp->type;
	}
	| postfix_expression INC_OP {
		$$ = new unary();
		if($1->ismatrix){
			$$->symp = gentemp(_DOUBLE);
			sym *temp = gentemp(_DOUBLE);
			emit(ARRR , temp->name , $1->symp->name , $1->loc->name);   // temp->name = $1->symp->name[$1->symp->loc]
			emit(EQUAL,$$->symp->name,temp->name);                      // $$->symp->name = temp->name
			emit (ADD, temp->name, temp->name, "1");	                  // temp->name = temp->name + 1 
			emit(ARRL , $1->symp->name,$1->loc->name,temp->name);       // $1->symp->name[$1->symp->loc] = temp->name
		}else{
		                                                                // copy $1 to $$
		$$->symp = gentemp($1->symp->type->cat);                      
		string ss = $$->symp->name;
		emit (EQUAL, $$->symp->name, $1->symp->name);                 // $$->symp->name = $1->symp->name

		                                                                // Increment $1
		emit (ADD, $1->symp->name, $1->symp->name, "1"); }          // $1->symp->name = $1->symp->name + 1
	}
	
	;

argument_expression_list
	: argument_expression_list COM assignment_expression {
		string ss = $3->symp->name;
		emit (PARAM, $3->symp->name);                               //param$3->symp->name
		$$ = $1+1;
	}
	| assignment_expression {
		string ss = $1->symp->name;
		emit (PARAM, $1->symp->name);                                   //param $1->symp->name
		$$ = 1;
	}
	
	;

unary_expression
	: DEC_OP unary_expression {
		if($2->ismatrix){
			$$ = new unary();
			$$->symp = gentemp(_DOUBLE);
			emit(ARRR, $$->symp->name , $2->symp->name , $2->loc->name);      // $$->symp->name = $2->symp->name[$2->loc->name]
			emit( SUB, $$->symp->name , $$->symp->name , "1");	              // $$->symp->name = $$->symp->name -1
			emit(ARRL, $2->symp->name , $2->loc->name  , $$->symp->name);     // $2->symp->name[$2->loc->name] =  $$->symp->name 

		}
		                                                                                    // Decrement $1
		else{
			$$ = new unary();
			string ss = $2->symp->name;
			emit (SUB, $2->symp->name, $2->symp->name, "1");                    // $2->symp->name = $2->symp->name - 1
			ss += "null";
			                                                                                    // Use the same value
			$$ = $2;
		}
	}
	| unary_operator cast_expression {
		$$ = new unary();
		switch ($1) {
			case '~':
				if($2->ismatrix){

					$$->symp = gentemp(_DOUBLE);
					emit(ARRR, $$->symp->name , $2->symp->name , $2->loc->name);      // $$->symp->name = $2->symp->name [$2->loc->name ]
					emit(BNOT, $$->symp->name , $$->symp->name);	                    //  $$->symp->name ~= $$->symp->name
					//emit(ARRL, $2->symp->name,$2->loc->name,$$->symp->name);

					break;
				}
				else{
					$$->symp = gentemp($2->symp->type->cat);
					int offs;
					emit (BNOT, $$->symp->name, $2->symp->name);                        //  $$->symp->name ~= $$->symp->name
					break;
				}
			case '+':
				if($2->ismatrix){
				//	cout << "im herre\n";
					$$->symp = gentemp(_DOUBLE);
					emit(ARRR, $$->symp->name , $2->symp->name , $2->loc->name);          // $$->symp->name = $2->symp->name [$2->loc->name ]
					//emit(ARRL, $2->symp->name,$2->loc->name,$$->symp->name);

					break;	
				}
				else{
					$$ = $2;
					break;
				}
			case '*':
					if($2->ismatrix){
						$$->symp = gentemp(_DOUBLE);
						$$->symp->type->ptr = $2->symp->type;
						sym* temp = gentemp(_DOUBLE);
						emit(ARRR, temp->name , $2->symp->name , $2->loc->name);         // $$->symp->name = $2->symp->name [$2->loc->name ]
						emit (PTRR, $$->symp->name, temp->name);
					//offset++;                                                             //  $$->symp->name = *$$->symp->name
						break;
					}
					else{
						debug ("got pointer");
						$$->cat = PTR;
						debug ($2->symp->name);
						$$->loc = gentemp ($2->symp->type->ptr);                    // temp of type ptr
						int offset;
						emit (PTRR, $$->loc->name, $2->symp->name);                   // $$->symp->name = *$$->symp->name 
						offset++;
						$$->symp = $2->symp;                                          
						debug ("here pointer");
						break;
					}
			
			case '&':
				if($2->ismatrix){
					$$->symp = gentemp(PTR);
					$$->symp->type->ptr = $2->symp->type;
					sym* temp = gentemp(_DOUBLE);                                         // $$->symp->name = $2->symp->name [$2->loc->name ]
					emit(ARRR, temp->name , $2->symp->name , $2->loc->name);                  // $$->symp->name = &$$->symp->name 
					emit (ADDRESS, $$->symp->name, temp->name);
					//offset++;
					break;
				}
				else{
					$$->symp = gentemp(PTR);
					$$->symp->type->ptr = $2->symp->type; 
					int size;
					emit (ADDRESS, $$->symp->name, $2->symp->name);                       // $$->symp->name = &$2->symp->name 
					//offset++;
					break;
				}
			
			case '!':

				if($2->ismatrix){
					int i=10;
					//cout << i++ << endl;
					$$->symp = gentemp(_DOUBLE);
					//cout << i++ << endl;
					emit(ARRR, $$->symp->name , $2->symp->name , $2->loc->name);          // $$->symp->name = $2->symp->name [$2->loc->name ]
					//cout << i++ << endl;
					emit(LNOT, $$->symp->name , $$->symp->name);	                // $$->symp->name = !$$->symp->name 
					//emit(ARRL, $2->symp->name,$2->loc->name,$$->symp->name);
					cout << i++ << endl;
					break;

				}
				else{
					$$->symp = gentemp($2->symp->type->cat);
				
					emit (LNOT, $$->symp->name, $2->symp->name);                          // $$->symp->name = !$2->symp->name 
					
					break;
				}
			case '-':
				//cout << " - " << endl;
				if($2->ismatrix){
					int i = 12;
					//cout << i++ << endl;
					sym* temp = gentemp(_DOUBLE);
					$$->symp = gentemp(_DOUBLE);
					//cout << i++ << endl;
					emit(ARRR, temp->name , $2->symp->name , $2->loc->name);    // $$->symp->name = $2->symp->name [$2->loc->name ]
					//emit(ARRL, $2->symp->name,$2->loc->name,$$->symp->name);
					//cout << i++ << endl;
					emit (UMINUS, $$->symp->name, temp->name);                    // $$->symp->name = -$$->symp->name 
					//cout << i++ << endl;	
					break;	
				}
				else{

					$$->symp = gentemp($2->symp->type->cat);
				
					emit (UMINUS, $$->symp->name, $2->symp->name);                // $$->symp->name = -$2->symp->name 
				
					break;
				}
			
			default:
				break;
		}
	}
	
	
	| INC_OP unary_expression {
		
		if($2->ismatrix){
			$$ = new unary();
			int i = 10;
			//cout << i++ << endl;
			$$->symp = gentemp(_DOUBLE);
			//cout << i++ << endl;
			emit(ARRR, $$->symp->name , $2->symp->name , $2->loc->name);    // $$->symp->name = $2->symp->name [$2->loc->name ]
			//cout << i++ << endl;
			emit(ADD , $$->symp->name , $$->symp->name , "1");	               // $$->symp->name = $$->symp->name - 1 
			//cout << i++ << endl;
			emit(ARRL, $2->symp->name , $2->loc->name  , $$->symp->name);     // $2->symp->name[$2->loc->name] =  $$->symp->name 
			//cout << i++ << endl;
		}
		else{
			$$ = new unary();
		                                                                                            	// Increment $1
			emit (ADD, $2->symp->name, $2->symp->name, "1");
			                                                                                          // Use the same value
			$$ = $2;
		}
	}
	
	| postfix_expression {
		$$ = $1;
		                                                                                    //cout << "as\n";
                                                                                 //		debug ($$->symp);
	}
	
	;

unary_operator
	
	: '*' {
		$$ = '*';
	}
	
	| '+' {
		$$ = '+';
	}
	| '-' {
		$$ = '-';
	}
	| '&' {
		$$ = '&';
	}
	;

cast_expression
	: unary_expression  {
		$$ = $1;
	}
;
multiplicative_expression
	: multiplicative_expression '*' cast_expression {
		if (typecheck ($1->symp, $3->symp) ) {                      // check for compatible types
			int x; 
			$$ = new expr();
			$$->symp = gentemp($1->symp->type->cat);
			x = x + 1;
			emit (MULT, $$->symp->name, $1->symp->name, $3->symp->name);    // $$->symp->name = $1->symp->name * $3->symp->name
		}
		else cout << "Type Error"<< endl;
	}
	| cast_expression {
		                                                    // Now the cast expression can't go to LHS of assignment_expression
		                                                    // So we can safely store the rvalues of pointer and arrays in temporary
		                                                    // We don't need to carry lvalues anymore
		$$ = new expr();
		if ($1->cat==ARR) {                                       // Array
			string ss;
			$$->symp = gentemp($1->loc->type);
			ss = $$->symp->name;
			emit(ARRR, $$->symp->name, $1->symp->name, $1->loc->name);       // $$->symp->name = $1->symp->name[$1->loc->name]
		}
		else if ($1->cat==PTR) {                                            // Pointer
			int z;
			$$->symp = $1->loc;
		}
		else {                                                              // otherwise
			int k;
			$$->symp = $1->symp;
		}
	}
	
	
	| multiplicative_expression '/' cast_expression{
		int z;
		if (typecheck ($1->symp, $3->symp) ) {                          // check for compatible types
			$$ = new expr();
			int size;
			$$->symp = gentemp($1->symp->type->cat);
			string ss = $$->symp->name;
			size++;
			emit (DIVIDE, $$->symp->name, $1->symp->name, $3->symp->name);     // $$->symp->name = $1->symp->name / $3->symp->name
			size = size*size;
		}
		else cout << "Type Error"<< endl;
	}
	| multiplicative_expression '%' cast_expression {
		if (typecheck ($1->symp, $3->symp) ) {                        // check for compatible types
			$$ = new expr();
			int width;
			width--;
			$$->symp = gentemp($1->symp->type->cat);
			string s1 = $$->symp->name;
			emit (MODOP, $$->symp->name, $1->symp->name, $3->symp->name);    // $$->symp->name = $1->symp->name / $3->symp->name
		}
		else cout << "Type Error"<< endl;
	}
	
	;

additive_expression
	
	: additive_expression '+' multiplicative_expression {
		if (typecheck($1->symp, $3->symp)) {                       // check for compatible types
			$$ = new expr();
			int addint = 4;
			$$->symp = gentemp($1->symp->type->cat);
			string ss = $$->symp->name;
			emit (ADD, $$->symp->name, $1->symp->name, $3->symp->name);   // $$->symp->name = $1->symp->name + $3->symp->name
			addint+=4;
		}
		else cout << "Type Error"<< endl;
	}
	| additive_expression '-' multiplicative_expression {
		if (typecheck($1->symp, $3->symp)) {                      // check for compatible types
			$$ = new expr();
			int addinteger = 4;
			$$->symp = gentemp($1->symp->type->cat);
			int size;
			string ss = $$->symp->name;
			size = 4;
			emit (SUB, $$->symp->name, $1->symp->name, $3->symp->name);   // $$->symp->name = $1->symp->name - $3->symp->name
			addinteger+=1;
		}
		else cout << "Type Error"<< endl;
	}
	| multiplicative_expression {$$ = $1;}
	;

shift_expression
	: additive_expression {$$ = $1;}
	
	| shift_expression RIGHT_OP additive_expression {
		if ($3->symp->type->cat == _INT) {
			$$ = new expr();
			int expression = 1;
			$$->symp = gentemp (_INT);
			string ss = $$->symp->name;
			emit (RIGHTOP, $$->symp->name, $1->symp->name, $3->symp->name);  // $$->symp->name = $1->symp->name >> $3->symp->name
			expression--;
		}
		else cout << "Type Error"<< endl;
	}
	| shift_expression LEFT_OP additive_expression {
		if ($3->symp->type->cat == _INT) {
			$$ = new expr();
			int val = 1;
			$$->symp = gentemp (_INT);
			string ss = $$->symp->name;
			emit (LEFTOP, $$->symp->name, $1->symp->name, $3->symp->name);      // $$->symp->name = $1->symp->name << $3->symp->name
		}
		else cout << "Type Error"<< endl;
	}
	;

relational_expression
	: relational_expression LET shift_expression {
		if (typecheck ($1->symp, $3->symp) ) {
			// New bool
			$$ = new expr();
			int val = 1;
			$$->isbool = true;

			$$->truelist = makelist (nextinstr());
			$$->falselist = makelist (nextinstr()+1);
			int width;
			emit(LT, "", $1->symp->name, $3->symp->name);             // $1->symp->name <= $3->symp->name goto truelist , else falselist
			val++;
			emit (GOTOOP, "");
		}
		else cout << "Type Error"<< endl;
	}
	| relational_expression GE_OP shift_expression {
		if (typecheck ($1->symp, $3->symp) ) {
			// New bool
			$$ = new expr();
			int nval = 4;
			$$->isbool = true;
			$$->truelist = makelist (nextinstr());
			$$->falselist = makelist (nextinstr()+1);
			int width;
			nval++;
			emit(LE, "", $1->symp->name, $3->symp->name);                 // $1->symp->name >= $3->symp->name goto truelist , else falselist
			emit (GOTOOP, "");
			nval++;
		}
		else cout << "Type Error"<< endl;
	}
	| shift_expression { $$ = $1;}
	| relational_expression GET shift_expression {
		if (typecheck ($1->symp, $3->symp) ) {
			// New bool
			$$ = new expr();
			$$->isbool = true;

			$$->truelist = makelist (nextinstr());
			$$->falselist = makelist (nextinstr()+1);
			int width ;
			emit(GT, "", $1->symp->name, $3->symp->name);             // $1->symp->name > $3->symp->name goto truelist , else falselist
			emit (GOTOOP, "");
			width = 4;
		}
		else cout << "Type Error"<< endl;
	}
	| relational_expression LE_OP shift_expression {
		if (typecheck ($1->symp, $3->symp) ) {
			// New bool
			$$ = new expr();
			$$->isbool = true;
			int address = 0;
			$$->truelist = makelist (nextinstr()); 
			$$->falselist = makelist (nextinstr()+1);
			int width;
			emit(LE, "", $1->symp->name, $3->symp->name);          // $1->symp->name < $3->symp->name goto truelist , else falselist
			emit (GOTOOP, "");
			address++;
		}
		else cout << "Type Error"<< endl;
	}
	
	;

equality_expression
		: equality_expression EQ_OP relational_expression {
		if (typecheck ($1->symp, $3->symp) ) {
			                                                                                // If any is bool get its value
		
			convertfrombool ($1);
			convertfrombool ($3);
			int eqal = 1;
			$$ = new expr();
			$$->isbool = true;
			eqal++;
			$$->truelist = makelist (nextinstr());
			$$->falselist = makelist (nextinstr()+1);
			int width;
			emit (EQOP, "", $1->symp->name, $3->symp->name);
			eqal++;
			emit (GOTOOP, "");
			eqal++;
		}
		else cout << "Type Error"<< endl;
	}
	| equality_expression NE_OP relational_expression {
		if (typecheck ($1->symp, $3->symp) ) {
			                                                                            // If any is bool get its value
			int i=11;
			//cout << i++ << endl;
			convertfrombool ($1);
			//cout << i++ << endl;
			convertfrombool ($3);
			//cout << i++ << endl;
			string str = "null";
			$$ = new expr();
			//cout << i++ << endl;
			$$->isbool = true;
			//cout << i++ << endl;
			str+="temp";
			$$->truelist = makelist (nextinstr());                      // truelist
			//cout << i++ << endl;
			$$->falselist = makelist (nextinstr()+1);                           // falselist
			//cout << i++ << endl;
			int width;
			str+="local";
			emit (NEOP, "", $1->symp->name, $3->symp->name);      // $1->symp->name!=$3->symp->name goto truelist, else goto falselist
			//cout << i++ << endl;
			emit (GOTOOP,"");
			str+="local";
		}
		else cout << "Type Error"<< endl;
	}
	| relational_expression {$$ = $1;}

	;

and_expression
	: equality_expression {$$ = $1;}

	| and_expression '&' equality_expression {
		if (typecheck ($1->symp, $3->symp) ) {
			$$ = new expr();
			$$->isbool = false;
			string typeinit = "null";
			$$->symp = gentemp (_INT);
			string ss = $$->symp->name;
			emit (BAND, $$->symp->name, $1->symp->name, $3->symp->name);    // $$->symp->name = $1->symp->name & $3->symp->name
			typeinit += "temp";
		}
		else cout << "Type Error"<< endl;
	}
		;

exclusive_or_expression
	: and_expression {$$ = $1;}

	| exclusive_or_expression POW and_expression {
		if (typecheck ($1->symp, $3->symp) ) {
			                                                                            // If any is bool get its value
			convertfrombool ($1);
			string ssx = "null";
			convertfrombool ($3);
			ssx+="temp";
			$$ = new expr();
			$$->isbool = false;
			ssx+="local";
			$$->symp = gentemp (_INT);
			string ss = $$->symp->name;
			emit (XOR, $$->symp->name, $1->symp->name, $3->symp->name);     // $$->symp->name = $1->symp->name ^ $3->symp->name
			ssx+="empty";
		}
		else cout << "Type Error"<< endl;
	}
		;

inclusive_or_expression
	: exclusive_or_expression {$$ = $1;}
	| inclusive_or_expression UOR exclusive_or_expression {
		if (typecheck ($1->symp, $3->symp) ) {
			                                                                                  // If any is bool get its value
			convertfrombool ($1);
			string uniq= "null";
			convertfrombool ($3);
			uniq+="local";
			$$ = new expr();
			$$->isbool = false;
			uniq+="temp";
			$$->symp = gentemp (_INT);
			string ss = $$->symp->name;
			emit (INOR, $$->symp->name, $1->symp->name, $3->symp->name);
			uniq+="temp";
		}
		else cout << "Type Error"<< endl;
	}
	;

logical_and_expression
	: inclusive_or_expression {$$ = $1;}
	| logical_and_expression N AND_OP M inclusive_or_expression {
		convert2bool($5);
		string convboo = "null";
		                                                                                // N to convert $1 to bool
		backpatch($2->nextlist, nextinstr());
		convert2bool($1);
		convboo+="temp";
		$$ = new expr();
		$$->isbool = true;
		convboo+="local";
		backpatch($1->truelist, $4);
		$$->truelist = $5->truelist;
		$$->falselist = merge ($1->falselist, $5->falselist);
		convboo+="null";
	}
	;

logical_or_expression
	: logical_and_expression {$$ = $1;}
	| logical_or_expression N OR_OP M logical_and_expression {
		convert2bool($5);
		string convbool = "null";
		                                                                                // N to convert $1 to bool
		backpatch($2->nextlist, nextinstr());
		convert2bool($1);
		convbool+="temp";
		$$ = new expr();
		$$->isbool = true;
		convbool+="true";
		backpatch ($$->falselist, $4);
		$$->truelist = merge ($1->truelist, $5->truelist);
		$$->falselist = $5->falselist;
		convbool+= "true";
	}
	;


;
conditional_expression
		: logical_or_expression N Q M expression N POL M conditional_expression {
                                                                                              //		convert2bool($5);
		$$->symp = gentemp();
		$$->symp->update($5->symp->type);
		string sss = "null";
		emit(EQUAL, $$->symp->name, $9->symp->name);
		lint l = makelist(nextinstr());
		emit (GOTOOP, "");
		sss+="local";
		backpatch($6->nextlist, nextinstr());
		emit(EQUAL, $$->symp->name, $5->symp->name);
		lint m = makelist(nextinstr());
		l = merge (l, m);
		string s = "";
		emit (GOTOOP, "");
		sss+="temp";
		backpatch($2->nextlist, nextinstr());
		convert2bool ($1);
		backpatch ($1->truelist, $4);
		backpatch ($1->falselist, $8);
		backpatch (l, nextinstr());
		sss+="null";
	}
	| logical_or_expression {$$ = $1;}

	;

assignment_expression
	
	: unary_expression assignment_operator assignment_expression {
		switch ($1->cat) {
			                                                                                            //cout << "IM HERE" << endl;
			case ARR:
				//cout << "ARR" << endl;
				emit(ARRL,$1->symp->name,$1->loc->name,$3->symp->name);
				$$ = $3;
				break;
			case PTR:
				int off;
				emit(PTRL, $1->symp->name, $3->symp->name);
				$$ = $3;	
				break;
			default:
				//cout << "def\n";
				if($1->ismatrix){
					//cout << "MATRIX" << endl;
					emit(ARRL,$1->symp->name,$1->loc->name,$3->symp->name);         // $1->symp->name = $1->loc->name[$3->symp->name]
				$$ = $3;
				break;
				}
				else{
						 
							//cout << "default" << endl;
							$3->symp = conv($3->symp, $1->symp->type->cat);
							string s = $1->symp->name;
							emit(EQUAL, $1->symp->name, $3->symp->name);
							$$ = $3;
							break;
						
				}	
				
		}
		//cout << "out switch" << endl;
		
	}

	| conditional_expression {
		$$ = $1;
	}
	;

assignment_operator
  : EQ

  	| MUL_ASSIGN
	| DIV_ASSIGN
	| MOD_ASSIGN
	| ADD_ASSIGN
	| SUB_ASSIGN
	| LEFT_ASSIGN
	| RIGHT_ASSIGN
	
	| AND_ASSIGN
	| XOR_ASSIGN
	| OR_ASSIGN
	;

expression
	: assignment_expression {
		//cout << "exp ==> assignment_expression\n";
		$$ = $1;
	}
	| expression COM assignment_expression
	//cout << "exp ==> expression COM assignment_expression\n";
	{printf("expression\n");}
	;

constant_expression
	: conditional_expression
	{printf("constant_expression\n");}
	;

/*** Declaration ***/

declaration
	
	: declaration_specifiers init_declarator_list SECOL {
		debug ("declaration");
	}
	| declaration_specifiers SECOL {

	}
	;

declaration_specifiers

	
	: type_specifier declaration_specifiers {printf("declaration_specifiers\n");}
  | type_specifier
	
	;

init_declarator_list
	
	: init_declarator_list COM init_declarator {
		debug("init_declarator_list");
	}
	| init_declarator
	;

init_declarator
	: declarator EQ initializer {
		//int i =111;
		//cout << i++ << endl;
		debug ($1->name);
		//cout << i++ << endl;
		debug ($3->name);
		//cout << i++ << endl;
		debug ($3->init);
		//cout << i++ << endl;
		//cout << $3->init << endl;
		if ($3->init!="") {//cout << i++ << endl;
			$1->initialize($3->init);}
		//cout << i++ << endl;
		emit (EQUAL, $1->name, $3->name);                                                    // $1->name = $3->name
		//cout << i++ << endl;
		debug ("here init");
	}
	| declarator {
		$$ = $1;
	}
	
	;

type_specifier
	
	: CHAR {
		TYPE = _CHAR;
	}
	| SHORT
	| INT {
		TYPE = _INT;
	}
	| VOID {
		TYPE = _VOID;
	}
	| LONG
	| FLOAT
	| DOUBLE {
		TYPE = _DOUBLE;
	}
	| SIGNED
	| UNSIGNED
	| BOOL
	| COMPLEX
	| MATRIX
  
	;


declarator
	: direct_declarator
	| pointer direct_declarator {
		symtype * t = $1;
		while (t->ptr !=NULL) t = t->ptr;
		t->ptr = $2->type;
		$$ = $2->update($1);
	}
	
	;

direct_declarator
	: IDENTIFIER {
		$$ = $1->update(TYPE);
		debug ("currsym: "<< $$->name);
		currsym = $$;
	}
	| CO declarator CC {
		$$ = $2;
	}

	| direct_declarator BO assignment_expression BC BO assignment_expression BC {
		symtype * t = $1 -> type;
		string decre = "null";
		symtype * prev = NULL;
		while (t->cat == ARR) {
			prev = t;
			t = t->ptr;
		}
		decre+="temp";
		if (prev==NULL) {
			int x = atoi($3->symp->init.c_str());                                                                  // width
			int y = atoi($6->symp->init.c_str());                                                                  // length
			symtype* s = new symtype(ARR, $1->type, x ,y);
			 y = sizeoftype(s);
			$$ = $1->update(s);
		}
		
		else {
			decre+="temp";
			prev->ptr =  new symtype(ARR, t, atoi($3->symp->init.c_str()) , atoi($6->symp->init.c_str())); // set dim
			$$ = $1->update ($1->type);
			decre+="temp";
		}
		
	}
	| direct_declarator BO BC BO BC {
		symtype * t = $1 -> type;
		symtype * prev = NULL;
		string decar = "null";
		while (t->cat == ARR) {
			prev = t;
			t = t->ptr;
		}
		decar+="null";
		if (prev==NULL) {
			symtype* s = new symtype(ARR, $1->type, 0);
			int y = sizeoftype(s);
			$$ = $1->update(s);
		}
		else {
			int sizofint = 4;
			prev->ptr =  new symtype(ARR, t, 0);
			$$ = $1->update ($1->type);
			sizofint+=1;
		}
		
	}

	| direct_declarator CO CST parameter_type_list CC {
		table->tname = $1->name;
		int zero = 0;
		if ($1->type->cat !=_VOID) {
			sym *s = table->lookup("retVal");
			s->update($1->type);		
		}
		zero+=4;
		$1 = $1->linkst(table);
		zero++;
		table->parent = gTable;
		changeTable (gTable);				                                                // Come back to globalsymbol table
		zero++;
		debug ("currsym: "<< $$->name);
		currsym = $$;						
	}
	| direct_declarator CO identifier_list CC {                                     /* Ignored */

	}
	| direct_declarator CO CST CC {		
		table->tname = $1->name;			                                          // Update function symbol table name
		int sint = 4;
		if ($1->type->cat !=_VOID) {
			sym *s = table->lookup("retVal");                                   // Update type of return value
			s->update($1->type);
		}
		sint++;
		$1 = $1->linkst(table);		                                              // Update type of function in global table
		sint--;
		table->parent = gTable;
		changeTable (gTable);				                                            // Come back to globalsymbol table
		sint--;
		debug ("currsym: "<< $$->name);
		currsym = $$;
		sint++;
	}
	;



pointer
	: '*' pointer {
		$$ = new symtype(PTR, $2);
	}
	
	| '*' {
		$$ = new symtype(PTR);
	}
	
	
	;




parameter_type_list
	: parameter_list
	
	;

parameter_list
	: parameter_declaration
	| parameter_list COM parameter_declaration {
		debug("parameter_list");
	}
	;

parameter_declaration
	: declaration_specifiers declarator {
		debug ("here");
		$2->category = "param";
	}
	| declaration_specifiers
	{printf("parameter_declaration\n");}
	;

identifier_list
	: IDENTIFIER 
	| identifier_list COM IDENTIFIER
	{printf("identifier_list\n");}
	;


initializer
	: BRO initializer_row_list BRC {}
	| assignment_expression {
		$$ = $1->symp;
	}
	

	;
initializer_row_list : initializer_row {}
|initializer_row_list SECOL initializer_row {}
;

initializer_row : initializer {}
|designation initializer 
|initializer_row COM initializer    
|initializer_row COM designation initializer
{printf("initializer_row\n");}
;

designation
	: designator_list EQ
	{printf("designation\n");}
	;

designator_list
	: designator_list designator

	| designator
		{printf("designator_list\n");}
	;

designator
	: BO constant_expression BC BO constant_expression BC {cout << "here\n";}
	| DOT IDENTIFIER
	{printf("designator\n");}
	;

statement
	
	
	: compound_statement {
		$$ = $1;
		debug("Compound Statement");
	}
	| expression_statement {
		$$ = new statement();
		$$->nextlist = $1->nextlist;
		debug("Expression Statement");
	}
	| iteration_statement {
		$$ = $1;
		debug("iteration statement");
	}
	| selection_statement {
		$$ = $1;
		debug("selection statement\n");
	}
	| labeled_statement /* Skipped */
	
	| jump_statement {
		$$ = $1;
		debug("jump statement");
	}
	;

labeled_statement /* Ignored */
	: IDENTIFIER POL statement {$$ = new statement();}
	| CASE constant_expression POL statement {$$ = new statement();}
	| DEFAULT POL statement {$$ = new statement();}
	;

compound_statement
	: BRO BRC { $$ = new statement();}
	| BRO block_item_list BRC {
		$$ = $2;
	}
	;

block_item_list
	: block_item_list M block_item {
		$$ = $3;
	/*	
		debug ("M.instruction = " << $2);

		if (gDebug) {
			debug ("1 contains: ");
			printlist($1->nextlist);
		} 

		if (gDebug) {
			debug ("3 contains: ");
			printlist($3->nextlist);
		} 
	*/
		backpatch ($1->nextlist, $2);
	//	debug ("backpatching 1 done");
	}
	| block_item {
		$$ = $1;		
	}
	
	;

block_item
	
	: statement {
		$$ = $1;
	/*	debug ("-------------------------------------------------");
		debug ("statement next instruction");
		if (gDebug) {
			printlist($$->nextlist);
		} 
	*/
	}
	| declaration { 
		$$ = new statement();
	/*	debug ("-------------------------------------------------");
		debug ("declaration next instruction");
		if (gDebug) {
			printlist($$->nextlist);
		} 
	*/
	}
	;

expression_statement
	
	: expression SECOL {
		$$ = $1;
	}
	| SECOL {	$$ = new expr();}
	;

selection_statement
	: SWITCH CO expression CC statement                                           /* Skipped */
	{printf("selection_statement\n");}
	| IF CO expression N CC M statement N {
		backpatch ($4->nextlist, nextinstr());
		convert2bool($3);
		$$ = new statement();
		backpatch ($3->truelist, $6);
		lint temp = merge ($3->falselist, $7->nextlist);
		$$->nextlist = merge ($8->nextlist, temp);
		
	}
	| IF CO expression N CC M statement N ELSE M statement {                          // 100 if f==0, goto m1, //101  goto m2
		backpatch ($4->nextlist, nextinstr());
		convert2bool($3);
		backpatch ($3->truelist, $6);
		backpatch ($3->falselist, $10);
		lint temp = merge ($7->nextlist, $8->nextlist);
		$$->nextlist = merge (temp, $11->nextlist);
	}
	
	;

iteration_statement 	
	: DO M statement M WHILE CO expression CC SECOL {
		$$ = new statement();
		convert2bool($7);
		                                                                        // M1 to go back to statement if expression is true
	                                                              	// M2 to go to check expression if statement is complete
		backpatch ($7->truelist, $2);
		backpatch ($3->nextlist, $4);

		                                                                    // Some bug in the next statement
		$$->nextlist = $7->falselist;

	}
	| FOR CO expression_statement M expression_statement CC M statement {
		$$ = new statement();
		convert2bool($5);
		backpatch ($5->truelist, $7);
		backpatch ($8->nextlist, $4);
		emit (GOTOOP, tostr($4));
		$$->nextlist = $5->falselist;
	}
	| WHILE M CO expression CC M statement { 
		$$ = new statement();
		convert2bool($4);
		                                                                            // M1 to go back to boolean again
		                                                    // M2 to go to statement if the boolean is true
		backpatch($7->nextlist, $2);
		backpatch($4->truelist, $6);
		$$->nextlist = $4->falselist;
		                                                  // Emit to prevent fallthrough
		emit (GOTOOP, tostr($2));
	}
	
	| FOR CO expression_statement M expression_statement M expression N CC M statement {
		$$ = new statement();
		convert2bool($5);
		backpatch ($5->truelist, $10);
		backpatch ($8->nextlist, $4);
		backpatch ($11->nextlist, $6);
		emit (GOTOOP, tostr($6));
		$$->nextlist = $5->falselist;
	                                                                            //	debug ("for done");
	}
	;

jump_statement /* Ignored except return */
	
	: CONTINUE SECOL {$$ = new statement();}
	| BREAK SECOL {$$ = new statement();}
	| RETURN SECOL {
		$$ = new statement();
		emit(_RETURN,"");
	}
	| RETURN expression SECOL{
		$$ = new statement();
	//	if (table->lookup("retVal")->type->cat==$2->symp->type->cat) {
			emit(_RETURN,$2->symp->name);
	//	}
	//	else yyerror("Wrong return type\n");			

	}
	| GOTO IDENTIFIER SECOL {$$ = new statement();}
	;

translation_unit
	 
	: translation_unit external_declaration {
                                                                          //		if (gDebug) table->printall();
	}
	| external_declaration
	;

external_declaration
	: function_definition
	| declaration

	
		;

function_definition
	
	: declaration_specifiers declarator CST compound_statement {
                                                                    //		table->tname = $2->name;
		
                                                                    //		$2 = $2->update(FUNC, table);
		table->parent = gTable;
		changeTable (gTable);
	}
	| declaration_specifiers declarator declaration_list CST compound_statement {

	}
	;
declaration_list
	
	: declaration_list declaration
	{printf("declaration_list\n");}
	| declaration
	;

%%

void yyerror(const char *s) {
	printf ("ERROR: %s",s);
}
