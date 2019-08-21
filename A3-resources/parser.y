%{
	#include <stdio.h>
	#include <assert.h>
	int yylex(void);
    void yyerror(char *s){};
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
%token AND
%token OR
%token NOT
%token WHILE
%token DO
%token IF
%token ELSE
%token <string_value> NAME
%left '+' '-'
%left '*' '/'
%left '(' ')'
%type <program> program
%type <procedure> procedure_definition 
%type <symbol_entry_list> variable_list
%type <symbol_table> declaration_list variable_declaration_list optional_variable_declaration_list variable_declaration declaration
%type <ast_list> statement_list sequence_list
%type <ast> assignment_statement iteration_statement selection_statement statement expression variable constant term identifier relational_expression logical_expression
// %type <>

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

declaration_list	:	variable_declaration_list {
							$$ = $1;
							
						}
					|   {
							$$ = NULL;
						}
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

optional_variable_declaration_list	:	variable_declaration_list {
											$$ = $1;
										}
									|	{
											$$ = NULL;
										}
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

variable_declaration			:	declaration ';' {
										$$ = $1;
									}
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
										$$->push_front(ste);
									}
								|	variable_list ',' NAME {
										Symbol_Table_Entry *ste = new Symbol_Table_Entry(*$3,void_data_type,yylineno);  
										$1->push_front(ste);
										$$ = $1;
									}
								;

statement_list	        		:	{
										$$ = new list<Ast *>();
									}
								|	statement_list
									statement
								;

assignment_statement			:	variable ASSIGN variable ';' {
										$$ = new Assignment_Ast($1, $3, yylineno);
                                        if (!$$->check_ast()) {
											printf("cs316: Error Assignment statement data type not compatible, Line number : %d\n",yylineno);
											exit(0);
										}
								}
								|	variable ASSIGN constant ';' {
										$$ = new Assignment_Ast($1, $3, yylineno);
                                        if (!$$->check_ast()) {
											printf("cs316: Error Assignment statement data type not compatible, Line number : %d\n",yylineno);
											exit(0);
										}
								}
								| 	variable ASSIGN expression ';' {
										$$ = new Assignment_Ast($1, $3, yylineno);
                                        if (!$$->check_ast()) {
											printf("cs316: Error Assignment statement data type not compatible, Line number : %d\n",yylineno);
											exit(0);
										}								}
								;

iteration_statement				:	DO 
									'{'
										sequence_list
									'}'
									WHILE '(' logical_expression ')' ';'
								|	WHILE '(' logical_expression ')'
									'{'
										sequence_list
									'}'
								;

selection_statement				:	IF '(' logical_expression ')'
									'{'
										sequence_list
									'}'
								|	IF '(' logical_expression ')'
									'{'
										sequence_list
									'}'
									ELSE
									'{'
						    			sequence_list
									'}'
								;

sequence_list					:	/* empty */ {
										$$ = new list<Ast *>();
									}
								|	statement_list
									statement {
										$1->push_back($2);						
										$$ = $1;
									}
								;

statement 						: 	matched_statement 
								|	unmatched_statement
								;

matched_statement				: 	assignment_statement
								|	iteration_statement
								|	selection_statement
								|	IF '(' logical_expression ')' matched_statement ELSE matched_statement
								;	

unmatched_statement				:	IF '(' logical_expression ')' statement
								|	IF '(' logical_expression ')' matched_statement ELSE unmatched_statement
								;

logical_expression				:	relational_expression AND relational_expression
								|	relational_expression OR relational_expression
								|	NOT relational_expression
								|	relational_expression
								;

relational_expression			: 	expression LESS_THAN expression
								|	expression GREATER_THAN expression
								|	expression LESS_THAN_EQUAL expression
								|	expression GREATER_THAN_EQUAL expression
								|	expression EQUAL expression	
								|	expression NOT_EQUAL expression
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
										}									}
								| 	identifier {
										$$ = $1;
									}
								;	
identifier						:	variable {
										$$ = $1;
									}
								|	'-' variable {
										$$ = new UMinus_Ast($2, NULL, yylineno);
										$$->set_data_type($2->get_data_type());
									}
								|	constant {
										$$ = $1;
									}
								|	'-' constant {
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
