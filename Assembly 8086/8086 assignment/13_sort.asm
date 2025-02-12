;13. Write an assembly language program for 8086 to sort an array of ten numbers stored in memory. Display the numbers in the screen after sorting.
DATA SEGMENT
    ARRAY DB 04H, 03H, 08H, 05H, 06H, 09H, 02H, 07H, 01H, 06H  
    COUNT DB 9       ; Outer loop runs 9 times for 10 elements
    NEWLINE DB 10,13,'$'
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

; Optimized Bubble Sort for 8-bit numbers
SORT PROC NEAR
OUTER_LOOP:
    LEA SI, ARRAY    ; Reset pointer to start of array
    MOV DL, 0        ; Swap flag (0 = no swap)
    MOV CL, COUNT    ; Inner loop counter

INNER_LOOP:
    MOV AL, [SI]     ; Current element
    CMP AL, [SI+1]   ; Compare with next element
    JBE NO_SWAP      ; Skip swap if already in order

    ; Swap elements
    MOV BL, [SI+1]
    MOV [SI+1], AL
    MOV [SI], BL
    MOV DL, 1        ; Set swap flag

NO_SWAP:
    INC SI           ; Move to next element
    LOOP INNER_LOOP

    DEC COUNT        ; Reduce inner loop iterations
    TEST DL, DL      ; Check if any swaps occurred
    JNZ OUTER_LOOP   ; Continue sorting if swaps happened
    RET
SORT ENDP

; Corrected Display Routine (No Leading Zeros)
DISPLAY_NUMBERS PROC NEAR
    MOV CX, 10
    LEA SI, ARRAY

PRINT_LOOP:
    MOV AL, [SI]     ; Load number to display
    AAM              ; Convert AL to ASCII digits (AH = tens, AL = ones)
    ADD AX, '00'     ; Convert digits to ASCII characters

    ; Print tens digit only if non-zero
    CMP AH, '0'
    JE SKIP_TENS
    MOV DL, AH
    MOV AH, 02H
    INT 21H

SKIP_TENS:
    ; Always print ones digit
    MOV DL, AL
    MOV AH, 02H
    INT 21H

    ; Print newline
    PUSH CX          ; Preserve loop counter
    LEA DX, NEWLINE
    MOV AH, 09H
    INT 21H
    POP CX

    INC SI           ; Move to next array element
    LOOP PRINT_LOOP
    RET
DISPLAY_NUMBERS ENDP

CODE ENDS
END MAIN