#include<string>
#include<iostream>
#include<iomanip>
#include<typeinfo>
#include<list>
#include"ast.hh"

#define AST_SPACE "         "
#define AST_NODE_SPACE "            "
#define AST_SUB_NODE_SPACE "               "

#define END_OF_PROG -3	
// Used by goto_ast and basic_block
template class Number_Ast<int>;
template class Number_Ast<double>;
using namespace std;

Ast::Ast() {}
Ast::~Ast() {}

Data_Type Ast::get_data_type() {
	return node_data_type;
}

void Ast::set_data_type(Data_Type dt) {
	node_data_type = dt;
}

void Ast::print(ostream & file_buffer) {
}

bool Ast::is_value_zero() {return true;}

bool Ast::check_ast() {return true;}

Symbol_Table_Entry & Ast::get_symbol_entry(){}                                                                                                                                                           

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

Name_Ast::Name_Ast(string & name, Symbol_Table_Entry & var_entry, int line)
{
	variable_symbol_entry = & var_entry;
	lineno = line;
	// variable_symbol_entry -> set name
}

Data_Type Name_Ast::get_data_type()
{
	return node_data_type; 
}
Symbol_Table_Entry & Name_Ast::get_symbol_entry()
{
	return *variable_symbol_entry;
}
void Name_Ast::set_data_type(Data_Type dt)
{
	node_data_type = dt;
}

void Name_Ast::print(ostream & file_buffer)
{
	file_buffer<<"Name : "<<variable_symbol_entry->get_variable_name();
}

template <typename T>
Number_Ast<T>::Number_Ast(T number, Data_Type constant_data_type, int line)
{
	constant = number;
	node_data_type = constant_data_type;
	lineno = line;
}

template <typename T>
Data_Type Number_Ast<T>::get_data_type()
{
	return node_data_type;
}

template <typename T>
void Number_Ast<T>::set_data_type(Data_Type dt)
{
	node_data_type = dt;
}

template <typename T>
bool Number_Ast<T>::is_value_zero()
{
	return constant == 0;
}

template <typename T>
void Number_Ast<T>::print(ostream & file_buffer)
{
	file_buffer<<"Num : "<<constant;
}


Data_Type Arithmetic_Expr_Ast::get_data_type()
{
	return node_data_type;
}
void Arithmetic_Expr_Ast::set_data_type(Data_Type dt)
{
	node_data_type = dt;
}

bool Arithmetic_Expr_Ast::check_ast(){
    if (lhs->get_data_type() == rhs->get_data_type()) return true;
    else return false;
}

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

Return_Ast::Return_Ast(int line)
{
	lineno = line;
}

void Return_Ast::print(ostream & file_buffer)
{

}
