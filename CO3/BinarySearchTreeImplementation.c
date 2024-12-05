#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *right;
    struct node *left;
};

struct node *new_node(int x)
{
    struct node *p;
    p=(struct node *)malloc(sizeof(struct node));
    p->data=x;
    p->left=NULL;
    p->right=NULL;
    return p;
}

struct node *insert(struct node *root, int x)
{
    if(root==NULL)
    {
        return new_node(x);
    }
    else if(x>root->data)
    {
        root->right=insert(root->right,x);
    }
    else
    {
        root->left=insert(root->left,x);
    }
    return root;
}

void inorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

void preorder(struct node *root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}
struct node *find_minimum(struct node *node)
{
    struct node *current = node;
    while(current && current->left != NULL)
    current = current->left;
    
    return current;
}
struct node *deleteNode(struct node *root, int x)
{
    if(root == NULL) 
        return root;
    
    if(x < root->data)
        root->left = deleteNode(root->left, x);
    
    else if(x > root->data)
        root->right = deleteNode(root->right, x);
    else {
        if(root->left == NULL) {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL) {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
            struct node *temp = find_minimum(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

struct node *search(struct node *root, int x)
{
    if(root == NULL || root->data == x)
    return root;
    else if(x>root->data)
    return search(root->right,x);
    else
    return search(root->left,x); 
}

int main(){
    struct node *root=NULL;
    int ch,x;
    struct node *t;
    printf("Enter the data to insert: ");
    scanf("%d",&x);
    root=new_node(x);
    while(1){
        printf("\n\nMenu:\n1.Insertion\n2.Inorder Traversal\n3.Preorder Traversal\n4.Postorder Traversal\n5.Delete elements\n6.Search elements\n7.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch (ch){
            case 1:
                printf("Enter the data to insert:");
                scanf("%d",&x);
                root=insert(root,x);
                break;
            case 2:
                printf("In-Order traversal of the tree:\n");
                inorder(root);
                printf("\n");
                break;
            case 3:
                printf("Pre-Order traversal of the tree:\n");
                preorder(root);
                printf("\n");
                break;
            case 4:
                printf("Post-Order traversal of the tree:\n");
                postorder(root);
                printf("\n");
                break;
            case 5:
                printf("\nDeletion:\n");
                printf("\nEnter the element to be deleted:");
                scanf("%d",&x);
                root = deleteNode(root,x);
                break;
            case 6:
                printf("\nEnter the element to search: ");
                scanf("%d",&x);
                t = search(root,x);
                if(t == NULL){
                    printf("\nElement not Found ");
                }
                else{
                    printf("\nElement Found");
                }
                break;
            case 7:
                return 0;
                break;
        }
    }
    return 0;
}

