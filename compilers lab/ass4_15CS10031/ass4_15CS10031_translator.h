/*
* 	translator.h
* 	Author: Pankaj Dhurve
*/
#ifndef TRANSLATE 
#define TRANSLATE
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#define size_of_char 		1
#define size_of_int  		4
#define size_of_double		8
#define size_of_pointer		4

#define debug(x) do { \
  if (gDebug) { cerr << x << std::endl; } \
} while (0)

extern  char* yytext;
extern  int yyparse();

using namespace std;

/********* Forward Declarations ************/

class sym;						// Entry in a symbol table
class symtab;					// Symbol Table
class quad;						// Entry in quad array
class quads;					// All Quads
class symtype;				// Type of a symbol in symbol table

/************** Enum types *****************/

enum type_e {	// Type enumeration
_VOID, _CHAR, _INT, _DOUBLE, PTR, ARR, FUNC}; 	
enum optype { EQUAL, 
// Relational Operators 
LT, GT, LE, GE, EQOP, NEOP,
GOTOOP, _RETURN,
// Arithmatic Operators
ADD, SUB, MULT, DIVIDE, RIGHTOP, LEFTOP, MODOP,
// Unary Operators
UMINUS, UPLUS, ADDRESS, RIGHT_POINTER, BNOT, LNOT,
// Bit Operators
BAND, XOR, INOR,
// PTR Assign
PTRL, PTRR,
// ARR Assign
ARRR, ARRL,
// Function call
PARAM, CALL, LABEL
};

/********** Class Declarations *************/

class symtype { // Type of an element in symbol table
public:
	symtype(type_e cat, symtype* ptr = NULL, int width = 1, int length = 1);
	int width;					// Size of array
	symtype* ptr;				// Array -> array of ptr type; pointer-> pointer to ptr type 
	type_e cat;
  int length;
	friend ostream& operator<<(ostream&, const symtype);
};

class sym { // Row in a Symbol Table
public:
	symtab* nest;				// Pointer to nested symbol table
	int size;					// Size of the type of symbol
	string category;			// local, temp or global
	int offset;					// Offset of symbol computed at the end
	string init;				// Symbol initialisation
	string name;				// Name of symbol
	symtype *type;				// Type of Symbol

	sym (string, type_e t=_INT, symtype* ptr = NULL, int width = 0);
	sym* linkst(symtab* t);
	sym* initialize (string);
	sym* update(type_e t); 		// Update using raw type and nested table pointer
	friend ostream& operator<<(ostream&, const sym*);
	sym* update(symtype * t); 	// Update using type object and nested table pointer
};

class symtab { // Symbol Table
public:
	symtab* parent;
	list <sym> table; 			// The table of symbols
	int tcount;					// Count of temporary variables
	string tname;				// Name of Table

	symtab (string name="");
	void computeOffsets();						// Compute offset of the whole symbol table recursively
	void print(int all = 0);					// Print the symbol table
	sym* lookup (string name);					// Lookup for a symbol in symbol table
};

class quad { // Individual Quad
public:
	string arg2;				// Argument 2
	string arg1;				// Argument 1
	string result;				// Result
	optype op;					// Operator

	quad (string result, int arg1, optype op = EQUAL, string arg2 = "");
	quad (string result, string arg1, optype op = EQUAL, string arg2 = "");
	void update (int addr);						// Used for backpatching address
	void print ();								// Print Quads
};

class quads { // Quad Array
public:
	vector <quad> array;;		// Vector of quads

	void printtab();							// Print quads in tabular form
	void print ();								// Print all the quads
	quads () {array.reserve(300);}
};

class Singleton {	// Global Symbol Table is Singleton Object
public:
   static Singleton* GetInstance();
private:
   Singleton();
   static Singleton* pSingleton;					// singleton instance
};

/*********** Function Declarations *********/

typedef list<int> lint;
int nextinstr();									// Returns the address of the next instruction
string NumberToString(int);							// Converts a number to string mainly used for storing numbers
void changeTable (symtab* newtable);
sym* gentemp (symtype* t, string init = "");		// Generate a temporary variable and insert it in symbol table
sym* gentemp (type_e t=_INT, string init = "");		// Generate a temporary variable and insert it in symbol table

void backpatch (list <int>, int);
void emit(optype op, string result, int arg1, string arg2 = "");
void emit(optype opL, string result, string arg1="", string arg2 = "");

list<int> merge (list<int> &, list <int> &);		// Merge two lists
list<int> makelist (int);							// Make a new list contaninig an integer

int sizeoftype (symtype*);							// Calculate size of any type
string optostr(int);
string convert_to_string (const symtype*);			// For printing type structure

sym* conv (sym*, type_e);							// Convert symbol to different type
bool typecheck(symtype* s1, symtype* s2);			// Check if the type objects are equivalent
bool typecheck(sym* &s1, sym* &s2);					// Checks if two symbbol table entries have same type



/*** Global variables declared in cxx file****/

extern sym* currsym;			// Pointer to just encountered symbol
extern quads qarr;				// Quads
extern symtab* gTable;			// Global Symbbol Table
extern symtab* table;			// Current Symbbol Table

/** Attributes/Global for Boolean Expression***/

struct expr {

	// Valid for non-bool type

	// Valid for bool type

	// Valid for statement expression
	lint nextlist;
	lint falselist;				// Falselist valid for boolean expressions
	lint truelist;				// Truelist valid for boolean
	sym* symp;	
				// Pointer to the symbol table entry
	bool isbool;				// Boolean variable that stores if the expression is bool
};



struct statement {
	lint nextlist;				// Nextlist for statement
};

struct unary {
	bool ismatrix;
	symtype* type;				// type of the subarray generated
	sym* symp;					// Pointer to symbol table // Matrix name
	sym* loc;					// Temporary used for computing array address // Offset
	type_e cat;
};

// Utility functions
template <typename T> string tostr(const T& t) { 
   ostringstream os; 
   os<<t; 
   return os.str(); 
} 

expr* convertfrombool (expr*);			// convert bool to expression
expr* convert2bool (expr*);				// convert any expression to bool

// For debugging 
void printlist (lint list);				// Print the list of integers
#endif
