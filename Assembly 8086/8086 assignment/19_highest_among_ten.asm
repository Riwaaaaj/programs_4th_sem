;19. Write an assembly language program for 8086 to find the largest number among 10 numbers stored as array.
DATA    SEGMENT  
        
        LINB    DB 0DH, 0AH, " $"
        MSG1    DB 0DH, 0AH, "Please enter the numbers: $"
        MSG2    DB ": $"
        MSG4    DB 0DH, 0AH, "Highest:   $"
        
        ARRN    DB 10 DUP (00H)
        LEN     DB 0AH
        HNUM    DB 00H
DATA    ENDS

CODE    SEGMENT
        ASSUME CS:CODE, DS:DATA

START:
        MOV     AX, DATA
        MOV     DS, AX
             
             
        MOV     AH, 09H
        LEA     DX, MSG1    ;
        INT     21H
        
        LEA     SI, ARRN
        MOV     CL, LEN
        MOV     BL, 01H
        
BK1:    MOV     AH, 09H
        LEA     DX, LINB
        INT     21H
        MOV     AH, 02H
        MOV     DL, BL
        ADD     DL, 30H
        INT     21H
        MOV     AH, 09H
        LEA     DX, MSG2
        INT     21H

        MOV     BH, AL
        MOV     AL, AH
        INC     AH 

        MOV     BH, AL
        MOV     AL, BL
        ADD     AL, 01H
        DAA
        MOV     BL, AL
        MOV     AL, BH


        CALL    GET
        MOV     [SI], AL
        INC     SI
        DEC     CL
        JNZ     BK1
        
CALC:   LEA     SI, ARRN
        MOV     CL, LEN
        MOV     AL, HNUM
        
BCK2:   CMP     AL, [SI]
        JNC    SKP2
        MOV     AL, [SI]
SKP2:   INC     SI
        DEC     CL
        JNZ     BCK2
        MOV     HNUM, AL
SHOW:   MOV     AH, 09H
        LEA     DX, MSG4
        INT     21H
        LEA     SI, HNUM
        CALL    PUT
        
        
EXIT:   MOV     AH, 4CH 
        INT     21H
        
        
PROC    GET
      
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

ENDP    GET


PROC    PUT
      
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

ENDP    PUT
             
CODE    ENDS
        END     START
