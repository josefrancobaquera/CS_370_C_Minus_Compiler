/*
   Author's Name: Jose Franco Baquera

   Project Name:  Lab 7 - Add Symbol Table and Type Checking 

   Program Name: symtable.h
            
   Date: April 11, 2018
      
   Class: CS 370 - Shaun Cooper
   
   Lab Number: 7
    
   Purpose/Description: This file will serve as the header file 
   for the symtable.c file. 
   
*/

#ifndef _SYMTAB 
#define _SYMTAB
#include "Lab6AST.h"

// Here is the SymbTab structure. Each node will contain
// one of every attribute.
struct SymbTab {

   char *symbol;
   int offset; /* from activation record boundary */
   int mysize;  /* number of words this item is 1 or more */
   int level;  /* the level where we found the variable */
   int isArray;
   enum OPERATORS Type;  /* the type of the symbol */
   int IsAFunc;  /* the element is a function */
   ASTnode * fparms; /* pointer to parameters of the function in the AST */
   struct SymbTab *next;
   
};

// Here are allmy function protypes.
void Display();
void PrintSym( struct SymbTab *s);
struct SymbTab * Search( char name[], int level, int recur );
struct SymbTab *  Insert( char *name, enum OPERATORS Type, int isafunc, int  level, int mysize, int offset, ASTnode * fparms, int array  );
char * CreateTemp();
char * CreateLabel();
int Delete(int level);
int CompareFormals( ASTnode *formalParams, ASTnode *actualParams ); 

#endif
