DATA SEGMENT
    MSG1    DB 0DH, 0AH, "ENTER THE VALUE OF X [TWO DIGITS]: $"
    MSG2    DB 0DH, 0AH, "THE SUM OF THE SERIES IS: $"
    TEN     DW 10
    X       DB ?
    SUM     DW 0000H
DATA ENDS

CODE SEGMENT
    ASSUME CS:CODE, DS:DATA

START:
    MOV     AX, DATA
    MOV     DS, AX

    ; Display message 1
    MOV     AH, 09H
    LEA     DX, MSG1
    INT     21H

    ; Read two-digit input using GET (decimal)
    CALL    GET
    MOV     [X], AL

    ; Calculate sum = x * 55
    MOV     BL, 55       ; Correct multiplier (55 decimal)
    MUL     BL           ; AX = AL * BL
    MOV     [SUM], AX    ; Store result

    ; Display message 2
    MOV     AH, 09H
    LEA     DX, MSG2
    INT     21H  

    ; Display the sum using PUT
    LEA     SI, SUM
    CALL    PUT

    MOV     AH, 4CH
    INT     21H

; ----------------------------------------
; GET PROCEDURE: Reads two-digit decimal input
; ----------------------------------------
PROC GET
    PUSH    CX          ; Save registers used
    PUSH    BX

    ; Read first digit
    MOV     AH, 01H
    INT     21H
    SUB     AL, '0'     ; Convert ASCII to digit
    MOV     BL, 10
    MUL     BL          ; AX = AL * 10
    MOV     BH, AL      ; Store result in BH

    ; Read second digit
    MOV     AH, 01H
    INT     21H
    SUB     AL, '0'     ; Convert ASCII to digit
    ADD     AL, BH      ; AL = 10*d1 + d2

    POP     BX          ; Restore registers
    POP     CX
    RET
ENDP GET

; ----------------------------------------
; PUT PROCEDURE: Displays a 16-bit number (decimal)
; ----------------------------------------
PROC PUT
    PUSH    CX
    MOV     AX, [SI]    ; Load number into AX
    MOV     CX, 0       ; Initialize digit counter

L2: MOV     DX, 0
    DIV     TEN         ; Divide AX by 10
    INC     CX          ; Increment digit count
    ADD     DL, '0'     ; Convert remainder to ASCII
    PUSH    DX          ; Push digit onto stack
    CMP     AX, 0       ; Check if quotient is zero
    JNE     L2          ; Continue if not zero

L3: POP     DX          ; Pop digit from stack
    MOV     AH, 02H
    INT     21H         ; Display digit
    LOOP    L3          ; Repeat for all digits

    POP     CX
    RET
ENDP PUT

CODE ENDS
    END START