s macro msg
lea dx,msg            ;display string
mov ah,09h
int 21h
endm

.model small
.data
msg1 db 10,13, "Menu$"
msg2 db 10,13, "1.Hex to BCD$"
msg3 db 10,13, "2.BCD to Hex$"
msg4 db 10,13, "3.EXIT$"
msg5 db 10,13, "Enter your choice :$"
msg6 db 10,13, "Enter hexadecimal number : $"
msg7 db 10,13, "Equivalent BCD no is : $"
msg8 db 10,13, "Enter BCD number :$"
msg9 db 10,13, "Equivalent hexdecimal no is :$"
n1 db 00h,00h,00h,00h,00h
n2 dw 0000h,0000h,0000h,0000h,0000h



.code
start:

mov ax,@data
mov ds,ax

up:s msg1
   s msg2
   s msg3
   s msg4
   s msg5

   mov ah,01h                 ;accept choice
   int 21h

   cmp al,31h
   je l1

   cmp al,32h
   je l2

   jmp l3


   l1:call htob
      jmp up

   l2:call btoh
      jmp up

   l3:mov ah,4ch            ;termination
      int 21h


   htob proc near              ;hex to bcd

   s msg6

   mov cl,04h

   down:mov ah,01h              ;accept digit
        int 21h
        cmp al,39h
       jbe l4

      cmp al,46h
      jbe l5

      sub al,57h
      jmp l6

      l4:sub al,30h
         jmp l6

      l5:sub al,37h
         jmp l6

      l6:shl bx,04h
         add bl,al
         dec cl
         jnz down

      mov cl,0000h
      mov ax,bx
      mov bx,000ah
         
      u1:mov dx,0000h
         div bx
         push dx
     
         inc cl
         cmp ax,0000h
         jnz u1

        s msg7
        u2:pop dx
         add dx,30h
         mov ah,02h        ;display digit
         int 21h
         dec cl
         jnz u2 


   ret
   endp


   btoh proc near          ;bcd to hex

    s msg8

    mov ax,@data
    mov ds,ax
    lea si,n1
    mov cl,05h

  up0:mov ah,01h     ;accept digit
      int 21h
      sub al,30h
      mov [si],al
      inc si
      dec cl
      jnz up0

     mov cl,05h
     dec si
     mov bx,0001h

     lea di,n2

   t:mov ah,00h
     mov al,[si]
     mul bx
     mov [di],ax
     inc di
     inc di
     dec si
     mov ax,000ah
     mul bx
     mov bx,ax
     dec cl
     jnz t

     lea di,n2
     mov bx,0000h
     mov cl,05h

   up1:add bx,[di]
       inc di
       inc di
       dec cl                    
       jnz up1                    

       mov cl,04h                  
       s msg9
    a1:rol bx,04h
       push bx                      
       and bx,000fh                   
       cmp bx,09h                    
       jbe l12                         
       add bx,37h                     
       jmp l23                        
    l12: add bx,30h
    
    l23: mov dx,bx                     
        mov ah,02h            ;display digit       
        int 21h
        pop bx
        dec cl
        jnz a1

   ret
   endp

end;


