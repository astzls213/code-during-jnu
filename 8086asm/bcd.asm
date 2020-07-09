assume cs:code
data segment
    BCD1 dw 2563h
    BCD2 dw 1278h
    BCD3 dw 0000h
data ends

stack segment
    dw 128 dup(0)
stack ends

code segment
start:
    mov ax,data
    mov ds,ax
    mov es,ax

    mov al,38h
    mov bl,87h
    add al,bl
    daa
code ends

end start