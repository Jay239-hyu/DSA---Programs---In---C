#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *InorderTraversal(struct Node* root)
{
    if(root != NULL)
    {
        InorderTraversal(root->left);  
        printf("%d " , root->data);
        InorderTraversal(root->right);  
    }  
}

struct Node* search(struct Node* root , int key)
{
    if(root == NULL) return NULL;
    if(root->data == key) return root;
    else if(root->data > key) return search(root->left , key);
    else return search(root->right , key);
}

int isBST(struct Node* root)
{
    static struct Node* prev = NULL;
    if(root!=NULL)
    {
        if(!isBST(root->left))
        {
            return 0;
        }
        if(prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return  isBST(root->right);

    }
    else
    {
        return 1;
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
    struct Node *p = createNode(5); // Root Node
    struct Node *p1 = createNode(3);
    struct Node *p2 = createNode(7);
    struct Node *p3 = createNode(1);
    struct Node *p4 = createNode(4);

    // Linking the root Node with left and right child Nodes
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4; 
    
    
    struct Node* n = search(p , 1000);
    if(n!=NULL) printf("Found : %d" , n->data);
    else printf("Not Found");
    





 

  

    return 0;
}



