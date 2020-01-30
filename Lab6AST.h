/*

   Author's Name: Jose Franco Baquera

   Project Name:  Lab 6 - Abstract Syntax Tree

   Program Name: Lab6AST.h
            
   Date: March 26, 2018
      
   Class: CS 370 - Shaun Cooper
   
   Lab Number: 6
    
   Purpose/Description: The purpose of this C file is to 
   serve as the header file for the C file Lab6AST.c 

*/

// Define AST_H if it has not define so we don't include Lab6AST.h file several times
// on other files. 
#ifndef AST_H
#define AST_H

// Include the relevant header files.
#include <stdio.h>
#include <malloc.h>


// Extern the mydebug variable.
int mydebug;

// Nodes can be of the following types. 
enum ASTtype {
   PROGRAM,
   VARDEC,
   FUNDEC,
   PARAM, 
   BLOCK, 
   EXPR,
   TERM, 
   NUMBER, 
   ARGLIST,
   READSTMT,
   IDENT, 
   CALL, 
   EXPRSTMT,
   IFSTMT,
   WRITESTMT,
   RETURNSTMT,
   ASSIGN,
   ITSTMT 
};

// Operators can be of the following types.
enum OPERATORS {
   INTTYPE,
   VOIDTYPE,
   PLUS, 
   MULT,
   DIV,
   MINUS,
   LESSTHANEQUAL,
   LESSTHAN,
   GREATERTHAN,
   GREATERTHANEQUAL,
   EQUAL,
   NOTEQUAL
};


/* 
   Define a type AST node which will hold pointers to AST structs that will
   allow us to represent the parsed code as a AST. 
*/


typedef struct ASTnodetype {
    
   // NOTE: I changed the names of the pointers in order to make it easier to program.
   enum ASTtype type; /* A node can have an accompying type. */
   enum OPERATORS operator; /* A node can have an accompying operator type. */
   enum OPERATORS typeOfDeclaration; /* This will keep track of the declaration types of the variable. */
   char * name; /* A node can have an accompying string name. */
   char * label; /* A node can store the name of the label given to it. */
   int value; /* A node can have a integer value. */
   struct ASTnodetype *next; /* next is usually the connector between lists. */
   struct SymbTab * symbol; /* This will keep keep track of the symbol we inserted into the symbol table. */
   struct ASTnodetype *stmt0, *stmt1, *stmt2; /* Trivally-named pointers of type ASTnodetype. */
   
} ASTnode;

#include "symtable.h"
// This function will created a node of specified type.
ASTnode *ASTCreateNode( enum ASTtype mytype );

// This function will print out the abstract syntax tree. 
void ASTprint(int level, ASTnode *p);

// This function will print out a specified number of spaces (i.e. whitespace). 
void ASTspacePrint ( int copyLevel );

// Defining "rootNode", which will point to the entire AST once yacc finishes parsing. 
ASTnode *rootNode;

#endif  
