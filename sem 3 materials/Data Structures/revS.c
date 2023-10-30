#include <stdio.h>  
#include <string.h>  
  
#define max 100  
int top, stack[max];  
  
void push(char x){  
  
      // Push(Inserting Element in stack) operation  
      if(top == max-1){  
          printf("stack overflow");  
      }  else {  
          stack[++top]=x;  
      }  
  
}  
  
char pop(){  
    // Pop (Removing element from stack)  
      return stack[top--];  
}  

  
  
main()  
{  
    printf("Enter a string : ");
   char str[20];
   scanf("%s",str);  
   int len = strlen(str);  
   int i;  
  
   for(i=0;i<len;i++)  
        push(str[i]);  
  
    printf("reversed string : ");
   for(i=0;i<len;i++)  
      printf("%c",pop()); 
} 