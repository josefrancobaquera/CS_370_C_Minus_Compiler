/*
   Author's Name: Jose Franco Baquera

   Project Name:  Lab 6 - Abstract Syntax Tree

   Program Name: Lab6CMinus.l
            
   Date: March 26, 2018
      
   Class: CS 370 - Shaun Cooper
   
   Lab Number: 6
    
   Purpose/Description: The purpose of this lex file is to 
   read in streams of character strings and produce the appropriate tokens.
*/

%{

   // Declare a global variable that will allow us to count the
   // number of lines a user inputs. We start counting the lines at
   // 1, not 0.
   
   // Turn mydebug off since we do not need all the extra and unessary printing. 
   int lineCounter = 1;
   int mydebug = 0;
   
   // #include the YACC file.
   
   #include "Lab6AST.h"
   #include "y.tab.h"
   #include "Lab6AST.h"
   #include "symtable.h"
   
   // NOTE: For the next regular expressions, reserved words MUST come first.

%}

%%

\".*\" {

   /* If LEX encounters a string of characters, return a STRING token." */
   
   if( mydebug )
   
      fprintf( stderr, "Found a STRING token.\n" );
      
    /*
   
      NOTE: 'strdup' dublicates the string and places it on the heap.
   
    */
    
    yylval.string = strdup( yytext );
    
    return( STRING ); }

write {

   /* If LEX encounters 'write', return a WRITE token. */
   
   if ( mydebug )

      fprintf( stderr, "Found a WRITE token.\n" );
   
   return( WRITE ); }

read {

   /* If LEX encounters 'read', return a READ token. */
   
   if ( mydebug )

      fprintf( stderr, "Found a READ token.\n" );
   
   return( READ ); }

int { 

   /* If LEX encounters 'int', return a INT token. */
   
   if ( mydebug )
   
      fprintf( stderr, "Found a INT token.\n" ); 
   
   return( INT ); }

void {

   /* If LEX encounters 'void', return a VOID token. */
   
   if ( mydebug )

      fprintf( stderr, "Found a VOID token.\n" );
   
   return( VOID ); }
   
if {

   /* If LEX encounters 'if', return a IF token. */
   
   if ( mydebug )
   
      fprintf( stderr, "Found a IF token.\n" );
   
   return( IF ); }

while {

   /* If LEX encounters 'while', return a WHILE token. */
   
   if ( mydebug )

      fprintf( stderr, "Found a WHILE token.\n" );
   
   return( WHILE ); }

else {

   /* If LEX encounters 'else', return a ELSE token. */
   
   if ( mydebug )

      fprintf( stderr, "Found a ELSE token.\n" );
   
   return( ELSE ); } 

return {

   /* If LEX encounters 'return', return a RETURN token. */
   
   if( mydebug )
   
      fprintf( stderr, "Found a RETURN token.\n" );

   return( RETURN ); }

[<][=] {

   /* If LEX encounters '<=', return a LE token. */
   
   if ( mydebug )
   
      fprintf( stderr, "Found a LE (i.e. <=) token.\n" );
   
   return( LE ); }
   
[>][=] {

   /* If LEX encounters '>=', return a GE token. */
   
   if ( mydebug )
   
      fprintf( stderr, "Found a GE (i.e. >=) token.\n" );

   return( GE ); }
   
[=][=] {

   /* If LEX encounters '==', return a EQ token. */
   
   if ( mydebug )
   
      fprintf( stderr, "Found a EQ (i.e. ==) token.\n" );

   return( EQ ); } 

[!][=] {

   /* If LEX encounters '!=', return a NE token. */
   
   if ( mydebug )
   
      fprintf( stderr, "Found a NE (i.e. !=) token.\n" );

   return( NE ); } 

[a-zA-Z][a-zA-Z0-9]* { 

   /* This regular expression will take care of variables being used and/or declared.
   NOTE: A valid variable can only start with a lower/uppercase letter, followed
   by zero or more letters (uppercase or lowercase) and/or numbers. */
   
   /*
   
   NOTE: 'strdup' dublicates the string and places it on the heap.
   
   */

   yylval.string = strdup( yytext );
   
   if ( mydebug )
   
      fprintf( stderr, "VALID ID found with name '%s'. Returning the 'ID' token.\n", yylval );

   return( ID ); }
   
[0-9][0-9]* {

   /*
   
      This regular expression is responsible for all digits that are one
      or more in length (ex: 0, 11, 564, etc.).
    
   */
   
   /* NOTE: The atoi function will convert a string into an integer. */
   
   yylval.value = atoi( yytext ); 
   
   if( mydebug )
   
      fprintf( stderr, "Constant found with value %d. Returning an NUM token.\n", yylval );

   return( NUM ); }

[ \t] {

   /* If whitespace or a tab is found, do not return any tokens. Ignore it.*/
   /* NOTE: The space before \t means something! */
   
   if ( mydebug )
   
      fprintf( stderr, "Whitespace or Tab found. Ignoring. No tokens are returned.\n"); }

[=\-{}+*,/()<>;\[\]] { 

   /*
   
      This regular expression is responsible for operands such as those related to 
      arithmetic caculations and syntatically correct rules such as adding 
      a semicolon after declaring an integer or a curly braces for compund statements.
      
   */
   
   if ( mydebug )
   
      fprintf( stderr, "Found a special character. Returning the special token: %c\n", *yytext); 

   return ( *yytext ); }

[/][/].* {

   /* This regular expression will allow us to have in-line comments. */
   
   if( mydebug )
   
      fprintf( stderr, "In-Line comments found. Ignoring this line of code." ); }

\n { 

   /* Increment the lineCounte variable. This will allow us print the error line number in the YACC file. */

   lineCounter++;

   /* If a newline is found, ignore it since our YACC file does not use it for its production rules. */ 
   
   if( mydebug )
   
      fprintf( stderr, "Newline/Carriage Return found.%c\n", *yytext ); }

%%

int yywrap( void ) { 

   return 1;

}
