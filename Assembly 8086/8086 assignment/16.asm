; 16. Write an assembly language program to read a string from the user, convert it to upper case, count the number of words and display each word in each line and number of words.
INCLUDE "EMU8086.INC"
.MODEL SMALL
.STACK 100H

.DATA
    STR1 DB "ENTER A STRING: $"
    MAXLEN DB 100            ; MAXIMUM INPUT LENGTH
    ACTCHAR DB ?             ; ACTUAL INPUT LENGTH
    STRING DB 100 DUP('$')   ; INPUT BUFFER
    NEWLINE DB 13,10,'$'     ; CORRECTED TO CR LF
    COUNT DB 0               ; WORD COUNTER
    TEN DW 10
    STR2 DB "WORD COUNT: $"

.CODE
MAIN PROC FAR
    MOV AX, @DATA  
    MOV DS, AX    
    
    ; DISPLAY INPUT PROMPT
    LEA DX, STR1  
    MOV AH, 09H  
    INT 21H  
    
    ; READ USER INPUT (DOS FUNCTION 0AH)
    LEA DX, MAXLEN 
    MOV AH, 0AH  
    INT 21H  

    ; PRINT NEWLINE
    LEA DX, NEWLINE  
    MOV AH, 09H  
    INT 21H  
    
    ; POINT TO START OF STRING
    LEA SI, STRING+2   
    XOR CX, CX        
    MOV CL, ACTCHAR    ; LOAD ACTUAL CHARACTER COUNT
    MOV COUNT, 0       ; RESET WORD COUNTER
    
    MOV BL, ' '        ; TRACK PREVIOUS CHARACTER
    
PROCESS_STRING:
    CMP CL, 0          ; EXIT LOOP WHEN ALL CHARACTERS PROCESSED
    JE PRINT_COUNT
    
    MOV AL, [SI]       ; GET CURRENT CHARACTER
    
    ; CONVERT LOWERCASE TO UPPERCASE
    CMP AL, 'a'        
    JB CHECK_SPACE    
    CMP AL, 'z'    
    JA CHECK_SPACE    
    SUB AL, 20H        ; CONVERT TO UPPERCASE
    
CHECK_SPACE:
    CMP AL, ' '        ; CHECK IF CURRENT CHARACTER IS SPACE
    JNE NOT_SPACE
    
    CMP BL, ' '        ; CHECK IF PREVIOUS CHARACTER WAS ALSO SPACE
    JE SKIP_SPACE      ; IF YES, SKIP
    
    ; PRINT NEWLINE FOR WORD SEPARATION
    LEA DX, NEWLINE  
    MOV AH, 09H  
    INT 21H  
    
SKIP_SPACE:
    MOV BL, AL         ; UPDATE PREVIOUS CHARACTER
    JMP NEXT_CHAR
    
NOT_SPACE:
    ; IF PREVIOUS WAS SPACE, INCREMENT WORD COUNT (NEW WORD DETECTED)
    CMP BL, ' '        
    JNE DISPLAY_CHAR
    INC COUNT
    
DISPLAY_CHAR:
    MOV DL, AL         
    MOV AH, 02H        
    INT 21H
    
    MOV BL, AL         ; UPDATE PREVIOUS CHARACTER

NEXT_CHAR:
    INC SI              
    DEC CL              
    JMP PROCESS_STRING  

PRINT_COUNT:
    ; HANDLE LAST WORD IF INPUT DOESN'T END WITH SPACE
    CMP BL, ' '        
    JE PRINT_RESULT
    INC COUNT
    
PRINT_RESULT:
    ; PRINT NEWLINE
    LEA DX, NEWLINE  
    MOV AH, 09H  
    INT 21H  
    
    ; PRINT "WORD COUNT: "
    LEA DX, STR2  
    MOV AH, 09H  
    INT 21H  
    
    ; PRINT WORD COUNT
    MOV AL, COUNT      
    XOR AH, AH          
    CALL PRINT_NUMBER  
    
    ; EXIT PROGRAM
    MOV AX, 4C00H  
    INT 21H  
    
MAIN ENDP

PRINT_NUMBER PROC NEAR
    XOR CX, CX          
NUMBER_LOOP:
    XOR DX, DX          
    DIV TEN             
    PUSH DX             
    INC CX              
    TEST AX, AX         
    JNZ NUMBER_LOOP     
  
PRINT_DIGITS:
    POP DX              
    ADD DL, '0'         
    MOV AH, 02H         
    INT 21H             
    LOOP PRINT_DIGITS   
    RET  
PRINT_NUMBER ENDP

END MAIN