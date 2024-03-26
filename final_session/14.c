/*
14. Develop a menu driven program to implement Binary Search tree with the followingoperations.
i) Construction ii) Traversals (Pre, In and Post Order) iii) Searching a node by key and displaying its
information along with its parent if exists, otherwise a suitablemessage. iv)Counting all nodes. v)
Finding height. vi Finding node with the Maximum key value and printing the node details along
with the parent
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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

void postorder(struct Node *root)
{
    if (root == NULL)
        return;
    postorder(root->lchild);
    postorder(root->rchild);
    printf("%d ", root->data);
}

int height(struct Node *root)
{
    if (root == NULL)
        return 0;

    int leftHeight = height(root->lchild);
    int rightHeight = height(root->rchild);

    return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}

void searchKey(struct Node *root, int key)
{
    struct Node *temp = root;
    struct Node *parent = NULL;

    while (temp != NULL)
    {
        if (key == temp->data)
        {
            printf("Element found\n");
            printf("Parent is : %d", parent->data);
            return;
        }

        if (key > root->data)
        {
            parent = temp;
            temp = temp->rchild;
        }
        else
        {
            parent = temp;
            temp = temp->lchild;
        }
    }
    printf("Key not found\n");
}

// function to count the number of nodes

int count(struct Node *root)
{
    if (root)
        return count(root->lchild) + count(root->rchild) + 1;
    return 0;
}

// function to find the max ele and print its parent

void maximum(struct Node *root)
{
    struct Node *temp = root;
    struct Node *parent = NULL;

    while (temp->rchild != NULL)
    {
        parent = temp;
        temp = temp->rchild;
    }
    printf("\nmax ele : %d", temp->data);
    printf("\nparent is : %d", parent->data);
}
int main()
{
    struct Node *root = NULL;
    root = treeCreate(root, 100);
    treeCreate(root, 200);
    treeCreate(root, 50);
    treeCreate(root, 10);
    treeCreate(root, 30000);
    inOrder(root);

    printf("\nHeight : %d\n", height(root));
    searchKey(root, 10);
    printf("\n cunt : %d \n", count(root));
    maximum(root);
    return 0;
}