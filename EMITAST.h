/*

   Author's Name: Jose Franco Baquera

   Project Name:  Lab 9 - Create NASM code from your AST 

   Program Name: EMITAST.h
            
   Date: April 25, 2018
      
   Class: CS 370 - Shaun Cooper
   
   Lab Number: 9
    
   Purpose/Description: The purpose of this H file is to serve as the
   header file for the EMITAST.c file. This header file will contain 
   all of the function prototypes found in the EMITAST.c file.

*/

#ifndef EMITAST_H
#define EMITAST_H

#include "Lab6AST.h"
#include "symtable.h"

// Here are the function prototypes for file EMITAST.c:
void emitExpression ( FILE *fp, ASTnode * p );
void printStrings( FILE *fp, ASTnode *p );
void printBody( FILE *fp, ASTnode *p );
void emitReturn( FILE *fp, ASTnode * p );
void printCommon( FILE *fp, ASTnode *p );
void emitFunction ( FILE *fp, ASTnode *p );
void copyArgsIntoParameters( FILE *fp, ASTnode * arguments , ASTnode * parameters, int sizeOfFunction );
void evaluateArguments( FILE *fp, ASTnode *p );
void emitIdentifier( FILE *fp, ASTnode *p );
void emitAST( FILE *fp, ASTnode *p );

#endif
