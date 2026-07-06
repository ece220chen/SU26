;; main prog 
.ORIG x3000
MAIN
	LD R5, RSTACK	;set R5 to point to addr x4000
	LD R6, RSTACK	;set R6 to point to addr x4000
	LD R0, NUMBER	;set R0 to x0005 
	STR R0, R6, #0	;push number to stack (at addr x4000)
	ADD R6, R6, #-1	;push answer to stack (at addr x3FFF)
	; answer (x3FFF) <-R6
	; number (x4000) <-R5

        ; 1. Caller setup (push callee’s argument onto the RTS)
   	; push number
	LDR R1, R5, #0 ;load number into R1
	STR R1, R6, #-1;store it to RTS
	ADD R6, R6, #-1;update R6

        ; 2. Caller pass control to callee
	JSR FACTORIAL

        ; 7. Caller teardown 
        ; (pop callee’s return value and argument from the RTS)  
	; load return value at top of stack (R6) 
	LDR R1, R6, #0 ;load R.V. to R1
	; perform assignment: answer = Fact(number)
	STR R1, R5, #-1;store R.V. to answer
   	; pop return value and argument
	ADD R6, R6, #2

	HALT

NUMBER 	.FILL	x0005	
RSTACK	.FILL 	x4000


FACTORIAL
	; 3. Callee setup 
	; (push bookkeeping info & local variables onto the RTS)
	; leave space for return value
	ADD R6, R6, #-1 ;reserve space
	; push return address (R7)
	STR R7, R6, #-1 ;store R7 to R.A.
	ADD R6, R6, #-1 ;update R6
	; push caller’s frame pointer (R5)
	STR R5, R6, #-1 ;store R5 to C.F.P
	ADD R6, R6, #-1 ; update R6
	; set new frame pointer
	ADD R5, R6, #-1 ;update R5
	; push local variables
	ADD R6, R6, #-2 ;update R6
	AND R1, R1, #0
	ADD R1, R1, #1  ;set R1=1
	STR R1, R5, #-1 ;push value to RTS

	; 4. Execute function 
	; (function logic omitted here for simplicity)

	; 5. Callee teardown 
	; (pop local variables, C.F.P., and return addr from the RTS) 
	; copy result into return value
	LDR R1, R5, #-1 ;get result to R1	        
	STR R1, R5, #3  ;store result to R.V.

	; pop local variables	
	ADD R6, R6, #2 ;pop both
	; pop caller’s frame pointer (into R5)
	LDR R5, R6, #0
	ADD R6, R6, #1
	; pop return address (into R7)
	LDR R7, R6, #0
	ADD R6, R6, #1
	; 6. Return to caller 
	; (R6 should be pointing to return value)
	RET
.END
