.model small
.stack 100h
.data
    hello_message db "Hello World!", "$"
.code
main proc
    mov ax, @data
    mov ds, ax

    mov ah, 09h
    mov bl, 9
    mov cx, 12
    int 10h

    mov dx, offset hello_message
    int 21h

    mov ah, 09h
    mov bl, 0E4h
    mov cx, 12
    int 10h

    mov dx, offset hello_message
    int 21h

    mov ah, 09h
    mov bl, 0E4h
    mov cx, 12
    int 10h

    mov dx, offset hello_message
    int 21h

    mov ax, 4C00h
    int 21h
main endp
end main
