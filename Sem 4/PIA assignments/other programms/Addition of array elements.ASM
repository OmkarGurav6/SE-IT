.model small
.data
n1 dw 0001h,1232h,1243h,1111h,1122h

.code
start:

mov ax,@data
mov ds,ax
lea si,n1

mov cl,04h
mov ax,[si]

up:inc si
   inc si
   add ax,[si]
   dec cl
   jnz up

mov ah,4ch
int 21h

end;
