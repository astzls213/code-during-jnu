assume cs:code,ds:data,ss:stack
data segment
    msg db "You are right!",0dh,0ah,24h
    msg1 db "Fuck!",0dh,0ah,24h
data ends
stack segment stack
    dw 10 dup(0)
stack ends
code segment
start:
    mov ax,data
    mov ds,ax

    mov cx,4
    mov ax,0F000H
rol_like:
    test ax,8000H
    jnz not_zero
    clc
    jmp handler
not_zero:
    stc
handler:
    rcl ax,1
    loop rol_like
    cmp ax,0FH
    jne failed
    mov ah,9
    lea dx,msg
    int 21h
    jmp ending
failed:
    mov ah,9
    lea dx,msg1
    int 21h
ending:
    mov ax,4c00h
    int 21h
code ends
end start