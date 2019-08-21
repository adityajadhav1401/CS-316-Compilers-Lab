#include<string>
#include<fstream>
#include<iostream>
#define VAR_SPACE "         "

template class Number_Ast<int>;
template class Number_Ast<double>;
using namespace std;

Eval_Result & Assignment_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer) {
	// finding name of variable on LHS 
	string var_name = lhs->get_symbol_entry().get_variable_name();
	// evaluating the ast on RHS to get value of RHS
	Eval_Result * result = &(rhs->evaluate(eval_env, file_buffer));

	// NOTE : 	No need to check if var_name exists in symbol_table as 
	//			this is already done in during the parsing phaze
	// updating the local environment with new value of variable on LHS  
	// setting the variable status as defined in the local environemnt or global enviornment
	// NOTE :	No need to check if exists in global as it is already handeled in parsing stage  
	if (result->get_result_enum() == int_result) {
		if (eval_env.does_variable_exist(var_name)) {
			eval_env.get_variable_value(var_name)->set_value(result->get_int_value());
			eval_env.get_variable_value(var_name)->set_variable_status(true);
			// cout << var_name << "  random" << endl;
		}
		else {
			interpreter_global_table.get_variable_value(var_name)->set_value(result->get_int_value());
			interpreter_global_table.get_variable_value(var_name)->set_variable_status(true);
		}
	}
	else {
		if (eval_env.does_variable_exist(var_name)) {
			eval_env.get_variable_value(var_name)->set_value(result->get_double_value());
			eval_env.get_variable_value(var_name)->set_variable_status(true);
		}
		else {
			interpreter_global_table.get_variable_value(var_name)->set_value(result->get_double_value());
			interpreter_global_table.get_variable_value(var_name)->set_variable_status(true);
		}
	}

	// printing the statement AST
	print(file_buffer);
	// printing the result of assignment statement
	file_buffer << "\n" << VAR_SPACE << var_name << " : ";
	if (result->get_result_enum() == int_result) file_buffer << result->get_int_value();
	else file_buffer << result->get_double_value();
	file_buffer << "\n\n";

	// deleting the temporary result variable
	delete result;

	// no need to return anything
}

Eval_Result & Arithmetic_Expr_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer) {}

Eval_Result & Name_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer) {
	// finding name using symbol table entry
	string var_name = variable_symbol_entry->get_variable_name();
	// value to be returned
	// will differ based on the type of data
	Eval_Result * result;
	if (variable_symbol_entry->get_data_type() == int_data_type) {
		result = new Eval_Result_Value_Int();
		result->set_result_enum(int_result);
		if (eval_env.does_variable_exist(var_name)) {
			if (eval_env.is_variable_defined(var_name)) result->set_value(eval_env.get_variable_value(var_name)->get_int_value());
			else {
				cout << "cs316: Error, value must be initialized before use" << endl;
				exit(0);
			}
		} 
		else result->set_value(interpreter_global_table.get_variable_value(var_name)->get_int_value());
		
	} 
	else {
		result = new Eval_Result_Value_Double();
		result->set_result_enum(double_result);
		if (eval_env.does_variable_exist(var_name)) {
			if (eval_env.is_variable_defined(var_name)) result->set_value(eval_env.get_variable_value(var_name)->get_double_value());
			else {
				cout << "cs316: Error, value must be initialized before use" << endl;
				exit(0);
			}
		}
		else result->set_value(interpreter_global_table.get_variable_value(var_name)->get_double_value());
	}

	return *result;
}

template <class T>
Eval_Result & Number_Ast<T>::evaluate(Local_Environment & eval_env, ostream & file_buffer) {
	// value to be returned
	// will differ based on the type of data
	Eval_Result * result;
	if (node_data_type == int_data_type) {
		result = new Eval_Result_Value_Int();
		result->set_result_enum(int_result);
		result->set_value(constant);
	} else {
		result = new Eval_Result_Value_Double();
		result->set_result_enum(double_result);
		result->set_value(constant);
	}

	return *result;
}

Eval_Result & Plus_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer) {
	// evaluating tree on both LHS and RHS
	Eval_Result * result_lhs = &(lhs->evaluate(eval_env, file_buffer));
	Eval_Result * result_rhs = &(rhs->evaluate(eval_env, file_buffer));
	// value to be returned
	// will differ based on the type of data
	Eval_Result * result;
	// NOTE :	No need to check compatiblity of LHS and RHS
	//			as this already done during the parsing stage		 
	if (result_lhs->get_result_enum() == int_result) {
		result = new Eval_Result_Value_Int();
		result->set_result_enum(int_result);
		// adding values of both LHS and RHS
		result->set_value(result_lhs->get_int_value() + result_rhs->get_int_value());
	} else {
		result = new Eval_Result_Value_Double();
		result->set_result_enum(double_result);
		// adding values of both LHS and RHS
		result->set_value(result_lhs->get_double_value() + result_rhs->get_double_value());
	}

	// deleting temporary result variables
	delete result_lhs;
	delete result_rhs;
	return *result;
}

Eval_Result & Minus_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer) {
	// evaluating tree on both LHS and RHS
	Eval_Result * result_lhs = &(lhs->evaluate(eval_env, file_buffer));
	Eval_Result * result_rhs = &(rhs->evaluate(eval_env, file_buffer));
	// value to be returned
	// will differ based on the type of data
	Eval_Result * result;
	// NOTE :	No need to check compatiblity of LHS and RHS
	//			as this already done during the parsing stage
	if (result_lhs->get_result_enum() == int_result) {
		result = new Eval_Result_Value_Int();
		result->set_result_enum(int_result);
		// subtracting values of both LHS and RHS
		result->set_value(result_lhs->get_int_value() - result_rhs->get_int_value());
	} else {
		result = new Eval_Result_Value_Double();
		result->set_result_enum(double_result);
		// subtracting values of both LHS and RHS
		result->set_value(result_lhs->get_double_value() - result_rhs->get_double_value());
	}

	// deleting temporary result variables
	delete result_lhs;
	delete result_rhs;
	return *result;
}

Eval_Result & Divide_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer) {
	// evaluating tree on both LHS and RHS
	Eval_Result * result_lhs = &(lhs->evaluate(eval_env, file_buffer));
	Eval_Result * result_rhs = &(rhs->evaluate(eval_env, file_buffer));
	// value to be returned
	// will differ based on the type of data
	Eval_Result * result;
	// NOTE :	No need to check compatiblity of LHS and RHS
	//			as this already done during the parsing stage
	if (result_lhs->get_result_enum() == int_result) {
		result = new Eval_Result_Value_Int();
		result->set_result_enum(int_result);
		// dividing values of both LHS and RHS
		result->set_value(result_lhs->get_int_value() / result_rhs->get_int_value());
	} else {
		result = new Eval_Result_Value_Double();
		result->set_result_enum(double_result);
		// dividing values of both LHS and RHS
		result->set_value(result_lhs->get_double_value() / result_rhs->get_double_value());
	}

	// deleting temporary result variables
	delete result_lhs;
	delete result_rhs;
	return *result;
}

Eval_Result & Mult_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer) {
	// evaluating tree on both LHS and RHS
	Eval_Result * result_lhs = &(lhs->evaluate(eval_env, file_buffer));
	Eval_Result * result_rhs = &(rhs->evaluate(eval_env, file_buffer));
	// value to be returned
	// will differ based on the type of data
	Eval_Result * result;
	// NOTE :	No need to check compatiblity of LHS and RHS
	//			as this already done during the parsing stage
	if (result_lhs->get_result_enum() == int_result) {
		result = new Eval_Result_Value_Int();
		result->set_result_enum(int_result);
		// multiplying values of both LHS and RHS
		result->set_value(result_lhs->get_int_value() * result_rhs->get_int_value());
	} else {
		result = new Eval_Result_Value_Double();
		result->set_result_enum(double_result);
		// multiplying values of both LHS and RHS
		result->set_value(result_lhs->get_double_value() * result_rhs->get_double_value());
	}

	// deleting temporary result variables
	delete result_lhs;
	delete result_rhs;
	return *result;
}

Eval_Result & UMinus_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer) {
	// evaluating tree on RHS
	Eval_Result * result_rhs = &(lhs->evaluate(eval_env, file_buffer));
	// value to be returned
	// will differ based on the type of data
	Eval_Result * result;
	if (result_rhs->get_result_enum() == int_result) {
		result = new Eval_Result_Value_Int();
		result->set_result_enum(int_result);
		// changing the sign of RHS
		result->set_value(-1 * result_rhs->get_int_value());
	} else {
		result = new Eval_Result_Value_Double();
		result->set_result_enum(double_result);
		// changing the sign of  RHS
		result->set_value(-1.0 * result_rhs->get_double_value());
	}

	// deleting temporary result variables
	delete result_rhs;
	return *result;
}

Eval_Result & Relational_Expr_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer) {
	// evaluating tree on both LHS and RHS
	Eval_Result * result_lhs = &(lhs_condition->evaluate(eval_env, file_buffer));
	Eval_Result * result_rhs = &(rhs_condition->evaluate(eval_env, file_buffer));
	// value to be returned
	// output will be a boolean (implemented using int)
	Eval_Result * result = new Eval_Result_Value_Int();
	int temp;
	// NOTE :	No need to check compatiblity of LHS and RHS
	//			as it is already done during parsing stage. 
	if (rel_op == less_than) {
		result->set_result_enum(int_result);
		(result_lhs->get_int_value() < result_rhs->get_int_value())? temp = 1 : temp = 0;
		result->set_value(temp);
	} else if (rel_op == greater_than){
		result->set_result_enum(int_result);
		(result_lhs->get_int_value() > result_rhs->get_int_value())? temp = 1 : temp = 0;
		result->set_value(temp);
	} else if (rel_op == less_equalto){
		result->set_result_enum(int_result);
		(result_lhs->get_int_value() <= result_rhs->get_int_value())? temp = 1 : temp = 0;
		result->set_value(temp);
	} else if (rel_op == greater_equalto){
		result->set_result_enum(int_result);
		(result_lhs->get_int_value() >= result_rhs->get_int_value())? temp = 1 : temp = 0;
		result->set_value(temp);
	} else if (rel_op == equalto){
		result->set_result_enum(int_result);
		(result_lhs->get_int_value() == result_rhs->get_int_value())? temp = 1 : temp = 0;
		result->set_value(temp);
	} else if (rel_op == not_equalto){
		result->set_result_enum(int_result);
		(result_lhs->get_int_value() != result_rhs->get_int_value())? temp = 1 : temp = 0;
		result->set_value(temp);
	}

	// deleting temporary result variables
	delete result_lhs;
	delete result_rhs;
	return *result;
}

Eval_Result & Logical_Expr_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer) {
	// LHS might be null for logical_not
	Eval_Result * result_lhs;
	if (lhs_op != NULL) result_lhs = &(lhs_op->evaluate(eval_env, file_buffer));
	Eval_Result * result_rhs = &(rhs_op->evaluate(eval_env, file_buffer));
	// value to be returned
	// output will be a boolean (implemented using int)
	Eval_Result * result = new Eval_Result_Value_Int();
	int temp;
	// NOTE :	No need to check compatiblity of LHS and RHS
	//			as it is already of same type int. 
	if (bool_op == _logical_and) {
		result->set_result_enum(int_result);
		(result_lhs->get_int_value() && result_rhs->get_int_value())? temp = 1 : temp = 0;
		result->set_value(temp);
	} else if (bool_op == _logical_or){
		result->set_result_enum(int_result);
		(result_lhs->get_int_value() || result_rhs->get_int_value())? temp = 1 : temp = 0;
		result->set_value(temp);
	} else if (bool_op == _logical_not){
		result->set_result_enum(int_result);
		(!result_rhs->get_int_value())? temp = 1 : temp = 0;
		result->set_value(temp);
	}

	// deleting temporary result variables
	if (lhs_op != NULL) delete result_lhs;
	delete result_rhs;
	return *result;
}

Eval_Result & Selection_Statement_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer) {
	// Condition cannot be null as it is not allowed in the grammer
	Eval_Result * result_cond = &(cond->evaluate(eval_env, file_buffer));

	if (result_cond->get_int_value() && then_part != NULL) then_part->evaluate(eval_env, file_buffer);
	else if (!result_cond->get_int_value() && else_part != NULL) else_part->evaluate(eval_env, file_buffer); 

	// deleting temporary result variables
	delete result_cond;
}

Eval_Result & Iteration_Statement_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer) {
	// Condition cannot be null as it is not allowed in the grammer
	Eval_Result * result_cond;
	if (is_do_form) {
		do {
			body->evaluate(eval_env,file_buffer);
			result_cond = &(cond->evaluate(eval_env, file_buffer));
		} while (result_cond->get_int_value());
	} else {
		result_cond = &(cond->evaluate(eval_env, file_buffer));
		while(result_cond->get_int_value()) {
			body->evaluate(eval_env,file_buffer);
			result_cond = &(cond->evaluate(eval_env, file_buffer));
		}
	}
}

Eval_Result & Sequence_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer) {
	// temporary variable to store result
	Eval_Result * result = NULL;

	for (list <Ast *>::iterator i = statement_list.begin(); i != statement_list.end(); i++) {
		CHECK_INVARIANT(((*i) != NULL), "Ast pointer in a Sequence AST seems to be NULL");
		result = &((*i)->evaluate(eval_env, file_buffer)); 
	}
}

Eval_Result & Return_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer) {}

Eval_Result & Conditional_Expression_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer)
{
	// Condition cannot be null as it is not allowed in the grammer
	Eval_Result * result = NULL;
	Eval_Result * result_cond = &(cond->evaluate(eval_env, file_buffer));

	if (result_cond->get_int_value())result = & (lhs->evaluate(eval_env, file_buffer));
	else if (!result_cond->get_int_value())result = & (rhs->evaluate(eval_env, file_buffer)); 

	// deleting temporary result variables
	delete result_cond;
	return *result;
}
