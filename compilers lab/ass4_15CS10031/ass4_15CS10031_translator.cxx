/*
* 	translator.cxx
* 	Author: Pankaj Dhurve
*/

#include "ass4_15CS10031_translator.h"

/************ Global variables *************/

sym* currsym; 					// points to latest function entry in symbol table
quads qarr;						// Quads
bool gDebug = false;			// Debug mode
type_e TYPE;					// Stores latest type specifier
symtab* gTable;					// Global Symbbol Table
symtab* table;					// Points to current symbol table

/* Singleton Design Pattern */
Singleton* Singleton::pSingleton= NULL;
Singleton::Singleton() {
   // do init stuff
}
int sizeoftype (symtype* t){ 					//returns the size of data type
	switch (t->cat) {
		case _INT:
			return size_of_int;
		case FUNC:
			return 0;
		case ARR:{
			if(t->width==0 || t->length==0) return 8;
			return t->width * t->length * 8;
		}
		case _DOUBLE:
			return size_of_double;
		case _VOID:
			return 0;
		case _CHAR:
			return size_of_char;
		case PTR:
			return size_of_pointer;
	}
}
Singleton* Singleton::GetInstance() {
	if (pSingleton== NULL) {
		pSingleton = new Singleton();
	}
	return pSingleton;
}

string convert_to_string (const symtype* t){          //converts the type of data into string
	if (t==NULL) return "null";
	switch (t->cat) {
		case PTR:
			return "ptr("+ convert_to_string(t->ptr)+")";
		case _CHAR:
			return "char";
		case FUNC:
			return "funct";
		case _INT:
			return "int";
		case _DOUBLE:
			return "double";
		case ARR:{
		  	if(t->width==0 || t->length==0) return "double";
			return "Matrix(" + tostr(t->width) + ", "+ tostr(t->length) + " ,double" + ")" ;}
		case _VOID:
			return "void";
		default:
			return "type";
	}
}
symtype::symtype(type_e cat, symtype* ptr, int width,int length):              // constructor of class symtype
	cat (cat), 
	ptr (ptr), 
	width (width) ,
	length (length) {} ; 
sym* symtab::lookup (string name) {					// checks if a variable is already present and if not adds it to symbol table									
	sym* s;
	list <sym>::iterator it;						// list of rows in symbol table
	it = table.begin();
	while ( it!=table.end()) {
		if (it->name == name ) break;
		it++;
	}
	if (it!=table.end() ) {							// if found in table return already present
		string str = " already present";
		if (gDebug) cout << name << str << "\n";
		return &*it;
	}
	else {											// if not found add the variable to the symbol table
		
			s =  new sym (name);
			string str = "local";
			s->category = str;
			table.push_back (*s);
			if (gDebug) print();
			return &table.back();
			
	}
}
sym* gentemp (type_e t, string init) {				// since type_t is ENUM , it can be used for simple data types only
	char n[50];		
	//cout << init << endl;									
	sprintf(n, "t%02d", table->tcount++);			//table->count++ increments the no. of rows
	sym* s = new sym (n, t);						// make a new row of size 20 and of type t
	s-> init = init;								// initialise the temporary variable
	string tempest = "temp";
	s->category = tempest;							// category of the variable is temp
	table->table.push_back ( *s);					// push the temporary variable into the symbol table
	if (gDebug) table->print();						// print the last row added
	return &table->table.back();
}
sym* gentemp (symtype* t, string init) {			// used for array or pointers
	char n[50];
	sprintf(n, "t%02d", table->tcount++);			// increment the number of rows in symbol table
	sym* s = new sym (n);							// make a new row of size 20
	string tempest = "temp"; 
	s->category = tempest;							// category = temp
	s->type = t;									// assign type
	s-> init = init;								// initialisation
	table->table.push_back ( *s);					// push the row
	if (gDebug) table->print();
	return &table->table.back();
}
symtab::symtab (string name): tname (name), tcount(0) {}

void symtab::print(int all) {  // print all symbol tables
	string str;
	list<symtab*> tablelist;			// to store the list of symbol tables
	 str = "=";
	cout << setw(80) << setfill ('=') << str<< "\n";
	str = "Symbol Table: ";
	cout << str << setfill (' ') << left << setw(35)  << this -> tname ;
	str = "Parent: ";
	cout << right << setw(20) << str;
	if (this->parent!=NULL)
		cout << this -> parent->tname;
	else cout << "null" ;
	cout << "\n";
	cout << setw(80) << setfill ('-') << "-"<< "\n";
	str = "Name";
	cout << setfill (' ') << left << setw(16) << str;
	str = "Type";
	cout << left << setw(16) << str;
	str = "Category";
	cout << left << setw(12) << str;
	str  = "Init Val";
	cout << left << setw(12) << str;
	str = "Size";
	cout << left << setw(8) << str;
	str="Offset";
	cout << left << setw(8) << str;
	str = "Nest";
	cout << left << str << "\n";
	cout << setw(80) << setfill ('-') << "-"<< setfill (' ') << "\n";
	
	for (list <sym>::iterator it = table.begin(); it!=table.end(); it++) {
		cout << &*it;												// print the row
		if (it->nest!=NULL) tablelist.push_back (it->nest);			// push the nested symbol table into tablelist
	}
	cout << setw(80) << setfill ('-') << "-"<< setfill (' ') << "\n";
	cout << "\n";
	if (all) {														// if all symbol tables have to be printed other than global
		list<symtab*>::iterator iterator = tablelist.begin();
		while (
				iterator != tablelist.end()
				) {
		    (*iterator)->print();									// iterate through each symbol table and call print on it
		++iterator;
		}		
	}
}
void symtab::computeOffsets() {									// A method to compute offset value
	list<symtab*> tablelist;
	int off;
	list <sym>::iterator it = table.begin();						
	while ( it!=table.end() ) {
		if (it==table.begin()) {
			int zero = 0;
			it->offset = zero;
			off = it->size;						// if start of the table then offset is equal to the size of the first variable
		}
		else {				// if not , then offsset is equal to the size of cuurent row variable plus the previous value of offset
			it->offset = off;
			off = it->offset + it->size;
		}
		if (it->nest!=NULL) tablelist.push_back (it->nest);	// if the table entry is some function then push another table into tablelist
		it++;
	}
	list<symtab*>::iterator iterator = tablelist.begin();
	while ( 
			iterator != tablelist.end() 
			) {										
//	    debug ("computing for child");
	    (*iterator)->computeOffsets();				// iterate through all symbol tables and compute offset
//		if (gDebug) (*iterator)->print();
		++iterator;
	}
}
sym* sym::linkst(symtab* t) {				// nest a new symbol table and set the category to function
	this->nest = t;
	string str = "function";
	this->category = str ;
}

ostream& operator<<(ostream& os, const symtype* t) { 	// outstream the symbol type
	type_e cat = t->cat;
	string str = "convert2bool";
	//string stype = convert_to_string(t);
	os << convert_to_string(t);
	return os;
}
quad::quad (string result, int arg1, optype op, string arg2):
	result (result), arg2(arg2), op (op) {
		this ->arg1 = NumberToString(arg1);
	}
ostream& operator<<(ostream& os, const sym* it) { 		// outstream the table row  
	string na = it->name;
	os << left << setw(16) << na;
	os << left << setw(16) << it->type;
	string ti = it->category;
	os << left << setw(12) << ti;
	string kl = it->init;
	os << left << setw(12) << kl;
	int sz = it->size;
	os << left << setw(8) << sz;
	os << left << setw(8) << it->offset;
	os << left;

	if (it->nest == NULL) {
		string str = "null";				// if not nested print null in nested
		os << str <<  "\n";	
	}
	else {
//		os << "not null" << "\n";
		os << it->nest->tname <<  "\n";        // elss print the name of the nested symbol table
	}
	return os;
}
quad::quad (string result, string arg1, optype op, string arg2):
	result (result), arg1(arg1), arg2(arg2), op (op){};


sym::sym (string name, type_e t, symtype* ptr, int width): name(name)  {   // construtor for a symbol table row
	type = new symtype (symtype(t, ptr, width));
	nest = NULL;
	init = "";
	category = "";
	int zero = 0;
	offset = zero;
	size = sizeoftype(type);
}
sym* sym::update(type_e t) {                 // update symbol table using datatype (simple data types like int , void  
	this->type = new symtype(t);
	this->size = sizeoftype(this->type);
	if (gDebug) table->print();
	return this;
}
sym* sym::initialize (string init) { // initialise the symbol table row
	this->init = init;
}
sym* sym::update(symtype* t) {           // update symbol table using datatype  (for arrays and pointers)
	type = t;
	this -> size = sizeoftype(t);
	if (gDebug) table->print();
	return this;
}

void quad::update (int addr) {	// Used for backpatching address
	this ->result = addr;
}
void quad::print () {
	switch(op) {
		// Binary Operations
		case SUB:			{string str1 = " = ";string str2 = " - "; cout << result << str1 << arg1 << str2 << arg2;	break;}
		case BAND:			{string str1 = " = ";string str2 = " & "; cout << result << str1 << arg1 << str2 << arg2;   break;}
		case XOR:			{string str1 = " = ";string str2 = " ^ "; cout << result << str1 << arg1 << str2 << arg2;	break;}
		case ADD:			{string str1 = " = ";string str2 = " + "; cout << result << str1 << arg1 << str2 << arg2;	break;}
		case DIVIDE:		{string str1 = " = ";string str2 = " / "; cout << result << str1 << arg1 << str2 << arg2;   break;}
		case MODOP:			{string str1 = " = ";string str2 = " % "; cout << result << str1 << arg1 << str2 << arg2;	break;}
		case MULT:			{string str1 = " = ";string str2 = " * "; cout << result << str1 << arg1 << str2 << arg2;	break;}
		case INOR:			{string str1 = " = ";string str2 = " | "; cout << result << str1 << arg1 << str2 << arg2;	break;}
		
		// Shift Operations
		case EQUAL:			{string str1 = " = ";cout << result << str1 << arg1 ;										break;}
		case RIGHTOP:		{string str1 = " = ";string str2 = " >> ";cout << result << str1 << arg1 << str2 << arg2;	break;}
		case LEFTOP:		{string str1 = " = ";string str2 = " << ";cout << result << str1 << arg1 << str2 << arg2;	break;}
		// Relational Operations
		case NEOP:			{string str1 = "if ";string str2= " != ";string str3 = " goto "; cout << str1 << arg1 <<  str2 << arg2 << str3 << result;	break;}
		case GOTOOP:		{string str = "goto ";cout << str << result;						break;}
		case LT:			{string str1 = "if ";string str2 = " < ";string str3 = " goto ";cout << str1 << arg1 <<  str2  << arg2 << str3 << result;	break;}
		case GE:			{string str1 = "if ";cout << str1 << arg1 <<  " >= " << arg2 << " goto " << result;				break;}
		case EQOP:			{string str1 = "if ";cout << str1 << arg1 <<  " == " << arg2 << " goto " << result;				break;}
		case GT:			{string str1 = "if ";cout << str1 << arg1 <<  " > "  << arg2 << " goto " << result;				break;}
		case LE:			{string str1 = "if ";cout << str1 << arg1 <<  " <= " << arg2 << " goto " << result;				break;}
		//Unary Operators
		case PTRL:			{string str1 = "*";  cout << str1 << result	<< " = " << arg1 ;		break;}
		case UMINUS:		{string str1= " = -";cout << result 	<< str1 << arg1;				break;}
		case BNOT:			{string str1 = " = ~";cout << result 	<< str1 << arg1;				break;}
		case PTRR:			{string str1 = " = *";cout << result	<< str1 << arg1 ;				break;}
		case ADDRESS:		{string str1 = " = &";cout << result << str1 << arg1;				break;}
		case LNOT:			{string str1 = " = !";cout << result 	<< str1 << arg1;				break;}

		case _RETURN: 		{string str1 = "ret ";cout << str1 << result;				break;}
		case LABEL:			{string str1 = ": ";cout << result << str1;					break;}
		case ARRR:	 		{string str1 = " = ";cout << result << str1 << arg1 << "[" << arg2 << "]";			break;}
		case ARRL:	 		{string str1 = "[";cout << result << str1 << arg1 << "]" <<" = " <<  arg2;			break;}
		case PARAM: 		{string str1 = "param ";cout << str1 << result;				break;}
		case CALL: 			{string str1 = " = ";cout << result << str1 << "call " << arg1<< ", " << arg2;				break;}
		default:			{string str1 = "op";cout << str1;							break;}
	}
	cout << "\n";
	
}
void quads::printtab() {                    // print quads table
	string qw = "=== Quad Table ===";
	cout <<  qw << "\n";
	string in = "index";
	cout << setw(8) << in << "";
	string op = " op";
	cout << setw(8) << " op";
	string arg1 = "arg 1";
	cout << setw(8)  << "";
	string arg2 = "arg 2";
	cout << setw(8)  ;
	string r = "result";
	cout << setw(8)  << r <<"\n";
	for (vector<quad>::iterator it = array.begin(); it!=array.end(); it++) {
		cout << left << setw(8) << it - array.begin(); 
		cout << left << setw(8) << optostr(it->op);
		string argument1 = it->arg1;
		cout << left << setw(8) << argument1;
		string argument2 = it->arg2;
		cout << left << setw(8) << argument2;
		cout << left << setw(8) << it->result << "\n";
	}
}
void backpatch (list <int> l, int addr) {
	for (list<int>::iterator it= l.begin(); it!=l.end(); it++) qarr.array[*it].result = tostr(addr);
	if (gDebug) qarr.printtab();
}
void quads::print () { 									// print quads
	cout << setw(30) << setfill ('=') << "="<< "\n";
	string q = "Quad Translation";
	cout <<  q<< "\n";
	string s = "-" ; 
	cout << setw(30) << setfill ('-') << s<< setfill (' ') << "\n";
	vector<quad>::iterator it = array.begin();
	while ( it!=array.end() ) {
		if (it->op != LABEL) {
			cout << "\t" << setw(4) << it - array.begin() << ":\t";
			it->print();
		}
		else {
			cout << "\n";
			it->print();
			cout << "\n";
		}
		it++;
	}
	cout << setw(30) << setfill ('-') << "-"<< "\n";
}
void emit(optype op, string result, string arg1, string arg2) {    
	qarr.array.push_back(*(new quad(result,arg1,op,arg2)));    // push new quad into quad array
	if (gDebug) qarr.print();									// print quad
}
void emit(optype op, string result, int arg1, string arg2) {	// push new quad into quad array
	qarr.array.push_back(*(new quad(result,arg1,op,arg2)));
	if (gDebug) qarr.print();									// print quad
}
string optostr (int op) {
	switch(op) {
		case EQUAL:				{string str = " = ";return str;}
		case SUB:				{string str = " - ";return str;}
		case DIVIDE:			{string str = " / ";return str;}
		case MULT:				{string str = " * ";return str;}
		case ADD:				{string str = " + ";return str;}
		case EQOP:				{string str = " == ";return str;}
		case NEOP:				{string str = " != ";return str;}
		case LT:				{string str = " < ";return str;}
		case GT:				{string str = " > ";return str;}
		case GE:				{string str = " >= ";return str;}
		case LE:				{string str = " <= ";return str;}
		case GOTOOP:			{string str = " goto ";return str;}
		
		case ADDRESS:			{string str = " &";return str;}
		case PTRR:				{string str = " *R";return str;}
		case PTRL:				{string str = " *L";return str;}
		case UMINUS:			{string str = " -";return str;}
		case BNOT:				{string str = " ~";return str;}

		case CALL: 				{string str = " call ";return str;}
		case _RETURN: 			{string str = " ret";return str;}
		case PARAM: 			{string str = " param ";return str;}
		case ARRR:	 			{string str = " =[]R";return str;}
		case LNOT:				{string str = " !";return str;}
		default:				{string str = " op ";return str;}
	}
}
list<int> makelist (int i) {
	list<int> l(1,i);
	return l;
}
list<int> merge (list<int> &a, list <int> &b) {
	a.merge(b);
	return a;
}
int nextinstr() {
	return qarr.array.size();
}
string NumberToString ( int Number ) {
	ostringstream ss;
	ss << Number;
	return ss.str();
}
expr* convert2bool (expr* e) {	// Convert any expression to bool
	if (!e->isbool) {
		e->falselist = makelist (nextinstr());
		string str = "0";
		emit (EQOP, "", e->symp->name, str);
		e->truelist = makelist (nextinstr());
		emit (GOTOOP, "");
	}
}
expr* convertfrombool (expr* e) {	// Convert any expression to bool
	if (e->isbool) {
		e->symp = gentemp(_INT);
		backpatch (e->truelist, nextinstr());
		bool t = true;
		emit (EQUAL, e->symp->name, t);
		emit (GOTOOP, tostr (nextinstr()+1));
		backpatch (e->falselist, nextinstr());
		bool f = false;
		emit (EQUAL, e->symp->name, f);
	}
}
bool typecheck(sym*& s1, sym*& s2){ 	// Check if the symbols have same type or not
	symtype* type2 = s2->type;
	symtype* type1 = s1->type;
	bool t = true;
	if ( typecheck (type1, type2) ) return t;
	else if (s1 = conv (s1, type2->cat) ) return t;
	else if (s2 = conv (s2, type1->cat) ) return t;
	return false;
}
bool typecheck(symtype* t1, symtype* t2){ 	// Check if the symbol types are same or not
	if (t1 != NULL || t2 != NULL) {
		if (t1==NULL || t2==NULL) return false;
		//if (t2==NULL) return false;
		if (t1->cat==t2->cat) return (t1->ptr, t2->ptr);
		else return false;
	}
	return true;
}

sym* conv (sym* s, type_e t) {
	sym* temp = gentemp(t);
	switch (s->type->cat) {
		case _INT: {
			switch (t) {
				case _DOUBLE: {
					string str = "int2double(";
					emit (EQUAL, temp->name, str + s->name + ")");
					return temp;
				}
				case _CHAR: {
					string str = "int2char(";
					emit (EQUAL, temp->name, str + s->name + ")");
					return temp;
				}
			}
			return s;
		}
		case _DOUBLE: {
			switch (t) {
				case _INT: {
					string str = "double2int(";
					emit (EQUAL, temp->name, str + s->name + ")");
					return temp;
				}
				case _CHAR: {
					string str = "double2char(";
					emit (EQUAL, temp->name, str + s->name + ")");
					return temp;
				}
			}
			return s;
		}
		case _CHAR: {
			switch (t) {
				case _INT: {
					string str = "char2int(";
					emit (EQUAL, temp->name, str + s->name + ")");
					return temp;
				}
				case _DOUBLE: {
					string str = "char2double(";
					emit (EQUAL, temp->name, str + s->name + ")");
					return temp;
				}
			}
			return s;
		}
	}
	return s;
}
void changeTable (symtab* newtable) {	// Change current symbol table
	string str = "Symbol table changed from ";
	if (gDebug)	cout << str << table->tname;
	table = newtable;
	 str = " to ";
	if (gDebug)	cout << str << table->tname << "\n";
} 


// Functions for debugging 
void printlist (lint l) {	// Print integers in list l 
	for (list<int>::iterator iterator = l.begin(); iterator != l.end(); ++iterator) {
	    if (gDebug) cout << *iterator << " ";
	}
	cout << "\n";
}

int  main (int argc, char* argv[]){
	if (argc>1) gDebug = true;
	string g = "Global";
	gTable = new symtab(g);
	table = gTable;
	yyparse();
	table->computeOffsets();
	table->print(1);
//	qarr.printtab();
	qarr.print();
	int n, x;
	scanf("%d",&n);
	if (n==10) {
		for (int i = n; i > 0; i--) {
			cin >> x;
			if(x==1) {
				gentemp(_DOUBLE);
			}
			else if (x==2) {
				emit(ADD, "a", "b", "c");
			}
		}	
	}

};
