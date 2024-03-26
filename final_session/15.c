/*
5. Develop a menu driven program to implement Binary Search tree with the followingoperations.
i) Construction ii) Traversals (Pre, In and Post Order) iii) Searching a node by key and deleting if
exists ( node to be deleted may be leaf or non- leaf with one child ortwo children)
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

struct Node *inorderPre(struct Node *root)
{
    struct Node *temp = root;
    while (temp && temp->rchild != NULL)
    {
        temp = temp->rchild;
    }
    return temp;
}

struct Node *inorderSuc(struct Node *root)
{
    struct Node *temp = root;
    while (temp && temp->lchild != NULL)
    {
        temp = temp->lchild;
    }
    return temp;
}

struct Node *delete(struct Node *root, int key)
{
    struct Node *temp = root;
    struct Node *current;

    if (temp == NULL)
        return NULL;
    if (temp->lchild == NULL && temp->rchild == NULL)
    {
        if (temp == root)
            root = NULL;
        free(temp);
        return NULL;
    }
    if (key < root->data)
        root->lchild = delete (root->lchild, key);
    else if (key > root->data)
        root->rchild = delete (root->rchild, key);
    else
    {
        if (height(root->lchild) > height(root->rchild))
        {
            current = inorderPre(root->lchild);
            temp->data = current->data;
            temp->lchild = delete (root->lchild, key);
        }
        else
        {
            current = inorderSuc(root->rchild);
            temp->data = current->data;
            temp->rchild = delete (root->rchild, key);
        }
    }
    return temp;
}

// develop a menu driven program as required
int main()
{
    struct Node *root = NULL;
    int choice, key;

    do
    {
        printf("\n----- Binary Search Tree Operations -----\n");
        printf("1. Insert\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Search\n");
        printf("6. Delete\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &key);
            root = treeCreate(root, key);
            break;

        case 2:
            printf("Inorder Traversal: ");
            inOrder(root);
            printf("\n");
            break;

        case 3:
            printf("Preorder Traversal: ");
            preorder(root);
            printf("\n");
            break;

        case 4:
            printf("Postorder Traversal: ");
            postorder(root);
            printf("\n");
            break;

        case 5:
            printf("Enter key to search: ");
            scanf("%d", &key);
            searchKey(root, key);
            break;

        case 6:
            printf("Enter key to delete: ");
            scanf("%d", &key);
            root = delete (root, key);
            break;

        case 7:
            printf("Exiting program...\n");
            break;

        default:
            printf("Invalid choice! Please enter a number between 1 and 7.\n");
            break;
        }
    } while (choice != 7);

    return 0;
}