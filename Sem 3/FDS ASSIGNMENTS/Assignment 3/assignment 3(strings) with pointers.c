#include<stdio.h>
#include<stdlib.h>

/*length of string*/
 int  length(char *s)
   {
    int i,c=0;
    for(i=0;*(s+i)!='\0';i++)
    c++;
    return c;
   }

/*palindrone of  string*/
int palindrone(char *s)
  {
   int l,i;
   l=length(s);
   for(i=0;i<(l/2);i++)
    {
     if(*(s+i)!=*(s+l-i-1))
    break;
    }
    if((i)==(l/2))
    printf("String is palindrone \n");
    else
    printf("String is not a Palindrone \n");
    return 0;
  }

/*comparison of two strings*/
int compare(char *s,char *s1)
  {
   int a,b;
   printf("Enter another string\n");
   scanf("%s",s1);
   a=length(s);
   b=length(s1);
   if(a-b<0)
    printf("String %s is larger than string %s",s1,s);
   if(a-b>0)
    printf("String %s is smaller than string %s",s1,s);
   if(a-b==0)
    printf("String have same length");
   return 0;
  }

/*copy of string*/
int copy(char *s,char *s1)
 {
   int i;
  for(i=0;*(s+i)!='\0';i++)
   {
    *(s1+i)=*(s+i);
   }
   *(s1+i)='\0';
   printf("String is copied\nThe copied string is %s\n",s1);
  return 0;
 }

/*reverse of string*/
int reverse(char *s,char *s1)
 {
  int i,l,j;
  l=length(s);
  for(i=l-1,j=0;i>=0,j<=l-1;i--,j++)
  {
   *(s1+i)=*(s+j);
  }
   *(s1+l)='\0';
  printf("Reverse string is %s\n",s1);
  return 0;
 }

 /*substring of string*/
 int substring(char *s,char *s1)
 {
  printf("Enter another string\n");
   scanf("%s",s1);
  int i,j,l;
  l=length(s1);
  for(i=0,j=0;s[i]!='\0' &&s1[j]!='\0';i++)
  {
      if(*(s+i)==*(s1+j))
        j++;
      else
        j=0;
  }
  if(j==l)
       printf("Substring is present in string at index %d\n",i-j);
    else
     printf("Substring is not present in string\n");
     return 0;
 }


int  main()
  {
   int ch,c,i,y;
   char *s=(char*)malloc(sizeof(char));
    char *s1=(char*)malloc(sizeof(char));

   printf("Enter the string\n\n");
   scanf("%s",s);

  do
  {
   printf("1.length of string\n");
   printf("2.palindrone of string\n");
   printf("3.comparison of two strings\n");
   printf("4.copy of string\n");
   printf("5.reverse of string\n");
   printf("6.substring of string\n");
   printf("7.Exit\n\n");
   printf("Enter your choice\n");
   scanf("%d",&ch);

  switch(ch)
  {
    case 1:
    c=length(s);
    printf("length of string is %d\n",c);
    break;

    case 2:
    palindrone(s);
    break;

    case 3:
    compare(s,s1);
    break;

    case 4:
    copy(s,s1);
    break;

    case 5:
    reverse(s,s1);
    break;

    case 6:
    substring(s,s1);
    break;

    case 7:
    exit(0);
    break;

    default:
    printf("Invalid choice!\nEnter number between 1-7\n");
    break;
  }
  printf("\nDo u want to perform another operation? (0/1)");
  scanf("%d",&y);
  }
  while(y==1);

  return 0;
}
