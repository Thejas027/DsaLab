#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    struct Node *lchild;
    int data;
    int height;
    struct Node *rchild;
} node;

node *createNode(int value)
{
    node *newNode = (node *)malloc(sizeof(node));
    if (newNode == NULL)
    {
        printf("Memory Allocation Failed..\n");
        exit(1);
    }
    newNode->data = value;
    newNode->height = 1;
    newNode->rchild = newNode->lchild = NULL;
    return newNode;
}

// function to find the height of a tree
int nodeHeight(node *root)
{
    int hl, hr;
    hl = root && root->lchild ? root->lchild->height : 0;
    hr = root && root->rchild ? root->rchild->height : 0;

    return hl > hr ? hl + 1 : hr + 1;
}

// function to find the balance factor of tree
int balanceFactor(node *root)
{
    int hl, hr;
    hl = root && root->lchild ? root->lchild->height : 0;
    hr = root && root->rchild ? root->rchild->height : 0;

    return hl - hr;
}

// function for LL-Rotation
node *LLRotation(node *root)
{
    node *rootLChild = root->lchild;
    node *rootLRChild = rootLChild->rchild;

    rootLChild->rchild = root;
    root->lchild = rootLRChild;

    root->height = nodeHeight(root);
    rootLChild->height = nodeHeight(rootLChild);

    return rootLChild;
}

node *LRRotation(node *root)
{
    return NULL;
}

node *RRRotation(node *root)
{
    node *rootRChild = root->rchild;
    root->rchild = rootRChild->lchild;
    rootRChild->lchild = root;

    root->height = nodeHeight(root);
    rootRChild->height = nodeHeight(rootRChild);

    return rootRChild;
}

node *RLRotation(node *root)
{
    return NULL;
}

// Recursive function to create a tree
node *RecTreeCreate(node *root, int value)
{
    ;
    if (root == NULL)
    {
        return createNode(value);
    }
    if (value < root->data)
        root->lchild = RecTreeCreate(root->lchild, value);
    else if (value >= root->data)
        root->rchild = RecTreeCreate(root->rchild, value);

    root->height = nodeHeight(root); // to find the height of a tree

    // based on the balance factor its get rotated
    if (balanceFactor(root) == 2 && balanceFactor(root->lchild) == 1)
        return LLRotation(root);

    if (balanceFactor(root) == -2 && balanceFactor(root->rchild) == -1)
        return RRRotation(root);

    if (balanceFactor(root) == 2 && balanceFactor(root->lchild) == -1)
        return LRRotation(root);

    if (balanceFactor(root) == -2 && balanceFactor(root->rchild) == 1)
        return RLRotation(root);
    return root;
}

void preOrder(node *root)
{
    if (root != NULL)
    {

        printf("%d ", root->data);
        preOrder(root->lchild);
        preOrder(root->rchild);
    }
}

int main()
{
    node *root = NULL;
    root = RecTreeCreate(root, 10);
    root = RecTreeCreate(root, 5);
    root = RecTreeCreate(root, 2);
    root = RecTreeCreate(root, 15);
    root = RecTreeCreate(root, 20);
    root = RecTreeCreate(root, 25);

    printf("Pre-order Traversal: ");
    preOrder(root);

    return 0;
}
