dis macro msg                  ;macro to display string
lea dx,msg
mov ah,09h
int 21h
endm


.model small
.data

f1 db 24 dup (0)
f2 db 24 dup (0)
buff db 10 dup ('$')
h1 dw 0000h
h2 dw 0000h
temp dw 0000h

msg1 db 10,10,13, "File can not be opened$"
msg2 db 10,10,13, "File successfully opened$"
msg3 db 10,10,13, "File can not be created$"
msg4 db 10,10,13, "File successfully created$"
msg5 db 10,10,13, "Unable to read$"
msg7 db 10,10,13, "Unable to write$"
msg8 db 10,10,13, "Successfully copied$"


.code
start:

mov ax,@data
mov ds,ax
mov es,ax

mov ah,62h                   ;interrupt to get psp address    
int 21h

mov es,bx

lea si,es:0080h              ;length of command tail
mov cl,es:[si]

inc si
inc si
dec cl
lea di,f1

u1:mov bl,es:[si]
   cmp bl,20h
   je u2
   mov [di],bl
   inc si
   inc di
   dec cl
   jmp u1

u2:inc si
   mov [di],'00'
   lea di,f2
   dec cl

u3:mov bl,es:[si]
   mov [di],bl
   inc si
   inc di
   dec cl
   jnz u3

   mov [di],'00'

lea dx,f1
mov al,02h

mov ah,3dh                            ;interrupt to open file
int 21h

jc l1
mov h1,ax
dis msg2

   lea dx,f2
   mov cx,0000h
   
   mov ah,5bh                      ;interrupt to create file
   int 21h

   jc l3
   mov h2,ax
   dis msg4
   jmp l5 

l3:dis msg3 
   jmp go

l5:lea dx,buff
   mov cx,0ah
   mov bx,h1

   mov ah,3fh                 ;interrupt to read contents of file
   int 21h
   jc l6
   cmp ax,0000h
   je l9
   mov temp,ax
   jmp t

l6:dis msg5
   jmp go
   
   
t: lea dx,buff
   mov cx,temp
   mov bx,h2

  mov ah,40h
  int 21h
  jc l8
  jmp l5

jmp go

l1:dis msg1
   jmp go

l8:dis msg7
   jmp go

l9:dis msg8

go:mov ah,4ch
   int 21h

end;
