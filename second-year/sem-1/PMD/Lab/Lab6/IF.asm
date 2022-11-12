org 100h 

.data 
    A db 0 
    B db 0
    
.code


MOV AH, 1
INT 21h 
MOV A, AL

MOV AH, 1
INT 21h 
MOV B, AL

MOV DL, 10
MOV AH,2     ;new line
INT 21h 
  
MOV DL, 13
MOV AH,2     ;new line from start
INT 21h

MOV AH, A
MOV BH, B

CMP AH, BH

JG ELSE   
; JZ <Label> - jump if zero to last opertation
; JG <Label> - jump if greater
; JMP <Label> - jamp to label

IF_TRUE:    
    MOV DL, B 
    JMP IF_END   
    
ELSE:    
    MOV DL, A            
    JMP IF_END 
     
IF_END:  
    MOV AH,2   
    INT 21h 

ret