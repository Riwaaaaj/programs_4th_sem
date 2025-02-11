; Program to calculate sum of the series 1^2 + 2^2 + 3^2 + ... up to 10 terms and display the result.

DATA SEGMENT
    MESSAGE DB 0DH, 0AH, "THE SUM OF THE SERIES IS: $"
    TEN     DW 10
    SUM     DW 0000H
DATA ENDS

CODE SEGMENT
    ASSUME CS:CODE, DS:DATA

START:
    MOV     AX, DATA
    MOV     DS, AX

    ; Sum of the series
    MOV     CX, 10    ; Counter for 10 terms
    MOV     BL, 1     ; Start from 1
    MOV     DX, 0     ; Store sum

SUM_LOOP:
    MOV     AL, BL    ; Load BL into AL
    MUL     BL        ; AL * BL -> AX (square)
    ADD     DX, AX    ; Accumulate sum in DX
    INC     BL        ; Increment BL
    LOOP    SUM_LOOP  ; Repeat until CX = 0

    MOV     [SUM], DX ; Store sum

    ; Display message
    MOV     AH, 09H
    LEA     DX, MESSAGE
    INT     21H

    ; Display the result
    MOV     AX, [SUM]
    CALL    PRINT_NUMBER

    ; Exit program
    MOV     AH, 4CH
    INT     21H

; Procedure to print a number
PROC PRINT_NUMBER
    PUSH    CX
    PUSH    DX

    MOV     CX, 0      ; Counter for digits

CONVERT_LOOP:
    MOV     DX, 0      ; Clear DX
    DIV     TEN        ; AX / 10 -> Quotient in AX, remainder in DX
    PUSH    DX         ; Store remainder (digit)
    INC     CX         ; Increase counter
    CMP     AX, 0
    JNE     CONVERT_LOOP

PRINT_LOOP:
    POP     DX         ; Get the digit
    ADD     DL, 30H    ; Convert to ASCII
    MOV     AH, 02H
    INT     21H        ; Print character
    LOOP    PRINT_LOOP ; Loop until CX = 0

    POP     DX
    POP     CX
    RET
ENDP PRINT_NUMBER

CODE ENDS
    END START
