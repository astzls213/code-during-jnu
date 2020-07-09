code segment
    assume cs:code
go:
    mov ah,6         ; BIOS6号功能，al为0时清屏
    mov al,0
    mov bh,01110000b ; 通过bh设置灰色背景， 6 5 4三位设置R G B背景色
    mov cx,1900h         ; ch,cl左上角坐标，dh，dl右下角坐标。这个范围内会灰色
    mov dx,194fh     ; 80x25 column x row
    int 10h

    mov ah,6         ; BIOS6号功能，al为0时清屏
    mov al,1
    mov bh,01110000b ; 通过bh设置灰色背景， 6 5 4三位设置R G B背景色
    mov cx,0         ; ch,cl左上角坐标，dh，dl右下角坐标。这个范围内会灰色
    mov dx,184fh     ; 80x25 column x row
    int 10h

    mov ah,0
    int 16h

    mov ah,004Ch  ;terminate program
    int 21h
code ends

end go