#include<stdio.h>
#include<stdlib.h>

struct node{
    int data ;
    struct node *right,*left;
};

struct node *createNode(int data){
    struct node* tree;
    tree=(struct node*)malloc(sizeof(struct node));
    tree->left=tree->right=NULL;
    tree->data=data;
    return tree;
}

struct node *createBST(int data){
        return createNode(data);
}

void insert(struct node *root,int data){
    if(data < root->data){
        if(root->left==NULL){
            root->left=createNode(data);
            return NULL;
        }
        else{
            insert(root->left,data);
        }
    }
    else if(data > root->data){
        if(root->right==NULL){
            root->right=createNode(data);
            return NULL;
        }
        else{
            insert(root->right,data);
        }
    }
}

struct node *preorder(struct node *root){
    if(root==NULL) return NULL;

    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

struct node *inorder(struct node *root){
    if(root==NULL) return NULL;

    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

struct node *postorder(struct node *root){
    if(root==NULL) return NULL;

    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}

int smallest(struct node *root){
    if(root->left==NULL) {       //go to left extreme
        return root->data;
    }
    smallest(root->left);
}

int largest(struct node *root){
    if(root->right==NULL) {       //go to right extreme
        return root->data;
    }
    largest(root->right);
}

void mirror(struct node *root){
    if(root==NULL) return NULL;
    mirror(root->left);
    mirror(root->right);

    struct node *temp = root->left;
    root->left=root->right;
    root->right=temp;
}

int countNodes(struct node*root){
    if(root==NULL) return 0;

    return(countNodes(root->left)+countNodes(root->right)+1);
}

int internalNodeCount(struct node*root){
    if(root==NULL) return 0;
    if((root->right==NULL && root->left==NULL)) return 0;

    return(internalNodeCount(root->left)+internalNodeCount(root->right)+1);
}

int LeafNodeCount(struct node*root){
    if(root==NULL) return 0;
    if(root->right==NULL && root->left==NULL) return 1;

    return(LeafNodeCount(root->right) + LeafNodeCount(root->left));
}

int height(struct node *root){
    if(root==NULL) return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return(__max(leftHeight,rightHeight)+1);
}

struct node* deleteNode(struct node*root,int data){
    if(data<root->data) 
        root->left= deleteNode(root->left,data);
    else if(data>root->data) 
        root->right= deleteNode(root->right,data);

    else{
        if(root->right==NULL && root->left==NULL){
            free(root);
            return NULL;
        }
        else if(root->right==NULL || root->left==NULL){
            struct node* temp;

            if(root->right!=NULL) temp =root->right;
            else temp =root->left;

            free(root); 
            return temp;
        }
        else{
            int inorderSucc= smallest(root->right);
            root->data=inorderSucc;
            root->right= deleteNode(root->right,inorderSucc);
        }
    }
}

struct node* deleteTree(struct node*root){
    if(root==NULL) return NULL;
    if(root->right==NULL && root->left==NULL){
        printf("%d ",root->data);
        free(root);
        return NULL;
    }
    root->left =deleteTree(root->left);
    root->right= deleteTree(root->right);
    deleteTree(root);
}

int main()
{
    struct node *root=NULL;
    int option,val;
    
    do{
        printf("\n\n----------------------------- MAIN MENU ------------------------------------------");
        printf("\n 1. Insert Element");
        printf("\t\t\t 2. Preorder Traversal");
        printf("\n 3. Inorder Traversal");
        printf("\t\t\t 4. Postorder Traversal");
        printf("\n 5. Find the smallest element");
        printf("\t\t 6. Find the largest element");
        printf("\n 7. Delete an element");
        printf("\t\t\t 8. Count total number of nodes");
        printf("\n 9. Count total number of leaf nodes");
        printf("\t 10. Count total number of internal nodes");
        printf("\n 11. Determine the height of the tree");
        printf("\t 12. Find the mirror image of the tree");
        printf("\n 13. Delete the tree");
        printf("\t\t\t 14. Exit\n");

        printf("\n Enter your option : ");
        scanf("%d", &option);
        switch (option)
        {
            case 1:
                printf("\n Enter the value of the new node : ");
                scanf("%d", &val);
                if(root==NULL) {
                root=createBST(val);
                }
                else insert(root,val);
                break;
            case 2:
                printf("\n The elements of the tree in preorder are : ");
                preorder(root);
                break;
            case 3:
                printf("\n The elements of the tree in inorder are : ");
                inorder(root);
                break;
            case 4:
                printf("\n The elements of the tree in postorder are : ");
                postorder(root);
                break;
            case 5:
                printf("\n Smallest element is :%d",smallest(root));
                break;
            case 6:
                printf("\n Largest element is : %d",largest(root));
                break;
            case 7:
                printf("\n Enter the element to be deleted : ");
                scanf("%d", &val);
                deleteNode(root, val);
                break;
            case 8:
                printf("\n Total no. of nodes = %d", countNodes(root));
                break;
            case 9:
                printf("\n Total no. of leaf nodes = %d",LeafNodeCount(root));
                break;
            case 10:
                printf("\n Total no. of internal nodes = %d",internalNodeCount(root));
                break;
            case 11:
                printf("\n The height of the tree = %d", height(root)-1);
                break;
            case 12:
                mirror(root);
                break;
            case 13:
                root=deleteTree(root);
                break;
        }
    } while(option != 14);

    return 0;
}