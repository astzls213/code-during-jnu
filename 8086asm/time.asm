data segment
    assume ds:data
    begin_time db 0,0,0
    end_time db 0,0,0
data ends

code segment
    assume cs:code
a macro b,d
    local lp
    lp:
        mov ax,b
        mov bx,d
endm
d macro b,c
    local lp
    lp:
        mov cx,b
        mov dx,c
endm
go:
    a 1,2
    d 1,2

    mov ax,4c00h
    int 21h
code ends

end go