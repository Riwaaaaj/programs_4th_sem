.model small
.data
sum dw ?

.code
main proc
    mov ax, @data
    mov ds, ax

    mov ax, 100h
    mov bx, ax
    inc bx
    
    mul bx

    mov sum, dx

    mov ah, 4Ch
    int 21h

main endp
end
