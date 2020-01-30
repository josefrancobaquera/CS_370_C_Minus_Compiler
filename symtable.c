/*
   Author's Name: Jose Franco Baquera

   Project Name:  Lab 7 - Add Symbol Table and Type Checking 

   Program Name: symtable.c
            
   Date: April 11, 2018
      
   Class: CS 370 - Shaun Cooper
   
   Lab Number: 7
    
   Purpose/Description: This file will serve as a 
   header file for the symtable.c file. 
   
*/

/* Include several files that will allow us to complete the project. */

#include<stdio.h>
#include "symtable.h"
#include<malloc.h>
#include<string.h>
#include<stdlib.h>

// The "size" variable will keep track of the 
// number of nodes in the structure. 
int size = 0;

// Make a global counting variable for temporary variables. 
int GTEMP = 0;  

// Make a global vounting variable for labels.
int LTEMP = 0;

// Create two nodes that will keep track of the first 
// and last nodes in the symbol table.
struct SymbTab *first, *last;


// Search function. This function will search if a variable name is found
// inside the symbol table.
struct SymbTab * Search( char name[], int level, int recur ) {
   
   // Declare two variables that will allow us to use a for loop 
   // and a flag.
   int i;
   int flag = 0;
   struct SymbTab *p;

   // While loop that will check up to level 0.
   while ( level >= 0 ) {
      
      p = first;
      
      // Use a while loop that will check if p is null. 
      while ( p != NULL ) {
          
         // Use an if statement that will compare both the name and the level.
         // If they are the same, return true (i.e. the pointer to the node).
         
          if( ( strcmp(p->symbol,name)==0) && (p->level == level))
           
              return p;
         
          p =p->next;
          
      } // end while.
        
      //
      if ( recur == 0 ) 
         /* We did not find it at our level. Return null. */
         return (NULL);   
      
      // Check the next level. 
      level--; 
       
   } // end while.

   // If we did not find the identifier, return NULL (i.e. 0).
   return  NULL;  
   
} // end Search.

// Insert function. This function will insert a node into the symbol table.
struct SymbTab *  Insert( char *name, enum OPERATORS Type, int isafunc, int  level, int mysize, int offset, ASTnode * fparms, int array  ) {
    
    struct SymbTab * n;
    n = Search(name,level, 0);
    
    // Check if the variable is already inside the symbol table. If it is, print an error and return NULL.
    if( n != NULL){
        
      printf("\n\tThe name %s exists at level %d already in the symbol table\n\tDuplicate can.t be inserted",name, level);
      return (NULL);
      
    } // end if.
    
    else {
      
      // Update all the attributes using the parameters of the functions. 
      struct SymbTab *p;
      p=malloc(sizeof(struct SymbTab));
      p->symbol=name;
      p->offset=offset;  /* assign the offset */
      p->level=level;  /* assign the level */
      p->mysize=mysize;  /* assign the size */
      p->Type=Type;  /* assign the Type */
      p->IsAFunc=isafunc;  /* assign the Function  */
      p->fparms=fparms;  /* assign the Function  */
      p->next=NULL;
      p->isArray = array;

      /* Update the pointers of the first and last nodes of the symbol table. */
      if( first==NULL ) {
          
        first = p;
        
      }// end if.
      
      else {
          
        p->next=first;
        first=p;
        
      } // end else.
      
      // Increment the size of the symbol table.
      
      size++;
     
      return (p);
 
    } // end outer else.
    
} // end Insert frunction.

// Delete function. This function will delete all the variables at a given level. 
int Delete(int level) {
    
    // Declare a temp pointer that will allow us to "traverse" through 
    // the symbol table.
    struct SymbTab *p,*f=NULL;  /* we follow with pointer f */
    int SIZE = 0;
    p = first;

    // Traverse through the entire symbol table linked list.
    while (p != NULL) {
        /* do we match? */
        if ( p->level>= level ) { 
           /* If it is the first in the list we have to update first, we know this by f being NULL. */
           // Update total size if we found a variable at or above the parameter level.
           SIZE+=p->mysize;
           
           // Actually "delete" the node from the symbol table.
           if ( f == NULL) 
               
              first =p->next;
           
           else {
               
              f->next=p->next;
              
            } // end else.
            
            p=p->next;
           
        } // end if.
        
        else {
           
            /* Update follow pointer, move the p pointer. */
            f = p;
            p = p->next;
            
        } // end else.

    } // end while loop.
      
    // Return the total size we "deleted."
    return(SIZE);
    
} // end Delete function.

// PrintSym function. This function will serve as a helper "function" for the Display function.
void PrintSym( struct SymbTab *s) {

    printf( "\t%s\t\t%d\t\t%d\n",s->symbol,s->offset, s->level );

} // end PrintSym function.


/*  General display to see what is our symbol table */
void Display() {
   
   
   int i;
   struct SymbTab *p;
   p=first;
   
   // Print a meaningfull message to the user.
   printf("\n\tLABEL\t\tOffset \t\tLEVEL\n");
   
   // Use a while loop that will traverse through 
   // the symbol table. Use the helper function 
   // to print thenode's payload.
   while ( p!=NULL ) {
       
      PrintSym(p);
      p=p->next;
      
   } // end while.
      
} // end Display function.


char * CreateTemp() {    

   // Create a new character array.
   char hold[100];
   char *s;
   
   sprintf(hold,"_T%d",GTEMP++);
   
   // Duplicate the char array.
   s = strdup(hold);
   
   // Return the new temp variable created.
   return (s);

}// end CreateTemp function.

//
char * CreateLabel() {    

   // Create a new character array.
   // This will be used to create strings 
   // in the assembly file.
   char hold[100];
   char *s;
   
   sprintf(hold,"_L%d", LTEMP++);
   
   // Duplicate the char array.
   s = strdup(hold);
   
   // Return the new temp variable created.
   return (s);

}// end CreateTemp function.

// CompareFormals function. This function will compare the actual 
// and formal parameters in a function call.
int CompareFormals( ASTnode *formalParams, ASTnode *actualParams ) {

   // If we reach the end of the list, return true.
   if( formalParams == NULL && actualParams == NULL ) {
      return 1;  
   } // end if..
   
   // If the sizes are not the same, return false.
   if( formalParams == NULL || actualParams == NULL ) {
      return 0;
   }// end if.
   
   // If the types of the parameters do not match, return false.
   if( formalParams->typeOfDeclaration != actualParams->typeOfDeclaration ) { 
      return 0; 
   } // end if.
   
   // Recursively call the function. 
   return ( CompareFormals( formalParams->next, actualParams->next ) );
   
} // end CompareFormals function.
