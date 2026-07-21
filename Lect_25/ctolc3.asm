;;main -> printlist(head) -> printlist(head->next)
;;;     callee setup/teardown
;;;     in its function logic: caller setup/teardown for the recursive call

.ORIG x3000

MAIN
  LD R5, RSTACK		;set R5 to bottom of RTS
  LD R6, RSTACK		;set R6 to the same address
  LD R0, HEAD		;load value of HEAD to R0
  STR R0, R6, #0	;set up local variable 'head' in main
  ADD R6, R6, #-1	;caller setup: push callee's arg to RTS
  LDR R1, R5, #0	;load 'head' from RTS
  STR R1, R6, #0	;push 'head'(argument) to RTS
  JSR PRINT_LIST	;transfer control to callee
  ADD R6, R6, #2	;caller tear-down: pop callee's R.V. and arg
  HALT

HEAD .FILL x4004
RSTACK .FILL x7000

PRINT_LIST
;;Part 1 - callee setup: push bookkeeping info
ADD R6, R6, #-3
STR R5, R6, #0
STR R7, R6, #1
ADD R5, R6, #-1 ;update R5

;;Part 2 - implement function logic
;if(head == NULL) skip to the end;
LDR R1, R5, #4 ;load head to R1
BRz TEAR_DOWN
;printf("%c", head->data);
LDR R0, R1, #0 ;R0=head->data
OUT

;printlist(head->next);
;caller set-up
LDR R2, R1, #1 ;R2=head->next
ADD R6, R6, #-1
STR R2, R6, #0 ;push arg to RTS
JSR PRINT_LIST
;caller tear-down: pop R.V. & arg
ADD R6, R6, #2

;skip to here if head is null
;;Part 3 - callee tear down: prepare to return
TEAR_DOWN
LDR R5, R6, #0
LDR R7, R6, #1
ADD R6, R6, #2
RET


.END
