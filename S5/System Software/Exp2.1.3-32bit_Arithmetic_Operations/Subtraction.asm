assume cs:code, ds:data
data segment
    opr1         dd 0fedc5678h
    opr2         dd 1234ba98h
    result_low   dw ?
    result_high  dw ?
    result_carry dw ?
data ends

code segment
    start:mov ax, data
          mov ds, ax

          xor ax,ax
          mov cx, ax

          mov si, offset opr1
          mov di, offset opr2

          clc
          mov ax,[si]
          sub ax,[di]
          mov result_low, ax

          mov ax, [si + 2]
          sbb ax, [di + 2]
          mov result_high, ax

          jnc stop
          inc cx

    stop: mov result_carry, cx
          mov ah, 4ch
          int 21h
          
code ends
end start