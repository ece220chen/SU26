.ORIG x3000
;;Lecture1 Examples
; 1. initialize a register to zero
AND R1, R1, #0 ;R1=0
ADD R1, R1, #8 ;R1=8

; 2. copy from one register to another
;AND R2, R1, R1 ; option 1
ADD R2, R1, #0 ; option 2

; 3. compute 8 - 2
;option 1 - add negative two
;ADD R2, R2, #-2 ;R2=R2-2
;option 2
AND R3, R3, #0
ADD R3, R3, #2 ;R3=2
NOT R3, R3
ADD R3, R3, #1 ;R3=-2
ADD R2, R2, R3 ;R2=8-2

; 4. compute 6 x 4
;option 1 - use a loop
LD R1, operand_1 ;R1=6
LD R2, operand_2 ;R2=4
AND R4, R4, #0 ;R4=0 used as result
MULT_LOOP
	ADD R4, R4, R1 ;R4=R4+R1
	ADD R2, R2, #-1;R2=R2-1
	BRp MULT_LOOP
;option 2 - add a number to itself (left shift)
;LD R1, operand_1 ;R1=6
;ADD R1, R1, R1
;ADD R1, R1, R1

HALT

operand_1	.FILL x0006
operand_2	.FILL x0004

.END
