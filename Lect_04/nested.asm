;Nested subroutine example

;;depending on whether we are using caller-saved or callee-saved
;;the location of saving/restoring regs could be different

.ORIG x3000
AND R1, R1, #0			;init R1
AND R2, R2, #0			;init R2
ADD R1, R1, #5			;set R1=5
ADD R2, R2, #2			;set R2=2
JSR SUBTR			;call SUBTR to calculate R1-R2 
ADD R6, R0, #0			;copy result to R6
HALT

;SUBTR subroutine computes R1-R2
;IN: R1, R2
;OUT: R0 <- R1 - R2
SUBTR
	ST R3, SAVE_R3		;callee-saved R3
      	ADD R3, R2, #0
	ST R7, SAVE_R7		;caller-saved R7 (PC value) before JSR again
	JSR NEGATE		;R3 = -R2	
      	ADD R0, R1, R3          ;R0 <- R1-R2
	LD R7, SAVE_R7		;caller restore original R7 value
	LD R3, SAVE_R3		;callee restore original R3 value
      	RET

;NEGATE subroutine negates an input
;IN: R3
;OUT: R3
NEGATE
	NOT R3, R3
	ADD R3, R3, #1
	RET

SAVE_R3 .BLKW #1 ;use a label to save R3 in SUBTR
SAVE_R7 .BLKW #1 ;use a label to save R7

.END
