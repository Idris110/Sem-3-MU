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

queue createQueue(int max){
    queue q;
    q=(struct Queue*)malloc(sizeof(struct Queue));
    q->capcacity=max;
    q->front=-1,q->rear=-1;
    q->arr=(int*)malloc(max*sizeof(int));
    return q;
}

int circularIncrement(int n,int max){
    n++;
    //printf("\ncirInc: %d\n",(n==max) ? 0 : n);
    return (n==max) ? 0 : n;
}

int isfull(queue q){
    return (q->rear+1)%q->capcacity==q->front;
}
int isempty(queue q){
    return q->rear ==-1 && q->front==-1;
}

queue enqueue(queue q){
    if(isfull(q)) printf("Overflow !\n");
    else{
        q->rear=circularIncrement(q->rear,q->capcacity);
        printf("Enter the element to be inserted : ");
        scanf("%d",&q->arr[q->rear]);
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
        q->front=circularIncrement(q->front,q->capcacity);
    }
    return q;
}
void display(queue q){
    if(isempty(q)) printf("Queue is Empty\n");
    else{
        printf("Elements in queue : front =%d rear =%d\n",q->front,q->rear);

        int i=q->front;
        // for (int j=0;  j <= 10; j++)
        // {i=circularIncrement(i,q->capcacity);
        // printf("%d ",i);}
        while (1)
        {
            printf("%d ",q->arr[i]);
            if(i==q->rear) break;
            i=circularIncrement(i,q->capcacity);
        }
        
        printf("\n");
    }
}

int main(int argc, char const *argv[])
{
    int max = 3,choice;
    queue q;
    q=createQueue(max);
    do{
        printf("\n1.Enqueue  2.Dequeue  3.Display  4.Exit \n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        
        switch (choice)
        {
            case 1:
                q=enqueue(q);
                break;
            case 2:
                q=dequeue(q);
                break;
            case 3:
                display(q);
                break;
            case 4:
                break;

            default:
                printf("Invalid choice ^_^");
        }

    }while(choice!=4);
    
    return 0;
}