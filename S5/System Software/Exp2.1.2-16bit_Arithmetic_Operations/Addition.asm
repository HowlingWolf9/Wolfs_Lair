assume cs:code, ds:data
data segment
    opr1   dw 1234h
    opr2   dw 0002h
    result dw 01h dup(?)
data ends

code segment
    start:mov ax, data
          mov ds, ax

          mov ax, opr1
          mov bx, opr2
        
          clc
          add ax, bx
          mov di, offset result
          mov [di], ax
        
          mov ah, 4ch
          int 21h
        
code ends
end start