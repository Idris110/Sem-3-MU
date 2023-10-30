#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head=NULL,*newnode,*ptr;

struct node *createnode(){
    //creating a new node
    newnode = (struct node*)malloc(sizeof(struct node)); //allocates mem to new node, newnode contains base add of new node

    printf("Enter the data : ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    return newnode;
}

int createll(){
    int length=0;
    while (1)
    {
        newnode=createnode();

        if(newnode->data==-1) {
            printf("Linked List created \n");
            return length;
        };
        //new node is created
        length++;
        //Linking this node to the List
        if(head==NULL) head= ptr= newnode;
        else{
            ptr->next=newnode;   //linking previous node's next to this (new)node
            ptr= newnode;        //updating our pointer to this (new)node                                                                                                                                                                                                                                                                                                                                                   
        }
    }
}

void display(){
    ptr = head;
    printf("Elements in list are :");
    while (ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}

void insertstart(){
    newnode=createnode();
    newnode->next = head;
    head = newnode;
}

void insertend(){
    newnode=createnode();
    ptr=head;
    while (ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=newnode;
}

void insertmidway(int after,int length,int beforeOrAfter){
    if(after>length) printf("Invalid index\n");
    else{
        ptr=head;
        for (int i = 1; i <= after-beforeOrAfter; i++)
        {
            ptr=ptr->next;
        }
        newnode=createnode();
        newnode->next= ptr->next;
        ptr->next=newnode;
    }
}

void deleteStart(){
    // ptr = head->next;
    // free(head);
    // head = ptr;
    ptr=head;
    if(ptr==NULL) return NULL;
    printf("%d ",ptr->data);
    deleteStart(ptr->next);
    printf("%d ",ptr->data);
}

void deleteEnd(){
    ptr = head;
    while (ptr->next->next!=NULL) 
    {
        ptr=ptr->next;
    }
    free(ptr->next->next);
    ptr->next=NULL; 
}

void delete(int at,int length){
    if(at>length) printf("Invalid index\n");
    else{
        struct node *temp;
        ptr=head;
        for (int i = 1; i <= at-2; i++)
        {
            ptr=ptr->next;
        }
        temp=ptr->next->next;
        free(ptr->next);
        ptr->next=temp;
    }
}

void deletell(){
    struct node *temp;
    ptr=head;
    head=NULL;
    while (ptr!=NULL)
    {
        temp=ptr;
        ptr=ptr->next;
        free(temp);
    }   
}

void sort(int n){
    for (int i = 0; i < n-1; i++){
        ptr=head;
        for(int j=0;j<n-i-1;j++){
            if(ptr->data > ptr->next->data){
                int temp= ptr->data;
                ptr->data=ptr->next->data;
                ptr->next->data=temp;
            }
            ptr=ptr->next;
        }
    }
    printf("After sorting in ascending order,\n");
}

int main()
{
    int length,at,choice;

    do{
        printf("\nMAIN MENU :\n");
        printf("1. To Create a list \t\t\t2. To Add a Node at the beginning \n3. To Add Node at the end \t\t4. To Add Node after the given node \n5. To Add Node before the given node \t6. To delete a Node at the beginning \n7. To delete a node from the end \t8. Delete a given Node\n9. Display the Linked List\t\t10. Delete entire List\n11. Sort the list \t\t\t12. Exit\nEnter the choice:");
    
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            length= createll();
            break;
        case 2:
            insertstart();
            length++;
            break;
        case 3:
            insertend();
            length++;
            break;
        case 4:
            printf("add a new node before :\n");
            scanf("%d",&at);
            insertmidway(at,length,1);// 2 for before and 1 for after
            length++;
            break;
        case 5:
            printf("add a new node before :\n");
            scanf("%d",&at);
            insertmidway(at,length,2);// 2 for before and 1 for after
            length++;
            break;
        case 6:
            deleteStart();
            break;
        case 7:
            deleteEnd();
            break;
        case 8:
            printf("Delete node at index :\n");
            scanf("%d",&at);
            delete(at,length);
            length--;
            break;
        case 9:
            display();
            break;
        case 10:
            deletell();
            length=0;
            break;
        case 11:
            sort(length);
            display();
            break;
        } 
    }while (choice != 12);

    display();

    return 0;
}