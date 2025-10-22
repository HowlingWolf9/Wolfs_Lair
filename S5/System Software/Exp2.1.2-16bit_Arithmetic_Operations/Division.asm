assume cs:code, ds:data
data segment
    opr1      dw 1234h
    opr2      dw 0003h
    quotient  dw 01h dup(?)
    remainder dw 01h dup(?)
data ends

code segment
    start:mov ax, data
          mov ds, ax

          mov ax, opr1
          mov bx, opr2

          clc
          xor dx, dx
          div bx

          mov di, offset quotient
          mov [di], ax

          mov di, offset remainder
          mov [di],dx

          mov ah, 4ch
          int 21h
          
code ends
end start