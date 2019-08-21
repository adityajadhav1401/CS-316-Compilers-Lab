%{
	#include <stdio.h>
	#include <assert.h>
	int yylex(void);
    void yyerror(string s){};
    extern int yylineno;
    Procedure * main_procedure;
%}
	
%union {
	int integer_value;
	double double_value;
	std::string * string_value;
	list<Ast *> * ast_list;
	Ast * ast;
	Symbol_Table * symbol_table;
	Symbol_Table_Entry * symbol_entry;
	list<Symbol_Table_Entry *> * symbol_entry_list;
	Basic_Block * basic_block;
	Procedure * procedure;
	Program * program;
	Sequence_Ast * sequence_ast;
}

%token <integer_value> INTEGER_NUMBER 
%token <double_value> DOUBLE_NUMBER 
%token ARITHOP 
%token INTEGER 
%token FLOAT
%token ASSIGN 
%token VOID 
%token RETURN
%token LESS_THAN
%token GREATER_THAN
%token LESS_THAN_EQUAL
%token GREATER_THAN_EQUAL
%token EQUAL
%token NOT_EQUAL
%token NOT
%token AND
%token OR
%token WHILE
%token DO
%token IF
%token ELSE
%token <string_value> NAME

%left ':' '?'
%left OR
%left AND 
%left EQUAL NOT_EQUAL
%left LESS_THAN GREATER_THAN LESS_THAN_EQUAL GREATER_THAN_EQUAL
%left '+' '-'
%left '*' '/'
%left NOT
%left '(' ')'
%left '{' '}'
%left WHILE

%type <program> program
%type <procedure> procedure_definition 
%type <symbol_entry_list> variable_list
%type <symbol_table> declaration_list variable_declaration_list optional_variable_declaration_list variable_declaration declaration
%type <ast_list> statement_list
%type <ast> iterative_unmatched_statement iterative_matched_statement statement open_statement closed_statement simple_assignment_statement
%type <ast> conditional_expression logical_expression relational_expression expression variable term identifier constant    
%type <sequence_ast> sequence_list

%%

program				:	declaration_list {
							if($1 != NULL)
							{
								$1->set_table_scope(global);
								program_object.set_global_table(*$1);
							}
						}
						procedure_definition {							
							$$ = &program_object;
							$$->set_procedure($<procedure>3,yylineno);
						}
					;

declaration_list	:	variable_declaration_list { $$ = $1; }
					|   { $$ = NULL; }
					;

procedure_definition	:	VOID NAME '(' ')'
                  	   		'{'
								optional_variable_declaration_list {
									main_procedure = new Procedure(void_data_type,*$2,yylineno);
	        	           			
	        	           			if($6 != NULL)
	        	           			{
	        	           				$6->set_table_scope(local);
	        	           				main_procedure->set_local_list(*$6);
	        	           			}
								}
	                        	statement_list
        	           		'}' {
        	           				$$ = main_procedure;
	        	           			if($<ast_list>8 != NULL && $$ != NULL)
	        	           			{	        	           				
	        	           				$$->set_ast_list(*($<ast_list>8));	        	           				
	        	           			}
        	           			}
                        ;

optional_variable_declaration_list	:	variable_declaration_list { $$ = $1; }
									|	{ $$ = NULL; }
									;

variable_declaration_list			:	variable_declaration {
											$$ = $1;
										}
									|	variable_declaration_list 
										variable_declaration {
											$$ = $1;
											$$->append_list(*$2,yylineno);
										}
									;

variable_declaration			:	declaration ';' { $$ = $1; }
								;

declaration						:	INTEGER variable_list {
										Symbol_Table *st = new Symbol_Table();
										st->set_table_scope(local);
										for (list<Symbol_Table_Entry *>::iterator it = $2->begin(); it != $2->end(); it++) {
											(*it)->set_data_type(int_data_type);
											(*it)->set_symbol_scope(local);
											st->push_symbol(*it);
										}
										$$ = st;
									}
								| 	FLOAT variable_list {
										Symbol_Table *st = new Symbol_Table();
										st->set_table_scope(local);
										for (list<Symbol_Table_Entry *>::iterator it = $2->begin(); it != $2->end(); it++) {
											(*it)->set_data_type(double_data_type);
											(*it)->set_symbol_scope(local);
											st->push_symbol(*it);
										}
										$$ = st;
									}
                                ;

variable_list                   :	NAME {
										$$ = new list<Symbol_Table_Entry*>();
										Symbol_Table_Entry *ste = new Symbol_Table_Entry(*$1,void_data_type,yylineno);  
										$$->push_back(ste);
									}
								|	variable_list ',' NAME {
										Symbol_Table_Entry *ste = new Symbol_Table_Entry(*$3,void_data_type,yylineno);  
										$1->push_back(ste);
										$$ = $1;
									}
								;

statement_list	        		:	{ $$ = new list<Ast *>();}
								|	statement_list
									statement {
										$1->push_back($2);
										$$ = $1;
									}
								;

sequence_list	        		:	statement { 
										$$ = new Sequence_Ast(yylineno);
										$$->ast_push_back($1);
									}
								|	sequence_list
									statement {
										$1->ast_push_back($2);
										$$ = $1;
									}
								;

statement 						: 	closed_statement {$$ = $1; }
								|	open_statement {$$ = $1; }
								;

open_statement					:	IF '(' logical_expression ')' statement {
										$$ = new Selection_Statement_Ast($3, $5,  NULL, yylineno);
									}
								|	IF '(' logical_expression ')' closed_statement ELSE open_statement {
										$$ = new Selection_Statement_Ast($3, $5, $7, yylineno);
									}
								|	iterative_unmatched_statement {$$ = $1;}
								;

closed_statement				:	IF '(' logical_expression ')' closed_statement ELSE closed_statement {
										$$ = new Selection_Statement_Ast($3, $5, $7, yylineno);
									}
								// |	WHILE '(' logical_expression ')' closed_statement {
								// 		$$ = new Iteration_Statement_Ast($3, $5, yylineno, false);
								// 	}
								// |	DO statement WHILE '(' logical_expression ')' ';'{
								// 		$$ = new Iteration_Statement_Ast($5, $2, yylineno, true);
								// }
								|	simple_assignment_statement {$$ = $1; }
								|	'{'
										sequence_list
									'}'
									{
										$$ = $2;
									}

								|	iterative_matched_statement {$$ = $1;}
								;

// simple_statement				:	
// |

								
// 								|	DO  statement WHILE '(' logical_expression ')' ';'{
// 										$$ = new Iteration_Statement_Ast($5, $2, yylineno, true);
// 								}
// 								;
									
// 								;

iterative_matched_statement 	: 	WHILE '(' logical_expression ')' closed_statement {
										$$ = new Iteration_Statement_Ast($3, $5, yylineno, false);
									}
								|	DO closed_statement WHILE '(' logical_expression ')' ';' {
										$$ = new Iteration_Statement_Ast($5, $2, yylineno, true);
									}
								;

iterative_unmatched_statement	:	WHILE '(' logical_expression ')' open_statement {
										$$ = new Iteration_Statement_Ast($3, $5, yylineno, false);
									}
								|	DO open_statement WHILE '(' logical_expression ')' ';' {
										$$ = new Iteration_Statement_Ast($5, $2, yylineno, true);
									}
								;

simple_assignment_statement		:	variable ASSIGN expression ';' {
										$$ = new Assignment_Ast($1, $3, yylineno);
                                        if (!$$->check_ast()) {
											printf("cs316: Error Assignment statement data type not compatible, Line number : %d\n",yylineno);
											exit(0);
										}	
								}
								;

conditional_expression			:	logical_expression '?' expression ':' expression
									{
										$$ = new Conditional_Expression_Ast($1, $3, $5,yylineno);
										if ($$->check_ast()) {
											$$->set_data_type($1->get_data_type());
										}
										else {
											printf("cs316: Error Arithmetic statement data type not compatible, Line number : %d\n",yylineno);											
											exit(0);
										}
									}



logical_expression				:	logical_expression AND logical_expression {
										$$ = new Logical_Expr_Ast($1, _logical_and, $3, yylineno);
										$$->set_data_type($1->get_data_type());
										// no need to check LHS and RHS compatibility as they will always be int	
									}
								|	logical_expression OR logical_expression {
										$$ = new Logical_Expr_Ast($1, _logical_or, $3, yylineno);
										$$->set_data_type($1->get_data_type());
										// no need to check LHS and RHS compatibility as they will always be int	
 									}
								|	NOT logical_expression {
										$$ = new Logical_Expr_Ast(NULL, _logical_not, $2, yylineno);
										$$->set_data_type($2->get_data_type());
									}
								|	relational_expression { $$ = $1; }
								|	'(' logical_expression ')' {$$ = $2;}
								;

relational_expression			: 	expression LESS_THAN expression {
										$$ = new Relational_Expr_Ast($1, less_than, $3, yylineno);
										if ($$->check_ast()) {
											$$->set_data_type($1->get_data_type());
										}
										else {
											printf("cs316: Error Relational statement data type not compatible, Line number : %d\n",yylineno);											
											exit(0);
										}
									}
								|	expression GREATER_THAN expression {
										$$ = new Relational_Expr_Ast($1, greater_than, $3, yylineno);
										if ($$->check_ast()) {
											$$->set_data_type($1->get_data_type());
										}
										else {
											printf("cs316: Error Relational statement data type not compatible, Line number : %d\n",yylineno);											
											exit(0);
										}	
									}
								|	expression LESS_THAN_EQUAL expression {
										$$ = new Relational_Expr_Ast($1, less_equalto, $3, yylineno);
										if ($$->check_ast()) {
											$$->set_data_type($1->get_data_type());
										}
										else {
											printf("cs316: Error Relational statement data type not compatible, Line number : %d\n",yylineno);											
											exit(0);
										}	
									}
								|	expression GREATER_THAN_EQUAL expression {
										$$ = new Relational_Expr_Ast($1, greater_equalto, $3, yylineno);
										if ($$->check_ast()) {
											$$->set_data_type($1->get_data_type());
										}
										else {
											printf("cs316: Error Relational statement data type not compatible, Line number : %d\n",yylineno);											
											exit(0);
										}	
									}
								|	expression EQUAL expression	{
										$$ = new Relational_Expr_Ast($1, equalto, $3, yylineno);
										if ($$->check_ast()) {
											$$->set_data_type($1->get_data_type());
										}
										else {
											printf("cs316: Error Relational statement data type not compatible, Line number : %d\n",yylineno);											
											exit(0);
										}	
									}
								|	expression NOT_EQUAL expression {
										$$ = new Relational_Expr_Ast($1, not_equalto, $3, yylineno);
										if ($$->check_ast()) {
											$$->set_data_type($1->get_data_type());
										}
										else {
											printf("cs316: Error Relational statement data type not compatible, Line number : %d\n",yylineno);											
											exit(0);
										}	
									}
								;


expression						:	expression '+' term {
                                     	$$ = new Plus_Ast($1, $3, yylineno);
										if ($$->check_ast()) {
											$$->set_data_type($1->get_data_type());
										}
										else {
											printf("cs316: Error Arithmetic statement data type not compatible, Line number : %d\n",yylineno);											
											exit(0);
										}
									}
								|	expression '-' term {
										$$ = new Minus_Ast($1, $3, yylineno);
										if ($$->check_ast()) {
											$$->set_data_type($1->get_data_type());
										}
										else {
											printf("cs316: Error Arithmetic statement data type not compatible, Line number : %d\n",yylineno);											
											exit(0);
										}	
									}
								| 	term {
										$$ = $1;
									}
								|	 conditional_expression
									{
										$$ = $1;
									}
									
								;	
term							:	term '*' identifier {
										$$ = new Mult_Ast($1, $3, yylineno);
										if ($$->check_ast()) {
											$$->set_data_type($1->get_data_type());
										}
										else {
											printf("cs316: Error Arithmetic statement data type not compatible, Line number : %d\n",yylineno);											
											exit(0);
										}	
									}
								|	term '/' identifier {
										$$ = new Divide_Ast($1, $3, yylineno);
										if ($$->check_ast()) {
											$$->set_data_type($1->get_data_type());
										}
										else {
											printf("cs316: Error Arithmetic statement data type not compatible, Line number : %d\n",yylineno);											
											exit(0);
										}									
									}
								| 	identifier {
										$$ = $1;
									}
								;	
identifier						:	variable {
										$$ = $1;
									}
								
								|	constant {
										$$ = $1;
									}
								|	'-' identifier {
										$$ = new UMinus_Ast($2, NULL, yylineno);
										$$->set_data_type($2->get_data_type());
									}
								;

variable						:	NAME {
										assert(main_procedure != NULL);
										if (main_procedure->variable_in_symbol_list_check(*$1)) {
											Symbol_Table_Entry *ste = &main_procedure->get_symbol_table_entry(*$1);
											assert(ste != NULL);
											ste->set_symbol_scope(local);
											$$ = new Name_Ast(*$1,*ste,yylineno);
											$$->set_data_type(ste->get_data_type());
										}
										else if (program_object.variable_in_symbol_list_check(*$1)) {
											Symbol_Table_Entry *ste = &program_object.get_symbol_table_entry(*$1);
											ste->set_symbol_scope(global);
											$$ = new Name_Ast(*$1,*ste,yylineno);
											$$->set_data_type(ste->get_data_type());
										}
										else {
											printf("cs316: Error Variable undeclared, Line number : %d\n",yylineno);
											exit(0);
										}	
										
									}
								| 	'('expression')' {
										$$ = $2;
									}
								;

constant						:	INTEGER_NUMBER {										
										$$ = new Number_Ast<int>($1, int_data_type, yylineno);
									} 
								|	DOUBLE_NUMBER {										
										$$ = new Number_Ast<double>($1, double_data_type, yylineno);
									}
								;

%%
