.model small
.data
sum dw ?

.code
main proc
    mov ax, @data
    mov ds, ax

    mov cx, 100
    mov ax, 00h
    mov bx, 01h

up: add ax, bx
    add bx, 01h
    loop up

    mov sum, ax

    mov ah, 4Ch
    int 21h

main endp
end
