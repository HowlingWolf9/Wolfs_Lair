assume cs:code, ds:data
data segment
    opr1         dd 01edcba98h
    opr2         dd 12345678h
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
          add ax,[di]
          mov result_low, ax
          
          mov ax, [si + 2]
          adc ax, [di + 2]
          mov result_high, ax
          
          jnc stop
          inc cx
    
    stop: mov result_carry, cx
          mov ah, 4ch
          int 21h
          
code ends
end start