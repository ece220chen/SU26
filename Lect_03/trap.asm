.ORIG x3000

AND R0, R0, #0
ADD R0, R0, #3	;init R0 and set it to 3
ADD R7, R0, #2	;set R7 to 5
ADD R0, R0, #1	;increment R0
ADD R7, R7, #1	;increment R7

IN

ADD R0, R0, #1	;increment R0
ADD R7, R7, #1	;increment R7

HALT

.END
