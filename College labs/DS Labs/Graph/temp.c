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

int isfull(queue q){
    return q->rear == q->capcacity-1;
}
int isempty(queue q){
    return q->rear ==-1 && q->front==-1;
}

void enqueue(queue q,int data){
        q->rear++;
        q->arr[q->rear]=data;
}

int dequeue(queue q){
    return q->arr[q->front++];
}

int main()
{
    int a[20][20],visited[20],n,start;
    queue q;
    q=createQueue(20);
        printf("Enter the number of vertices in graph :");
        scanf("%d",&n);
        printf("Enter the adjacency matrix :\n");
        for(int i=0;i<n;i++){
            visited[i]=0;
            for(int j=0;j<n;j++){
                scanf("%d",&a[i][j]);
            }
        }
        printf("Enter the starting vertex :");
        scanf("%d",&start);
    
    printf("BFS traversal : %d ",start);
    visited[start]=1;
    enqueue(q,start); //enqueue the first node

    while(isempty(q)){
        int node= dequeue(q);
        for(int i=0;i<n;i++){
            if(a[node][i]==1 && visited[i]==0){
                printf("%d ",i);
                visited[i]=1;
                enqueue(q,i);
                printf("enquqing %d",i);
            }
        }
    }
    
    return 0;
}
