assume cs:code, ds:data     
data segment
    arr   dw 4321h, 1234h, 6789h, 1111h, 9999h
    count dw 5
data ends
code segment
    start:     
               mov  ax, data
               mov  ds, ax

               mov  cx, count
               dec  cx
               mov  dx, count

    outer_loop:
               mov  dx, count
               dec  dx
               mov  si, offset arr

    inner_loop:
               mov  ax, [si]
               mov  bx, [si + 2]
               cmp  ax, bx
               jbe  skip_swap
               
               xchg ax, bx
               mov  [si], ax
               mov  [si + 2], bx

    skip_swap: 
               add  si, 2
               dec  dx
               jnz  inner_loop
               dec  cx
               jnz  outer_loop
               
               mov  ah, 4ch
               int  21h
code ends
end start