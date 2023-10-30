#include<stdio.h>
#include<stdlib.h>

struct queue
{
    int data;
    struct queue *next;
};

struct queue *front=NULL,*ptr,*temp;

struct queue *createnode(){
    struct queue *newnode;
    newnode = (struct queue*)malloc(sizeof(struct queue));
    printf("Enter the number to enqueued : ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    
    return newnode;
}

void enqueue(){
    struct queue *newnode=createnode();

    if(front==NULL) front=ptr=newnode;
    else{
        ptr->next=newnode;
        ptr=newnode;
    }
}

void dequeue(){
    
    if(front==NULL) printf("Underflow\n");
    else{
        printf("Dequeued element : %d\n",front->data);
        front=front->next;
    }
}

void display(){
    struct queue ;
    if(front==NULL) printf("No elements in the queue\n");
    else{
        temp=front;
        printf("Elements in queue : ");
        while (temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}

int main()
{
    do{
        int choice;
        printf("\n1. ENQUEUE   2. DEQUEUE   3. DISPLAY   4. EXIT\nEnter your choice : ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
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