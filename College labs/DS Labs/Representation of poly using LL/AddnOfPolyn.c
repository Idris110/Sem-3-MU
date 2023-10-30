#include<stdio.h>
#include<stdlib.h>

struct term{
    int coeff,pow;
    struct term *next;
};
typedef struct term*ptrtonode;
typedef ptrtonode node;


node head1=NULL,head2=NULL,head3=NULL,ptr1,ptr2,ptr3;

struct term * createTerm(){
    struct term *newNode = (struct term*)malloc(sizeof(struct term));
    printf("Enter the exponent : ");
    scanf("%d",&newNode->pow);
    printf("Enter the coefficient of that term : ");
    scanf("%d",&newNode->coeff);
    return newNode;
}

void getPolynomial(){
    int n;
    printf("Enter the number of terms in 1st polynomial :");
    scanf("%d",&n);
    head1=ptr1=createTerm();
    for(int i=1;i<n;i++){
        struct term *newNode=createTerm();
        ptr1->next=newNode;
        ptr1=newNode;
    }
    ptr1->next=NULL;

    printf("\nEnter the number of terms in 2nd polynomial :");
    scanf("%d",&n);
    head2=ptr2=createTerm();
    for(int i=1;i<n;i++){
        struct term *newNode=createTerm();
        ptr2->next=newNode;
        ptr2=newNode;
    }
    ptr2->next=NULL;
}

void displaydebug(){
    ptr1=head3;
    while(ptr1!=NULL){
        if(ptr1!=head3)
        if(ptr1->coeff>=0) printf(" + ");
        else printf(" - ");
        printf("%dx^",ptr1->coeff);
        printf("%d",ptr1->pow);
        ptr1=ptr1->next;
    }
    printf("\n");
}

struct term *createNode(){
    struct term *newNode;
    newNode= (struct term*)malloc(sizeof(struct term));
    if(head3==NULL) head3=ptr3=newNode;
    else{
        ptr3->next=newNode;
        ptr3=newNode;
    }
    return newNode;
}

void addPolynomial(){
    struct term *newNode;
    ptr1=head1;
    ptr2=head2;
    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1->pow==ptr2->pow){
            newNode= createNode();
            newNode->coeff=ptr1->coeff+ptr2->coeff;
            newNode->pow=ptr1->pow;
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        else if(ptr1->pow>ptr2->pow){
            newNode= createNode();
            newNode->coeff=ptr1->coeff;
            newNode->pow=ptr1->pow;
            ptr1=ptr1->next;
        }
        else{
            newNode= createNode();
            newNode->coeff=ptr2->coeff;
            newNode->pow=ptr2->pow;
            ptr2=ptr2->next;
        }
    }
    if(ptr1!=NULL){
        while(ptr1!=NULL){
            newNode= createNode();
            newNode->coeff=ptr1->coeff;
            newNode->pow=ptr1->pow;
            ptr1=ptr1->next;
        }
    }
    if(ptr2!=NULL){
        while(ptr2!=NULL){
            newNode= createNode();
            newNode->coeff=ptr2->coeff;
            newNode->pow=ptr2->pow;
            ptr2=ptr2->next;
        }
    }
    ptr3->next=NULL;
}

int main()
{
    getPolynomial();
    addPolynomial();
    displaydebug();
    return 0;
}
