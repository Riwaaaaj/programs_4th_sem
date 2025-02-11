; Convert lowercase letters to uppercase and display the modified string  

DATA SEGMENT  
    STR1 DB "ENTER A STRING: ",'$'  
    MAXLEN DB 100  
    STRING DB 100 DUP('$')  
    NEWLINE DB 10,13,'$'  
DATA ENDS  

CODE SEGMENT  
MAIN PROC FAR  
    MOV AX, @DATA  
    MOV DS, AX  

    MOV AH, 09H  
    LEA DX, STR1  
    INT 21H  

    MOV AH, 0AH  
    LEA DX, MAXLEN  
    INT 21H  

    LEA SI, STRING+1  
    MOV CL, [STRING]  

CONVERT:  
    CMP [SI], '$'  
    JE DISPLAY  
    CMP [SI], 20H  
    JE NEXT_CHAR  
    CMP [SI], 'a'  
    JB NEXT_CHAR  
    CMP [SI], 'z'  
    JA NEXT_CHAR  
    SUB [SI], 20H  

NEXT_CHAR:  
    INC SI  
    LOOP CONVERT  

DISPLAY:  
    MOV AH, 09H  
    LEA DX, NEWLINE  
    INT 21H  

    MOV AH, 09H  
    LEA DX, STRING+1  
    INT 21H  

    MOV AX, 4C00H  
    INT 21H  
MAIN ENDP  
CODE ENDS  
END MAIN  
