;9. Write an assembly language program for 8086 to read a string and find the number of alphabets, numerals and other characters. Display the different counts.
DATA SEGMENT
    MSG1    DB 0DH, 0AH, "ENTER A STRING: $"
    MSG2    DB 0DH, 0AH, "ALPHABETS: $"
    MSG3    DB 0DH, 0AH, "NUMERALS: $"
    MSG4    DB 0DH, 0AH, "OTHER CHARACTERS: $"
    
    STR     DB 50 DUP('$')   ; BUFFER TO STORE INPUT STRING
    ALPHA   DB 00H           ; COUNT OF ALPHABETS
    NUM     DB 00H           ; COUNT OF NUMERALS
    OTHER   DB 00H           ; COUNT OF OTHER CHARACTERS
DATA ENDS

CODE SEGMENT
    ASSUME CS:CODE, DS:DATA

START:
    MOV     AX, DATA
    MOV     DS, AX

    ; DISPLAY MESSAGE FOR INPUT
    MOV     AH, 09H
    LEA     DX, MSG1
    INT     21H

    ; READ STRING FROM USER
    LEA     SI, STR
    MOV     CX, 50
INPUT_LOOP:
    MOV     AH, 01H
    INT     21H
    CMP     AL, 0DH         ; CHECK FOR ENTER KEY
    JE      PROCESS_STRING
    MOV     [SI], AL
    INC     SI
    LOOP    INPUT_LOOP

PROCESS_STRING:
    LEA     SI, STR

CHECK_CHAR:
    MOV     AL, [SI]
    CMP     AL, '$'         ; END OF STRING
    JE      DISPLAY_RESULT

    CMP     AL, 'A'
    JB      CHECK_NUM       ; BELOW 'A', CHECK IF IT'S A NUMBER
    CMP     AL, 'Z'
    JBE     COUNT_ALPHA     ; IF BETWEEN 'A' AND 'Z', IT'S AN ALPHABET

    CMP     AL, 'a'
    JB      CHECK_NUM
    CMP     AL, 'z'
    JBE     COUNT_ALPHA     ; IF BETWEEN 'a' AND 'z', IT'S AN ALPHABET

CHECK_NUM:
    CMP     AL, '0'
    JB      COUNT_OTHER
    CMP     AL, '9'
    JBE     COUNT_NUM       ; IF BETWEEN '0' AND '9', IT'S A NUMERAL

COUNT_OTHER:
    INC     OTHER
    JMP     NEXT_CHAR

COUNT_ALPHA:
    INC     ALPHA
    JMP     NEXT_CHAR

COUNT_NUM:
    INC     NUM

NEXT_CHAR:
    INC     SI
    JMP     CHECK_CHAR

DISPLAY_RESULT:
    ; DISPLAY ALPHABETS COUNT
    MOV     AH, 09H
    LEA     DX, MSG2
    INT     21H
    MOV     AL, ALPHA
    CALL    PRINT_NUM

    ; DISPLAY NUMERALS COUNT
    MOV     AH, 09H
    LEA     DX, MSG3
    INT     21H
    MOV     AL, NUM
    CALL    PRINT_NUM

    ; DISPLAY OTHER CHARACTERS COUNT
    MOV     AH, 09H
    LEA     DX, MSG4
    INT     21H
    MOV     AL, OTHER
    CALL    PRINT_NUM

    ; EXIT PROGRAM
    MOV     AH, 4CH
    INT     21H

; PROCEDURE TO PRINT A NUMBER
PRINT_NUM PROC
    PUSH    AX
    PUSH    DX

    MOV     AH, 00H
    MOV     DL, AL
    ADD     DL, 30H        ; CONVERT TO ASCII
    MOV     AH, 02H
    INT     21H

    POP     DX
    POP     AX
    RET
PRINT_NUM ENDP

CODE ENDS
    END START
