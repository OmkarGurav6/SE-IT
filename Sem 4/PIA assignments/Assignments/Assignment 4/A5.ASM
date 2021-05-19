disp macro msg                         ;macro to display string
lea dx,msg
mov ah,09h
int 21h
endm

.model small
.data

extrn msg1:byte
extrn msg2:byte
extrn msg3:byte
extrn msg4:byte
extrn msg5:byte
extrn msg6:byte
extrn msg7:byte
extrn msg8:byte
extrn msg9:byte
extrn msg10:byte
extrn msg11:byte
extrn msg12:byte
extrn msg13:byte
extrn msg14:byte
extrn msg15:byte
extrn msg16:byte
extrn msg17:byte
extrn msg18:byte

extrn str1:byte
extrn str2:byte
extrn str3:byte

extrn count_smal:word
extrn count_capal:word
extrn count_num:word
extrn count_spl:word
extrn count_wrds:word


.code
start:

public cat
public comp
public subs
public count


cat proc far               ;procedure for concatenation

lea si,str1+1
lea di,str3+2
mov cl,[si]
inc si

cld
repe movsb

lea si,str2+1
mov cl,[si]
inc si

cld
repe movsb

disp msg10

lea dx,str3+2
mov ah,09h
int 21h

ret
endp

comp proc far                    ;procedure for comparison

lea si,str1+1
mov bl,[si]
inc si

lea di,str2+1
mov al,[di]
inc di

sub al,bl
jz s1

jmp s2

s1:mov cl,bl

   cld
   repe cmpsb

   jnz s2

   disp msg12
    jmp go

s2:disp msg11

go:

ret
endp


subs proc far                        ;procedure for substring

mov al,str1+1
lea si,str1+2

mov dx,0000h
mov bl,00h

up1:lea di,str2+2
    mov cl,str2+1

    cld
    repe cmpsb
    jnz e

    inc bl

    e:add dx,0001h
      lea si,str1+2
      add si,dx
      dec al
      jnz up1

    disp msg13

    mov al,bl
    mov ah,00h
    mov ch,04h

q:rol ax,04h
  push ax
  and ax,000fh
  cmp ax,09h
  jbe dig

  add ax,037h
  jmp l1

  dig:add ax,030h

  l1:mov dx,ax
     mov ah,02h
     int 21h
     pop ax
     dec ch
     jnz q

ret
endp


count proc far                   ;procedure for counting 

mov count_smal,0000h
mov count_capal,0000h
mov count_num,0000h
mov count_spl,0000h
mov count_wrds,0000h

lea si,str1+1
mov cl,[si]
inc si


n1: mov bl,[si]
    cmp bl,20h
    je space

   mov bl,[si]
   cmp bl,29h
   jbe sp1

b0:mov bl,[si]
   cmp bl,39h
   jbe nu

b1:mov bl,[si]
   cmp bl,5Ah
   jbe uc

b2:mov bl,[si]
   cmp bl,7ah
   jbe lc

k1:jmp k

space: inc count_wrds
       jmp k

sp1: mov bl,[si]
     cmp bl,21h
     jge sp12
     jmp b0

nu: mov bl,[si]
    cmp bl,30h
    jge nu1
    jmp b1

uc: mov bl,[si]
    cmp bl,41h
    jge uk
    jmp b2

lc: mov bl,[si]
    cmp bl,61h
    jge lk
    jmp k1

uk: inc count_capal
    jmp k

lk: inc count_smal
    jmp k

sp12: inc count_spl
      jmp k

nu1: inc count_num
    jmp k


k: inc si
   dec cl
   jnz n1

   inc count_wrds

   mov bx,0000h
   disp msg15
   mov bx,count_spl
   call dispc

   disp msg16
   mov bx,count_num
   call dispc

   disp msg18
   mov bx,count_capal
   call dispc

   disp msg17
   mov bx,count_smal
   call dispc

   disp msg14
   mov bx,count_wrds
   call dispc


ret
endp

dispc proc near

 mov cl,04h

q1:rol bx,04h
  push bx
  and bx,000fh
  cmp bx,09h
  jbe dig1

  add bx,037h
  jmp l1

  dig1:add bx,030h

  l12:mov dx,bx
     mov ah,02h
     int 21h
     pop bx
     dec cl
     jnz q1

ret
endp

end;
