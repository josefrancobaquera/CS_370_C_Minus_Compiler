/*
   Author's Name: Jose Franco Baquera

   Project Name:  Lab 9 - Create NASM code from your AST 

   Program Name: EMITAST.c
            
   Date: April 25, 2018
      
   Class: CS 370 - Shaun Cooper
   
   Lab Number: 9
    
   Purpose/Description: The purpose of this yacc file is to 
   syntactically check the tokens fed to it. It holds the
   production rules for our grammar and target language.
   It also checks the semantics of the grammar by using the
   symbol table file. For example, it will check that we do not
   declare two variables with the same name at the same level.
   
*/

%{

/* Begin Specifications */

/*
   #include several directories, including the header files 
   for Lab6AST which will be the file responsible for
   printing our our Abstract Syntax Tree. In addition, 
   include the symtable.h file since it will allow for us 
   to check semantic actions.
   
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Lab6AST.h"
#include "symtable.h"
#include "EMITAST.h"

/*
   Extern the global variables found in lex. lineCunter will allow
   us to print the error line number if an error is found. mydebug 
   will allow us to turn off or on the comments that are printed 
   when we encounter a token. 
*/

/* Define a new function that will find the maximum
 of the two parameters. */
#define max(x,y) (((x) > (y) ? (x): (y)))
int lineCounter; 
int mydebug;
int level = 0;
int maxOffset;
FILE *fp;

/* 
   Declare two global int variables. One will keep track of the globalOffset and
   another one will be used as a temp variable for whenever we want to change
   the globalOffset.
*/
int globalOffset = 0;
int goffset = 0;

#define maxSize 26

/*
   regs will keep track of the value of the variable and actualSize will
   keep track of the number of variables declared.
*/

int regs[ maxSize ];
int actualSize = 0;


/*
   yyerror function. This function is called by yyparse if
   an error is found. The paramter is a string, meaning that 
   it can be sent a specific string message error.
*/

void yyerror ( s ) 
   char *s;
{

   /* If an error is found, print the line number in which they are found. */
   printf( "ERROR FOUND ON LINE NUMBER: %d.\n", lineCounter );
   
} /* end yyerror function */


%}

/*  
   Define the start symbol, what values come back from LEX, and how the operators 
   are associated once we start the program. 
   NOTE: $$ stands for the semantic value of the grouping created under the respective rule. 
*/

/* The start symbol for our grammar is "program." */
%start program

/* Make a %UNION type in order to allow LEX to return integers, strings, operators, or ASTnode nodes. */ 
%union {
   int value;
   int level;
   char * string;
   ASTnode *node;
   enum OPERATORS operator;
} /* end union */

/* Define the types of the tokens (terminals) and non-terminals to their appropriate types. */
%token <string> ID
%token <string> STRING
%token <value> NUM IF INT VOID RETURN ELSE WHILE READ WRITE LE GE EQ NE 
%type <node> program declarationlist declaration vardeclaration fundeclaration params param paramlist compoundstmt localdeclarations 
%type <node> statementlist statement expressionstmt selectionstmt iterationstmt assignmentstmt returnstmt readstmt writestmt expression
%type <node> simpleexpression additiveexpression term args arglist factor var call
%type <operator> typespecifier addop multop relop

/* This will help us remove the shift-reduce error found with the IF, ELSE statements. */
%nonassoc IFX
%nonassoc ELSE

%%   /* End specficications. Everything previously typed will be shoved into C. Now begin rules. */

program : declarationlist { rootNode = $1; } /* The ASTnode rootNode will point to declarationlist. rootNode will be the */
                                             /* root of our abstract syntax tree. */
        ;

declarationlist : declaration { $$ = $1; } /* If declaration does not have a declarationlist, do not do any extra steps. */
                | declaration declarationlist { $1->next = $2; 
                                                $$ = $1; } /* If declaration does have a declarationlist, use next to point to the declarationlist. */
                ;

declaration : vardeclaration { $$ = $1; } /* A declaration can be a vardeclaration or a fundeclaration. */
            | fundeclaration { $$ = $1; } /* "Return" a pointer to the nodes found in these non-terminals. */
            ;

vardeclaration : typespecifier ID ';' { if( Search( $2, level, 0 ) == NULL ) { /* A variable declaration can be "regular." */
                                           $$ = ASTCreateNode( VARDEC ); /* Create a ASTnode of type VARDEC. */
                                           $$->operator = $1; /* Store the operator type and the name of the vardeclaration in the node's payload. */    
                                           $$->symbol = Insert( $2, $1, 0, level, 1, globalOffset, NULL, 0 ); /* Make symbol point to the newly created SymbTab created. */
                                           $$->name = $2; /* Store the name of the variable in the ASTCreateNode node. */
                                           $$->value = 0; /* Store 0 as the value. This will help us differenciate between an array and an int declaration. */
                                           $$->typeOfDeclaration = $1; /* Store the type of the declaration in the attribute. */
                                           globalOffset++; /* Increment the global offset. Since this is an integer declaration, offeset increments by 1. */ 
                                           } /* end if */
                                        else {
                                           /* If the variable is already declared, print out an error. */
                                           yyerror( ); 
                                           printf( "Type of Error --> '%s' already defined.\n", $2 );
                                           exit( 1 );         
                                        } /* end else */
                                        
                                } /* end production rule */
                                        
               | typespecifier ID '[' NUM ']' ';' { if( Search( $2, level, 0 ) == NULL ) { /* Check if the variable being declared is already declared in level 0. */
                                                       $$ = ASTCreateNode( VARDEC ); /* Create a ASTnode of type VARDEC. */ 
                                                       $$->operator = $1; /* Store the operator type and the name of the vardeclaration in the node's payload. */
                                                       $$->symbol = Insert( $2, $1, 0, level, $4, globalOffset, NULL, 1 ); /* Make symbol point to the newly created SymbTab created. */
                                                       $$->name= $2; /* Store the operator type and the name of the vardeclaration in the node's payload. */ 
                                                       $$->typeOfDeclaration = $1; /* Store the type of the declaration in the attribute. */
                                                       $$->value = $4; /* In addition, store the value of the array into the node's payload. */
                                                       globalOffset = globalOffset + $4; /* Update the globalOffset. This offeset will increment by the number located inside the brakets. */   
                                                    } /* end if */
                                                    else {
                                                       /* If the variable was already declared in level 0, print out an error and exit. */
                                                       yyerror( ); 
                                                       printf( "Type of Error --> '%s' already defined.\n", $2 );
                                                       exit( 1 ); 
                                                    } /* end else */
                                                  } /* end production rule */
               ;

typespecifier : INT { $$ = INTTYPE; } /* "Return" the type of the typespecifier. */
              | VOID { $$ = VOIDTYPE; } /* "Return" the type of the typespecifier. */
              ;

fundeclaration : typespecifier ID '('{ if( Search( $2, level, 0 ) == NULL ){ /* Check if the function has already been declared on level 0. */
                                          Insert( $2, $1, 1, level, 0, 0, NULL, 0 ); /* Insert a new symbol in the symboltable that will keep track of the function being declared . */
                                          goffset = globalOffset; /* Remember the globalOffset before changing it. */ 
                                          globalOffset = 2; /* Change globalOffset to 2 since each function will need to have one word for the base pointer and one word for the stack pointer. */
                                          maxOffset = globalOffset; /* Update maxOffset to be the same as globalOffset. */
                                          /* Should the two prev, prev lines be swtiched? */
                                        } /* end if */
                                        else {
                                           /* If the function was already declared, print an error and exit. */
                                           yyerror( ); 
                                           printf( "Type of Error --> '%s' already defined.\n", $2 );
                                           exit( 1 ); 
                                        } /* end else */
                                     }  /* end semantic action */
                                     
                params               {
                                        /* Make fparms of the newly created node point to the params. */
                                        (Search($2, 0, 0))->fparms = $5;
                                     } /* end semantic action */
                                     
                                     
                                     
                ')' compoundstmt { $$ = ASTCreateNode( FUNDEC ); /* Create a ASTnode of type FUNDEC. */
                                   $$->operator = $1; /* Store the type and name of the fundeclaration into the node's payload. */
                                   $$->name = $2; /* Store the name on the node's payload. */
                                   $$->stmt0 = $5; /* stmt0 will point to the function's parameters while stmt1 will point to the */
                                   $$->stmt1 = $8; /*Change these $$*/ 
                                   $$->symbol = Search( $2, 0, 0 ); /* Make symbol point to the created function node in the symboltable.  */
                                   $$->typeOfDeclaration = $1; /* Update the type of declaration of the AST node.  */   
                                   $$->value = maxOffset; /* Store the new maxOffset in the node's payload. */
                                   (Search($2, 0, 0))->mysize = maxOffset; /* Store the new maxOffset in the node's payload. */
                                   globalOffset = goffset; /* Restore the globalOffset to its original value. */                 
                                 } /* end semantic action */
               ; 

params : VOID { $$ = NULL; } /* If the fundeclaration has no parameters, return NULL. */
       | paramlist { $$ = $1; } /* If the fundeclaration has parameters, return the pointer to the nodes created in paramlist. */
       ;

paramlist : param { $$ = $1; } /* If there is only one parameter, return the pointer that points to the nodes created in the non-terminal param. */
          | param ',' paramlist { $$ = $1; /* Make paramlist point to the first node created in paramlist. */
                                  $1->next =$3; /* Since this is a list, we need to use "next." */
                                } 
          ;
param : typespecifier ID { if( Search( $2, level + 1, 0 ) == NULL ) { /* Check if the param being declared has already beeen declared in the same level. */
                              $$ = ASTCreateNode( PARAM ); /* Create a new ASTnode node type PARAM. */
                              $$->operator = $1; /* Store the operator type on the node's payload. */
                              $$->name = $2; /* Store the name on the node's payload. */
                              $$->value = 10; /* Use a "dummy" variable to distinguish the param as an array. */
                              $$->typeOfDeclaration = $1; /* Update the type of declaration of the AST node. */
                              $$->symbol = Insert($2, $1, 0, level + 1, 1, globalOffset, NULL, 0 ); /* Make symbol point to the newly created symbol table node. */
                              globalOffset++; /* Since this is an int, the globalOffset increments by 1. */
                           /* Params will always be level 1. */
                           } /* end if */
                           else {
                              /* If the variable was already declared, print an error and exit. */
                              yyerror( ); 
                              printf( "Type of Error --> '%s' already defined.\n", $2 );
                              exit( 1 ); 
                           } /* end else*/
                           } /* Use a "dummy" variable to distinguish the param as a non-array. */
      | typespecifier ID '[' ']' { if( Search( $2, level + 1, 0 ) == NULL ) { /* Check if the param being declared has already beeen declared in the same level. */
                                       $$ = ASTCreateNode( PARAM ); /* Create a new ASTnode node type PARAM. */
                                       $$->operator = $1; /* Store the operator type on the node's payload. */
                                       $$->name = $2; /* Store the name on the node's payload. */
                                       $$->value = 11; /* Use a "dummy" variable to distinguish the param as an array. */
                                       $$->typeOfDeclaration = $1; /* Update the type of declaration of the AST node. */
                                       $$->symbol = Insert( $2, $1, 0, level + 1, 1, globalOffset, NULL, 1 ); /* Make symbol point to the newly created symbol table node. */
                                       globalOffset++; /* Even though this is an array, globalOffset still increments by 1. */
                                      /* Params will always be level 1. */
                                } /* end if */
                                else {
                                   /* If the variable was already declared, print an error and exit. */
                                   yyerror( ); 
                                   printf( "Type of Error --> '%s' already defined.\n", $2 );
                                   exit( 1 ); 
                                } /* end else*/
                            } /* end semantic action. */
           ;

compoundstmt : '{' { level++; } /* Increment level since we are in a compoundstmt. */

                localdeclarations statementlist '}' { $$ = ASTCreateNode(BLOCK); /* Create a new ASTnode node type BLOCK. */
                                                         if( $3 == NULL) { /*No local declarations found. stmt0 will point to NULL. */ 
                                                            $$->stmt1 = $4; /* Make stmt1 point to the first node created in statementlist. */
                                                         } /* end if */
                                                         else{
                                                            $$->stmt0 = $3; /* Make stmt0 point to the first node created in localdeclarations. */
                                                            $$->stmt1 = $4; /* Make stmt1 point to the first node created in statementlist. */
                                                         } /* end else */ 
                                                         if( mydebug ) {
                                                            Display( ); /* Display the symbol table if mydebug is true. */
                                                         } /* end if */
                                                         maxOffset= max(maxOffset, globalOffset); /* maxOffset will be the bigger value between maxOffset and globalOffset. */
                                                         globalOffset = globalOffset - Delete(level); /* Update the globalOffset and Delete all variables at the current level. */ 
                                                         level--; /* Decrement level by 1 since we are exiting out a compoundstmt. */ } 
                                                         ;
             
localdeclarations : /* Empty */ { $$ = NULL; } /* This will allow zero or more local declarations. Empty will be the stopping case. */ 
                  | vardeclaration localdeclarations { $1->next = $2; /* Since this is a list, we need to use "next." */
                                                       $$ = $1; } /* Local declarations can be empty or a one or more variable declaration. */ 
                  ;
                 
statementlist : /* Empty. */ { $$ = NULL; } /* This will allow zero or more statement list. Empty will be the stopping case. */ 
              | statement statementlist { $1->next = $2; /* Since this is a list, we need to use "next." */
                                          $$ = $1; } /* If not empty, a statement list can be a list of statements. */ 
              ;
              
statement : expressionstmt { $$ = $1; } /* Make statement point to the first node created in the nonterminal expressionstmt. */
          | compoundstmt { $$ = $1; } /* Make statement point to the first node created in the nonterminal compoundstmt. */
          | selectionstmt { $$ = $1; } /* Make statement point to the first node created in the nonterminal selectionstmt. */
          | iterationstmt { $$ = $1; } /* Make statement point to the first node created in the nonterminal iterationstmt. */
          | assignmentstmt { $$ = $1; } /* Make statement point to the first node created in the nonterminal assignmentstmt. */
          | returnstmt { $$ = $1; } /* Make statement point to the first node created in the nonterminal returnstmt. */
          | readstmt { $$ = $1; } /* Make statement point to the first node created in the nonterminal readstmt. */
          | writestmt { $$ = $1; } /* Make statement point to the first node created in the nonterminal writestmt. */
          ;
          
expressionstmt : expression ';' { $$ = ASTCreateNode( EXPRSTMT ); /* Create a new ASTnode node type EXPRSTMT. */
                                  $$->stmt0 = $1; /* stmt0 will point to the first node created in the nonterminal expression. */
                                  $$->typeOfDeclaration = $1->typeOfDeclaration; /* */
                                  $$->name = CreateTemp( ); /* Create a temp string and store it into name. */
                                  $$->symbol = Insert( $$->name, INTTYPE, 0, level, 1, globalOffset, NULL, 0); /* Make symbol point to the inserted node. */
                                  globalOffset++;
                                } /* An expression statement can be either an expression followed by a ';' or just ';' by itself. */
               | ';' { $$ = ASTCreateNode( EXPRSTMT ); /* Create a new ASTnode node type EXPRSTMT. */
                       $$->stmt0 = NULL; } /* stmt0 will point to NULL since it has no accompanying the expressionstmt. */
               ;
               
selectionstmt : IF '(' expression ')' statement %prec IFX { $$ = ASTCreateNode( IFSTMT ); /* Create a new ASTnode node type IFSTMT. */
                                                            $$->stmt0 = $3; /* stmt0 will point to the first node created in the nonterminal expression. */
                                                            $$->stmt1 = $5; /* stmt1 will point to the first node created in the nonterminal statement. */
                                                            $$->stmt2 = NULL; } /* stmt2 will point to NULL since there is no ELSE part. */
              | IF '(' expression ')' statement ELSE statement { $$ = ASTCreateNode( IFSTMT ); /* Create a new ASTnode node type IFSTMT. */
                                                                 $$->stmt0 = $3; /* stmt0 will point to the first node created in the nonterminal expression. */
                                                                 $$->stmt1 = $5; /* stmt1 will point to the first node created in the nonterminal statement. */
                                                                 $$->stmt2 = $7; } /* stmt3 will point to the first node created in the second nonterminal statement. */
              ;
             

iterationstmt : WHILE '(' expression ')' statement { $$ = ASTCreateNode( ITSTMT ); /* Create a new ASTnode node type ITSTMT. */
                                                     $$->stmt0 = $3; /* Make stmt0 point to the first node created in the nonterminal expression. */
                                                     $$->stmt1 = $5; } /* Make stmt1 point to the first node created in the nonterminal statement. */
              ;
              
assignmentstmt : var '=' expressionstmt  { $$=ASTCreateNode(ASSIGN); /* Create a new ASTnode node type ASSIGN. */
                                           if( ( $1->typeOfDeclaration == VOIDTYPE ) || ( $1->typeOfDeclaration != $3 ->typeOfDeclaration ) ) {
                                              /* Check the the right hand side is not a void and that the right and left hand side match in types. */
                                              /* If they do not match, print an error and exit. */
                                              yyerror( );
                                              printf( "Type of Error --> Assignment statement mismatch. Left is not the same as right.\n" );
                                              exit( 1 );
                                           } /* end if */
                                           $$->stmt0 = $1; /* stmt0 will point to the first node created in the nonterminal var. */
                                           $$->stmt1 = $3;                                           
                                           } /* stmt1 will point to the first node created in the nonterminal expressionstmt.  */
               ;                           /* *******NOTE: I changed this production rule to have expressionstmt since this is how Dr. Cooper printed */ 
                                           /* his AST in his example provided to us. I took out the ';' since expressionstmt already has a ';'. */
                                           

returnstmt : RETURN expression ';' { $$ = ASTCreateNode(RETURNSTMT); /* Create a new ASTnode node type RETURNSTMT. */
                                     $$->stmt0 = $2; 
                                     } /* Make stmt0 point to the first node created in expression. */
           | RETURN ';' { $$ = ASTCreateNode(RETURNSTMT); /* Create a new ASTnode node type RETURNSTMT. */
                          $$->stmt0 = NULL; 
                          } /* Make stmt0 point to NULL since there is no expression to return. */
           ;                                 

readstmt : READ var ';' { $$ = ASTCreateNode(READSTMT); /* Create a new ASTnode node type READSTMT. */
                          $$->stmt0 = $2; }/* stmt0 will point to the first node created in var. */
         ;
         
writestmt : WRITE expression ';' { $$ = ASTCreateNode( WRITESTMT); /* Create a new ASTnode node type WRITESTMT. */
                                   $$->stmt0 = $2; }/* stmt0 will point to the first node created in expression. */
           | WRITE STRING ';' { $$ = ASTCreateNode( WRITESTMT); /* A user can also write a string into the screen. */
                                $$->stmt0 = NULL; /* If stmt0 points to NULL, we know that the user wants to write a string. */
                                $$->name = $2; /* Store the string into the node's payload. */
                                $$->label = CreateLabel( ); } /* Create a new label for the string. Store it into the node's payload. */                                                                                            
          ;
          
expression : simpleexpression { $$ = $1; }/* Make expression point to the nodes created in simpleexpression. */
           ;
           
var : ID { struct SymbTab *p;
           if ( ( p = Search( $1, level, 1 ) ) == NULL ) { /* Check if the variable has been declared before. */
              /* If the variable was not found, print an error and exit. */
              yyerror( ); 
              printf( "Type of Error --> '%s' is undeclared.\n", $1 );
              exit( 1 ); 
           } /* end if */
           if( p->IsAFunc == 1 ) {
              /* If the variable is a function type, print an error and exit. */
              yyerror( ); 
              printf( "Type of Error --> Incompatible types. '%s' is function variable.\n", $1 );
              exit( 1 ); 
           } /* end inner if */ 
           if( p->isArray == 1 ) {
             /* If the variable is an array, print an error and exit. */
              yyerror( ); 
              printf( "Type of Error --> Incompatible types. '%s' is a an array variable.\n", $1 );
              exit( 1 ); 
           } /* end if */
              $$ = ASTCreateNode(IDENT); /* Create a new ASTnode node type IDENT. */
              $$->name = $1; /* Store the name on the node's payload. */
              $$->stmt0 = NULL; /* Since this is not an array, point stmt0 to NULL since there are no expression. */
              $$->symbol = p; /* Make symbol point to the variable found in the symbol table. */
              $$->value = 15; /* Store a "dummy number" that will allow us to distinguish between both var nodes. */
              $$->typeOfDeclaration = p->Type; /* Inherit the type. */
         }/* ID [ [ expression ] ]+ */ 
    | ID '[' expression ']' { struct SymbTab *p;
                             if ( ( p = Search( $1, level, 1 ) ) == NULL ) { 
                                 /* Check that the variable has been defined in other previous levels. */
                                 /* If the varible has not been defined, print an error message and exit. */
                                 yyerror( ); 
                                 printf( "Type of Error --> '%s' is undeclared.\n", $1 );
                                 exit( 1 ); 
                              } /* end if */
                             if ( p->IsAFunc == 1 ) {
                                /* If the variable is a function type, print an error and exit. */
                                yyerror( ); 
                                printf( "Type of Error --> Incompatible types. '%s' is function variable.\n", $1 );
                                exit( 1 ); 
                             } /* end if */
                             if( p->isArray == 0 ) {
                                /* If the variable being used is not an array, print an error and exit. */
                                yyerror( ); 
                                printf( "Type of Error --> Incompatible types. '%s' is a scalar.\n", $1 );
                                exit( 1 ); 
                             } /* end if */
                                $$=ASTCreateNode(IDENT); /* Create a new ASTnode node type IDENT. */
                                $$->name = $1; /* Store the name on the node's payload. */
                                $$->stmt0 = $3; /* stmt0 will point to the nodes created in expression.*/
                                $$->symbol = p; /* Inherit the type. */
                                $$->typeOfDeclaration = p->Type; /* Inherit the type. */
                             } /* end production rule */
                ;
simpleexpression : additiveexpression { $$ = $1; } /* Make simpleexpression point to the nodes created in additiveexpression. */
                 | simpleexpression relop additiveexpression { /* We need to to type checking. */
                                                               /* Do type checking. */
                                                               if( $1->typeOfDeclaration != $3->typeOfDeclaration) {
                                                                  /* If the right type does not equalto left type, print an error and exit. */
                                                                  yyerror( );
                                                                  printf( "Type of Error --> Simpleexpression expression type mismatch.\n" );
                                                                  exit( 1 ); 
                                                               } /* end if */
                                                                  $$ = ASTCreateNode( EXPR ); /* Create a new ASTnode node type EXPR. */
                                                                  $$->stmt0 = $1; /* stmt0 will point to the nodes created in simpleexpression. */
                                                                  $$->operator = $2; /* Store the operator type on the node's payload. */
                                                                  $$->stmt1 = $3; /* stmt1 will point to the nodes created in additiveexpression. */
                                                                  $$->typeOfDeclaration = INTTYPE; /* We already checked that we do not use void type */
                                                                  $$->name = CreateTemp( ); /* Create a temp variable that will allow us to do expression assembly. */
                                                                  $$->symbol = Insert( $$->name, INTTYPE, 0, level, 1, globalOffset, NULL, 0); /* Make symbol point to the inserted node. */
                                                                  globalOffset++; /* Increment globalOffset by 1. */
                                                               }
                 ;
                   
relop : LE { $$ = LESSTHANEQUAL; } /* These are all the relational operations. <=, >, <, >=, ==, and != */
      | '<'{ $$ = LESSTHAN; } /* Return the appropriate operator type. */
      | '>'{ $$ = GREATERTHAN; } /* Return the appropriate operator type. */
      | GE { $$ = GREATERTHANEQUAL; } /* Return the appropriate operator type. */
      | EQ { $$ = EQUAL; } /* Return the appropriate operator type. */
      | NE { $$ = NOTEQUAL; } /* Return the appropriate operator type. */
      ;

additiveexpression : term { $$ = $1; } /* Make additiveexpression point to the nodes created in term. */
                   | additiveexpression addop term { /* We need to to type checking. */
                                                              if( $1->typeOfDeclaration != $3->typeOfDeclaration) {
                                                                 /* If the right type does not equalto left type, print an error and exit. */
                                                                  yyerror( );
                                                                  printf( "Type of Error --> Additive expression type mismatch.\n" );
                                                                  exit( 1 ); 
                                                               } /* end if */
                                                                  $$ = ASTCreateNode( EXPR ); /* Create a new ASTnode node type EXPR. */
                                                                  $$->stmt0 = $1; /* stmt0 will point to the nodes created in simpleexpression. */
                                                                  $$->operator = $2; /* Store the operator type on the node's payload. */
                                                                  $$->stmt1 = $3; /* stmt1 will point to the nodes created in additiveexpression. */
                                                                  $$->typeOfDeclaration = INTTYPE; /* We already checked that we do not use void type */
                                                                  $$->name = CreateTemp( ); /* Create a temp variable that will allow us to do expression assembly. */
                                                                  $$->symbol = Insert( $$->name, INTTYPE, 0, level, 1, globalOffset, NULL, 0); /* Make symbol point to the inserted node. */
                                                                  globalOffset++; /* Increment globalOffset by 1. */
                                                               } 
                   ;
                    
addop : '+' { $$ = PLUS; }/* You can either add or subtract in the addop. */
      | '-' { $$ = MINUS; } /* Return the appropriate operator type. */
      ;
      
term : factor { $$ = $1; } /* If a single factor is found make term point to the nodes created in the factor non-terminal.*/
     | term multop factor {  /* We need to to type checking. */  if( $1->typeOfDeclaration != $3->typeOfDeclaration) {
                                                                  /* If the right type does not equalto left type, print an error and exit. */
                                                                  yyerror( );
                                                                  printf( "Type of Error --> Term expression type mismatch.\n" );
                                                                  exit( 1 ); 
                                                               } /* end if */
                                                                  $$ = ASTCreateNode( EXPR ); /* Create a new ASTnode node type EXPR. */
                                                                  $$->stmt0 = $1; /* stmt0 will point to the nodes created in simpleexpression. */
                                                                  $$->operator = $2; /* Store the operator type on the node's payload. */
                                                                  $$->stmt1 = $3; /* stmt1 will point to the nodes created in additiveexpression. */
                                                                  $$->typeOfDeclaration = INTTYPE; /* We already checked that we do not use void type */
                                                                  $$->name = CreateTemp( ); /* Create a temp variable that will allow us to do expression assembly. */
                                                                  $$->symbol = Insert( $$->name, INTTYPE, 0, level, 1, globalOffset, NULL, 0); /* Make symbol point to the inserted node. */
                                                                  globalOffset++; /* Increment globalOffset by 1. */
                                                               } 
                                                ;
     
multop : '*' {$$ = MULT; }/* You can either muliply or divide in multop */
       | '/' {$$ = DIV; } /* Return the appropriate operator type. */
       ;

factor : '(' expression ')' { $$ = $2; }/* Make factor point to the nodes created in expression. */
       | NUM { $$ = ASTCreateNode(NUMBER);  /* Create a new ASTnode node type NUMBER. */
               $$->value = $1; 
               $$->typeOfDeclaration = INTTYPE;
               }/* Store the value of the number inside the node's payload. */
       | var { $$ = $1; } /* Make factor point to the nodes created in var if a var non-terminal is found. */
       | call {$$ = $1; } /* Make factor point to the nodes created in call if a call nonterminal is found. */
       ;
       
call : ID '(' args ')' { struct SymbTab *p;
                         /* First check if the function has already been declared. */
                         if( ( p = Search( $1, 0, 0 ) ) == NULL ) { 
                            /* If the function name is not inside the symbol table, print an error message and exit. */
                             yyerror( );
                             printf( "Type of Error --> Undeclared Function %s.\n", $1 );
                             exit( 1 ); 
                         } 
                         /* Check if the variable found is a function type. */
                         if( p->IsAFunc != 1 ) {
                            /* If the variable found is not a funtion type, print an error message and exit. */
                            yyerror( );
                            printf( "Type of Error --> %s is not a function.\n", $1 );
                            exit( 1 ); 
                         } /* end if */
                         /* Compare formal and actual paramters. */
                         if( CompareFormals( p->fparms, $3 ) != 1 ) {
                            /* If the formal and actual parameters do not match, print an error and exit. */
                            yyerror( );
                            printf( "Type of Error --> Formal and Actual Parameter Mistmatch. Type or length mismatch.\n", $1 );
                            exit( 1 ); 
                         } /* end if */
                         $$ = ASTCreateNode( CALL ); /* Create a new ASTnode node type CALL. */
                         $$->stmt0 = $3; /* stmt0 will point to the nodes created in args. */
                         $$->name = $1; /* Store the name of the ID inside the node's payload. */
                         $$->typeOfDeclaration = p->Type; /* Update the type. */
                         $$->symbol = p; /* Make symbol point to the variable found. */  
                       }/* call -> ID ( args ). */
     ;
     
args : { $$ = NULL; } /*Empty args. Return NULL.*/ 
     | arglist { $$ = $1; }/* The arguments can be empty or a list of arguments. If one */
     ; /* or more arguments are found, make args point to arglist. */
     
arglist : expression { $$=ASTCreateNode( ARGLIST ); /* Create a new ASTnode node type ARGLIST. */
                                   $$->name = CreateTemp( ); /* Create a temp variable since an argument can be an expression. */
                                   $$->next = NULL; /* Make stmt0 point to the expression. However, make "next" */
                                   $$->stmt0 = $1;  /* point to NULL since there are no more expressions found. */
                                   $$->symbol = Insert( $$->name, INTTYPE, 0, level, 1, globalOffset, NULL, 0 ); /* Insert the argument into the symbol table. */
                                   $$->typeOfDeclaration = $1->typeOfDeclaration; /* Update the globalOffset by 1. */
                                   globalOffset++; /* Update the globalOffset by 1. */
                                   
                     } /* An argument list can be expression followed by zero or more expressions, seperated by a comma. */
        | expression ',' arglist { $$=ASTCreateNode( ARGLIST ); /* Create a new ASTnode node type ARGLIST. */
                                   $$->name = CreateTemp( ); /* Create a temp variable since an argument can be an expression. */
                                   $$->next = $3; /* Since this is a list, we need to make the node's "next" point to the arglist. */
                                   $$->stmt0 = $1; /* stmt0 will point to the expression. */            
                                   $$->symbol = Insert( $$->name, INTTYPE, 0, level, 1, globalOffset, NULL, 0 ); /* Insert the argument into the symbol table. */
                                   $$->typeOfDeclaration = $1->typeOfDeclaration; /* Update the globalOffset by 1. */
                                   globalOffset++; /* Increment globalOffset by 1. */
                                 } /* NOTE: I changed this production rule to right-recusive since we want to print them "in-order" */ 
                                   /* (that is, from left to right). In other words, since this is a bottom up parser, if */
                                   /* the production rule were to be left recusive, then the argument list would be printed "backwards." */
        ; 

%% /* End of rules, start of program. */

/* Main Function */
main( int argv, char * argc[ ] ) {

   // Declare several variables to make creating a file easier.
   int i = 0;
   int flag = 0;
   char * s;
 
   // Check for all the arguments that are passed down by the user.
   while( i < argv ) {
   
      // If the user inputted the debug flag, set mydebug to 1. 
      if( strcmp( argc[i], "-d" ) == 0 ) { 
         mydebug = 1;
      } // end if.
      
      // If the user inputed the executable flag, the element next to it must 
      // be the name of the file we want. Update fp.
      if( strcmp( argc[ i ], "-o") == 0 ) {
         flag = 1;
         sprintf( s, "%s.asm", argc[ i + 1 ] );
         fp = fopen( s, "w" );
      } // end if. 
        
      // Increment i.
      i++;
   
   } // end while.
   
   // If fp equals to null, the user did not enter the -o flag. Exit
   // since if we run the program, we will get a segment fault. 
   if( fp == NULL ) {
      printf( "ERROR: MUST HAVE A FILE NAME WITH AN EXECUTABLE FLAG -o with file name.\n" );
      printf( "Making a default file named default.asm\n" );
      sprintf( s, "default.asm" );
      fp = fopen( s, "w" );
      //exit(1);
   } // end if.
   
   // Parse the tree.
   yyparse();
   
   if( mydebug ) {
      /* Print a meaningful message.*/
      printf( "The input has been syntactically checked. Here is the AST.\n");
      
      /* This is were we can print the AST starting at the rootNode. */
      /* NOTE: We comment the ASTprint( ) since it makes the output cluttered. */ 
      ASTprint( 0, rootNode);   

      /* Display the symbol table and print a meaningful message. */

      printf( "\nMain symbol table START\n" );
      Display( );
      printf( "\nMain symbol table END\n\n" );

   } // end if.
   
   // Call emitAST with the root node in order to produce the assembly code.
   emitAST( fp, rootNode );
   
   // Close the FILE object.
   fclose( fp );

} // end main.
