DATA    SEGMENT  
    MSG1    DB 0DH, 0AH, "Enter number: $"
    MSG2    DB 0DH, 0AH, "After adding these ten single digit number in hex, we get: $"  
DATA    ENDS  

CODE    SEGMENT  
    ASSUME CS:CODE, DS:DATA  

START:
    MOV AX, DATA  
    MOV DS, AX  

    MOV CX, 000AH   ; Loop counter (10 numbers)  
    MOV BL, 00H   ; Sum stored in BL  

ADDITION:
    MOV AH, 09H  
    LEA DX, MSG1  
    INT 21H          ; Print "Enter number: " message  

    MOV AH, 01H      ; Read single character input  
    INT 21H  

    SUB AL, 30H      ; Convert ASCII to decimal (0-9) 
    ADD BL, AL       ; Add to BL  

    LOOP ADDITION    ; Repeat 10 times 
    
    ;Displaying the sum message
    LEA DX, MSG2     
    MOV AH, 09H
    INT 21H

    ;Displaying the higher nibble
    MOV AL, BL
    AND AL, 0F0H
    MOV CL, 04H
    ROL AL, CL
    ADD AL, 30H

    CMP AL, 40H
    JNC SKIP1

    ADD AL, 07H
SKIP1:
    

    MOV AH, 02H      
    INT 21H
    
    ;Displaying the lower nibble
    MOV AL, BL
    AND AL, 0FH
    ADD AL, 30H

    CMP AL, 40H
    JNC SKIP2

    ADD AL, 07H
SKIP2:
    

    MOV AH, 02H     
    INT 21H



    MOV AX, 4C00H  
    INT 21H  

CODE    ENDS  
    END START  
