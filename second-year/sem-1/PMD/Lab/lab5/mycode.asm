
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

.data
    A db 0
    B db 0
    rez dw 0
  
.code  

MOV AH,1     ;Citire A                                               
INT 21h
  
MOV A, AL
SUB A, 30h   ;

;MOV Al, 0

MOV AH,1     ;Citire B                                                
INT 21h

MOV B, AL
SUB B, 30h 
 
 
MOV Al, A
MOV Bl, B

MUL Bl 
MOV rez, AX

ret




