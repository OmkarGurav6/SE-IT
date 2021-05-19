dis macro msg               ;macro to display string
lea dx,msg
mov ah,09h
int 21h
endm


.model small
.data
msg1 db 10,13, "MENU$"
msg2 db 10,13, "1.Length of string$"
msg3 db 10,13, "2.Reverse of string$"
msg4 db 10,13, "3.Palindrome$"
msg5 db 10,13, "4.EXIT$"
msg6 db 10,13, "Enter your choice :$"
msg7 db 10,13, "Enter string :$"
msg8 db 10,13, "Length of string :$"
msg9 db 10,13, "Reverse of string :$"
msg10 db 10,13, "String is palindrome $"
msg11 db 10,13, "String is not palindrome $"
str1 db 24 dup ('$')
str2 db 24 dup ('$')

.code
start:

mov ax,@data
mov ds,ax
mov es,ax

dis msg7

lea dx,str1
mov ah,0ah               ;accept string
int 21h

up1:dis msg1
   dis msg2
   dis msg3
   dis msg4
   dis msg5
   dis msg6

   mov ah,01h            ;accept single digit
   int 21h

   cmp al,31h
   je l1
   cmp al,32h
   je l2
   cmp al,33h
   je l3
  
  jmp l4


   l1:call lh        ;calls proc to calculate length of string
      jmp up1

   l2:call reverse      ;calls proc to reverse string
      jmp up1

   l3:call palindrome     ;calls proc to  check if string is palindrome
     jmp up1

   l4:mov ah,4ch          ;termination
     int 21h


   lh proc near                    ;length of string

   lea si,str1+1
   mov bl,[si]
   mov bh,00h
   mov cl,04h

   dis msg8

   up:rol bx,04h
      push bx
      and bx,000fh
      cmp bx,09h
      jbe dig
      add bx,037h
      jmp l12

      dig:add bx,030h

      l12:mov dx,bx
         mov ah,02h
         int 21h
         pop bx
         dec cl
         jnz up


    ret
    endp


   reverse proc near                      ;reverse string

   lea di,str2
   lea si,str1+1
   mov cl,[si]            ;storing length of string for reversing
   mov ch,[si]            ;storing length of string for pointing to last character

   rev:inc si
       dec ch
       jnz rev

   dis msg9

   rev1:mov bl,[si]
        mov [di],bl

        inc di
        dec si
        dec cl
        jnz rev1

   dis str2


   ret 
   endp


   palindrome proc near                  ;check if string is palindrome 

   call reverse

   lea si,str1+1
   mov cl,[si]
   mov ch,00h
   inc si
   lea di,str2

   cld
   repe cmpsb
   jz na

   dis msg11
   jmp ex

   na:dis msg10

   ex:

   ret
   endp

end;
