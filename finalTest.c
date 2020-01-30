int globalSOne;
int globalSTwo;
int globalAThree;
int globalArray[10];
int squareOfNumber( int x ) {
    
   x = x * x;
   return x;
    
} 

int readANumbersFromUser( void ) {
    
   write "Please enter TWO numbers";
   read globalSOne;
   read globalSTwo;
   write "The two numbers you entered were:";
   write globalSOne;
   write globalSTwo;    
    
}

int fibonacci ( int number ) {

   if( number <= 0 ) {
       return 0;
   }
   if( number == 1){
       return 1;
   }
   if( number == 2 ) {
       return 1;
   }
   
   return fibonacci( number - 1 ) + fibonacci( number - 2 );
    
    
}

int maxOfTwoNumbers( int x, int y ) {

    if( x > y ) {
       return x;
    }
    
    if ( x < y ) {
       return y;    
    }
    
    if( x == y ) {
       return x;    
    }
    
}

void printGreetingMessage( void ) {
   
   int numberOfDays;
   numberOfDays = 10;
   write "Hello. Welcome to CS 370: Compilers.";
   write "This compiler project took the following number of days to complete:";
   write numberOfDays;
   write "****************************";
 
}

void checkArithmeticOperations( void ) {
    
   int temp;
   globalSOne = 10;
   write "CHECKING ARITHMETIC OPERATIONS:";
   write "Suppose there exists a varaible named globalSOne that holds a value of 10.";
   write "The square of globalSOne is the following:";
   temp = squareOfNumber( globalSOne );
   write temp;
   write "The answer should be 100.";
   write "Now we check if our arithmetic works.";
   write "Suppose temp holds 100";
   write "The answer to ( temp*50 + globalSOne/10 - 2 ) * 5 is:";
   write ( temp*50 + globalSOne/10 - 2 ) * 5;
   write "The answer should be 24995";
   if( ( ( temp*50 + globalSOne/10 - 2 ) * 5 ) == 24995 ) {
      write "CONGRATS! Answer is correct! :)";
   }
   else {
      write "I'm sorry. The answer is not correct. :(";
   }
   
   write "****************************";
  
}

void main ( void ) {
    
   int counter;
   int temp;
   counter = 0;
   printGreetingMessage( );
   checkArithmeticOperations( );
   write "Filling the first 10 fibonacci numbers in an array";
   write "Here are the the first 10 fibonacci numbers:";

   while( counter < 10 ) {
      globalArray[counter]= fibonacci(counter + 1);
      counter = counter + 1;
   }
   
   counter = 0;
   
   while( counter < 10 ) {
      write globalArray[counter];
      counter = counter +1;
   }
   
   write "****************************";
   
   readANumbersFromUser( );
   temp = maxOfTwoNumbers( globalSOne, globalSTwo );
   write "The largest number you inputted was:";
   write temp;
   write "END OF TEST CODE!! YESSS! TIME TO GO TO JAGUARS!"; 
    
  
} 
