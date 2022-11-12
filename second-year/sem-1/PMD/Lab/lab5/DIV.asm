
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
  
MOV A, Al    ; A = AL 
SUB A, 30h   


MOV AH,1     ;Citire B                                                
INT 21h

MOV B, AL    ; B = AL
SUB B, 30h 

MOV AX,0 
 
MOV Al, A
MOV Bl, B

DIV Bl 
MOV rez, AX  

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

MOV DL, 10
MOV AH,2     ;new line
INT 21h 
  
MOV DL, 13
MOV AH,2     ;new line from start
INT 21h
 
MOV AX, rez  ; rescriem in AX rezultatul impartirii
 
MOV DL,AL    ;pregatim catul pentru afisare
ADD DL,30h   ;decimal -> Ascii

MOV AH,2     ;Afisare catul
INT 21h   
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;  
                                    
MOV DL, 44  ; pregatim ' , ' pentru afisare

MOV AH,2     ;Afisare  ' , '
INT 21h                                    
                                    
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; 

MOV AX, rez  ; rescriem in AX rezultatul impartirii

MOV DL,AH    ;pregatim restul pentru afisare
ADD DL,30h   ;decimal -< Ascii

MOV AH,2     ;Afisare restul
INT 21h
 
ret




