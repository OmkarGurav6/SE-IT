
.model small
.data

.code
start:

mov bx,0000h
mov cl,04h

up:mov ah,01h      ;accept single digit
   int 21h

   cmp al,039h     ;compare for digits
   jbe l1

   cmp al,046h     ;compare for capital letters
   jbe l2

   sub al,057h
   jmp l3

   l1:sub al,030h
      jmp l3

   l2:sub al,037h
      jmp l3

   l3:shl bx,04h
      add bl,al
      dec cl
      jnz up


mov ah,04ch
int 21h

end;
