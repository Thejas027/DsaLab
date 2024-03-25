/*

*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};

struct Node *createNode(int value)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    if (newnode == NULL)
    {
        printf("Memory allocation failed..\n");
        return NULL;
    }
    newnode->data = value;
    newnode->lchild = newnode->rchild = NULL;
    return newnode;
}

struct Node *treeCreate(struct Node *root, int value)
{
    struct Node *newnode = createNode(value);
    if (root == NULL)
    {
        root = newnode;
        return root;
    }
    if (value < root->data)
        root->lchild = treeCreate(root->lchild, value);
    else if (value > root->data)
        root->rchild = treeCreate(root->rchild, value);
    return root;
}

void inOrder(struct Node *root)
{
    if (root == NULL)
        return;
    inOrder(root->lchild);
    printf("%d ", root->data);
    inOrder(root->rchild);
}

void preorder(struct Node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->lchild);
    preorder(root->rchild);
}

int main()
{
    struct Node *root = NULL;
    root = treeCreate(root, 100);
    treeCreate(root, 200);
    treeCreate(root, 30);
    treeCreate(root, 70);
    treeCreate(root, 50);
    treeCreate(root, 100);
    inOrder(root);
    return 0;
}