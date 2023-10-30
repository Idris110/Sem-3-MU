#include<stdio.h>
#include<stdlib.h>

struct Queue
{
    int capcacity;
    int rear,front;
    int *arr;
};

typedef struct Queue *PtrToNode;
typedef PtrToNode queue;

queue createQueue(int maxSize){
    queue q= (struct Queue*)malloc(sizeof(struct Queue));
    q->capcacity=maxSize;
    q->rear=q->front=-1;
    q->arr= (int*)malloc(maxSize*sizeof(int));
    return q;
}

int isfull(queue q){
    return q->rear == q->capcacity-1;
}
int isempty(queue q){
    return q->rear ==-1 && q->front==-1;
}

queue enqueue(queue q,int data){
    if(isfull(q)) printf("Overflow\n");
    else{
        int pos=q->rear;
        q->rear=q->rear+1;
        while(pos>=0 && q->arr[pos]>data){
            q->arr[pos+1] = q->arr[pos];
            pos--;
        }
        q->arr[pos+1]=data;
        if(q->front==-1) q->front=0;
    }

    return q;
}

queue dequeue(queue q){
    if(isempty(q)) printf("underflow !\n");
    else if(q->front==q->rear) {
        printf("Element dequeued : %d\n", q->arr[q->front]);
        q->front=q->rear=-1;
    }
    else{
        printf("Element dequeued : %d\n", q->arr[q->front]);
        q->front++;
    }
    return q;
}

void display(queue q){
    if(isempty(q)) printf("Queue is Empty\n");
    else{
        printf("Elements in queue : ");
        for (int i = q->front; i <= q->rear; i++) printf("%d ",q->arr[i]);
        printf("\n");
    }
}

void search(queue q,int data){
    int i;
    for(i=q->front;i<=q->rear;i++)
        if(q->arr[i]==data){
            printf("Index of given element is %d",i);
            break;
        }
    printf("%s\n",(i==q->rear+1)?"Not found":"");
}

int main(int argc, char const *argv[])
{
    int maxSize = 10,choice,data;
    queue q;
    q=createQueue(maxSize);
    do{
        printf("\n1.Enqueue  2.Dequeue  3.Display  4.Search  5.Exit \n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        
        switch (choice)
        {
            case 1:
                printf("Enter the element to be inserted : ");
                scanf("%d",&data);
                q=enqueue(q,data);
                break;
            case 2:
                q=dequeue(q);
                break;
            case 3:
                display(q);
                break;
            case 4:
                printf("Enter the element to be searched : ");
                scanf("%d",&data);
                search(q,data);
                break;
            case 5:
                break;

            default:
                printf("Invalid choice ^_^");
        }

    }while(choice!=5);
    
    return 0;
}
