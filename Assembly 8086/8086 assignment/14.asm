.MODEL SMALL
.STACK 32H

DATA SEGMENT
    MESSAGE1 DB 10,13, "ENTER A STRING: $"
    MAXLENGTH DB 100
    ACTCHAR DB ?
    STRING DB 100 DUP('$')  ; Input buffer
    NEWLINE DB 10,13, "$"
DATA ENDS

CODE SEGMENT
    ASSUME CS:CODE, DS:DATA

MAIN PROC FAR
    MOV AX, DATA
    MOV DS, AX

    ; Display prompt message
    LEA DX, MESSAGE1
    CALL PUT

    ; Read input string
    LEA DX, MAXLENGTH
    CALL GET

    ; Clear screen
    CALL CLEAR_SCREEN

    ; Start displaying words at row 10
    MOV BL, 10

    ; Process string to separate words
    CALL PROCESS_WORDS

    ; Terminate program
    MOV AX, 4C00H
    INT 21H

MAIN ENDP

; ************* SUBROUTINES *************

; PUT - Display a string
PUT PROC
    MOV AH, 09H
    INT 21H
    RET
PUT ENDP

; GET - Read input string
GET PROC
    MOV AH, 0AH
    INT 21H
    RET
GET ENDP

; CLEAR_SCREEN - Clear screen with blue background and cyan text
CLEAR_SCREEN PROC
    MOV AX, 0600H    ; Scroll screen up
    MOV BH, 1EH      ; Blue background, Cyan text
    MOV CX, 0000H    ; Top left corner
    MOV DX, 184Fh    ; Bottom right corner
    INT 10H
    RET
CLEAR_SCREEN ENDP

; PROCESS_WORDS - Displays words at the center of the screen
PROCESS_WORDS PROC
    LEA SI, STRING+2  ; Actual string starts from STRING+2
    MOV CL, ACTCHAR   ; Load character count

NEXT_CHAR:
    CMP CX, 0
    JE DONE_PROCESSING

    MOV AL, [SI]      ; Load character
    CMP AL, ' '       ; Check for space (word separator)
    JE NEW_LINE

    MOV DL, AL        ; Move character to DL
    CALL DISPLAY
    INC SI            ; Move to next character
    DEC CX            ; Decrease counter
    JMP NEXT_CHAR

NEW_LINE:
    CALL NEWLINE_CURSOR
    INC SI
    DEC CX
    JMP NEXT_CHAR

DONE_PROCESSING:
    RET
PROCESS_WORDS ENDP

; DISPLAY - Display a single character
DISPLAY PROC
    MOV AH, 02H
    INT 21H
    RET
DISPLAY ENDP

; NEWLINE_CURSOR - Move cursor to a new centered position
NEWLINE_CURSOR PROC
    MOV AH, 02H
    MOV BH, 0         ; Page number
    MOV DH, BL        ; Set row position
    MOV DL, 35        ; Center the text at column 35
    INT 10H
    INC BL            ; Move to next row
    RET
NEWLINE_CURSOR ENDP

CODE ENDS
END MAIN
