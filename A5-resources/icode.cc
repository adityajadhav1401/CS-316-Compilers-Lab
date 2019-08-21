#define VAR_SPACE "         "
using namespace std;

template class Const_Opd<int>;
template class Const_Opd<double>;
/////////////////////////
//	COMPILE FOR AST    //
/////////////////////////
Code_For_Ast::Code_For_Ast() { result_register = NULL; }
Code_For_Ast::Code_For_Ast(list<Icode_Stmt *> & ic_l, Register_Descriptor * reg) { 
	this->ics_list = ic_l;
	this->result_register = reg;
}
Register_Descriptor * Code_For_Ast::get_reg() { return result_register; }
void Code_For_Ast::set_reg(Register_Descriptor * reg) { result_register = reg; }
list<Icode_Stmt *> & Code_For_Ast::get_icode_list() { return ics_list; }
void Code_For_Ast::append_ics(Icode_Stmt & ics) { ics_list.push_back(&ics); }
Code_For_Ast & Code_For_Ast::operator=(const Code_For_Ast & rhs) { 
	ics_list = rhs.ics_list;
	result_register = rhs.result_register;
	return *this;
}


/////////////////////////
//  INSTRUCTION DESC   //
/////////////////////////
Instruction_Descriptor::Instruction_Descriptor (Tgt_Op op, string name, string mnn, string ics, Icode_Format icf, Assembly_Format af) { 
	inst_op = op;
	mnemonic = mnn;
	ic_symbol = ics;
	this->name = name;
	ic_format = icf;
	assem_format = af;
}
Instruction_Descriptor::Instruction_Descriptor() { 
	inst_op = nop;
	mnemonic = "";
	ic_symbol = "";
	this->name = "";
	ic_format = i_nsy;
	assem_format = a_nsy;
}
Tgt_Op Instruction_Descriptor::get_op() { return inst_op; }
string Instruction_Descriptor::get_name() { return name; }
string Instruction_Descriptor::get_mnemonic() { return mnemonic; }
string Instruction_Descriptor::get_ic_symbol() { return ic_symbol; }
Icode_Format Instruction_Descriptor::get_ic_format() { return ic_format; }
Assembly_Format Instruction_Descriptor::get_assembly_format() { return assem_format; }
void Instruction_Descriptor::print_instruction_descriptor(ostream & file_buffer) {  }


/////////////////////////
//	ICODE STMT OPRAND  //
/////////////////////////
Register_Descriptor * Ics_Opd::get_reg() { }


/////////////////////////
//	MEM ADDR OPRAND    //
/////////////////////////
Mem_Addr_Opd::Mem_Addr_Opd(Symbol_Table_Entry & se) { symbol_entry = &se; }
void Mem_Addr_Opd::print_ics_opd(ostream & file_buffer) { 
	file_buffer << symbol_entry->get_variable_name() << "_";
}
void Mem_Addr_Opd::print_asm_opd(ostream & file_buffer) { 
	Table_Scope symbol_scope = symbol_entry->get_symbol_scope();
	if (symbol_scope == local) {
		int offset = symbol_entry->get_start_offset();
		file_buffer << offset << "($fp)";
	} else {
		file_buffer << symbol_entry->get_variable_name();
	}
}
Mem_Addr_Opd & Mem_Addr_Opd::operator= (const Mem_Addr_Opd & rhs) { 
	Mem_Addr_Opd * m = new Mem_Addr_Opd(*(rhs.symbol_entry));
	return *m;
}


/////////////////////////
//	REG ADDS OPRAND    //
/////////////////////////
Register_Addr_Opd::Register_Addr_Opd(Register_Descriptor * rd) { register_description = rd; }
Register_Descriptor * Register_Addr_Opd::get_reg() { return register_description; }
void Register_Addr_Opd::print_ics_opd(ostream & file_buffer) { 
	file_buffer << register_description->get_name();
}
void Register_Addr_Opd::print_asm_opd(ostream & file_buffer) { 
	file_buffer << "$" << register_description->get_name();
}
Register_Addr_Opd & Register_Addr_Opd::operator=(const Register_Addr_Opd & rhs) {
	Register_Addr_Opd * r = new Register_Addr_Opd(rhs.register_description);
	return *r;
}


/////////////////////////
//	CONSTANT OPRAND    //
/////////////////////////
template <class T>
Const_Opd<T>::Const_Opd (T n) { num = n; }
template <class T>
void Const_Opd<T>::print_ics_opd(ostream & file_buffer) { 
	file_buffer << num;
}
template <class T>
void Const_Opd<T>::print_asm_opd(ostream & file_buffer) { 
	file_buffer << num;
}
template <class T>
Const_Opd<T> & Const_Opd<T>::operator=(const Const_Opd & rhs) { 
	Const_Opd<T> * c = new Const_Opd<T>(rhs.num);
	return *c;
}


/////////////////////////
//	ICODE STATEMENT    //
/////////////////////////
Instruction_Descriptor & Icode_Stmt::get_op() { return op_desc; }
Ics_Opd * Icode_Stmt::get_opd1() { }
Ics_Opd * Icode_Stmt::get_opd2() { } 
Ics_Opd * Icode_Stmt::get_result() { }
void Icode_Stmt::set_opd1(Ics_Opd * io) { }
void Icode_Stmt::set_opd2(Ics_Opd * io) { }
void Icode_Stmt::set_result(Ics_Opd * io) { }


/////////////////////////
//	PRINT ICODE STMT   //
/////////////////////////
Print_IC_Stmt::Print_IC_Stmt() { }
Print_IC_Stmt::~Print_IC_Stmt() { }
void Print_IC_Stmt::print_icode(ostream & file_buffer) { }
void Print_IC_Stmt::print_assembly(ostream & file_buffer) { }


/////////////////////////
//	MOVE ICODE STMT    //
/////////////////////////
Move_IC_Stmt::Move_IC_Stmt(Tgt_Op inst_op, Ics_Opd * opd1, Ics_Opd * result) {
	this->opd1 = opd1;
	this->result = result;
	this->op_desc = *(machine_desc_object.spim_instruction_table[inst_op]);
} 
Instruction_Descriptor & Move_IC_Stmt::get_inst_op_of_ics() { return op_desc; }
Ics_Opd * Move_IC_Stmt::get_opd1() { return opd1;}
void Move_IC_Stmt::set_opd1(Ics_Opd * io) { opd1 = io;}
Ics_Opd * Move_IC_Stmt::get_result() { return result; }
void Move_IC_Stmt::set_result(Ics_Opd * io) { result = io; }
void Move_IC_Stmt::print_icode(ostream & file_buffer) { 
	string operation_name = op_desc.get_name();
	Icode_Format ic_format = op_desc.get_ic_format();
	if (ic_format == i_r_op_o1) {
		file_buffer << '\t' << operation_name << ":    \t";
		result->print_ics_opd(file_buffer);
		file_buffer << " <- ";
		opd1->print_ics_opd(file_buffer);
		file_buffer << "\n";
	} else {
		printf("cs316: Error, icode format unsupported\n");
	}
}
void Move_IC_Stmt::print_assembly(ostream & file_buffer) { 
	string operation_mnemonic = op_desc.get_mnemonic();
	Assembly_Format assem_format = op_desc.get_assembly_format();
	if (assem_format == a_op_r_o1) {
		file_buffer << "\t" << operation_mnemonic << " ";
		result->print_asm_opd(file_buffer);
		file_buffer << ", ";
		opd1->print_asm_opd(file_buffer);
		file_buffer << "\n";
	} else if (assem_format == a_op_o1_r) {
		file_buffer << "\t" << operation_mnemonic << " ";
		opd1->print_asm_opd(file_buffer);
		file_buffer << ", ";
		result->print_asm_opd(file_buffer);
		file_buffer << "\n";
	} else {
		printf("cs316: Error, icode format unsupported\n");
	}
}
Move_IC_Stmt & Move_IC_Stmt::operator=(const Move_IC_Stmt & rhs) { 
	op_desc = rhs.op_desc;
	opd1 = rhs.opd1;
	result = rhs.result; 
	return *this;
}


/////////////////////////
// COMPUTE ICODE STMT  //
/////////////////////////
Compute_IC_Stmt::Compute_IC_Stmt(Tgt_Op inst_op, Ics_Opd * opd1, Ics_Opd * opd2, Ics_Opd * result) {
	this->opd1 = opd1;
	this->opd2 = opd2;
	this->result = result;
	this->op_desc = *(machine_desc_object.spim_instruction_table[inst_op]);
} 
Ics_Opd * Compute_IC_Stmt::get_opd1() { return opd1; }
void Compute_IC_Stmt::set_opd1(Ics_Opd * io) { opd1 = io; }
Ics_Opd * Compute_IC_Stmt::get_opd2() { return opd2; }
void Compute_IC_Stmt::set_opd2(Ics_Opd * io) { opd2 = io; }
Ics_Opd * Compute_IC_Stmt::get_result() { return result; }
void Compute_IC_Stmt::set_result(Ics_Opd * io) { result = io; }
Instruction_Descriptor & Compute_IC_Stmt::get_inst_op_of_ics() { return op_desc; }
void Compute_IC_Stmt::print_icode(ostream & file_buffer) { 
	string operation_name = op_desc.get_name();
	Icode_Format ic_format = op_desc.get_ic_format();
	if (ic_format == i_r_o1_op_o2) {
		file_buffer << "\t" << operation_name << ":    \t";
		result->print_ics_opd(file_buffer);
		file_buffer << " <- ";
		opd1->print_ics_opd(file_buffer);
		file_buffer << " , ";
		opd2->print_ics_opd(file_buffer);
		file_buffer << "\n";
	} else if ((ic_format == i_op_o1_r) || (ic_format == i_op_r_o1) || (ic_format == i_r_op_o1)) {
		file_buffer << "\t" << operation_name << ":    \t";
		result->print_ics_opd(file_buffer);
		file_buffer << " <- ";
		opd1->print_ics_opd(file_buffer);
		file_buffer << "\n";
	} else {
		printf("cs316: Error, icode format unsupported\n");
	}
}
void Compute_IC_Stmt::print_assembly(ostream & file_buffer) { 
	string operation_mnemonic = op_desc.get_mnemonic();
	Assembly_Format assem_format = op_desc.get_assembly_format();

	if (assem_format == a_op_r_o1) {
		file_buffer << "\t" << operation_mnemonic << " ";
		result->print_asm_opd(file_buffer);
		file_buffer << ", ";
		opd1->print_asm_opd(file_buffer);
		file_buffer << "\n";
	} else if (assem_format == a_op_o1_r) {
		file_buffer << "\t" << operation_mnemonic << " ";
		opd1->print_asm_opd(file_buffer);
		file_buffer << ", ";
		result->print_asm_opd(file_buffer);
		file_buffer << "\n";
	} else if (assem_format == a_op_r_o1_o2) {
		file_buffer << "\t" << operation_mnemonic << " ";
		result->print_asm_opd(file_buffer);
		file_buffer << ", ";
		opd1->print_asm_opd(file_buffer);
		file_buffer << ", ";
		opd2->print_asm_opd(file_buffer);
		file_buffer << "\n";
	} else if (assem_format == a_op_o1_o2_r) {
		file_buffer << "\t" << operation_mnemonic << " ";
		opd1->print_asm_opd(file_buffer);
		file_buffer << ", ";
		opd2->print_asm_opd(file_buffer);
		file_buffer << ", ";
		result->print_asm_opd(file_buffer);
		file_buffer << "\n";
	} else {
		printf("cs316: Error, icode format unsupported\n");
	}
}
Compute_IC_Stmt & Compute_IC_Stmt::operator=(const Compute_IC_Stmt & rhs) { 
	op_desc = rhs.op_desc;
	opd1 = rhs.opd1;
	opd2 = rhs.opd2;
	result = rhs.result; 
	return *this;
}


/////////////////////////
//	CONTROL ICODE STMT //
/////////////////////////ake
Control_Flow_IC_Stmt::Control_Flow_IC_Stmt(Tgt_Op inst_op, Ics_Opd * opd1, string label) {
	this->opd1 = opd1;
	this->label = label;
	this->op_desc = *(machine_desc_object.spim_instruction_table[inst_op]);
}
Ics_Opd * Control_Flow_IC_Stmt::get_opd1() { return opd1; }
void Control_Flow_IC_Stmt::set_opd1(Ics_Opd * io) { opd1 = io; }
string Control_Flow_IC_Stmt::get_label() { return label; }
void Control_Flow_IC_Stmt::set_label(string label) { this->label = label; } 
Instruction_Descriptor & Control_Flow_IC_Stmt::get_inst_op_of_ics() { return op_desc; }
void Control_Flow_IC_Stmt::print_icode(ostream & file_buffer) { 
	string operation_name = op_desc.get_name();
	Icode_Format ic_format = op_desc.get_ic_format();
	if (ic_format == i_op_o1_o2_st) {	
		file_buffer << "\t" << operation_name << ":    \t";		
		opd1->print_ics_opd(file_buffer);		
		file_buffer << " , ";	
		file_buffer << "zero";
		file_buffer << " : goto " + label;	
		file_buffer << "\n";		
	} else if (ic_format == i_op_st) {
		file_buffer << "\tgoto " + label;
		file_buffer <<"\n";
	} else {
		printf("cs316: Error, icode format unsupported\n");
	}
}
void Control_Flow_IC_Stmt::print_assembly(ostream & file_buffer) { 
	string operation_mnemonic = op_desc.get_mnemonic();
	Assembly_Format assem_format = op_desc.get_assembly_format();
	if (assem_format == a_op_o1_o2_st) {
		file_buffer << "\t" << operation_mnemonic << " ";
		opd1->print_asm_opd(file_buffer);
		file_buffer << ", ";
		file_buffer << "$zero";
		file_buffer << ", " + label + " ";
		file_buffer << "\n";
	} else if (assem_format == a_op_st) { 
		file_buffer << "\tj " + label;
		file_buffer <<"\n";
	}
}
Control_Flow_IC_Stmt & Control_Flow_IC_Stmt::operator=(const Control_Flow_IC_Stmt & rhs) { 
	op_desc = rhs.op_desc;
	opd1 = rhs.opd1;
	label = rhs.label;
	return *this;
}


/////////////////////////
//	LABEL ICODE STMT   //
/////////////////////////   
Label_IC_Stmt::Label_IC_Stmt(Tgt_Op inst_op, string label) { 
	this->label = label;
	this->op_desc = *(machine_desc_object.spim_instruction_table[inst_op]);
}
Instruction_Descriptor & Label_IC_Stmt::get_inst_op_of_ics() { return op_desc; }
string Label_IC_Stmt::get_label() { return label; }
void Label_IC_Stmt::set_label(string label) { this->label = label; }
void Label_IC_Stmt::print_icode(ostream & file_buffer) { 
	Icode_Format ic_format = op_desc.get_ic_format();
	if (ic_format == i_op_st) {
		file_buffer <<"\n" + label + ":    \t";
		file_buffer << "\n";
	} else {
		printf("cs316: Error, icode format unsupported\n");
	}
}
void Label_IC_Stmt::print_assembly(ostream & file_buffer) { 
	Assembly_Format assem_format = op_desc.get_assembly_format();
	if (assem_format == a_op_st) {
		file_buffer <<"\n" + label + ":    \t";
		file_buffer << "\n";
	} else {
		printf("cs316: Error, icode format unsupported\n");
	}
}
Label_IC_Stmt & Label_IC_Stmt::operator=(const Label_IC_Stmt & rhs) { 
	op_desc = rhs.op_desc;
	label = rhs.label;
	return *this;
}
