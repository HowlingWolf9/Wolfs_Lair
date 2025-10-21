assume cs:code, ds:data
data segment
    mesg db "Hello, World!$"
data ends

code segment
start:
    mov ax, data
    mov ds, ax
    mov dx, offset mesg
    mov ah, 09h
    int 21h
    mov ax, 4ch
    int 21h
code ends
end start