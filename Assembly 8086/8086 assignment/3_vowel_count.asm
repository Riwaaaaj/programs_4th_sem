DATA SEGMENT
    BUFFER_SIZE DB 50           ; Maximum input size
    INPUT_LEN   DB ?            ; Actual input length (filled by DOS)
    INPUT_STR   DB 50 DUP('$')  ; Space for input string
    VOWEL_COUNT DB 0            ; Store vowel count
DATA ENDS

CODE SEGMENT
    ASSUME CS:CODE, DS:DATA

START:
    MOV AX, DATA
    MOV DS, AX   ; Initialize data segment

    ; Take input from user
    LEA DX, BUFFER_SIZE
    MOV AH, 0AH
    INT 21H

    ; Set SI to point to input string
    LEA SI, INPUT_STR
    MOV CX, 0          ; Initialize loop counter
    MOV CL, INPUT_LEN  ; Set CL to actual string length
    MOV BL, 0          ; BL will store vowel count

NEXT_CHAR:
    MOV AL, [SI]   ; Load character

    ; Check for vowels: a, e, i, o, u, A, E, I, O, U
    CMP AL, 'a'
    JE COUNT_VOWEL
    CMP AL, 'e'
    JE COUNT_VOWEL
    CMP AL, 'i'
    JE COUNT_VOWEL
    CMP AL, 'o'
    JE COUNT_VOWEL
    CMP AL, 'u'
    JE COUNT_VOWEL
    CMP AL, 'A'
    JE COUNT_VOWEL
    CMP AL, 'E'
    JE COUNT_VOWEL
    CMP AL, 'I'
    JE COUNT_VOWEL
    CMP AL, 'O'
    JE COUNT_VOWEL
    CMP AL, 'U'
    JE COUNT_VOWEL

    JMP NEXT_ITER

COUNT_VOWEL:
    INC BL   ; Increment vowel count

NEXT_ITER:
    INC SI   ; Move to next character
    LOOP NEXT_CHAR   ; Repeat for all characters

    MOV VOWEL_COUNT, BL  ; Store vowel count

    ; Exit program
    MOV AH, 4CH
    INT 21H

CODE ENDS
    END START
