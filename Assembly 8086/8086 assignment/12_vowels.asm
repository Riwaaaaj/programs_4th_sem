;12. Write an assembly language program for 8086 to read string count the number of vowels in the string and display the string and its vowels count in a clear screen.
DATA SEGMENT
    MESSAGE1 DB 10,13, "ENTER THE STRING: $"
    MAXLENGTH DB 100
    STRING DB 100 DUP('$')
    MESSAGE2 DB 10,13, "THE STRING IS: $"
    MESSAGE3 DB 10,13, "VOWEL COUNT: $"
    COUNT DW 0
    TEN DW 10
DATA ENDS

CODE SEGMENT
    ASSUME CS:CODE, DS:DATA

MAIN PROC FAR
    MOV AX, DATA
    MOV DS, AX
    
    ; Display message to enter string
    LEA DX, MESSAGE1
    CALL PUT

    ; Read input string
    LEA DX, MAXLENGTH
    CALL GET

    ; Count vowels
    CALL COUNT_VOWELS

    ; Clear screen
    CALL CLEAR

    ; Display original string
    LEA DX, MESSAGE2
    CALL PUT
    LEA DX, STRING+1
    CALL PUT

    ; Display vowel count message
    LEA DX, MESSAGE3
    CALL PUT

    ; Display vowel count
    CALL DISPLAY_COUNT

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

; CLEAR - Clear screen
CLEAR PROC
    MOV AX, 0600H
    MOV BH, 07H
    MOV CX, 0000H
    MOV DX, 184FH
    INT 10H
    RET
CLEAR ENDP

; COUNT_VOWELS - Count the vowels in the string
COUNT_VOWELS PROC
    MOV CX, 0
    LEA SI, STRING+1  ; Actual string starts from STRING+1

CHECK_LOOP:
    MOV DL, [SI]     ; Load character
    CMP DL, '$'      ; Check for end of string
    JE COUNT_DONE

    ; Check if character is a vowel
    CMP DL, 'A'      
    JE VOWEL_FOUND
    CMP DL, 'E'
    JE VOWEL_FOUND
    CMP DL, 'I'
    JE VOWEL_FOUND
    CMP DL, 'O'
    JE VOWEL_FOUND
    CMP DL, 'U'
    JE VOWEL_FOUND
    CMP DL, 'a'
    JE VOWEL_FOUND
    CMP DL, 'e'
    JE VOWEL_FOUND
    CMP DL, 'i'
    JE VOWEL_FOUND
    CMP DL, 'o'
    JE VOWEL_FOUND
    CMP DL, 'u'
    JE VOWEL_FOUND

    JMP NEXT_CHAR

VOWEL_FOUND:
    INC CX

NEXT_CHAR:
    INC SI
    JMP CHECK_LOOP

COUNT_DONE:
    MOV [COUNT], CX  ; Store vowel count
    RET
COUNT_VOWELS ENDP

; DISPLAY_COUNT - Display the vowel count
DISPLAY_COUNT PROC
    MOV AX, COUNT
    XOR CX, CX
    XOR DX, DX

CONVERT_LOOP:
    CMP AX, 0000H
    JE PRINT_COUNT
    DIV TEN
    ADD DX, 0030H
    PUSH DX
    INC CX
    JMP CONVERT_LOOP

PRINT_COUNT:
    POP DX
    MOV AH, 02H
    INT 21H
    LOOP PRINT_COUNT

    RET
DISPLAY_COUNT ENDP

CODE ENDS
END MAIN
