data  SEGMENT
    assume ds:data
    vector dd 0ffffffffh
data ENDS

stack segment stack
    dw 100 dup(0)
stack ends

code segment
    assume cs:code
start:
    mov ax,data
    mov ds,ax
    mov bx,1234h
    mov word ptr vector,bx
    mov word ptr vector+2,es
    mov ax,4c00h
    int 21h

code ends

end start