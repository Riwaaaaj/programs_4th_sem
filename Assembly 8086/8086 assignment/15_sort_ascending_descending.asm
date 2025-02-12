;15. Write assembly language program for 8086 to sort five numbers in ascending and descending order.
DATA SEGMENT
    ARRAY DB 04H, 03H, 08H, 05H, 06H  ; 5 Numbers
    COUNT DB 4  ; Outer loop runs 4 times for 5 elements
    NEWLINE DB 10,13,'$'
DATA ENDS

CODE SEGMENT
MAIN PROC FAR
    MOV AX, @DATA
    MOV DS, AX

    CALL SORT_ASCENDING
    LEA DX, NEWLINE
    MOV AH, 09H
    INT 21H
    CALL DISPLAY_NUMBERS

    ; Reset COUNT for descending sort
    MOV COUNT, 4

    LEA DX, NEWLINE
    MOV AH, 09H
    INT 21H

    CALL SORT_DESCENDING
    LEA DX, NEWLINE
    MOV AH, 09H
    INT 21H
    CALL DISPLAY_NUMBERS

    MOV AX, 4C00H
    INT 21H
MAIN ENDP

; Bubble Sort (Ascending Order)
SORT_ASCENDING PROC NEAR
OUTER_LOOP:
    LEA SI, ARRAY
    MOV DL, 0  ; Swap flag
    MOV CL, COUNT  ; Outer loop counter

INNER_LOOP:
    MOV AL, [SI]
    CMP AL, [SI+1]
    JBE NO_SWAP

    ; Swap elements
    MOV BL, [SI+1]
    MOV [SI+1], AL
    MOV [SI], BL
    MOV DL, 1  ; Set swap flag

NO_SWAP:
    INC SI
    LOOP INNER_LOOP

    TEST DL, DL  ; Check if any swaps occurred
    JZ SORT_DONE
    DEC COUNT
    JNZ OUTER_LOOP
SORT_DONE:
    RET
SORT_ASCENDING ENDP

; Bubble Sort (Descending Order)
SORT_DESCENDING PROC NEAR
OUTER_LOOP_DESC:
    LEA SI, ARRAY
    MOV DL, 0  ; Swap flag
    MOV CL, COUNT  ; Outer loop counter

INNER_LOOP_DESC:
    MOV AL, [SI]
    CMP AL, [SI+1]
    JAE NO_SWAP_DESC

    ; Swap elements
    MOV BL, [SI+1]
    MOV [SI+1], AL
    MOV [SI], BL
    MOV DL, 1  ; Set swap flag

NO_SWAP_DESC:
    INC SI
    LOOP INNER_LOOP_DESC

    TEST DL, DL  ; Check if any swaps occurred
    JZ SORT_DONE_DESC
    DEC COUNT
    JNZ OUTER_LOOP_DESC
SORT_DONE_DESC:
    RET
SORT_DESCENDING ENDP

; Display Sorted Numbers
DISPLAY_NUMBERS PROC NEAR
    MOV CX, 5
    LEA SI, ARRAY

PRINT_LOOP:
    MOV AL, [SI]
    AAM
    ADD AX, '00'

    ; Print tens digit only if non-zero
    CMP AH, '0'
    JE SKIP_TENS
    MOV DL, AH
    MOV AH, 02H
    INT 21H

SKIP_TENS:
    MOV DL, AL
    MOV AH, 02H
    INT 21H

    ; Print newline
    PUSH CX
    LEA DX, NEWLINE
    MOV AH, 09H
    INT 21H
    POP CX

    INC SI
    LOOP PRINT_LOOP
    RET
DISPLAY_NUMBERS ENDP

CODE ENDS
END MAIN