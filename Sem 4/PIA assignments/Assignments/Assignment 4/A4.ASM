dis macro msg                  ;macro to display string
lea dx,msg
mov ah,09h
int 21h
endm


dis1 macro str                ;macro to accept string 
lea dx,str
mov ah,0ah
int 21h
endm


.model small
.data
msg1 db 10,10,13, "MENU$"
msg2 db 10,13, "1.Concatenation of 2 strings$"
msg3 db 10,13, "2.Comparison of 2 strings$"
msg4 db 10,13, "3.Substring$"
msg5 db 10,13, "4.Counting $"
msg6 db 10,13, "5.Exit $"
msg7 db 10,10,13, "Enter your choice :$"
msg8 db 10,10,13, "Enter string :$"
msg9 db 10,10,13, "Invalid choice!!$"
msg10 db 10,13, "Concatenation is :$"
msg11 db 10,13, "Strings are not equal$"
msg12 db 10,13, "Strings are equal$"
msg13 db 10,13, "Substring count :$"
msg14 db 10,13, "Words count :$"
msg15 db 10,13, "Special character count :$"
msg16 db 10,13, "Numbers count :$"
msg17 db 10,13, "Lower case letters count :$"
msg18 db 10,13, "Capital case letters count :$"
str1 db 24 dup ('$') 
str2 db 24 dup ('$')
str3 db 24 dup ('$')

count_smal dw 0000h
count_capal dw 0000h
count_num dw 0000h
count_spl dw 0000h
count_wrds dw 0000h

.stack             
.code
start:

public msg1                          ;public messages
public msg2
public msg3
public msg4
public msg5
public msg6
public msg7
public msg8
public msg9
public msg10
public msg11
public msg12
public msg13
public msg14
public msg15
public msg16
public msg17
public msg18

public str1                         ;public data members
public str2
public str3
 
public count_smal 
public count_capal 
public count_num
public count_spl 
public count_wrds 



extrn cat:far                        ;external procedure
extrn comp:far                       
extrn subs:far                       
extrn count:far                      

mov ax,@data                   
mov ds,ax
mov es,ax

 up:dis msg1
    dis msg2
    dis msg3
    dis msg4
    dis msg5
    dis msg6
    dis msg7

   mov ah,01h                  ;accept choice
   int 21h

   cmp al,36h
   jge l6

   cmp al,31h
   je l1

   cmp al,32h
   je l2

   cmp al,33h
   je l3

   cmp al,34h
   je l4

   jmp l5

   l6:dis msg9
      jmp up

   l1:dis msg8
      dis1 str1
      dis msg8
      dis1 str2
      call cat                  ;call procedure for cocatenation
      jmp up

   l2:dis msg8
      dis1 str1
      dis msg8
      dis1 str2
      call comp                ;call procedure for comparison
      jmp up

   l3:dis msg8
      dis1 str1
      dis msg8
      dis1 str2
      call subs                ;call procedure for substring
     jmp up

   l4:dis msg8
      dis1 str1
      call count              ;call procedure for counting
     jmp up

   l5:mov ah,4ch              ;terminate
      int 21h


end;
