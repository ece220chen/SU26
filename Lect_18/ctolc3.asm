.ORIG x3000

;;C to LC-3 Conversion with RTS Example: 
;assume the following in main
;int number = 5;
;int answer = Running(number);

;;main code
;;Main's activation record starting at x4000
;;Assume it only has local variables
;answer (x3FFF) <-R6
;number (x4000) <-R5
MAIN
        LD R5, RSTACK   ;set R5 to point to addr x4000
        LD R6, RSTACK   ;set R6 to point to addr x4000
        LD R0, NUMBER   ;set R0 to x0005 
        STR R0, R6, #0  ;push number to stack (at addr x4000)
        ADD R6, R6, #-1 ;push answer to stack (at addr x3FFF)
        ;Caller stack Built-up - push RUNNING's arg to the stack
        ADD R6, R6, #-1
        LDR R0, R5, #0
        STR R0, R6, #0
        ;Pass control to callee - invoke RUNNING subroutine
        JSR RUNNING
        ;Caller stack Tear-down for RUNNING
        LDR R0, R6, #0  ;copy return value to R0
        STR R0, R5, #-1 ;save return value to answer
        ADD R6, R6, #1  ;pop return value from stack
        ADD R6, R6, #1  ;pop argument from stack
        HALT
NUMBER  .FILL   x0005
RSTACK  .FILL   x4000


;;RUNNING Subroutine
RUNNING
;callee set-up of Running(n)’s activation record
;push return value, return address & old frame pointer
ADD R6, R6, #-3
STR R7, R6, #1
STR R5, R6, #0
;;push local variables & update frame pointer
ADD R5, R6, #-1
ADD R6, R6, #-1

;function logic
;;base case (n==1)
LDR R1, R5, #4 ;set R1=n
ADD R0, R1, #-1 ;set R0=n-1
BRz BASE_CASE

;;recursive case
;caller setup for Running(n-1)
;push argument n-1 onto RTS
ADD R6, R6, #-1 ;update R6
STR R0, R6, #0  ;store n-1 to RTS

;call Running(n-1)
JSR RUNNING

;caller tear-down for Running(n-1)
;pop Running(n-1)’s return value to R2
LDR R2, R6, #0 ;R2=Running(n-1)
ADD R6, R6, #1 ;pop R.V.

;pop Running(n-1)’s argument
ADD R6, R6, #1 ;pop arg

;calculate n + Running(n-1)
LDR R1, R5, #4 ;R1=n
ADD R2, R1, R2 ;R2=n+Running(n-1)

;store result in fn
STR R2, R5, #0;

;ready to return
BRnzp RETURN

BASE_CASE
;set fn = 1
STR R1, R5, #0 ;store 1 to fn

RETURN
;set return value
LDR R3, R5, #0 ; R3=fn
STR R3, R5, #3 ; set R.V. to fn

;;callee tear-down of Running(n)’s activation record
;pop local variables
ADD R6, R6, #1 
;pop caller’s frame pointer and return address
LDR R5, R6, #0 ;restore R5 back to its previous value
LDR R7, R6, #1 ;restore R7 back to its previous value
ADD R6, R6, #2 ;update R6
;return to caller
RET

.END
