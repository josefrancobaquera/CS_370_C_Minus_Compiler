/*

   Author's Name: Jose Franco Baquera

   Project Name:  Lab 6 - Abstract Syntax Tree

   Program Name: Lab6AST.c
            
   Date: March 26, 2018
      
   Class: CS 370 - Shaun Cooper
   
   Lab Number: 6
    
   Purpose/Description: The purpose of this C file is to "store"
   all the Abstract Syntax Tree information created by the yacc
   file named Lab6CMinus.y. In other words, we will use this 
   file to store the syntax tree created by the production rules
   found in the Lab6CMinus.y yacc file. 

*/

// Include the header file for Lab6AST.c.

#include "Lab6AST.h"
#include "symtable.h"

// ASTCreateNode function. This function is responsible for creating a node with 
// with a specific type specified by the paramter named mytype.

ASTnode* ASTCreateNode( enum ASTtype mytype ) {
    
    // Create a new ASTnode pointer.
    ASTnode *p;
    
    // If mydebug is not zero, print a meaningful message, else do not 
    // print anything.
    if ( mydebug) 
       fprintf(stderr, "Creating AST Node \n");
    
    // Use malloc to create an ASTnode in the heap. Cast the return type to 
    // a ASTnode pointer, then assign this "address" to variable p.
    p = (ASTnode *) malloc( sizeof( ASTnode ) );
    
    // Assign the new node's type to the type of the parameter.    
    p->type = mytype;
    p->symbol = NULL;
    
    // Make all the ASTnodes point to NULL since they will point
    // to "nothing" until we assign it a new pointer in the YACC file.
    // This evetually makes it easier to avoid redundant code in the
    // YACC file.
    p->next = NULL;
    p->stmt0 = NULL;
    p->stmt1 = NULL;
    p->stmt2 = NULL;
    
    // Make the new node's value equal to zero since it will make
    // it easier when printing array declarations/parameters. 
    p->value = 0;
    
    // Inizalize the label to be empty.    
    p->label = "";
    
    // Return a pointer to the newly created node.
    return( p );
    
} // end ASTCreateNode function.

// NOTE: I removed the ASTattachnext function since it is not used 
// anywhere in this lab.  

// ASTspacePrint function. This function is responsible for 
// printing the "tabs" that will make the output look
// like a tree.

void ASTspacePrint ( int copyLevel ) {
    
   // Declare a variable outside the for loop since we cannot
   // declare a variable inside the for loop.
   int i;
   
   // Use a for loop to print the tabs.
   for ( i = 0; i < copyLevel; i++) 
      // Print tabbing blanks.
      printf(" "); 
   
} // end ASTspacePrint.

// ASTprint function. This function is responsible for 
// printing the Abstract syntax tree produced by the production 
// rules in the YACC file. 

void ASTprint( int level, ASTnode *p ) {
    
   // AUTHOR'S NOTE: I removed the for loop here and just made a 
   // more general function called ASTspacePrint that will accomplish
   // the same task. 

   // First check if pointer 'p' is NULL. If it is, return, else
   // print the "payload" of the relevant payload in the node. 
   // NOTE: This function "mimics" pre-order printing. 
   if ( p == NULL ) 
      return;
   
   else { 
       
      // Use a swtich statement that will check the type of the node. Each type of node will have
      // different printing rules. 
      switch ( p->type ) {
          
         // Case VARDEC.
         case VARDEC : 
             
            // Print the corresponding whitespace. 
            ASTspacePrint( level );
             
            // Check the operator type of the node using an else-if. 
            if ( p->operator == INTTYPE ) 
               // If the operator is INTTYPE, then the variable is 
               // type "int."                
               printf( "Variable INT %s", p->name );
            else if ( p->operator == VOIDTYPE )
               // If the operator is VOIDTYPE, then the variable is 
               // type "void." 
               printf( "Variable VOID %s", p->name );
            else 
               // Print an error message if an unknown specifier is found.
               printf( "Unknown typespecifier" );
            
            // Use an if statement that will check if the value is greaterthan 0.
            // If it is, the variable declaration found is an array. Therefore, we need
            // to print brakets. 
            if ( p->value > 0)
               printf( "[%d]", p->value );
            
            // Print a newline.
            printf( "\n" );
            
            break;
        
         // Case FUNDEC.
         case FUNDEC : 
            
            // Print the corresponding whitespace. 
            ASTspacePrint( level );
            
            // Use an else-if statement that will check the type of the fundeclaration.                
            if ( p->operator == VOIDTYPE ) {
               // If the operator type is VOIDTYPE, print "VOID FUNCTION" with its identifier. 
               printf( "VOID FUNCTION %s", p->name );
               printf( "\n" );
            } // end if.
            
            else if ( p->operator == INTTYPE ) { 
               // If the operator type is INTTYPE, print "INT FUNCTION" with its identifier.                
               printf( "INT FUNCTION %s", p->name );
               printf( "\n" );
            } // end else.
            
            else 
               // Print an error message if an unknown specifier is found.
               printf( "Unknown typespecifier" );
            
            // Now we print the function's parameters.
            
            // First check if the parameter list is NULL. If it is Null, print "(VOID)".
            if ( p->stmt0 == NULL  ) {
               ASTspacePrint( level + 1 );
               printf( "(VOID)\n" );
            } // end if.
            
            // If the parameter list if not NULL, recursively print the the parameters.
            else { 
               printf( " (\n" );
               // Recusive call the parameter list. 
               ASTprint( level + 1, p->stmt0 );
               printf( " )\n" );
            } // end else.

            // If stmt1 does not eqaul to NULL, there exists a compound statement. Print the coumpount statement recursively.
            if( p->stmt1 !=  NULL ) 
               ASTprint( level + 1, p->stmt1 );
            
            break;
         
        // Case PARAM.
        case PARAM:
        
           // Print the whitespace and a meaningful message. 
           ASTspacePrint( level );
           printf( "PARAMETER " );
           
           // Use an else-if statement that will check the type of the parameter.  
           if ( p->operator == VOIDTYPE ) { 
              // If the operator type is VOIDTYPE, print "VOID."
              printf( "VOID " );
           } // end if.
            
           else if ( p->operator == INTTYPE ) { 
              // If the operator type is INTTYPE, print "INT."
              printf( "INT " );
           } // end else.
           
           else
              // Print an error message if an unknown specifier is found.
              printf( "Unknown typespecifier" );
           
           // Print the name of the identifier.
           printf( "%s", p->name );
           
           // Use a "dummy" value that was stored in this node. If an 11 was stored 
           // in this node, then the parameter is an array parameter.
           if ( p->value == 11 ) 
               printf( "[ ]" );
            
            // Print a newline.
            printf( " \n" );
                
            break;
           
        // BLOCK case. 
        case BLOCK:
           
           // Print the whitespace and a meaningful message. 
           ASTspacePrint ( level );
           printf( "BLOCK STATEMENT\n" );
           
           // The following if statement will print the local declarations within a block.
           // If there are local declarations, print them recursively. 
           if ( p->stmt0 != NULL  ) {
              ASTprint( level + 1, p->stmt0 );
           } // end if.
           
           // The following if statement will print the statement list within a block.
           // If there is a statement list, print them recursively. 
           if ( p->stmt1 != NULL ) {
              ASTprint( level + 1, p->stmt1 );          
           } // end if.
           
           // If there are no local declarations or statement list, then the block 
           // is empty. Print a meaningful message to the user to demonstrate that
           // it is an empty statement.
           if ( p->stmt0 == NULL && p->stmt1 == NULL ) {
              ASTspacePrint( level + 1 );
              printf( "EMPTY BLOCK\n" );     
           } // end if.
           
           break;
        
        // Case NUMBER.
        case NUMBER:
           
           // Print the corresponding whitespace.
           ASTspacePrint( level );
           // Print the number stored in this node.
           printf( "NUMBER with value %d\n", p->value );
            
           break;
           
        case EXPRSTMT:
           
           // Print the corresponding whitespace and a meaningful message. 
           ASTspacePrint( level );
           printf( "EXPRSTMT\n" );
           
           // If stmt0 does not equal to NULL, the expression statement has 
           // an expression. Print it this expression recursively.
           if( p->stmt0 != NULL )
              ASTprint( level + 1, p->stmt0 );
           
           // If stmt0 equals to NULL, the expression statement has no expression.
           // Print a meaningful message to the user. 
           else {
               ASTspacePrint( level + 1 );
               printf( "Empty Expression\n" );
           } // end else.
           
           break;
        
        // Case EXPR.
        case EXPR:
           
           // Print the corresponding whitespace.
           ASTspacePrint( level );
           
           // Use a swtich statement that will check the type of the operator stored in this node. 
           switch( p->operator ) {
              
              // If the operator is PLUS, the expression revolves around a '+.' Print a meaningful message.
              case PLUS:
                 printf( "EXPR +\n" );
                 break;
            
              // If the operator is MINUS, the expression revolves around a '-.' Print a meaningful message.
              case MINUS:
                 printf( "EXPR -\n" );
                 break;
              
              // If the operator is DIV, the expression revolves around a '/.' Print a meaningful message.
              case DIV:
                 printf( "EXPR /\n" );
                 break;
                 
              // If the operator is MULT, the expression revolves around a '*.' Print a meaningful message.   
              case MULT:
                  printf( "EXPR *\n" );
                  break;
                  
              // If the operator is LESSTHANEQUAL, the expression revolves around a '<=.' Print a meaningful message.  
              case LESSTHANEQUAL:
                 printf( "EXPR <=\n" );
                 break;
                 
              // If the operator is LESSTHAN, the expression revolves around a '<.' Print a meaningful message.     
              case LESSTHAN:
                printf( "EXPR <\n" );
                break;
                
              // If the operator is GREATERTHAN, the expression revolves around a '>.' Print a meaningful message.     
              case GREATERTHAN:            
                 printf( "EXPR >\n" );
                 break;
                 
              // If the operator is GREATERTHANEQUAL, the expression revolves around a '>=.' Print a meaningful message.    
              case GREATERTHANEQUAL:
                 printf( "EXPR >=\n" );
                 break;
              
              // If the operator is EQUAL, the expression revolves around a '==.' Print a meaningful message. 
              case EQUAL:
                 printf( "EXPR ==\n" );
                 break;
              
              // If the operator is NOTEQUAL, the expression revolves around a '!=.' Print a meaningful message. 
              case NOTEQUAL:
                  printf( "EXPR !=\n" );
                  break;
              
              // If we reach the default case, the operator is unknown. Print an error message.
              default: printf( "NOTE: EXPRESSION Unknown\n" );
                  
           } // end swtich statement.
           
           // Print recursively stmt0. stmt0 can be either a term, simpleexpression, or additiveexpression.
           if ( p->stmt0 != NULL )
              ASTprint( level + 1, p->stmt0 ); 
           
           // Print recursively stmt1. stmt1 can be either a additiveexpression, term, or factor. 
           if( p->stmt1 != NULL )
              ASTprint( level + 1, p->stmt1 );
  
           break;
         
        // Case ASSIGN.
        case ASSIGN:
           
           // Print the corresponding whitespace and a meaningful message. 
           ASTspacePrint( level );
           printf( "ASSIGNMENT STATEMENT\n" );
           
           // stmt0 represents the 'var' (variable) of the assignment statement.
           // Print it recursively.
           if ( p->stmt0 != NULL )
              ASTprint( level + 1, p->stmt0 );
           
           // stmt1 represents the expressionstmt of the assignment statement.
           // Print it recursively.
           if ( p->stmt1 != NULL )
              ASTprint( level + 1, p->stmt1 );
            
           break;
           
        // Case READSTMT.
        case READSTMT:
           
           // Print the corresponding whitespace and a meaningful message. 
           ASTspacePrint( level );
           printf( "READ STATEMENT\n" );
           
           // stmt0 in this node represents the var in a read statement.
           // Print this recursively. 
           if ( p->stmt0 != NULL ) {
              ASTprint( level + 1, p->stmt0 );
           } // end if.
        
           break;
        
        // IDENT case.
        case IDENT:
           
           // Print the corresponding whitespace and the identifier's name. 
           ASTspacePrint( level );
           printf( "IDENTIFIER %s\n", p->name );
           
           // If stmt0 is not equal to NULL, the IDENT is an array.
           if (  p->stmt0 != NULL ) {
              // Print the corresponding whitespace and a meaningful message. 
              ASTspacePrint( level );
              printf( "ARRAY Reference [\n" );
              
              // stmt0 in this node correponds to the expression inside the array's 
              // brakets.
              ASTprint( level + 1, p->stmt0 );
              
              // Print the corresponding whitespace and a meaningful message.
              ASTspacePrint( level );
              printf( "] end array\n" ); 
           } // end if.
           
           break;
        
        // WRITESTMT case.
        case WRITESTMT: 
           
           // Print the corresponding whitespace and a meaningful message.
           ASTspacePrint( level );
           printf( "WRITE STATEMENT\n" );
           
           // If we write a string, print the string.
           if( p->stmt0 == NULL ) {
              ASTspacePrint( level + 1 );
              printf( "string %s\n", p->name ); 
           } // end if.
           
           // stmt0 in this node correponds to the write statement's expression.
           // Print this expression recursively.
           if ( p->stmt0 != NULL )
              ASTprint( level + 1, p->stmt0 );
           
           break;
        
        // IFSTMT case.
        case IFSTMT:
           
           // Print the corresponding whitespace and a meaningful message.
           ASTspacePrint( level );
           printf( "IF STATEMENT\n" );
           
           // Print the corresponding whitespace and the first parenthesis.
           ASTspacePrint( level );
           printf( "(\n" );
            
           // stmt0 in this node correponds to selectionstatement's expression. Print it
           // recursively.
           if( p->stmt0 != NULL )
              ASTprint( level + 1, p->stmt0 );
           
           // Print the corresponding whitespace, the second parenthesis, and a meaningful message.
           ASTspacePrint( level );
           printf( ") END BOOLEAN CHECK\n" );
           
           // stmt1 in this node correponds to IF's statement. Print it recursively.
           if ( p->stmt1 != NULL )
              ASTprint( level + 1, p->stmt1 );
         
           // stmt2 corresponds to the statement after ELSE. In other words,
           // if stmt2 IS NOT NULL, then the if statement does not have 
           // and else. If its not NULL, print a meaningful message 
           // and recursively print its statement.
           if ( p->stmt2 != NULL ) {
              ASTspacePrint( level );
              printf( "ELSE STATEMENT\n" );
              // Print ELSE's statement recursively.
              ASTprint( level + 1, p->stmt2);
           } // end if.
           
           break;
        
        // ITSTMT case. (i.e. WHILE statement).
        case ITSTMT:
           
           // Print the corresponding whitespace and a meaningful message.
           ASTspacePrint( level );
           printf( "WHILE STATEMENT\n" );
           
           // Print the corresponding whitespace and the first parenthesis.
           ASTspacePrint( level );
           printf( "(\n" );
           
           // stmt0 in this node corresponds to the expression of the iteration statement.
           // Print this expression recursively.
           if( p->stmt0 != NULL )
               ASTprint( level + 1, p->stmt0 );
           
           // Print the corresponding whitespace, the second parenthesis, and a meaningful message.
           ASTspacePrint( level );
           printf( ") END BOOLEAN CHECK\n" );
           
           // stmt1 corresponds to the statement of the iteration statement. Print this statement
           // recursively.
           if( p->stmt1 != NULL )
              ASTprint( level + 1, p->stmt1 );
            
           break;
                      
        // CALL case.   
        case CALL:
            
           // Print the corresponding whitespace and a meaningful message.
           ASTspacePrint( level );
           printf( "CALL STATEMENT\n" );
           
           // Print the corresponding whitespace and the name of the indentifier. 
           ASTspacePrint( level );
           printf ( "IDENTIFIER %s (\n", p->name );
           
           // stmt0 in this node correponds to the arguments within a call statement.
           // Print these arguments recursively.
           if( p->stmt0 != NULL )
              ASTprint( level + 1, p->stmt0 );
           
           // Print the corresponding whitespace and a meaningful message.
           ASTspacePrint( level );
           printf( ") END CALL STATEMENT\n" );
           
           break;
        
        // Case RETURNSTMT.
        case RETURNSTMT:
           
           // Print the corresponding whitespace and a meaningful message.
           ASTspacePrint( level );
           printf( "RETURN STATEMENT\n" );
           
           // stmt0 in this node represents the expression within a return statement. If 
           // stmt0 is NULL, no expression is found in the return statement. Print 
           // a meaningful message.
           if( p->stmt0 == NULL ) {
              ASTspacePrint( level + 1 );
              printf( "RETURN WITH NO EXPRESSION\n" );
           } // end if.
           
           // If stmt0 is not NULL, print the expression recursively.
           else 
              ASTprint( level + 1, p->stmt0 );
                   
           break;
        
        // Case ARGLIST.
        case ARGLIST:
           
           // Print the corresponding whitespace and a meaningful message.
           ASTspacePrint( level );
           printf( "ARGUMENT\n" );
        
           // Recursively call the argument list.
           if( p->stmt0 != NULL )
              ASTprint( level + 1, p->stmt0 );
           
           break;
           
        // Default Case: This case will print an error message if the
        // recusive calls encounter an unknown node type.
        default: printf( "NOTE: Unknown type in ASTprint.\n" );

      } // end switch.
      
      // Recursively call the node that the attribute "next" points to. 
      ASTprint( level, p->next );
    
   } // end else.

} // end ASTprint function.

// Dummy main program so I can compile for syntax error independently.
/* 

main( ){

} // end main function. 

*/
