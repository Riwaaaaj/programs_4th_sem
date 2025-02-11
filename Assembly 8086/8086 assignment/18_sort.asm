DATA SEGMENT  
    TABLE DW 0AAAH, 0999H, 0888H, 0777H, 0666H, 0555H, 0444H, 0333H, 0222H, 0111H  
    NEWLINE DB 10,13,'$'  
    COUNT DB 9  ; Fixed: 10 numbers ? 9 outer loop passes
    TEN DW 10  
DATA ENDS  

CODE SEGMENT  
MAIN PROC FAR  
    MOV AX, @DATA  
    MOV DS, AX  
    CALL SORT  
    CALL DISPLAY_NUMBERS  
    MOV AX, 4C00H  
    INT 21H  
MAIN ENDP  

; Bubble Sort Subroutine (Corrected)
SORT PROC NEAR  
SORT_LOOP:  
    LEA SI, TABLE  
    MOV DL, 0      ; Swap flag
    MOV CL, COUNT  ; Reset inner loop counter for each outer loop

INNER_LOOP:  
    MOV AX, [SI]  
    CMP AX, [SI+2]  
    JBE NO_SWAP  

    ; Swap elements
    MOV BX, [SI+2]  
    MOV [SI+2], AX  
    MOV [SI], BX  
    MOV DL, 1      ; Mark swap occurred

NO_SWAP:  
    ADD SI, 2  
    LOOP INNER_LOOP  

    ; Early exit if no swaps
    TEST DL, DL  
    JZ SORT_DONE  
    DEC COUNT  
    JNZ SORT_LOOP  
SORT_DONE:  
    RET  
SORT ENDP  

; Display Numbers in Decimal (Unchanged)
DISPLAY_NUMBERS PROC NEAR  
    MOV CX, 10  
    LEA SI, TABLE  

PRINT_LOOP:  
    XOR BX, BX  
    MOV AX, [SI]  

CONVERT:  
    XOR DX, DX  
    DIV TEN  
    ADD DX, '0'  
    PUSH DX  
    INC BL  
    TEST AX, AX  
    JNZ CONVERT  

DISPLAY:  
    POP DX  
    MOV AH, 02H  
    INT 21H  
    DEC BL  
    JNZ DISPLAY  

    LEA DX, NEWLINE  
    MOV AH, 09H  
    INT 21H  
    ADD SI, 2  
    LOOP PRINT_LOOP  
    RET  
DISPLAY_NUMBERS ENDP  

CODE ENDS  
END MAIN  