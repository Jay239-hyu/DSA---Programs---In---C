#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

void InorderTraversal(struct Node* root)
{
    if(root != NULL)
    {
        InorderTraversal(root->left);  
        printf("%d " , root->data);
        InorderTraversal(root->right);  
    }  
}


struct Node *createNode(int data)
{
    struct Node *n;
    n = (struct Node *)malloc(sizeof(struct Node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;

    return n;
}

struct Node* inOrderPredecessor(struct Node* root)
{
    root = root->left;
    while(root->right != NULL)
    {
        root = root->right;

    }
    return root;
}
struct Node* deleteNode(struct Node* root , int val)
{
    struct Node* iPre;
    if(root == NULL) return NULL;
    if(root -> left == NULL && root -> right == NULL) 
    {
        free(root);
        return NULL;

    }

    //Search for the node to be deleted
    if(val < root->data)
    {
        root->left = deleteNode(root->left , val);
    }
    else if(val > root->data)
    {
        root->right = deleteNode(root->right , val);
    }
    else
    {
        iPre =inOrderPredecessor(root);
        root->data = iPre->data;
        root->left = deleteNode(root->left , iPre->data);
    }
    return root;    
}
int main()
{
    /*

    //Manually creating the Nodes:

    struct Node *p;
    p = (struct Node*)malloc(sizeof(struct Node));
    p->data = 2;
    p->left = NULL;
    p->right = NULL;

    struct Node *p1;
    p1= (struct Node*)malloc(sizeof(struct Node));
    p->data = 1;
    p1->left = NULL;
    p1->right = NULL;

    struct Node *p2;
    p2= (struct Node*)malloc(sizeof(struct Node));
    p->data = 4;
    p2->left = NULL;
    p2->right = NULL;

    */
    // Constructing Nodes - using Function
    struct Node *p = createNode(5); // Root Node
    struct Node *p1 = createNode(3);
    struct Node *p2 = createNode(6);
    struct Node *p3 = createNode(1);
    struct Node *p4 = createNode(4);

    // Linking the root Node with left and right child Nodes
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4; 
    
InorderTraversal(p);
printf("\n");
p = deleteNode(p , 3);
printf("\n");
InorderTraversal(p);
    





 

  

return 0;
}



