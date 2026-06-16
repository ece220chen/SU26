;set up memory as following
;Addr	Content
;x5001	x6001
;...
;x6001	x7001
;x6002  x7002

.ORIG x3000
;;Using LD, LDI, LDR, LEA
LD  R6, LABEL
LDI R6, LABEL
LDR R2, R6, #1
LEA R2, LABEL
HALT
LABEL .FILL x5001
.END

