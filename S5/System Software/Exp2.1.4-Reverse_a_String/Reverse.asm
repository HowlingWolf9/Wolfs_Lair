assume cs:code, ds:data
data segment
    str  db 'MICROPROCESSOR$'
    len  dw 14
data ends

code segment
    start:mov  ax, data
          mov  ds, ax

          mov  ah, 09h
          mov  dx, offset str
          int  21h
          
          mov  si, offset str
          mov  cx, len
          
          dec  cx
          add  si, cx
          
          mov  di, offset str
          mov  cx, len
          shr  cx, 1

    swap: mov  al, [si]
          mov  bl, [di]
          mov  [di], al
          mov  [si], bl
          
          dec  si
          inc  di
          loop swap
          
          mov  ah, 09h
          mov  dx, offset str
          int  21h
          
          mov  ah, 4ch
          int  21h
          
code ends
end start