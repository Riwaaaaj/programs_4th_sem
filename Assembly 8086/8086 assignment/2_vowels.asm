DATA SEGMENT
    MSG     DB 'hello world, this is assembly programming.', '$'
DATA ENDS

CODE SEGMENT
    ASSUME CS:CODE, DS:DATA

START:
    MOV AX, DATA
    MOV DS, AX    ; Initialize data segment

    LEA SI, MSG   ; Load address of MSG

NEXT_CHAR:
    MOV AL, [SI]  ; Load character from string
    CMP AL, '$'   ; Check for end of string
    JE PRINT_STR  ; If '$' is found, go to print

    ; Check for lowercase vowels: a, e, i, o, u
    CMP AL, 'a'
    JE TO_UPPER
    CMP AL, 'e'
    JE TO_UPPER
    CMP AL, 'i'
    JE TO_UPPER
    CMP AL, 'o'
    JE TO_UPPER
    CMP AL, 'u'
    JE TO_UPPER

    JMP NEXT_ITER

TO_UPPER:
    SUB AL, 20H   ; Convert to uppercase
    MOV [SI], AL  ; Store back in string

NEXT_ITER:
    INC SI        ; Move to next character
    JMP NEXT_CHAR ; Repeat

PRINT_STR:
    LEA DX, MSG
    MOV AH, 09H   ; DOS print string function
    INT 21H

    MOV AH, 4CH   ; Exit program
    INT 21H

CODE ENDS
    END START
