#include <string>
#include <iostream>
#include <iomanip>
#include <typeinfo>
#include <list>
#include "ast.hh"
#include "assert.h"

#define AST_SPACE "         "
#define AST_NODE_SPACE "            "
#define AST_SUB_NODE_SPACE "               "

#define END_OF_PROG -3	
// Used by goto_ast and basic_block
template class Number_Ast<int>;
template class Number_Ast<double>;
using namespace std;

/*
====================
		AST 		
====================
*/

Ast::Ast() {}
Ast::~Ast() {}

Data_Type Ast::get_data_type() {return node_data_type;}

void Ast::set_data_type(Data_Type dt) {node_data_type = dt;}

void Ast::print(ostream & file_buffer) {}

void Ast::print_value(Local_Environment & eval_env, ostream & file_buffer) {}

Eval_Result & Ast::get_value_of_evaluation(Local_Environment & eval_env) {}

void Ast::set_value_of_evaluation(Local_Environment & eval_env, Eval_Result & result) {}

bool Ast::is_value_zero() {return true;}

bool Ast::check_ast() {return true;}

int Ast::labelCounter;

Symbol_Table_Entry & Ast::get_symbol_entry(){}                                                                                                                                                           

/*
====================
   ASSIGNMENT AST 		
====================
*/

Assignment_Ast::Assignment_Ast(Ast * temp_lhs, Ast * temp_rhs, int line)
{
	lhs = temp_lhs;
	rhs = temp_rhs;
	lineno = line;
	ast_num_child = binary_arity;
}


void Assignment_Ast::print(ostream & file_buffer)
{
	file_buffer<<'\n'<<AST_SPACE<<"Asgn:\n";
	file_buffer<<AST_NODE_SPACE<<"LHS (";
	lhs->print(file_buffer);
	file_buffer<<")\n";
	file_buffer<<AST_NODE_SPACE<<"RHS (";
	rhs->print(file_buffer);
	file_buffer<<")";
}

bool Assignment_Ast::check_ast(){
    if (lhs->get_data_type() == rhs->get_data_type()) return true;
    else return false;
}

/*
====================
	  NAME AST 		
====================
*/

Name_Ast::Name_Ast(string & name, Symbol_Table_Entry & var_entry, int line)
{
	variable_symbol_entry = & var_entry;
	lineno = line;
}

Data_Type Name_Ast::get_data_type() {return node_data_type;}

Symbol_Table_Entry & Name_Ast::get_symbol_entry() {return *variable_symbol_entry;}

void Name_Ast::set_data_type(Data_Type dt) {node_data_type = dt;}

void Name_Ast::print(ostream & file_buffer) {file_buffer<<"Name : "<<variable_symbol_entry->get_variable_name();}

void Name_Ast::print_value(Local_Environment & eval_env, ostream & file_buffer) {}

Eval_Result & Name_Ast::get_value_of_evaluation(Local_Environment & eval_env) {}

void Name_Ast::set_value_of_evaluation(Local_Environment & eval_env, Eval_Result & result) {}

/*
====================
	 NUMBER AST 		
====================
*/
template <typename T>
Number_Ast<T>::Number_Ast(T number, Data_Type constant_data_type, int line)
{
	constant = number;
	node_data_type = constant_data_type;
	lineno = line;
}

template <typename T>
Data_Type Number_Ast<T>::get_data_type() {return node_data_type;}

template <typename T>
void Number_Ast<T>::set_data_type(Data_Type dt) {node_data_type = dt;}

template <typename T>
bool Number_Ast<T>::is_value_zero() {return constant == 0;}

template <typename T>
void Number_Ast<T>::print(ostream & file_buffer) {file_buffer<<"Num : "<<constant;}

/*
====================
  ARITHMATIC EXPR 		
====================
*/

Data_Type Arithmetic_Expr_Ast::get_data_type() {return node_data_type;}

void Arithmetic_Expr_Ast::set_data_type(Data_Type dt) {node_data_type = dt;}

bool Arithmetic_Expr_Ast::check_ast(){
    if (lhs->get_data_type() == rhs->get_data_type()) return true;
    else return false;
}

/*
====================
	PLUS AST 		
====================
*/

Plus_Ast::Plus_Ast(Ast * l, Ast * r, int line)
{
	lhs = l;
	rhs = r;
	lineno = line;
}

void Plus_Ast::print(ostream & file_buffer)
{
	file_buffer<<'\n'<<AST_NODE_SPACE<<"Arith: PLUS\n";
	file_buffer<<AST_SUB_NODE_SPACE<<"LHS (";
	lhs->print(file_buffer);
	file_buffer<<")\n";
	file_buffer<<AST_SUB_NODE_SPACE<<"RHS (";
	rhs->print(file_buffer);
	file_buffer<<")";
}

/*
====================
	MINUS AST 		
====================
*/

Minus_Ast::Minus_Ast(Ast * l, Ast * r, int line)
{
	lhs = l;
	rhs = r;
	lineno = line;
}

void Minus_Ast::print(ostream & file_buffer)
{

	file_buffer<<'\n'<<AST_NODE_SPACE<<"Arith: MINUS\n";
	file_buffer<<AST_SUB_NODE_SPACE<<"LHS (";
	lhs->print(file_buffer);
	file_buffer<<")\n";

	file_buffer<<AST_SUB_NODE_SPACE<<"RHS (";
	rhs->print(file_buffer);
	file_buffer<<")";
}

/*
====================
	DIVIDE AST		
====================
*/

Divide_Ast::Divide_Ast(Ast * l, Ast * r, int line)
{

	lhs = l;
	rhs = r;
	lineno = line;

}

void Divide_Ast::print(ostream & file_buffer)
{

	file_buffer<<'\n'<<AST_NODE_SPACE<<"Arith: DIV\n";
	file_buffer<<AST_SUB_NODE_SPACE<<"LHS (";
	lhs->print(file_buffer);
	file_buffer<<")\n";

	file_buffer<<AST_SUB_NODE_SPACE<<"RHS (";
	rhs->print(file_buffer);
	file_buffer<<")";
}

/*
====================
	MULTIPLY AST 		
====================
*/

Mult_Ast::Mult_Ast(Ast * l, Ast * r, int line)
{

	lhs = l;
	rhs = r;
	lineno = line;
}

void Mult_Ast::print(ostream & file_buffer)
{
	file_buffer<<'\n'<<AST_NODE_SPACE<<"Arith: MULT\n";
	file_buffer<<AST_SUB_NODE_SPACE<<"LHS (";
	lhs->print(file_buffer);
	file_buffer<<")\n";

	file_buffer<<AST_SUB_NODE_SPACE<<"RHS (";
	rhs->print(file_buffer);
	file_buffer<<")";

}

/*
====================
	UMINUS AST 		
====================
*/

UMinus_Ast::UMinus_Ast(Ast * l, Ast * r, int line)
{

	lhs = l;
	rhs = r;
	lineno = line;
}

void UMinus_Ast::print(ostream & file_buffer)
{
	file_buffer<<'\n'<<AST_NODE_SPACE<<"Arith: UMINUS\n";
	file_buffer<<AST_SUB_NODE_SPACE<<"LHS (";
	lhs->print(file_buffer);
	file_buffer<<")";

}

/*
====================
  RELATIONAL EXPR 		
====================
*/

Relational_Expr_Ast::Relational_Expr_Ast(Ast * l, Relational_Op rop, Ast * r, int line) {
	lhs_condition = l;
	rhs_condition = r;
	lineno = line;
	rel_op = rop;
}

void Relational_Expr_Ast::print(ostream & file_buffer) {
	if (rel_op == less_than) file_buffer<<'\n'<<AST_NODE_SPACE<<"Condition: LT\n";
	else if (rel_op == greater_than) file_buffer<<'\n'<<AST_NODE_SPACE<<"Condition: GT\n";
	else if (rel_op == less_equalto) file_buffer<<'\n'<<AST_NODE_SPACE<<"Condition: LE\n";
	else if (rel_op == greater_equalto) file_buffer<<'\n'<<AST_NODE_SPACE<<"Condition: GE\n";
	else if (rel_op == equalto) file_buffer<<'\n'<<AST_NODE_SPACE<<"Condition: EQ\n";
	else if (rel_op == not_equalto) file_buffer<<'\n'<<AST_NODE_SPACE<<"Condition: NE\n";
	file_buffer<<AST_SUB_NODE_SPACE<<"LHS (";
	lhs_condition->print(file_buffer);
	file_buffer<<")\n";

	file_buffer<<AST_SUB_NODE_SPACE<<"RHS (";
	rhs_condition->print(file_buffer);
	file_buffer<<")";
}
// Relational_Expr_Ast::~Relational_Expr_Ast() {}
Data_Type Relational_Expr_Ast::get_data_type() {return node_data_type;}
void Relational_Expr_Ast::set_data_type(Data_Type dt) {node_data_type = dt;}
bool Relational_Expr_Ast::check_ast() {
	if (lhs_condition->get_data_type() == rhs_condition->get_data_type()) return true;
    else return false;
}
// Code_For_Ast & Relational_Expr_Ast::compile() {}

/*
====================
	LOGICAL EXPR 		
====================
*/

Logical_Expr_Ast::Logical_Expr_Ast(Ast * l, Logical_Op bop, Ast * r, int line) {
	lhs_op = l;
	rhs_op = r;
	lineno = line;
	bool_op = bop;
}

void Logical_Expr_Ast::print(ostream & file_buffer) {
	if (bool_op == _logical_or) file_buffer<<'\n'<<AST_NODE_SPACE<<"Condition: OR\n";
	else if (bool_op == _logical_and) file_buffer<<'\n'<<AST_NODE_SPACE<<"Condition: AND\n";
	else if (bool_op == _logical_not) file_buffer<<'\n'<<AST_NODE_SPACE<<"Condition: NOT\n";
	if(bool_op != _logical_not)
	{
		file_buffer<<AST_SUB_NODE_SPACE<<"LHS (";
		assert (lhs_op != NULL);
		lhs_op->print(file_buffer);
		file_buffer<<")\n";
	}

	file_buffer<<AST_SUB_NODE_SPACE<<"RHS (";
	assert (rhs_op != NULL);
	rhs_op->print(file_buffer);
	file_buffer<<")";
}

// Logical_Expr_Ast::~Logical_Expr_Ast() {}
Data_Type Logical_Expr_Ast::get_data_type() {return node_data_type;}
void Logical_Expr_Ast::set_data_type(Data_Type dt) {node_data_type = dt;}
bool Logical_Expr_Ast::check_ast() {
	if (lhs_op->get_data_type() == rhs_op->get_data_type()) return true;
	else return false;
}
// Code_For_Ast & Logical_Expr_Ast::compile() {}

/*
   ====================
   SELECTION STMT AST 		
   ====================
   */

Selection_Statement_Ast::Selection_Statement_Ast(Ast * c,Ast* t, Ast* e, int line) {
	cond = c;
	then_part = t;
	else_part = e;
	lineno = line;
}

void Selection_Statement_Ast::print(ostream & file_buffer) {
	file_buffer<<'\n'<<AST_SPACE<<"IF : ";
	file_buffer<<'\n'<<AST_SPACE<<"CONDITION (";
	cond->print(file_buffer);
	file_buffer<<")";
	file_buffer<<'\n'<<AST_SPACE<<"THEN (";
	then_part->print(file_buffer);

	if (else_part == NULL) {
		file_buffer<<")";
	}
	else {
		file_buffer<<")";
		file_buffer<<'\n'<<AST_SPACE<<"ELSE (";
		else_part->print(file_buffer);
		file_buffer<<")";	
	}
}

// Selection_Statement_Ast::~Selection_Statement_Ast() {}
Data_Type Selection_Statement_Ast::get_data_type() {return node_data_type;} 
void Selection_Statement_Ast::set_data_type(Data_Type dt) {node_data_type = dt;}
bool Selection_Statement_Ast::check_ast() {}
// Code_For_Ast & Selection_Statement_Ast::compile() {}

/*
   ====================
   ITERATION STMT AST 		
   ====================
   */

Iteration_Statement_Ast::Iteration_Statement_Ast(Ast * c, Ast* b, int line, bool d) {
	cond = c;
	body = b;
	lineno = line;
	is_do_form = d;
}

// Iteration_Statement_Ast::~Iteration_Statement_Ast() {}

void Iteration_Statement_Ast::print(ostream & file_buffer) {
	if (!is_do_form) {
		file_buffer<<'\n'<<AST_SPACE<<"WHILE : ";
		file_buffer<<'\n'<<AST_SPACE<<"CONDITION (";
		cond->print(file_buffer);
		file_buffer<<")";
		file_buffer<<'\n'<<AST_SPACE<<"BODY (";
		body->print(file_buffer);
		file_buffer<<")";
	} else {
		file_buffer<<'\n'<<AST_SPACE<<"DO (";
		// file_buffer<<AST_NODE_SPACE;
		body->print(file_buffer);
		file_buffer<<")\n";
		file_buffer<<AST_SPACE<<"WHILE CONDITION (";
		cond->print(file_buffer);
		file_buffer<<")";
	}
}

Data_Type Iteration_Statement_Ast::get_data_type() {return node_data_type;}
void Iteration_Statement_Ast::set_data_type(Data_Type dt) {node_data_type = dt;}
bool Iteration_Statement_Ast::check_ast() {}
// Code_For_Ast & Iteration_Statement_Ast::compile() {}

/*
====================
	SEQUENCE AST 		
====================
*/

Sequence_Ast::Sequence_Ast(int line) {lineno = line;}
void Sequence_Ast::print(ostream & file_buffer) {
	for (list<Ast *>::iterator it=statement_list.begin(); it != statement_list.end(); it++){
	 	file_buffer<<endl;
	 	file_buffer<< AST_NODE_SPACE;
	 	(*it)->print(file_buffer);
	 }
}

// Sequence_Ast::~Sequence_Ast() { }
void Sequence_Ast::ast_push_back(Ast * ast) {statement_list.push_back(ast);}
// Code_For_Ast & Sequence_Ast::compile() {}
// void Sequence_Ast::print_icode(ostream & file_buffer) {}
// void Sequence_Ast::print_assembly(ostream & file_buffer) {}

/*
====================
	RETURN AST 		
====================
*/

Return_Ast::Return_Ast(int line) {lineno = line;}

void Return_Ast::print(ostream & file_buffer) {}

/*
====================
	SYMBOL TABLE 		
====================
*/

void Symbol_Table::create(Local_Environment & local_global_variables_table) {
	for (list<Symbol_Table_Entry *>::iterator it = variable_table.begin(); it != variable_table.end(); it++){
		
		if ((*it)->get_data_type() == int_data_type) {
			Eval_Result * eval_result = new Eval_Result_Value_Int();
			eval_result->set_result_enum(int_result);
			if ((*it)->get_symbol_scope() == global) {
				eval_result->set_variable_status(true);
				eval_result->set_value(0);
			} else {
				eval_result->set_variable_status(false);	
			}
			
			local_global_variables_table.put_variable_value(*eval_result, (*it)->get_variable_name());
		}
		else if ((*it)->get_data_type() == double_data_type) {
			Eval_Result * eval_result = new Eval_Result_Value_Double();
			eval_result->set_result_enum(double_result);
			if ((*it)->get_symbol_scope() == global) {
				eval_result->set_variable_status(true);
				eval_result->set_value(0.0);
			} else {
				eval_result->set_variable_status(false);	
			}
			local_global_variables_table.put_variable_value(*eval_result, (*it)->get_variable_name());
		} 
	}
}

/*
====================
	CONDITIONAL
====================
*/

Conditional_Expression_Ast::Conditional_Expression_Ast(Ast* c, Ast* l, Ast* r, int line)
{
	lhs = l;
	rhs = r;
	cond = c;
	lineno = line;
}
//~Conditional_Expression_Ast();

void Conditional_Expression_Ast::print(ostream & file_buffer)
{
	file_buffer<<'\n'<<AST_SPACE<<"Cond:\n";
	file_buffer<<AST_NODE_SPACE<<"IF_ELSE";
	cond->print(file_buffer);
	file_buffer<<'\n';
	file_buffer<<AST_NODE_SPACE<<"LHS (";
	lhs->print(file_buffer);
	file_buffer<<")\n";
	file_buffer<<AST_NODE_SPACE<<"RHS (";
	rhs->print(file_buffer);
	file_buffer<<")";
}

//Code_For_Ast & Conditional_Expression_Ast::compile();
