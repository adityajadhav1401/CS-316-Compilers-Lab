#include<string>
#include<iostream>
#include<iomanip>
#include<typeinfo>
#include<list>

template class Number_Ast<int>;
template class Number_Ast<double>;
using namespace std;

///////////////////
//	  	AST  	 //
///////////////////
Code_For_Ast & Ast::compile() { }
Code_For_Ast & Ast::compile_and_optimize_ast(Lra_Outcome & lra) { }
Code_For_Ast & Ast::create_store_stmt(Register_Descriptor * store_register) { }

///////////////////
// 	ASSIGN AST 	 //
///////////////////
Code_For_Ast & Assignment_Ast::compile() { 
	Code_For_Ast & load_stmt = rhs->compile();
	Register_Descriptor * load_register = load_stmt.get_reg();
	
	list<Icode_Stmt *> & ic_list = *new list<Icode_Stmt *>;
	ic_list = load_stmt.get_icode_list();
	ic_list.splice(ic_list.end(), lhs->create_store_stmt(load_register).get_icode_list());

	Code_For_Ast * assign_stmt = new Code_For_Ast();
	assign_stmt = new Code_For_Ast(ic_list, load_register);
	
	load_register->reset_use_for_expr_result();
	return *assign_stmt;
}
Code_For_Ast & Assignment_Ast::compile_and_optimize_ast(Lra_Outcome & lra) { }

///////////////////
//    NAME AST 	 //
///////////////////
Code_For_Ast & Name_Ast::compile() {
	list<Icode_Stmt *> & ic_list = * new list<Icode_Stmt *>;
	Code_For_Ast * load_stmt = new Code_For_Ast();
	if(node_data_type == int_data_type){
		Register_Descriptor* load_register = machine_desc_object.get_new_register<int_reg>();
		Move_IC_Stmt *stmt = new Move_IC_Stmt(load,new Mem_Addr_Opd(*variable_symbol_entry),new Register_Addr_Opd(load_register));
		ic_list.push_back(stmt);	
		if (ic_list.empty() == false)
			load_stmt  = new Code_For_Ast(ic_list,load_register);
	}
	else if(node_data_type == double_data_type){
		Register_Descriptor* load_register = machine_desc_object.get_new_register<float_reg>();
		Move_IC_Stmt *stmt = new Move_IC_Stmt(load_d,new Mem_Addr_Opd(*variable_symbol_entry),new Register_Addr_Opd(load_register));
		ic_list.push_back(stmt);	
		if (ic_list.empty() == false)
			load_stmt  = new Code_For_Ast(ic_list,load_register);
	}
	return *load_stmt;
}
Code_For_Ast & Name_Ast::compile_and_optimize_ast(Lra_Outcome & lra) { }
Code_For_Ast & Name_Ast::create_store_stmt(Register_Descriptor * store_register) { 
	Move_IC_Stmt * stmt;
	list<Icode_Stmt *> & ic_list = *new list<Icode_Stmt *>;
	Code_For_Ast * store_stmt = new Code_For_Ast();
	if(node_data_type == int_data_type)
		stmt = new Move_IC_Stmt(store,new Register_Addr_Opd(store_register),new Mem_Addr_Opd(*variable_symbol_entry));
	else if(node_data_type == double_data_type)
		stmt = new Move_IC_Stmt(store_d,new Register_Addr_Opd(store_register),new Mem_Addr_Opd(*variable_symbol_entry));

	if (command_options.is_do_lra_selected() == false)
		variable_symbol_entry->free_register(store_register);
	else {
		variable_symbol_entry->update_register(store_register);
		store_register->reset_use_for_expr_result();
	}
	ic_list.push_back(stmt);	
	if (ic_list.empty() == false)
		store_stmt  = new Code_For_Ast(ic_list,NULL);
	return *store_stmt;
}


///////////////////
//  NUMBER AST 	 //
///////////////////
template <class T>
Code_For_Ast & Number_Ast<T>::compile() { 
	list<Icode_Stmt *> & ic_list = * new list<Icode_Stmt *>;
	Code_For_Ast * load_stmt = new Code_For_Ast();
	if(node_data_type == int_data_type){
		Const_Opd<int> * const_num = new Const_Opd<int>(constant);
		Register_Descriptor* load_register =  machine_desc_object.get_new_register<int_reg>();	
		Move_IC_Stmt *stmt = new Move_IC_Stmt(imm_load,const_num,new Register_Addr_Opd(load_register));
		ic_list.push_back(stmt);	
		if (ic_list.empty() == false)
			load_stmt  = new Code_For_Ast(ic_list,load_register);
	}
	else if(node_data_type == double_data_type){
		Const_Opd<double> * const_num = new Const_Opd<double>(constant);
		Register_Descriptor* load_register =  machine_desc_object.get_new_register<float_reg>();	
		Move_IC_Stmt *stmt = new Move_IC_Stmt(imm_load_d,const_num,new Register_Addr_Opd(load_register));
		ic_list.push_back(stmt);	
		if (ic_list.empty() == false)
			load_stmt  = new Code_For_Ast(ic_list,load_register);
	}
	return *load_stmt;

}

template <class T>
Code_For_Ast & Number_Ast<T>::compile_and_optimize_ast(Lra_Outcome & lra) { }


///////////////////
//  ARITH EXPR 	 //
///////////////////
Code_For_Ast & Arithmetic_Expr_Ast::compile() { }
Code_For_Ast & Arithmetic_Expr_Ast::compile_and_optimize_ast(Lra_Outcome & lra) { }


///////////////////
//  PLUS AST 	 //
///////////////////
Code_For_Ast & Plus_Ast::compile() { 
	Code_For_Ast & lhs_stmt = lhs->compile();
	Code_For_Ast & rhs_stmt = rhs->compile();
	Register_Descriptor * lhs_load_register = lhs_stmt.get_reg();
	Register_Descriptor * rhs_load_register = rhs_stmt.get_reg();
	list<Icode_Stmt *> & ic_list = * new list<Icode_Stmt *>;
	Code_For_Ast * plus_stmt = new Code_For_Ast();
	Register_Descriptor* load_register;

	if(node_data_type == int_data_type){
		load_register =  machine_desc_object.get_new_register<int_reg>();	
		Compute_IC_Stmt * stmt = new Compute_IC_Stmt(add,new Register_Addr_Opd(lhs_load_register),new Register_Addr_Opd(rhs_load_register),new Register_Addr_Opd(load_register));
		
		if (lhs_stmt.get_icode_list().empty() == false) ic_list = lhs_stmt.get_icode_list();
		if (rhs_stmt.get_icode_list().empty() == false) ic_list.splice(ic_list.end(), rhs_stmt.get_icode_list());
		ic_list.push_back(stmt);	
	}
	else if(node_data_type == double_data_type){
		load_register =  machine_desc_object.get_new_register<float_reg>();
		Compute_IC_Stmt * stmt = new Compute_IC_Stmt(add_d,new Register_Addr_Opd(lhs_load_register),new Register_Addr_Opd(rhs_load_register),new Register_Addr_Opd(load_register));
		
		if (lhs_stmt.get_icode_list().empty() == false) ic_list = lhs_stmt.get_icode_list();
		if (rhs_stmt.get_icode_list().empty() == false) ic_list.splice(ic_list.end(), rhs_stmt.get_icode_list());
		ic_list.push_back(stmt);	
	}
	if (ic_list.empty() == false) plus_stmt = new Code_For_Ast(ic_list, load_register);

	if(lhs_load_register!=NULL) lhs_load_register->reset_use_for_expr_result();
	if(rhs_load_register!=NULL) rhs_load_register->reset_use_for_expr_result();

	return *plus_stmt;
}
Code_For_Ast & Plus_Ast::compile_and_optimize_ast(Lra_Outcome & lra) { }


///////////////////
//  MINUS AST 	 //
///////////////////
Code_For_Ast & Minus_Ast::compile() { 
	Code_For_Ast & lhs_stmt = lhs->compile();
	Code_For_Ast & rhs_stmt = rhs->compile();
	Register_Descriptor * lhs_load_register = lhs_stmt.get_reg();
	Register_Descriptor * rhs_load_register = rhs_stmt.get_reg();
	list<Icode_Stmt *> & ic_list = * new list<Icode_Stmt *>;
	Code_For_Ast * minus_stmt = new Code_For_Ast();
	Register_Descriptor* load_register = NULL;

	if(node_data_type == int_data_type){
		load_register =  machine_desc_object.get_new_register<int_reg>();	
		Compute_IC_Stmt * stmt = new Compute_IC_Stmt(sub,new Register_Addr_Opd(lhs_load_register),new Register_Addr_Opd(rhs_load_register),new Register_Addr_Opd(load_register));
		
		if (lhs_stmt.get_icode_list().empty() == false) ic_list = lhs_stmt.get_icode_list();
		if (rhs_stmt.get_icode_list().empty() == false) ic_list.splice(ic_list.end(), rhs_stmt.get_icode_list());
		ic_list.push_back(stmt);	
	}
	else if(node_data_type == double_data_type){
		load_register =  machine_desc_object.get_new_register<float_reg>();
		Compute_IC_Stmt * stmt = new Compute_IC_Stmt(sub_d,new Register_Addr_Opd(lhs_load_register),new Register_Addr_Opd(rhs_load_register),new Register_Addr_Opd(load_register));
		
		if (lhs_stmt.get_icode_list().empty() == false) ic_list = lhs_stmt.get_icode_list();
		if (rhs_stmt.get_icode_list().empty() == false) ic_list.splice(ic_list.end(), rhs_stmt.get_icode_list());
		ic_list.push_back(stmt);	
	}

	if (ic_list.empty() == false) minus_stmt = new Code_For_Ast(ic_list, load_register);

	if(lhs_load_register!=NULL) lhs_load_register->reset_use_for_expr_result();
	if(rhs_load_register!=NULL) rhs_load_register->reset_use_for_expr_result();
	return *minus_stmt;
}
Code_For_Ast & Minus_Ast::compile_and_optimize_ast(Lra_Outcome & lra) { }


///////////////////
//  DIVIDE AST 	 //
///////////////////
Code_For_Ast & Divide_Ast::compile() { 
	Code_For_Ast & lhs_stmt = lhs->compile();
	Code_For_Ast & rhs_stmt = rhs->compile();
	Register_Descriptor * lhs_load_register = lhs_stmt.get_reg();
	Register_Descriptor * rhs_load_register = rhs_stmt.get_reg();
	list<Icode_Stmt *> & ic_list = * new list<Icode_Stmt *>;
	Code_For_Ast * div_stmt = new Code_For_Ast();
	Register_Descriptor* load_register = NULL;

	if(node_data_type == int_data_type){
		load_register =  machine_desc_object.get_new_register<int_reg>();	
		Compute_IC_Stmt * stmt = new Compute_IC_Stmt(divd,new Register_Addr_Opd(lhs_load_register),new Register_Addr_Opd(rhs_load_register),new Register_Addr_Opd(load_register));
		
		if (lhs_stmt.get_icode_list().empty() == false) ic_list = lhs_stmt.get_icode_list();
		if (rhs_stmt.get_icode_list().empty() == false) ic_list.splice(ic_list.end(), rhs_stmt.get_icode_list());
		ic_list.push_back(stmt);	
	}
	else if(node_data_type == double_data_type){
		load_register =  machine_desc_object.get_new_register<float_reg>();
		Compute_IC_Stmt * stmt = new Compute_IC_Stmt(div_d,new Register_Addr_Opd(lhs_load_register),new Register_Addr_Opd(rhs_load_register),new Register_Addr_Opd(load_register));
		
		if (lhs_stmt.get_icode_list().empty() == false) ic_list = lhs_stmt.get_icode_list();
		if (rhs_stmt.get_icode_list().empty() == false) ic_list.splice(ic_list.end(), rhs_stmt.get_icode_list());
		ic_list.push_back(stmt);	
	}

	if (ic_list.empty() == false) div_stmt = new Code_For_Ast(ic_list, load_register);

	if(lhs_load_register!=NULL) lhs_load_register->reset_use_for_expr_result();
	if(rhs_load_register!=NULL) rhs_load_register->reset_use_for_expr_result();

	return *div_stmt;
}
Code_For_Ast & Divide_Ast::compile_and_optimize_ast(Lra_Outcome & lra) { }

///////////////////
//    MULT AST   //
///////////////////
Code_For_Ast & Mult_Ast::compile() { 
	Code_For_Ast & lhs_stmt = lhs->compile();
	Code_For_Ast & rhs_stmt = rhs->compile();
	Register_Descriptor * lhs_load_register = lhs_stmt.get_reg();
	Register_Descriptor * rhs_load_register = rhs_stmt.get_reg();
	list<Icode_Stmt *> & ic_list = * new list<Icode_Stmt *>;
	Code_For_Ast * mult_stmt = new Code_For_Ast();
	Register_Descriptor* load_register = NULL;

	if(node_data_type == int_data_type){
		load_register =  machine_desc_object.get_new_register<int_reg>();	
		Compute_IC_Stmt * stmt = new Compute_IC_Stmt(mult,new Register_Addr_Opd(lhs_load_register),new Register_Addr_Opd(rhs_load_register),new Register_Addr_Opd(load_register));
		
		if (lhs_stmt.get_icode_list().empty() == false) ic_list = lhs_stmt.get_icode_list();
		if (rhs_stmt.get_icode_list().empty() == false) ic_list.splice(ic_list.end(), rhs_stmt.get_icode_list());
		ic_list.push_back(stmt);	
	}
	else if(node_data_type == double_data_type){
		load_register =  machine_desc_object.get_new_register<float_reg>();
		Compute_IC_Stmt * stmt = new Compute_IC_Stmt(mult_d,new Register_Addr_Opd(lhs_load_register),new Register_Addr_Opd(rhs_load_register),new Register_Addr_Opd(load_register));
		
		if (lhs_stmt.get_icode_list().empty() == false) ic_list = lhs_stmt.get_icode_list();
		if (rhs_stmt.get_icode_list().empty() == false) ic_list.splice(ic_list.end(), rhs_stmt.get_icode_list());
		ic_list.push_back(stmt);	
	}

	if (ic_list.empty() == false) mult_stmt = new Code_For_Ast(ic_list, load_register);

	if(lhs_load_register!=NULL) lhs_load_register->reset_use_for_expr_result();
	if(rhs_load_register!=NULL) rhs_load_register->reset_use_for_expr_result();

	return *mult_stmt;
}
Code_For_Ast & Mult_Ast::compile_and_optimize_ast(Lra_Outcome & lra) { }


///////////////////
//  UMINUS AST   //
///////////////////
Code_For_Ast & UMinus_Ast::compile() { 
	Code_For_Ast & lhs_stmt = lhs->compile();
	Register_Descriptor * lhs_load_register = lhs_stmt.get_reg();
	list<Icode_Stmt *> & ic_list = * new list<Icode_Stmt *>;
	Code_For_Ast * uminus_stmt = new Code_For_Ast();
	Register_Descriptor* load_register = NULL;

	if(node_data_type == int_data_type){
		load_register =  machine_desc_object.get_new_register<int_reg>();	
		Move_IC_Stmt * stmt = new Move_IC_Stmt(uminus,new Register_Addr_Opd(lhs_load_register),new Register_Addr_Opd(load_register));
		
		if (lhs_stmt.get_icode_list().empty() == false) ic_list = lhs_stmt.get_icode_list();
		ic_list.push_back(stmt);	
	}
	else if(node_data_type == double_data_type){
		load_register =  machine_desc_object.get_new_register<float_reg>();	
		Move_IC_Stmt * stmt = new Move_IC_Stmt(uminus_d,new Register_Addr_Opd(lhs_load_register),new Register_Addr_Opd(load_register));
		
		if (lhs_stmt.get_icode_list().empty() == false) ic_list = lhs_stmt.get_icode_list();
		ic_list.push_back(stmt);	
	}
	if (ic_list.empty() == false) uminus_stmt = new Code_For_Ast(ic_list, load_register);

	if(lhs_load_register!=NULL) lhs_load_register->reset_use_for_expr_result();

	return *uminus_stmt;
}
Code_For_Ast & UMinus_Ast::compile_and_optimize_ast(Lra_Outcome & lra) { }

//////////////////////
// CONDITIONAL EXPR //
//////////////////////
Code_For_Ast & Conditional_Expression_Ast::compile() { 
	Code_For_Ast & cond_stmt_code = cond->compile();
	Register_Descriptor * cond_load_register = cond_stmt_code.get_reg();
	Code_For_Ast & lhs_stmt_code = lhs->compile();
	Register_Descriptor * lhs_load_register = lhs_stmt_code.get_reg();
	Code_For_Ast & rhs_stmt_code = rhs->compile();
	Register_Descriptor * rhs_load_register = rhs_stmt_code.get_reg();
	Register_Addr_Opd * zero_addr = new Register_Addr_Opd(machine_desc_object.spim_register_table[zero]);

	Register_Descriptor * temp_register;
	if(node_data_type==int_data_type) temp_register = machine_desc_object.get_new_register<int_reg>();	
	else if(node_data_type ==double_data_type) temp_register = machine_desc_object.get_new_register<float_reg>();	

	Register_Addr_Opd * temp = new Register_Addr_Opd(temp_register);

	string label1 = get_new_label();
	string label2 = get_new_label();
	Control_Flow_IC_Stmt * cond_stmt = new Control_Flow_IC_Stmt(beq,new Register_Addr_Opd(cond_load_register),label1);
	Control_Flow_IC_Stmt * jump_stmt = new Control_Flow_IC_Stmt(j,NULL,label2);

	Compute_IC_Stmt * temp1_stmt = new Compute_IC_Stmt(or_t,new Register_Addr_Opd(lhs_load_register),zero_addr,temp);
	Compute_IC_Stmt * temp2_stmt = new Compute_IC_Stmt(or_t,new Register_Addr_Opd(rhs_load_register),zero_addr,temp);

	list<Icode_Stmt *> & ic_list = * new list<Icode_Stmt *>;
	if (cond_stmt_code.get_icode_list().empty() == false) ic_list = cond_stmt_code.get_icode_list();
	ic_list.push_back(cond_stmt);

	if (lhs_stmt_code.get_icode_list().empty() == false) ic_list.splice(ic_list.end(), lhs_stmt_code.get_icode_list());
	ic_list.push_back(temp1_stmt);	
	ic_list.push_back(jump_stmt);	
	ic_list.push_back(new Label_IC_Stmt(label,label1));

	if (rhs_stmt_code.get_icode_list().empty() == false) ic_list.splice(ic_list.end(), rhs_stmt_code.get_icode_list());
	ic_list.push_back(temp2_stmt);	
	ic_list.push_back(new Label_IC_Stmt(label,label2));	

	Code_For_Ast * conditional_stmt = new Code_For_Ast();
	if (ic_list.empty() == false) conditional_stmt = new Code_For_Ast(ic_list, temp_register);

	if(cond_load_register!=NULL) cond_load_register->reset_use_for_expr_result();
	if(lhs_load_register!=NULL) lhs_load_register->reset_use_for_expr_result();
	if(rhs_load_register!=NULL) rhs_load_register->reset_use_for_expr_result();

	return *conditional_stmt;
}

///////////////////
//  RETURN AST   //
///////////////////
Code_For_Ast & Return_Ast::compile() { }
Code_For_Ast & Return_Ast::compile_and_optimize_ast(Lra_Outcome & lra) { }

/////////////////////
// RELATIONAL EXPR //
/////////////////////
Code_For_Ast & Relational_Expr_Ast::compile() { 
	Code_For_Ast & lhs_stmt = lhs_condition->compile();
	Code_For_Ast & rhs_stmt = rhs_condition->compile();
	Register_Descriptor * lhs_load_register = lhs_stmt.get_reg();
	Register_Descriptor * rhs_load_register = rhs_stmt.get_reg();
	Tgt_Op ic_operator;	

 	if (rel_op == less_equalto) ic_operator = sle;
 	else if (rel_op == less_than) ic_operator = slt;
 	else if (rel_op == greater_than) ic_operator = sgt;
 	else if (rel_op == greater_equalto) ic_operator = sge;
 	else if (rel_op == equalto) ic_operator = seq;
 	else if (rel_op == not_equalto) ic_operator = sne;
 	else if (rel_op == less_than) ic_operator = slt;
 	else if (rel_op == less_than) ic_operator = slt;
 	else if (rel_op == less_than) ic_operator = slt;

	Register_Descriptor* load_register =  machine_desc_object.get_new_register<int_reg>();	

	Compute_IC_Stmt * stmt = new Compute_IC_Stmt(ic_operator,new Register_Addr_Opd(lhs_load_register),new Register_Addr_Opd(rhs_load_register),new Register_Addr_Opd(load_register));
	list<Icode_Stmt *> & ic_list = * new list<Icode_Stmt *>;

	if (lhs_stmt.get_icode_list().empty() == false) ic_list = lhs_stmt.get_icode_list();
	if (rhs_stmt.get_icode_list().empty() == false) ic_list.splice(ic_list.end(), rhs_stmt.get_icode_list());
	ic_list.push_back(stmt);	

	Code_For_Ast * rel_stmt =new Code_For_Ast();
	if (ic_list.empty() == false) rel_stmt = new Code_For_Ast(ic_list, load_register);

	if(lhs_load_register!=NULL) rhs_load_register->reset_use_for_expr_result();
	if(rhs_load_register!=NULL) lhs_load_register->reset_use_for_expr_result();

	return *rel_stmt;
} 

///////////////////
// LOGICAL EXPR  //
///////////////////
Code_For_Ast & Logical_Expr_Ast::compile() { 
	Code_For_Ast & rhs_stmt = rhs_op->compile();
	Register_Descriptor * rhs_load_register = rhs_stmt.get_reg();
	Register_Descriptor * lhs_load_register;
	Register_Addr_Opd *rhs_addr = new Register_Addr_Opd(rhs_load_register);
	Register_Descriptor* load_register =  machine_desc_object.get_new_register<int_reg>();	
	list<Icode_Stmt *> & ic_list = * new list<Icode_Stmt *>;
	Tgt_Op ic_operator;
	Code_For_Ast * bool_stmt = new Code_For_Ast();

	if(bool_op != _logical_not){
		Code_For_Ast & lhs_stmt = lhs_op->compile();
		lhs_load_register = lhs_stmt.get_reg();		
		Register_Addr_Opd *lhs_addr = new Register_Addr_Opd(lhs_load_register);
			
	 	if (bool_op == _logical_or) ic_operator = or_t;
	 	else if (bool_op == _logical_and) ic_operator = and_t;

		Compute_IC_Stmt * stmt = new Compute_IC_Stmt(ic_operator,lhs_addr,rhs_addr,new Register_Addr_Opd(load_register));
		
		if (lhs_stmt.get_icode_list().empty() == false) ic_list = lhs_stmt.get_icode_list();
		if (rhs_stmt.get_icode_list().empty() == false) ic_list.splice(ic_list.end(), rhs_stmt.get_icode_list());
		ic_list.push_back(stmt);	
	}
	else{
		lhs_load_register =  machine_desc_object.get_new_register<int_reg>();	
		Register_Addr_Opd *lhs_addr = new Register_Addr_Opd(lhs_load_register);
		Const_Opd<int> * one_num = new Const_Opd<int>(1);

	 	if (bool_op == _logical_not) ic_operator = not_t;

		Move_IC_Stmt * load_one_stmt = new Move_IC_Stmt(imm_load,one_num,lhs_addr);
		Compute_IC_Stmt * stmt = new Compute_IC_Stmt(ic_operator,rhs_addr,lhs_addr,new Register_Addr_Opd(load_register));

		ic_list.push_back(load_one_stmt);
		if (rhs_stmt.get_icode_list().empty() == false) ic_list.splice(ic_list.end(), rhs_stmt.get_icode_list());
		ic_list.push_back(stmt);	
	}
	if (ic_list.empty() == false) bool_stmt = new Code_For_Ast(ic_list, load_register);

	if(rhs_load_register!=NULL) rhs_load_register->reset_use_for_expr_result();
	if(lhs_load_register!=NULL) lhs_load_register->reset_use_for_expr_result();

	return *bool_stmt;
}

////////////////////
// SELECTION STMT //
////////////////////
Code_For_Ast & Selection_Statement_Ast::compile() { 
	Code_For_Ast & cond_stmt_code = cond->compile();
	Code_For_Ast & then_stmt_code = then_part->compile();
	Register_Descriptor * cond_load_register = cond_stmt_code.get_reg();
	Register_Descriptor * then_load_register = then_stmt_code.get_reg();

	string label1 = get_new_label();
	Control_Flow_IC_Stmt * cond_stmt = new Control_Flow_IC_Stmt(beq,new Register_Addr_Opd(cond_load_register),label1);
	
	list<Icode_Stmt *> & ic_list = * new list<Icode_Stmt *>;
	if (cond_stmt_code.get_icode_list().empty() == false) ic_list = cond_stmt_code.get_icode_list();
	ic_list.push_back(cond_stmt);	

	if (then_stmt_code.get_icode_list().empty() == false) ic_list.splice(ic_list.end(), then_stmt_code.get_icode_list());
	Code_For_Ast * selection_stmt = new Code_For_Ast();
	if (else_part == NULL) {		
		ic_list.push_back(new Label_IC_Stmt(label,label1));	

		if (ic_list.empty() == false) selection_stmt = new Code_For_Ast(ic_list, NULL);

	} else {
		Code_For_Ast & else_stmt_code = else_part->compile();
		Register_Descriptor * else_load_register = else_stmt_code.get_reg();

		string label2 = get_new_label();
		Control_Flow_IC_Stmt * jump_stmt = new Control_Flow_IC_Stmt(j,NULL,label2);
		ic_list.push_back(jump_stmt);

		ic_list.push_back(new Label_IC_Stmt(label,label1));	
		if (else_stmt_code.get_icode_list().empty() == false) ic_list.splice(ic_list.end(), else_stmt_code.get_icode_list());

		ic_list.push_back(new Label_IC_Stmt(label,label2));	
		if (ic_list.empty() == false) selection_stmt = new Code_For_Ast(ic_list, NULL);

		if(else_load_register!=NULL) else_load_register->reset_use_for_expr_result();
	}
	if(cond_load_register!=NULL) cond_load_register->reset_use_for_expr_result();
	if(then_load_register!=NULL) then_load_register->reset_use_for_expr_result();
	
	return *selection_stmt;
}

////////////////////
// ITERATION STMT //
////////////////////
Code_For_Ast & Iteration_Statement_Ast::compile() { 
	Code_For_Ast & cond_stmt_code = cond->compile();
	Register_Descriptor * cond_load_register = cond_stmt_code.get_reg();
	
	Code_For_Ast & body_stmt_code = body->compile();
	Register_Descriptor * body_load_register = body_stmt_code.get_reg();

	string label1 = get_new_label();
	string label2 = get_new_label();
	Control_Flow_IC_Stmt * cond_stmt = new Control_Flow_IC_Stmt(bne,new Register_Addr_Opd(cond_load_register),label1);
	
	list<Icode_Stmt *> & ic_list = * new list<Icode_Stmt *>;
	Code_For_Ast * iteration_stmt = new Code_For_Ast();

	if(!is_do_form){
		Control_Flow_IC_Stmt * jump_stmt = new Control_Flow_IC_Stmt(j,NULL,label2);

		ic_list.push_back(jump_stmt);	
		ic_list.push_back(new Label_IC_Stmt(label,label1));	
		
		if (body_stmt_code.get_icode_list().empty() == false) ic_list.splice(ic_list.end(), body_stmt_code.get_icode_list());
		ic_list.push_back(new Label_IC_Stmt(label,label2));	
		
		if (cond_stmt_code.get_icode_list().empty() == false) ic_list.splice(ic_list.end(), cond_stmt_code.get_icode_list());
		ic_list.push_back(cond_stmt);	
	}
	else{
		Code_For_Ast & body_stmt_code = body->compile();
		Register_Descriptor * body_load_register = body_stmt_code.get_reg();

		ic_list.push_back(new Label_IC_Stmt(label,label1));	
		
		if (body_stmt_code.get_icode_list().empty() == false) ic_list.splice(ic_list.end(), body_stmt_code.get_icode_list());
		ic_list.push_back(new Label_IC_Stmt(label,label2));	
		
		if (cond_stmt_code.get_icode_list().empty() == false) ic_list.splice(ic_list.end(), cond_stmt_code.get_icode_list());
		ic_list.push_back(cond_stmt);	
	}
	if (ic_list.empty() == false) iteration_stmt = new Code_For_Ast(ic_list, NULL);

	if(cond_load_register!=NULL) cond_load_register->reset_use_for_expr_result();
	if(body_load_register!=NULL) body_load_register->reset_use_for_expr_result();

	return *iteration_stmt;
}

///////////////////
//  SEQUENCE AST //
///////////////////
Code_For_Ast & Sequence_Ast::compile() { 
	for (list<Ast *>::iterator it = statement_list.begin();it!=statement_list.end();it++){
		Code_For_Ast & stmt = (*it)->compile();
		Register_Descriptor * reg = stmt.get_reg();
		if(reg != NULL)	reg->reset_use_for_expr_result();
		if (stmt.get_icode_list().empty() == false) sa_icode_list.splice(sa_icode_list.end(), stmt.get_icode_list());
	}
	Code_For_Ast * seq_stmt = new Code_For_Ast();
	if (sa_icode_list.empty() == false)
		seq_stmt = new Code_For_Ast(sa_icode_list, NULL);

	return *seq_stmt;
} 

void Sequence_Ast::print_assembly(ostream & file_buffer) {
	for(list<Icode_Stmt *>::iterator it = sa_icode_list.begin() ; it != sa_icode_list.end() ; it++)
		(*it)->print_assembly(file_buffer);
}

void Sequence_Ast::print_icode(ostream & file_buffer)
{	
	for(list<Icode_Stmt *>::iterator it = sa_icode_list.begin() ; it != sa_icode_list.end() ; it++)
		(*it)->print_icode(file_buffer);
}
