#Program Name: makefile
#Author's Name: Jose Franco Baquera
#Date: March 28, 2018
#Class: CS 370: Shaun Cooper
#Lab Title: Lab 6 - Abstract Syntax Tree 
#Purpose/Description: The purpose of this file is 
#to serve as the makefile for the runTest 
#executable code. The makefile will allow 
#the user to complie and create an executable
#with just typing "make" whenever a change 
#is made on on Lab6CMinus.l, Lab6CMinus.y, or 
#Lab6AST.c files.

all: Lab6CMinus.l Lab6CMinus.y Lab6AST.c symtable.c EMITAST.c y.tab.c lex.yy.c   
	lex Lab6CMinus.l 
	yacc -d Lab6CMinus.y
	gcc -c Lab6AST.c 
	gcc -c symtable.c
	gcc -c EMITAST.c
	gcc y.tab.c Lab6AST.c Lab6AST.h symtable.c symtable.h EMITAST.c EMITAST.h lex.yy.c -o runTest
