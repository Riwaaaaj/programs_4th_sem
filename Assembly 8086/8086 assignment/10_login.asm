DATA SEGMENT
    MSG1        DB 0DH,0AH,"USERNAME: $"
    USERNAME    DB 20,?,20 DUP('$')     ; Input buffer for username (larger size)
    MSG2        DB 0DH,0AH,"PASSWORD: $"
    PASSWORD    DB 20,?,20 DUP('$')     ; Input buffer for password (larger size)

    VALID_USER  DB "bebct$"             ; Correct username
    VALID_PASS  DB "engineering$"       ; Correct password

    MSG_SUCCESS DB 0DH,0AH,"LOGIN SUCCESSFUL$"
    MSG_FAIL    DB 0DH,0AH,"INVALID LOGIN$"
DATA ENDS

CODE SEGMENT
    ASSUME CS:CODE, DS:DATA

START:
    MOV AX, DATA
    MOV DS, AX

    ; Display "USERNAME: "
    MOV AH, 09H
    LEA DX, MSG1
    INT 21H

    ; Read username input
    MOV AH, 0AH
    LEA DX, USERNAME
    INT 21H

    ; Display "PASSWORD: "
    MOV AH, 09H
    LEA DX, MSG2
    INT 21H

    ; Read password input
    MOV AH, 0AH
    LEA DX, PASSWORD
    INT 21H

    ; Compare username
    LEA SI, USERNAME + 2    ; Skip buffer length bytes
    LEA DI, VALID_USER
    CALL STRCMP
    JNZ INVALID_LOGIN       ; If username mismatch, jump

    ; Compare password
    LEA SI, PASSWORD + 2    ; Skip buffer length bytes
    LEA DI, VALID_PASS
    CALL STRCMP
    JNZ INVALID_LOGIN       ; If password mismatch, jump

    ; Display success message
    MOV AH, 09H
    LEA DX, MSG_SUCCESS
    INT 21H
    JMP END_PROGRAM

INVALID_LOGIN:
    ; Display invalid message
    MOV AH, 09H
    LEA DX, MSG_FAIL
    INT 21H

END_PROGRAM:
    MOV AH, 4CH
    INT 21H

; String Comparison Function
; Compares two strings until '$' is found or mismatch
STRCMP PROC
    CLD                   ; Clear direction flag (forward comparison)
COMPARE_LOOP:
    MOV AL, [SI]          ; Load character from input
    MOV BL, [DI]          ; Load character from valid string
    CMP AL, '$'           ; Check for string end
    JE MATCH_FOUND
    CMP BL, '$'
    JE MATCH_FOUND
    CMP AL, BL            ; Compare characters
    JNE STRCMP_FAIL       ; If not equal, return non-zero
    INC SI
    INC DI
    JMP COMPARE_LOOP

MATCH_FOUND:
    XOR AX, AX            ; Set AX=0 (success)
    RET

STRCMP_FAIL:
    MOV AX, 1             ; Set AX=1 (mismatch)
    RET
STRCMP ENDP

CODE ENDS
    END START