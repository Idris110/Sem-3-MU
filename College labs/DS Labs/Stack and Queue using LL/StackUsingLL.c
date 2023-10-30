#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int data;
    struct stack *next;
};

struct stack *top=NULL,*ptr;

struct stack *createnode(){
    struct stack *newnode;
    newnode = (struct stack*)malloc(sizeof(struct stack));
    printf("Enter the number to be pushed onto the stack : ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    
    return newnode;
}

void push(){
    struct stack *newnode=createnode();

    newnode->next=top;
    top=newnode;
}

void pop(){
    if(top==NULL) printf("Underflow\n");
    else{
        printf("Poped element : %d\n",top->data);
        ptr=top;
        top=top->next;
        free(ptr);
    }
}

void display(){
    if(top==NULL) printf("No elements in the stack\n");
    else{
        ptr=top;
        printf("Elements in stack : ");
        while (ptr!=NULL)
        {
            printf("%d ",ptr->data);
            ptr=ptr->next;
        }
        printf("\n");
    }
}

int main()
{
    do{
        int choice;
        printf("\n1. PUSH   2. POP   3. DISPLAY   4. EXIT\nEnter your choice : ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;

        default:
            printf("Invalid choice !\n");
            break;
        }
    }while(1);
    
    return 0;
}
