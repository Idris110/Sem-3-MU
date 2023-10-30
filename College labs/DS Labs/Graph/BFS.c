#include<stdio.h>
#include<stdlib.h>

struct Queue{
    int size;
    int front;
    int rear;
    int* arr;
};
int isFull(struct Queue* q){
    if(q->rear==q->size-1){
        return 1;
    }
    return 0;
}
int isEmpty(struct Queue* q){
    if(q->front>=q->rear){
        return 1;
    }
    return 0;
}
struct Queue* enqueue(struct Queue* q,int data){
    if(q->rear!=q->size-1){
        q->rear++;
        q->arr[q->rear]=data;
        return q;
    }
}
int dequeue(struct Queue *q){
    int b = -1;
    if(isEmpty(q)){
        printf("This Queue is empty\n");
    }
    else{
        q->front++;
        b = q->arr[q->front]; 
    }
    return b;
}


int main(){
    struct Queue q ;
    q.size=20;
    q.front=-1;
    q.rear=-1;
    q.arr=(int*)malloc(q.size*sizeof(int));

    int a[20][20],visited[20],n,start;

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
    enqueue(&q,start);

    while(!isEmpty(&q)){
        int node = dequeue(&q);
        for(int j=0;j<n;j++){
            if(a[node][j]==1 && visited[j]==0){
                printf("%d ",j);
                visited[j] = 1;
                enqueue(&q,j);
            }
        }
    }
   
}