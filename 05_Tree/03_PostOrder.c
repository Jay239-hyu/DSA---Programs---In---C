#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *PostorderTraversal(struct Node* root)
{
    if(root != NULL)
    {
        PostorderTraversal(root->left);  
        PostorderTraversal(root->right);  
        printf("%d " , root->data);
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
    struct Node *p = createNode(4); // Root Node
    struct Node *p1 = createNode(1);
    struct Node *p2 = createNode(6);
    struct Node *p3 = createNode(5);
    struct Node *p4 = createNode(2);

    // Linking the root Node with left and right child Nodes
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    PostorderTraversal(p);

    return 0;
}



