DATA    SEGMENT  
    MSG     DB 0DH, 0AH, "The sum of first 100 even numbers is: $"
    SUM     DD 0  
DATA    ENDS  
  
CODE    SEGMENT  
    ASSUME CS:CODE, DS:DATA  
  
START:  
    MOV     AX, DATA  
    MOV     DS, AX    
      
    MOV     AX, 64H    ; n = 100 (decimal)
    MOV     BX, AX    
    INC     BX        ; (n+1)
    MUL     BX        ; DX:AX = AX * BX  
      
    MOV     [SUM], AX   ; Store lower 16 bits at SUM  
    MOV     [SUM+2], DX ; Store upper 16 bits at SUM+2    
      
    MOV     AH, 09H  
    LEA     DX, MSG  
    INT     21H    
      
    LEA     SI, SUM  
    CALL    PRINT_NUM ; Convert and print the 32-bit number
      
    MOV     AH, 4CH    
    INT     21H  
      
  
; Subroutine to print a 32-bit number in decimal format  
PROC PRINT_NUM  
    PUSH    AX  
    PUSH    BX  
    PUSH    CX  
    PUSH    DX  
    PUSH    SI  
    PUSH    DI  
    PUSHF  
      
    MOV     CX, 0H      ; Digit count
    MOV     BX, 0AH     ; Divisor for decimal conversion
      
    ; Load 32-bit value into DX:AX  
    MOV     AX, [SI]  
    MOV     DX, [SI+2]  
      
    ; Convert number to decimal and store digits in stack  
CONVERT_LOOP:  
    CMP     DX, 0  
    JNZ     DIV_32   ; If upper 16 bits are non-zero, use 32-bit division
    DIV     BX      ; Divide AX by 10 (remainder in DX)
    JMP     STORE_DIGIT  
      
DIV_32:  
    PUSH    DX  
    PUSH    AX  
    MOV     AX, DX  
    XOR     DX, DX  
    DIV     BX  
    XCHG    AX, BX  
    POP     AX  
    POP     DX  
    DIV     BX  
      
STORE_DIGIT:  
    ADD     DX, 30H  
    PUSH    DX  
    INC     CX  
    XOR     DX, DX  
    CMP     AX, 0  
    JNZ     CONVERT_LOOP  
      
    ; Print digits in correct order  
PRINT_LOOP:  
    POP     DX  
    MOV     AH, 02H  
    INT     21H  
    LOOP    PRINT_LOOP  
      
    POPF  
    POP     DI  
    POP     SI  
    POP     DX  
    POP     CX  
    POP     BX  
    POP     AX  
    RET  
ENDP PRINT_NUM  
  
CODE    ENDS  
    END     START
