
%include "io64.inc"
	common globalSOne 8	; common integer variable
	common globalSTwo 8	; common integer variable
	common globalAThree 8	; common integer variable
	common globalArray 80	; common integer array variable
section .data	; starting data segment of memory
_L16: db "Filling the first 10 fibonacci numbers in an array", 0	; global string
_L17: db "Here are the the first 10 fibonacci numbers:", 0	; global string
_L18: db "****************************", 0	; global string
_L19: db "The largest number you inputted was:", 0	; global string
_L20: db "END OF TEST CODE!! YESSS! TIME TO GO TO JAGUARS!", 0	; global string
_L5: db "CHECKING ARITHMETIC OPERATIONS:", 0	; global string
_L6: db "Suppose there exists a varaible named globalSOne that holds a value of 10.", 0	; global string
_L7: db "The square of globalSOne is the following:", 0	; global string
_L8: db "The answer should be 100.", 0	; global string
_L9: db "Now we check if our arithmetic works.", 0	; global string
_L10: db "Suppose temp holds 100", 0	; global string
_L11: db "The answer to ( temp*50 + globalSOne/10 - 2 ) * 5 is:", 0	; global string
_L12: db "The answer should be 24995", 0	; global string
_L15: db "****************************", 0	; global string
_L13: db "CONGRATS! Answer is correct! :)", 0	; global string
_L14: db "I'm sorry. The answer is not correct. :(", 0	; global string
_L2: db "Hello. Welcome to CS 370: Compilers.", 0	; global string
_L3: db "This compiler project took the following number of days to complete:", 0	; global string
_L4: db "****************************", 0	; global string
_L0: db "Please enter TWO numbers", 0	; global string
_L1: db "The two numbers you entered were:", 0	; global string
section .text	; starting code segment of memory
	global main
squareOfNumber:	; start of function
	mov r8, rsp	; FUNC header RSP has to be at most RBP
	add r8, -40	; adjust Stack Pointer for Activation record
	mov [r8], rbp	; FUNC header stores old BP
	mov [r8+8], rsp	; FUNC header stores old SP
	mov rsp, r8	; FUNC header new SP

	mov rax, 16	; Moving the identifier's offset into rax
	add rax, rsp	; Adding the offset and stack pointer together and storing it back into rax
	mov rax, [rax]	; moving the contents of the identifier into rax
	mov [rsp +24], rax	; storing the left hand side into the offset
	mov rax, 16	; Moving the identifier's offset into rax
	add rax, rsp	; Adding the offset and stack pointer together and storing it back into rax
	mov rbx, [rax]	; moving the contents of the identifier into rbx
	mov rax, [rsp + 24]	; fetching the left hand side
	imul rax, rbx	; multiply expression
	mov [rsp + 24], rax	; Storing the final answer of the expression into its offset
	mov rax, [rsp + 24]	; moving to register rax the contents of the expression
	mov [rsp + 32], rax	; storing the final value of EXPRSTMT into its offset
	mov rax, 16	; Moving the identifier's offset into rax
	add rax, rsp	; Adding the offset and stack pointer together and storing it back into rax
	mov rbx, [32 + rsp]	; Storing the final value of the expression into a temporary register
	mov [rax], rbx	; Store the value into the identifier's memory address
	mov rax, 16	; Moving the identifier's offset into rax
	add rax, rsp	; Adding the offset and stack pointer together and storing it back into rax
	mov rax, [rax]	; move the contents of the identifier's the memory address into rax

	mov rbp, [rsp]	; FUNC end restore old BP
	mov rsp, [rsp+8]	; FUNC end restore old SP
	ret	; return to the caller

	mov rbp, [rsp]	; FUNC end restore old BP
	mov rsp, [rsp+8]	; FUNC end restore old SP
	ret	; return to the caller
readANumbersFromUser:	; start of function
	mov r8, rsp	; FUNC header RSP has to be at most RBP
	add r8, -16	; adjust Stack Pointer for Activation record
	mov [r8], rbp	; FUNC header stores old BP
	mov [r8+8], rsp	; FUNC header stores old SP
	mov rsp, r8	; FUNC header new SP

	PRINT_STRING _L0	; print a string
	NEWLINE	; standard Write a NEWLINE
	mov rax, globalSOne	; storing the memory address of the global variable into rax
	GET_DEC 8, [rax]	; READ in an integer
	mov rax, globalSTwo	; storing the memory address of the global variable into rax
	GET_DEC 8, [rax]	; READ in an integer
	PRINT_STRING _L1	; print a string
	NEWLINE	; standard Write a NEWLINE
	mov rax, globalSOne	; storing the memory address of the global variable into rax
	mov rsi, [rax]	; move the contents of the identifier's the memory address into rsi
	PRINT_DEC 8, rsi	; standard Write a value
	NEWLINE	; standard Write a NEWLINE
	mov rax, globalSTwo	; storing the memory address of the global variable into rax
	mov rsi, [rax]	; move the contents of the identifier's the memory address into rsi
	PRINT_DEC 8, rsi	; standard Write a value
	NEWLINE	; standard Write a NEWLINE

	mov rbp, [rsp]	; FUNC end restore old BP
	mov rsp, [rsp+8]	; FUNC end restore old SP
	ret	; return to the caller
fibonacci:	; start of function
	mov r8, rsp	; FUNC header RSP has to be at most RBP
	add r8, -88	; adjust Stack Pointer for Activation record
	mov [r8], rbp	; FUNC header stores old BP
	mov [r8+8], rsp	; FUNC header stores old SP
	mov rsp, r8	; FUNC header new SP

	mov rax, 16	; Moving the identifier's offset into rax
	add rax, rsp	; Adding the offset and stack pointer together and storing it back into rax
	mov rax, [rax]	; moving the contents of the identifier into rax
	mov [rsp +24], rax	; storing the left hand side into the offset
	mov rbx, 0	; moving a number into register rbx
	mov rax, [rsp + 24]	; fetching the left hand side
	cmp rax, rbx	; EXPR lessthanequal
	setle al	; sets the last bit in the last byte of the rax register
	mov rbx, 1	; set rbx to one to filter rax
	and rax, rbx	; filter rax by using the 'and' assembly instruction
	mov [rsp + 24], rax	; Storing the final answer of the expression into its offset
	mov rax, [rsp + 24]	; moving to register rax the contents of the expression
	cmp rax, 0	; comparing register rax to 0. If equal, that means that the expression is false
	je _L21	; IF branch out

	mov rax, 0	; moving a number into register rax

	mov rbp, [rsp]	; FUNC end restore old BP
	mov rsp, [rsp+8]	; FUNC end restore old SP
	ret	; return to the caller
	jmp _L22	; jumping out of the 'if' body

_L21:	; label that will allow us to skip the if's body if the expression is false

_L22:	; Label to exit the else part
	mov rax, 16	; Moving the identifier's offset into rax
	add rax, rsp	; Adding the offset and stack pointer together and storing it back into rax
	mov rax, [rax]	; moving the contents of the identifier into rax
	mov [rsp +32], rax	; storing the left hand side into the offset
	mov rbx, 1	; moving a number into register rbx
	mov rax, [rsp + 32]	; fetching the left hand side
	cmp rax, rbx	; EXPR equal
	sete al	; sets the last bit in the last byte of the rax register
	mov rbx, 1	; set rbx to one to filter rax
	and rax, rbx	; filter rax by using the 'and' assembly instruction
	mov [rsp + 32], rax	; Storing the final answer of the expression into its offset
	mov rax, [rsp + 32]	; moving to register rax the contents of the expression
	cmp rax, 0	; comparing register rax to 0. If equal, that means that the expression is false
	je _L23	; IF branch out

	mov rax, 1	; moving a number into register rax

	mov rbp, [rsp]	; FUNC end restore old BP
	mov rsp, [rsp+8]	; FUNC end restore old SP
	ret	; return to the caller
	jmp _L24	; jumping out of the 'if' body

_L23:	; label that will allow us to skip the if's body if the expression is false

_L24:	; Label to exit the else part
	mov rax, 16	; Moving the identifier's offset into rax
	add rax, rsp	; Adding the offset and stack pointer together and storing it back into rax
	mov rax, [rax]	; moving the contents of the identifier into rax
	mov [rsp +40], rax	; storing the left hand side into the offset
	mov rbx, 2	; moving a number into register rbx
	mov rax, [rsp + 40]	; fetching the left hand side
	cmp rax, rbx	; EXPR equal
	sete al	; sets the last bit in the last byte of the rax register
	mov rbx, 1	; set rbx to one to filter rax
	and rax, rbx	; filter rax by using the 'and' assembly instruction
	mov [rsp + 40], rax	; Storing the final answer of the expression into its offset
	mov rax, [rsp + 40]	; moving to register rax the contents of the expression
	cmp rax, 0	; comparing register rax to 0. If equal, that means that the expression is false
	je _L25	; IF branch out

	mov rax, 1	; moving a number into register rax

	mov rbp, [rsp]	; FUNC end restore old BP
	mov rsp, [rsp+8]	; FUNC end restore old SP
	ret	; return to the caller
	jmp _L26	; jumping out of the 'if' body

_L25:	; label that will allow us to skip the if's body if the expression is false

_L26:	; Label to exit the else part
	mov rax, 16	; Moving the identifier's offset into rax
	add rax, rsp	; Adding the offset and stack pointer together and storing it back into rax
	mov rax, [rax]	; moving the contents of the identifier into rax
	mov [rsp +48], rax	; storing the left hand side into the offset
	mov rbx, 1	; moving a number into register rbx
	mov rax, [rsp + 48]	; fetching the left hand side
	sub rax, rbx	; subtraction expression
	mov [rsp + 48], rax	; Storing the final answer of the expression into its offset
	mov rax, [rsp + 48]	; moving to register rax the contents of the expression
	mov [rsp + 56], rax	; Storing the evaluated argument into ARGLIST's offset
	mov rcx, rsp	; Store the current stack pointer into a trivial register (i.e. rcx in this case)
	sub rcx, 96	; Subtract the size of the function (PLUS 1) in order to determine were the function is located on the stack
	mov rax, [rsp + 56]	; Move the contents of the argument into a temporary register
	mov [rcx + 16], rax	; 'Copy' the contents of rax into the parameter's memory address
	call fibonacci	; calling a function
	mov [rsp +80], rax	; storing the left hand side into the offset
	mov rax, 16	; Moving the identifier's offset into rax
	add rax, rsp	; Adding the offset and stack pointer together and storing it back into rax
	mov rax, [rax]	; moving the contents of the identifier into rax
	mov [rsp +64], rax	; storing the left hand side into the offset
	mov rbx, 2	; moving a number into register rbx
	mov rax, [rsp + 64]	; fetching the left hand side
	sub rax, rbx	; subtraction expression
	mov [rsp + 64], rax	; Storing the final answer of the expression into its offset
	mov rax, [rsp + 64]	; moving to register rax the contents of the expression
	mov [rsp + 72], rax	; Storing the evaluated argument into ARGLIST's offset
	mov rcx, rsp	; Store the current stack pointer into a trivial register (i.e. rcx in this case)
	sub rcx, 96	; Subtract the size of the function (PLUS 1) in order to determine were the function is located on the stack
	mov rax, [rsp + 72]	; Move the contents of the argument into a temporary register
	mov [rcx + 16], rax	; 'Copy' the contents of rax into the parameter's memory address
	call fibonacci	; calling a function
	mov rbx, rax	; 
	mov rax, [rsp + 80]	; fetching the left hand side
	add rax, rbx	; addition expression
	mov [rsp + 80], rax	; Storing the final answer of the expression into its offset
	mov rax, [rsp + 80]	; moving to register rax the contents of the expression

	mov rbp, [rsp]	; FUNC end restore old BP
	mov rsp, [rsp+8]	; FUNC end restore old SP
	ret	; return to the caller

	mov rbp, [rsp]	; FUNC end restore old BP
	mov rsp, [rsp+8]	; FUNC end restore old SP
	ret	; return to the caller
maxOfTwoNumbers:	; start of function
	mov r8, rsp	; FUNC header RSP has to be at most RBP
	add r8, -56	; adjust Stack Pointer for Activation record
	mov [r8], rbp	; FUNC header stores old BP
	mov [r8+8], rsp	; FUNC header stores old SP
	mov rsp, r8	; FUNC header new SP

	mov rax, 16	; Moving the identifier's offset into rax
	add rax, rsp	; Adding the offset and stack pointer together and storing it back into rax
	mov rax, [rax]	; moving the contents of the identifier into rax
	mov [rsp +32], rax	; storing the left hand side into the offset
	mov rax, 24	; Moving the identifier's offset into rax
	add rax, rsp	; Adding the offset and stack pointer together and storing it back into rax
	mov rbx, [rax]	; moving the contents of the identifier into rbx
	mov rax, [rsp + 32]	; fetching the left hand side
	cmp rax, rbx	; EXPR greaterthan
	setg al	; sets the last bit in the last byte of the rax register
	mov rbx, 1	; set rbx to one to filter rax
	and rax, rbx	; filter rax by using the 'and' assembly instruction
	mov [rsp + 32], rax	; Storing the final answer of the expression into its offset
	mov rax, [rsp + 32]	; moving to register rax the contents of the expression
	cmp rax, 0	; comparing register rax to 0. If equal, that means that the expression is false
	je _L27	; IF branch out

	mov rax, 16	; Moving the identifier's offset into rax
	add rax, rsp	; Adding the offset and stack pointer together and storing it back into rax
	mov rax, [rax]	; move the contents of the identifier's the memory address into rax

	mov rbp, [rsp]	; FUNC end restore old BP
	mov rsp, [rsp+8]	; FUNC end restore old SP
	ret	; return to the caller
	jmp _L28	; jumping out of the 'if' body

_L27:	; label that will allow us to skip the if's body if the expression is false

_L28:	; Label to exit the else part
	mov rax, 16	; Moving the identifier's offset into rax
	add rax, rsp	; Adding the offset and stack pointer together and storing it back into rax
	mov rax, [rax]	; moving the contents of the identifier into rax
	mov [rsp +40], rax	; storing the left hand side into the offset
	mov rax, 24	; Moving the identifier's offset into rax
	add rax, rsp	; Adding the offset and stack pointer together and storing it back into rax
	mov rbx, [rax]	; moving the contents of the identifier into rbx
	mov rax, [rsp + 40]	; fetching the left hand side
	cmp rax, rbx	; EXPR lessthan
	setl al	; sets the last bit in the last byte of the rax register
	mov rbx, 1	; set rbx to one to filter rax
	and rax, rbx	; filter rax by using the 'and' assembly instruction
	mov [rsp + 40], rax	; Storing the final answer of the expression into its offset
	mov rax, [rsp + 40]	; moving to register rax the contents of the expression
	cmp rax, 0	; comparing register rax to 0. If equal, that means that the expression is false
	je _L29	; IF branch out

	mov rax, 24	; Moving the identifier's offset into rax
	add rax, rsp	; Adding the offset and stack pointer together and storing it back into rax
	mov rax, [rax]	; move the contents of the identifier's the memory address into rax

	mov rbp, [rsp]	; FUNC end restore old BP
	mov rsp, [rsp+8]	; FUNC end restore old SP
	ret	; return to the caller
	jmp _L30	; jumping out of the 'if' body

_L29:	; label that will allow us to skip the if's body if the expression is false

_L30:	; Label to exit the else part
	mov rax, 16	; Moving the identifier's offset into rax
	add rax, rsp	; Adding the offset and stack pointer together and storing it back into rax
	mov rax, [rax]	; moving the contents of the identifier into rax
	mov [rsp +48], rax	; storing the left hand side into the offset
	mov rax, 24	; Moving the identifier's offset into rax
	add rax, rsp	; Adding the offset and stack pointer together and storing it back into rax
	mov rbx, [rax]	; moving the contents of the identifier into rbx
	mov rax, [rsp + 48]	; fetching the left hand side
	cmp rax, rbx	; EXPR equal
	sete al	; sets the last bit in the last byte of the rax register
	mov rbx, 1	; set rbx to one to filter rax
	and rax, rbx	; filter rax by using the 'and' assembly instruction
	mov [rsp + 48], rax	; Storing the final answer of the expression into its offset
	mov rax, [rsp + 48]	; moving to register rax the contents of the expression
	cmp rax, 0	; comparing register rax to 0. If equal, that means that the expression is false
	je _L31	; IF branch out

	mov rax, 16	; Moving the identifier's offset into rax
	add rax, rsp	; Adding the offset and stack pointer together and storing it back into rax
	mov rax, [rax]	; move the contents of the identifier's the memory address into rax

	mov rbp, [rsp]	; FUNC end restore old BP
	mov rsp, [rsp+8]	; FUNC end restore old SP
	ret	; return to the caller
	jmp _L32	; jumping out of the 'if' body

_L31:	; label that will allow us to skip the if's body if the expression is false

_L32:	; Label to exit the else part

	mov rbp, [rsp]	; FUNC end restore old BP
	mov rsp, [rsp+8]	; FUNC end restore old SP
	ret	; return to the caller
printGreetingMessage:	; start of function
	mov r8, rsp	; FUNC header RSP has to be at most RBP
	add r8, -32	; adjust Stack Pointer for Activation record
	mov [r8], rbp	; FUNC header stores old BP
	mov [r8+8], rsp	; FUNC header stores old SP
	mov rsp, r8	; FUNC header new SP

	mov rax, 10	; moving a number into register rax
	mov [rsp + 24], rax	; storing the final value of EXPRSTMT into its offset
	mov rax, 16	; Moving the identifier's offset into rax
	add rax, rsp	; Adding the offset and stack pointer together and storing it back into rax
	mov rbx, [24 + rsp]	; Storing the final value of the expression into a temporary register
	mov [rax], rbx	; Store the value into the identifier's memory address
	PRINT_STRING _L2	; print a string
	NEWLINE	; standard Write a NEWLINE
	PRINT_STRING _L3	; print a string
	NEWLINE	; standard Write a NEWLINE
	mov rax, 16	; Moving the identifier's offset into rax
	add rax, rsp	; Adding the offset and stack pointer together and storing it back into rax
	mov rsi, [rax]	; move the contents of the identifier's the memory address into rsi
	PRINT_DEC 8, rsi	; standard Write a value
	NEWLINE	; standard Write a NEWLINE
	PRINT_STRING _L4	; print a string
	NEWLINE	; standard Write a NEWLINE

	mov rbp, [rsp]	; FUNC end restore old BP
	mov rsp, [rsp+8]	; FUNC end restore old SP
	ret	; return to the caller
checkArithmeticOperations:	; start of function
	mov r8, rsp	; FUNC header RSP has to be at most RBP
	add r8, -136	; adjust Stack Pointer for Activation record
	mov [r8], rbp	; FUNC header stores old BP
	mov [r8+8], rsp	; FUNC header stores old SP
	mov rsp, r8	; FUNC header new SP

	mov rax, 10	; moving a number into register rax
	mov [rsp + 24], rax	; storing the final value of EXPRSTMT into its offset
	mov rax, globalSOne	; storing the memory address of the global variable into rax
	mov rbx, [24 + rsp]	; Storing the final value of the expression into a temporary register
	mov [rax], rbx	; Store the value into the identifier's memory address
	PRINT_STRING _L5	; print a string
	NEWLINE	; standard Write a NEWLINE
	PRINT_STRING _L6	; print a string
	NEWLINE	; standard Write a NEWLINE
	PRINT_STRING _L7	; print a string
	NEWLINE	; standard Write a NEWLINE
	mov rax, globalSOne	; storing the memory address of the global variable into rax
	mov rax, [rax]	; move the contents of the identifier's the memory address into rax
	mov [rsp + 32], rax	; Storing the evaluated argument into ARGLIST's offset
	mov rcx, rsp	; Store the current stack pointer into a trivial register (i.e. rcx in this case)
	sub rcx, 48	; Subtract the size of the function (PLUS 1) in order to determine were the function is located on the stack
	mov rax, [rsp + 32]	; Move the contents of the argument into a temporary register
	mov [rcx + 16], rax	; 'Copy' the contents of rax into the parameter's memory address
	call squareOfNumber	; calling a function
	mov [rsp + 40], rax	; storing the final value of EXPRSTMT into its offset
	mov rax, 16	; Moving the identifier's offset into rax
	add rax, rsp	; Adding the offset and stack pointer together and storing it back into rax
	mov rbx, [40 + rsp]	; Storing the final value of the expression into a temporary register
	mov [rax], rbx	; Store the value into the identifier's memory address
	mov rax, 16	; Moving the identifier's offset into rax
	add rax, rsp	; Adding the offset and stack pointer together and storing it back into rax
	mov rsi, [rax]	; move the contents of the identifier's the memory address into rsi
	PRINT_DEC 8, rsi	; standard Write a value
	NEWLINE	; standard Write a NEWLINE
	PRINT_STRING _L8	; print a string
	NEWLINE	; standard Write a NEWLINE
	PRINT_STRING _L9	; print a string
	NEWLINE	; standard Write a NEWLINE
	PRINT_STRING _L10	; print a string
	NEWLINE	; standard Write a NEWLINE
	PRINT_STRING _L11	; print a string
	NEWLINE	; standard Write a NEWLINE
	mov rax, 16	; Moving the identifier's offset into rax
	add rax, rsp	; Adding the offset and stack pointer together and storing it back into rax
	mov rax, [rax]	; moving the contents of the identifier into rax
	mov [rsp +48], rax	; storing the left hand side into the offset
	mov rbx, 50	; moving a number into register rbx
	mov rax, [rsp + 48]	; fetching the left hand side
	imul rax, rbx	; multiply expression
	mov [rsp + 48], rax	; Storing the final answer of the expression into its offset
	mov rax, [rsp + 48]	; moving the contents of the expression into rax
	mov [rsp +64], rax	; storing the left hand side into the offset
	mov rax, globalSOne	; storing the memory address of the global variable into rax
	mov rax, [rax]	; moving the contents of the identifier into rax
	mov [rsp +56], rax	; storing the left hand side into the offset
	mov rbx, 10	; moving a number into register rbx
	mov rax, [rsp + 56]	; fetching the left hand side
	xor rdx, rdx	; xor rdx to clear the register
	idiv rbx	; dividing rax by rbx
	mov [rsp + 56], rax	; Storing the final answer of the expression into its offset
	mov rbx, [rsp + 56]	; moving the contents of the expression into rbx
	mov rax, [rsp + 64]	; fetching the left hand side
	add rax, rbx	; addition expression
	mov [rsp + 64], rax	; Storing the final answer of the expression into its offset
	mov rax, [rsp + 64]	; moving the contents of the expression into rax
	mov [rsp +72], rax	; storing the left hand side into the offset
	mov rbx, 2	; moving a number into register rbx
	mov rax, [rsp + 72]	; fetching the left hand side
	sub rax, rbx	; subtraction expression
	mov [rsp + 72], rax	; Storing the final answer of the expression into its offset
	mov rax, [rsp + 72]	; moving the contents of the expression into rax
	mov [rsp +80], rax	; storing the left hand side into the offset
	mov rbx, 5	; moving a number into register rbx
	mov rax, [rsp + 80]	; fetching the left hand side
	imul rax, rbx	; multiply expression
	mov [rsp + 80], rax	; Storing the final answer of the expression into its offset
	mov rsi, [rsp + 80]	; moving to register rsi the contents of the expression
	PRINT_DEC 8, rsi	; standard Write a value
	NEWLINE	; standard Write a NEWLINE
	PRINT_STRING _L12	; print a string
	NEWLINE	; standard Write a NEWLINE
	mov rax, 16	; Moving the identifier's offset into rax
	add rax, rsp	; Adding the offset and stack pointer together and storing it back into rax
	mov rax, [rax]	; moving the contents of the identifier into rax
	mov [rsp +88], rax	; storing the left hand side into the offset
	mov rbx, 50	; moving a number into register rbx
	mov rax, [rsp + 88]	; fetching the left hand side
	imul rax, rbx	; multiply expression
	mov [rsp + 88], rax	; Storing the final answer of the expression into its offset
	mov rax, [rsp + 88]	; moving the contents of the expression into rax
	mov [rsp +104], rax	; storing the left hand side into the offset
	mov rax, globalSOne	; storing the memory address of the global variable into rax
	mov rax, [rax]	; moving the contents of the identifier into rax
	mov [rsp +96], rax	; storing the left hand side into the offset
	mov rbx, 10	; moving a number into register rbx
	mov rax, [rsp + 96]	; fetching the left hand side
	xor rdx, rdx	; xor rdx to clear the register
	idiv rbx	; dividing rax by rbx
	mov [rsp + 96], rax	; Storing the final answer of the expression into its offset
	mov rbx, [rsp + 96]	; moving the contents of the expression into rbx
	mov rax, [rsp + 104]	; fetching the left hand side
	add rax, rbx	; addition expression
	mov [rsp + 104], rax	; Storing the final answer of the expression into its offset
	mov rax, [rsp + 104]	; moving the contents of the expression into rax
	mov [rsp +112], rax	; storing the left hand side into the offset
	mov rbx, 2	; moving a number into register rbx
	mov rax, [rsp + 112]	; fetching the left hand side
	sub rax, rbx	; subtraction expression
	mov [rsp + 112], rax	; Storing the final answer of the expression into its offset
	mov rax, [rsp + 112]	; moving the contents of the expression into rax
	mov [rsp +120], rax	; storing the left hand side into the offset
	mov rbx, 5	; moving a number into register rbx
	mov rax, [rsp + 120]	; fetching the left hand side
	imul rax, rbx	; multiply expression
	mov [rsp + 120], rax	; Storing the final answer of the expression into its offset
	mov rax, [rsp + 120]	; moving the contents of the expression into rax
	mov [rsp +128], rax	; storing the left hand side into the offset
	mov rbx, 24995	; moving a number into register rbx
	mov rax, [rsp + 128]	; fetching the left hand side
	cmp rax, rbx	; EXPR equal
	sete al	; sets the last bit in the last byte of the rax register
	mov rbx, 1	; set rbx to one to filter rax
	and rax, rbx	; filter rax by using the 'and' assembly instruction
	mov [rsp + 128], rax	; Storing the final answer of the expression into its offset
	mov rax, [rsp + 128]	; moving to register rax the contents of the expression
	cmp rax, 0	; comparing register rax to 0. If equal, that means that the expression is false
	je _L33	; IF branch out

	PRINT_STRING _L13	; print a string
	NEWLINE	; standard Write a NEWLINE
	jmp _L34	; jumping out of the 'if' body

_L33:	; label that will allow us to skip the if's body if the expression is false
	PRINT_STRING _L14	; print a string
	NEWLINE	; standard Write a NEWLINE

_L34:	; Label to exit the else part
	PRINT_STRING _L15	; print a string
	NEWLINE	; standard Write a NEWLINE

	mov rbp, [rsp]	; FUNC end restore old BP
	mov rsp, [rsp+8]	; FUNC end restore old SP
	ret	; return to the caller
main:	; start of function
	mov rbp, rsp 	; SPECIAL RSP to RSB for MAIN only
	mov r8, rsp	; FUNC header RSP has to be at most RBP
	add r8, -112	; adjust Stack Pointer for Activation record
	mov [r8], rbp	; FUNC header stores old BP
	mov [r8+8], rsp	; FUNC header stores old SP
	mov rsp, r8	; FUNC header new SP

	mov rax, 0	; moving a number into register rax
	mov [rsp + 32], rax	; storing the final value of EXPRSTMT into its offset
	mov rax, 16	; Moving the identifier's offset into rax
	add rax, rsp	; Adding the offset and stack pointer together and storing it back into rax
	mov rbx, [32 + rsp]	; Storing the final value of the expression into a temporary register
	mov [rax], rbx	; Store the value into the identifier's memory address
	mov rcx, rsp	; Store the current stack pointer into a trivial register (i.e. rcx in this case)
	sub rcx, 40	; Subtract the size of the function (PLUS 1) in order to determine were the function is located on the stack
	call printGreetingMessage	; calling a function
	mov [rsp + 40], rax	; storing the final value of EXPRSTMT into its offset
	mov rcx, rsp	; Store the current stack pointer into a trivial register (i.e. rcx in this case)
	sub rcx, 144	; Subtract the size of the function (PLUS 1) in order to determine were the function is located on the stack
	call checkArithmeticOperations	; calling a function
	mov [rsp + 48], rax	; storing the final value of EXPRSTMT into its offset
	PRINT_STRING _L16	; print a string
	NEWLINE	; standard Write a NEWLINE
	PRINT_STRING _L17	; print a string
	NEWLINE	; standard Write a NEWLINE

_L35:	; start of while
	mov rax, 16	; Moving the identifier's offset into rax
	add rax, rsp	; Adding the offset and stack pointer together and storing it back into rax
	mov rax, [rax]	; moving the contents of the identifier into rax
	mov [rsp +56], rax	; storing the left hand side into the offset
	mov rbx, 10	; moving a number into register rbx
	mov rax, [rsp + 56]	; fetching the left hand side
	cmp rax, rbx	; EXPR lessthan
	setl al	; sets the last bit in the last byte of the rax register
	mov rbx, 1	; set rbx to one to filter rax
	and rax, rbx	; filter rax by using the 'and' assembly instruction
	mov [rsp + 56], rax	; Storing the final answer of the expression into its offset
	mov rax, [rsp + 56]	; moving to register rax the contents of the expression
	cmp rax, 0	; comparing register rax to 0. If equal, that means that the expression is false
	je _L36	; while branch out

	mov rax, 16	; Moving the identifier's offset into rax
	add rax, rsp	; Adding the offset and stack pointer together and storing it back into rax
	mov rax, [rax]	; moving the contents of the identifier into rax
	mov [rsp +64], rax	; storing the left hand side into the offset
	mov rbx, 1	; moving a number into register rbx
	mov rax, [rsp + 64]	; fetching the left hand side
	add rax, rbx	; addition expression
	mov [rsp + 64], rax	; Storing the final answer of the expression into its offset
	mov rax, [rsp + 64]	; moving to register rax the contents of the expression
	mov [rsp + 72], rax	; Storing the evaluated argument into ARGLIST's offset
	mov rcx, rsp	; Store the current stack pointer into a trivial register (i.e. rcx in this case)
	sub rcx, 96	; Subtract the size of the function (PLUS 1) in order to determine were the function is located on the stack
	mov rax, [rsp + 72]	; Move the contents of the argument into a temporary register
	mov [rcx + 16], rax	; 'Copy' the contents of rax into the parameter's memory address
	call fibonacci	; calling a function
	mov [rsp + 80], rax	; storing the final value of EXPRSTMT into its offset
	mov rax, 16	; Moving the identifier's offset into rax
	add rax, rsp	; Adding the offset and stack pointer together and storing it back into rax
	mov rax, [rax]	; move the contents of the identifier's the memory address into rax
	shl rax, 3	; shift rax left by 3 (i.e. this will simulate multiplying by 8)
	mov rbx, rax	; Storing the internal offset of an array into rbx
	mov rax, globalArray	; storing the memory address of the global variable into rax
	add rax, rbx	; adding the internal offset to the regular offset if we encounter an array
	mov rbx, [80 + rsp]	; Storing the final value of the expression into a temporary register
	mov [rax], rbx	; Store the value into the identifier's memory address
	mov rax, 16	; Moving the identifier's offset into rax
	add rax, rsp	; Adding the offset and stack pointer together and storing it back into rax
	mov rax, [rax]	; moving the contents of the identifier into rax
	mov [rsp +88], rax	; storing the left hand side into the offset
	mov rbx, 1	; moving a number into register rbx
	mov rax, [rsp + 88]	; fetching the left hand side
	add rax, rbx	; addition expression
	mov [rsp + 88], rax	; Storing the final answer of the expression into its offset
	mov rax, [rsp + 88]	; moving to register rax the contents of the expression
	mov [rsp + 96], rax	; storing the final value of EXPRSTMT into its offset
	mov rax, 16	; Moving the identifier's offset into rax
	add rax, rsp	; Adding the offset and stack pointer together and storing it back into rax
	mov rbx, [96 + rsp]	; Storing the final value of the expression into a temporary register
	mov [rax], rbx	; Store the value into the identifier's memory address
	jmp _L35	; jump back to check expression

_L36:	; end of while
	mov rax, 0	; moving a number into register rax
	mov [rsp + 64], rax	; storing the final value of EXPRSTMT into its offset
	mov rax, 16	; Moving the identifier's offset into rax
	add rax, rsp	; Adding the offset and stack pointer together and storing it back into rax
	mov rbx, [64 + rsp]	; Storing the final value of the expression into a temporary register
	mov [rax], rbx	; Store the value into the identifier's memory address

_L37:	; start of while
	mov rax, 16	; Moving the identifier's offset into rax
	add rax, rsp	; Adding the offset and stack pointer together and storing it back into rax
	mov rax, [rax]	; moving the contents of the identifier into rax
	mov [rsp +72], rax	; storing the left hand side into the offset
	mov rbx, 10	; moving a number into register rbx
	mov rax, [rsp + 72]	; fetching the left hand side
	cmp rax, rbx	; EXPR lessthan
	setl al	; sets the last bit in the last byte of the rax register
	mov rbx, 1	; set rbx to one to filter rax
	and rax, rbx	; filter rax by using the 'and' assembly instruction
	mov [rsp + 72], rax	; Storing the final answer of the expression into its offset
	mov rax, [rsp + 72]	; moving to register rax the contents of the expression
	cmp rax, 0	; comparing register rax to 0. If equal, that means that the expression is false
	je _L38	; while branch out

	mov rax, 16	; Moving the identifier's offset into rax
	add rax, rsp	; Adding the offset and stack pointer together and storing it back into rax
	mov rax, [rax]	; move the contents of the identifier's the memory address into rax
	shl rax, 3	; shift rax left by 3 (i.e. this will simulate multiplying by 8)
	mov rbx, rax	; Storing the internal offset of an array into rbx
	mov rax, globalArray	; storing the memory address of the global variable into rax
	add rax, rbx	; adding the internal offset to the regular offset if we encounter an array
	mov rsi, [rax]	; move the contents of the identifier's the memory address into rsi
	PRINT_DEC 8, rsi	; standard Write a value
	NEWLINE	; standard Write a NEWLINE
	mov rax, 16	; Moving the identifier's offset into rax
	add rax, rsp	; Adding the offset and stack pointer together and storing it back into rax
	mov rax, [rax]	; moving the contents of the identifier into rax
	mov [rsp +80], rax	; storing the left hand side into the offset
	mov rbx, 1	; moving a number into register rbx
	mov rax, [rsp + 80]	; fetching the left hand side
	add rax, rbx	; addition expression
	mov [rsp + 80], rax	; Storing the final answer of the expression into its offset
	mov rax, [rsp + 80]	; moving to register rax the contents of the expression
	mov [rsp + 88], rax	; storing the final value of EXPRSTMT into its offset
	mov rax, 16	; Moving the identifier's offset into rax
	add rax, rsp	; Adding the offset and stack pointer together and storing it back into rax
	mov rbx, [88 + rsp]	; Storing the final value of the expression into a temporary register
	mov [rax], rbx	; Store the value into the identifier's memory address
	jmp _L37	; jump back to check expression

_L38:	; end of while
	PRINT_STRING _L18	; print a string
	NEWLINE	; standard Write a NEWLINE
	mov rcx, rsp	; Store the current stack pointer into a trivial register (i.e. rcx in this case)
	sub rcx, 24	; Subtract the size of the function (PLUS 1) in order to determine were the function is located on the stack
	call readANumbersFromUser	; calling a function
	mov [rsp + 80], rax	; storing the final value of EXPRSTMT into its offset
	mov rax, globalSOne	; storing the memory address of the global variable into rax
	mov rax, [rax]	; move the contents of the identifier's the memory address into rax
	mov [rsp + 96], rax	; Storing the evaluated argument into ARGLIST's offset
	mov rax, globalSTwo	; storing the memory address of the global variable into rax
	mov rax, [rax]	; move the contents of the identifier's the memory address into rax
	mov [rsp + 88], rax	; Storing the evaluated argument into ARGLIST's offset
	mov rcx, rsp	; Store the current stack pointer into a trivial register (i.e. rcx in this case)
	sub rcx, 64	; Subtract the size of the function (PLUS 1) in order to determine were the function is located on the stack
	mov rax, [rsp + 96]	; Move the contents of the argument into a temporary register
	mov [rcx + 16], rax	; 'Copy' the contents of rax into the parameter's memory address
	mov rax, [rsp + 88]	; Move the contents of the argument into a temporary register
	mov [rcx + 24], rax	; 'Copy' the contents of rax into the parameter's memory address
	call maxOfTwoNumbers	; calling a function
	mov [rsp + 104], rax	; storing the final value of EXPRSTMT into its offset
	mov rax, 24	; Moving the identifier's offset into rax
	add rax, rsp	; Adding the offset and stack pointer together and storing it back into rax
	mov rbx, [104 + rsp]	; Storing the final value of the expression into a temporary register
	mov [rax], rbx	; Store the value into the identifier's memory address
	PRINT_STRING _L19	; print a string
	NEWLINE	; standard Write a NEWLINE
	mov rax, 24	; Moving the identifier's offset into rax
	add rax, rsp	; Adding the offset and stack pointer together and storing it back into rax
	mov rsi, [rax]	; move the contents of the identifier's the memory address into rsi
	PRINT_DEC 8, rsi	; standard Write a value
	NEWLINE	; standard Write a NEWLINE
	PRINT_STRING _L20	; print a string
	NEWLINE	; standard Write a NEWLINE

	mov rbp, [rsp]	; FUNC end restore old BP
	mov rsp, [rsp+8]	; FUNC end restore old SP
	mov rsp, rbp	; stack and BP need to be same on exit for main
	ret	; return to the caller
