;5. Write an assembly language program to get nth number from the user and sum the odd numbers from 1 to nth term and display sum. [sum = n2]

DATA    SEGMENT  
    MSG1    DB "Enter n for the sum of first n odd numbers (2 digit hex): $"
    MSG2    DB 0DH, 0AH, "Total sum(in hex): $"
    SUM     DD 0  
DATA    ENDS  
  
CODE    SEGMENT  
    ASSUME CS:CODE, DS:DATA  
  
START:  
    MOV     AX, DATA  
    MOV     DS, AX   

    MOV     AH, 09H  
    LEA     DX, MSG1  
    INT     21H

    CALL    GET_8       ;Stores an 8 bit number in AL 
    
    MUL     AL
    
    LEA     SI, SUM
    
    MOV     [SI], AX
    
    
    MOV     AH, 09H  
    LEA     DX, MSG2  
    INT     21H
                 
    INC     SI                
    CALL    PUT_8
    DEC     SI
    CALL    PUT_8
    
           
    MOV     AX, 004CH       
    INT     21H

PROC    GET_8
      
        PUSH    CX
        MOV     AH, 01H
        INT     21H
        
        SUB     AL, 30H
        CMP     AL, 09H
        JLE     G1
        SUB     AL, 07H
G1:     MOV     CL, 04H
        ROL     AL, CL
        MOV     CH, AL
 
 
        MOV     AH, 01H
        INT     21H
        
        SUB     AL, 30H
        CMP     AL, 09H
        JLE     G2
        SUB     AL, 07H
G2:     ADD     AL, CH
        POP     CX
        
        RET

ENDP    GET_8

PROC    PUT_8
      
        PUSH    CX
        MOV     AL, [SI]
        AND     AL, 0F0H
        MOV     CL, 04H
        ROL     AL, CL
        ADD     AL, 30H
        CMP     AL, 39H
        JLE     P1
        ADD     AL, 07H
P1:     MOV     AH, 02H
        MOV     DL, AL
        INT     21H
        
        MOV     AL, [SI]
        AND     AL, 0FH
        ADD     AL, 30H
        CMP     AL, 39H
        JLE     P2
        ADD     AL, 07H
P2:     MOV     AH, 02H
        MOV     DL, AL
        INT     21H
        
        POP     CX
        
        RET

ENDP    PUT_8
             

CODE    ENDS  
    END     START
