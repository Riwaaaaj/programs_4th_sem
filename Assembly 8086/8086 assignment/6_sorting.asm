; Program to sort an array of 10 numbers and display each number in a separate line.

DATA SEGMENT
    MSG1    DB 0DH, 0AH, "Enter 10 numbers: $"
    MSG2    DB 0DH, 0AH, "Sorted numbers: $"
    LINB    DB 0DH, 0AH, "$"  ; New line
    ARRN    DB 10 DUP(?)       ; Array of 10 numbers
    LEN     DB 10              ; Number of elements
DATA ENDS

CODE SEGMENT
    ASSUME CS:CODE, DS:DATA

START:
    MOV     AX, DATA
    MOV     DS, AX

    ; Display message to enter numbers
    MOV     AH, 09H
    LEA     DX, MSG1
    INT     21H

    ; Input numbers
    LEA     SI, ARRN
    MOV     CL, LEN
INPUT_LOOP:
    CALL    GET
    ;MOV     AH, 09
    ;LEA     DX, LINB
    ;INT 21H 
    MOV     [SI], AL
    INC     SI
    DEC     CL
    JNZ     INPUT_LOOP

    ; Bubble Sort Algorithm
    MOV     CL, LEN
SORT_LOOP:
    DEC     CL
    JZ      DISPLAY_RESULTS
    LEA     SI, ARRN
    MOV     CH, CL
INNER_LOOP:
    MOV     AL, [SI]
    MOV     DL, [SI+1]
    CMP     AL, DL
    JBE     NO_SWAP
    MOV     [SI], DL
    MOV     [SI+1], AL
NO_SWAP:
    INC     SI
    DEC     CH
    JNZ     INNER_LOOP
    JMP     SORT_LOOP

DISPLAY_RESULTS:
    ; Display sorted message
    MOV     AH, 09H
    LEA     DX, MSG2
    INT     21H

    ; Display sorted numbers
    LEA     SI, ARRN
    MOV     CL, LEN
DISPLAY_LOOP:
    MOV     AH, 09H
    LEA     DX, LINB
    INT     21H
    CALL    PUT
    INC     SI
    DEC     CL
    JNZ     DISPLAY_LOOP

    ; Exit program
    MOV     AH, 4CH
    INT     21H

; Procedure to Get Input
PROC GET
    PUSH    CX
    MOV     AH, 01H
    INT     21H
    SUB     AL, 30H
    CMP     AL, 09H
    JLE     G1
    SUB     AL, 07H
G1: MOV     CL, 04H
    ROL     AL, CL
    MOV     CH, AL
    MOV     AH, 01H
    INT     21H
    SUB     AL, 30H
    CMP     AL, 09H
    JLE     G2
    SUB     AL, 07H
G2: ADD     AL, CH
    POP     CX
    RET
ENDP GET

; Procedure to Print Output
PROC PUT
    PUSH    CX
    MOV     AL, [SI]
    AND     AL, 0F0H
    MOV     CL, 04H
    ROL     AL, CL
    ADD     AL, 30H
    CMP     AL, 39H
    JLE     P1
    ADD     AL, 07H
P1: MOV     AH, 02H
    MOV     DL, AL
    INT     21H
    MOV     AL, [SI]
    AND     AL, 0FH
    ADD     AL, 30H
    CMP     AL, 39H
    JLE     P2
    ADD     AL, 07H
P2: MOV     AH, 02H
    MOV     DL, AL
    INT     21H
    POP     CX
    RET
ENDP PUT

CODE ENDS
    END START
