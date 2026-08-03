;This code is taken from Prof. Moon's lecture.
;It only works in Prof. Hu's web-based LC-3 simulator.
;Go to https://courses.grainger.illinois.edu/ece220/sp2020/lc3web/index.html

.ORIG	x3000
	LEA	R0,ISR_KB	
	STI	R0,KBINTV 	;load ISR address to INTV
	LD	R3,EN_IE	
	STI	R3,KBSR 	;set IE bit of KBSR

AGAIN	LD	R0,NUM2 	;infinite loop printing '2'
	OUT
	BRnzp	AGAIN

ISR_KB	ST	R0,SaveR0 	;callee-save
	ST	R7,SaveR7 	
	LDI	R0,KBDR 	;read a char from KB and clear ready bit
	OUT
	LD	R0,SaveR0	;callee-restore
	LD	R7,SaveR7	
	HALT
	;RTI

EN_IE	.FILL	x4000 ;enable IE 0100_0000_0000_0000
NUM2	.FILL	x0032 ;'2'
KBSR	.FILL	xFE00
KBDR	.FILL	xFE02
KBINTV	.FILL	x0180 ;INT vector table address for keyboard
SaveR0	.BLKW	#1
SaveR7  .BLKW   #1
.END	
