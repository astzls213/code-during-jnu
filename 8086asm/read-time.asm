assume cs:code,ds:data
data segment
    time db 0eh dup(?)
data ends

code segment
start:
    mov ax,data
    mov ds,ax

    mov si,0ffffh
    mov al,0ffh
    mov cx,0eh
lp:
    inc si
    inc al
    mov bl,al  ;store al
    out 70h,al ;read 0-unit
    in al,71h
    mov time[si],al
    mov al,bl  ;restore
    loop lp

    mov ax,4c00h
    int 21h
code ends
end start