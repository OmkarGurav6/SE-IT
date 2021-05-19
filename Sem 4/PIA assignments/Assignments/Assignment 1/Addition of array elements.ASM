.model small
.data
 n dw 0001h,0002h,0003h,0004h,0005h,0006h,0007h,0008h,0000h
 msg1 db 10,13,  "Addition is:$"

.code
start:
       mov ax,@data            ;get starting address of data segment 
       mov ds,ax               ;move to ds register
       lea si,n               ;get offset address of array n in si pointer
     lea dx,msg1              ;get offset address of the string
     mov ah,09h               ;to display the string
     int 21h

       mov cl,08h                ;set counter to 8
       mov ax,[si]               ;move contents of si to ax
       up:inc si                 ; increment si pointer
       inc si
       add ax,[si]               ;add contents of si to ax one by one
       dec cl                     ;decrement counter
       jnz up                    ;jump if not zero to up

       mov cl,04h                   ;counter set to 4
    a1:rol ax,04h                   ;rotate to left 4 times
       push ax                       ;push contents of ax to stack
       and ax,000fh                    ;masking of contents in ax
       cmp ax,09h                     ;compare if less than 9
       jbe l1                         ;jump if below or equal
       add ax,37h                     ; if false add 37
       jmp l2                         ;unconditional jump
    l1: add ax,30h                    ;if condition true add 30
    l2: mov dx,ax                      ;move contents of ax to dx
        mov ah,02h                    ; to display the addition
        int 21h
        pop ax
        dec cl
        jnz a1

       mov ah,4ch
       int 21h

end start
