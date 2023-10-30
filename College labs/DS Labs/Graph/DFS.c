#include<stdio.h>
#include<stdlib.h>

int visited[20];
int a[20][20],n;

void DFS(int i){
    int j;
    printf("%d ",i);
    visited[i] = 1;
    for(int j=0;j<n;j++){
        if(a[i][j]==1 && visited[j]==0){
            DFS(j);
        }
    }
}


int main(){
    
    int start;

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

    printf("DFS traversal :");
    DFS(start);
}