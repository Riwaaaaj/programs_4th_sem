DATA    SEGMENT  
    
        MSG     DB 0DH, 0AH, "The sum of first 100 number is: $"
        SUM     DW ?
DATA    ENDS

CODE    SEGMENT
        ASSUME CS:CODE, DS:DATA

START:
        MOV     AX, @DATA  
        MOV     DS, AX  
        
        MOV     AX, 100H  
        MOV     BX, AX  
        INC     BX  
        
        MUL     BX  
          
        
        MOV     AH, 4CH  
        INT     21H  
        
        
CODE    ENDS
        END     START
