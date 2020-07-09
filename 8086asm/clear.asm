code segment
    assume cs:code
start:
    mov ah,0
    mov al,3
    int 10h

    mov ax,4c00h
    int 21h
code ends

end start