; 11. Program to generate multiplication tables of five numbers stored in memory.
; The results are stored in memory and displayed in table format.

DATA SEGMENT
    NUMBERS     DB 5, 3, 7, 9, 4     ; Numbers for multiplication table
    RESULTS     DB 50 DUP(0)         ; Storage for results (5 tables × 10 values each)

    MSG_TITLE   DB 0DH, 0AH, "MULTIPLICATION TABLE:", 0DH, 0AH, '$'  ; Title Message
    MSG_NEWLINE DB 0DH, 0AH, '$'      ; New line for formatting output
DATA ENDS

CODE SEGMENT
    ASSUME CS:CODE, DS:DATA

START:
    MOV AX, DATA
    MOV DS, AX

    MOV AH, 09H              ; Display title message
    LEA DX, MSG_TITLE
    INT 21H

    LEA SI, NUMBERS          ; Point to the first number
    LEA DI, RESULTS          ; Point to results storage

    MOV CX, 5                ; Number of multiplication tables (5)
    MOV BP, 0                ; Offset tracker for each table
TABLE_LOOP:
    MOV AL, [SI]             ; Load current number from array
    MOV BL, 1                ; Multiplier (1 to 10)
    MOV DX, 0                ; Reset DX for storing results
MULTIPLY_LOOP:
    MOV AH, 0                ; Clear AH for multiplication
    MUL BL                   ; AL * BL -> AX
    MOV [DI + BP], AL        ; Store result in memory at offset BP
    INC BP                   ; Move to next result slot
    INC BL                   ; Increase multiplier
    CMP BL, 11               ; Check if reached 10
    JNE MULTIPLY_LOOP

    CALL PRINT_TABLE         ; Print the current table
    INC SI                   ; Move to next number
    LOOP TABLE_LOOP          ; Repeat for next number

    MOV AH, 4CH              ; Exit program
    INT 21H

;-------------------------------
; PRINT_TABLE - Prints one row of results
;-------------------------------
PRINT_TABLE PROC
    PUSH CX               ; Save CX
    PUSH SI               ; Save SI

    MOV CX, 10            ; Print 10 numbers
    MOV BX, BP            ; Start from the current table's offset
    SUB BX, 10            ; Adjust to previous row start

PRINT_LOOP:
    MOV DL, [DI + BX]     ; Get stored number
    CALL PRINT_NUM        ; Print number
    MOV AH, 02H
    MOV DL, ' '           ; Print space separator
    INT 21H
    INC BX                ; Move to next result
    LOOP PRINT_LOOP

    MOV AH, 09H
    LEA DX, MSG_NEWLINE   ; Print newline
    INT 21H

    POP SI                ; Restore SI
    POP CX                ; Restore CX
    RET
PRINT_TABLE ENDP

;-------------------------------
; PRINT_NUM - Prints a properly formatted number
;-------------------------------
PRINT_NUM PROC
    PUSH AX               ; Save AX
    PUSH BX               ; Save BX

    MOV AH, 0
    MOV AL, DL
    MOV BL, 10
    DIV BL                ; AX / 10 ? AL=Quotient, AH=Remainder

    CMP AL, 0             ; Check if leading digit is zero
    JE PRINT_SINGLE       ; Skip first zero if single digit

    ADD AL, '0'           ; Convert first digit to ASCII
    MOV DL, AL
    MOV AH, 02H
    INT 21H               ; Print first digit

PRINT_SINGLE:
    ADD AH, '0'           ; Convert second digit to ASCII
    MOV DL, AH
    INT 21H               ; Print second digit

    POP BX                ; Restore BX
    POP AX                ; Restore AX
    RET
PRINT_NUM ENDP

CODE ENDS
    END START
