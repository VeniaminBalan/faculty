
org 100h

.data

rez db 0
     
 .code
 

MOV AH,1     ;Citire nr:                                                
INT 21h

MOV rez,AL   ;Adaugare in var
SUB rez,30h  ;Ascii -> decimal
   
MOV AH,1     ;Citire nr: 
INT 21h

ADD rez,AL   ;Adaugare in var
SUB rez,30h  ;Ascii -> decimal

MOV AH,1     ;Citire nr: 
INT 21h

ADD rez,AL   ;Adaugare in var
SUB rez,30h  ;Ascii -> decimal

MOV DL, 10
MOV AH,2     ;new line
INT 21h 
  
MOV DL, 13
MOV AH,2     ;new line from start
INT 21h

MOV DL,rez
ADD DL,30h   ;decimal -< Ascii

MOV AH,2     ;Afisare
INT 21h


ret