#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  struct Node *lchild;
  int data;
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
  newNode->rchild = newNode->lchild = NULL;
  return newNode;
}

// Iterative method to create the BINARAY SEARCH TREE
node *treeCreate(node *root, int value)
{
  node *temp = createNode(value);
  node *current = root, *prev = NULL;

  if (root == NULL)
  {
    root = temp;
    return root;
  }
  while (current != NULL)
  {
    prev = current;
    if (value < root->data)
    {
      current = current->lchild;
    }
    if (value >= root->data)
    {
      current = current->rchild;
    }
  }
  if (value < prev->data)
  {
    prev->lchild = temp;
  }
  else
  {
    prev->rchild = temp;
  }
  return root;
}

// RECURSIVE method for BINARAY SEARCH TREE

node *RecTreeCreate(node *root, int value)
{
  node *newNode = createNode(value);
  if (root == NULL)
  {
    root = newNode;
    return root;
  }
  if (value < root->data)
    root->lchild = RecTreeCreate(root->lchild, value);
  else if (value >= root->data)
    root->rchild = RecTreeCreate(root->rchild, value);
  return root;
}

// function for inorder travesal in recursion
void inOrder(node *root)
{
  if (root != NULL)
  {
    inOrder(root->lchild);
    printf("%d,", root->data);
    inOrder(root->rchild);
  }
}

// function for preorder travesal in recursion
void preOrder(node *root)
{
  if (root != NULL)
  {
    printf("%d,", root->data);
    preOrder(root->lchild);
    preOrder(root->rchild);
  }
}

// function for postorder travesal in recursion

void postOrder(node *root)
{
  if (root != NULL)
  {
    postOrder(root->lchild);
    postOrder(root->rchild);
    printf("%d,", root->data);
  }
}

// function to search the key element in BST

node *searchKey(node *root, int key)
{
  node *temp = root;
  while (temp != NULL)
  {
    if (key == temp->data)
      return temp;
    if (key < temp->data)
      temp = temp->lchild;
    else
      temp = temp->rchild;
  }
  return NULL;
}

// fucnction to find the height of a tree
int height(node *root)
{
  if (root == NULL)
    return -1;

  int leftHeight = height(root->lchild);
  int rightHeight = height(root->rchild);

  return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}

node *inOrderPredecessor(node *root)
{
  node *temp = root;
  while (temp && temp->rchild != NULL)
    temp = temp->rchild;
  return temp;
}

node *inOrderSucessor(node *root)
{
  node *temp = root;
  while (temp && temp->lchild != NULL)
    temp = temp->lchild;
  return temp;
}

// function to delete the node in binaray search tree
node *delete(node *root, int key)
{
  node *temp = root;
  node *current;

  if (temp == NULL)
  {
    return NULL;
  }
  if (temp->lchild == NULL && temp->rchild == NULL)
  {
    if (temp == root)
      root = NULL;
    free(temp);
    return NULL;
  }
  if (key < temp->data)
  {
    temp->lchild = delete (temp->lchild, key);
  }
  else if (key > temp->data)
  {
    temp->rchild = delete (temp->rchild, key);
  }
  else
  {
    if (height(temp->lchild) > height(temp->rchild))
    {
      current = inOrderPredecessor(temp->lchild);
      temp->data = current->data;
      temp->lchild = delete (temp->lchild, key);
    }
    else
    {
      current = inOrderSucessor(temp->rchild);
      temp->data = current->data;
      temp->rchild = delete (temp->rchild, key);
    }
  }
  return temp;
}
// function to count the number of nodes in a tree

int count(node *root)
{
  if (root)
    return count(root->lchild) + count(root->rchild) + 1;
  return 0;
}

// function to count the number of leaf nodes in a tree of degree two (2)

int countLeafNode(node *root)
{
  int leftNode, rightNode;
  if (root != NULL)
  {
    leftNode = countLeafNode(root->lchild);
    rightNode = countLeafNode(root->rchild);

    if (root->lchild == NULL && root->rchild == NULL)
      return leftNode + rightNode + 1;
    else
      return leftNode + rightNode;
  }
  return 0;
}

// function to find the number of leaf nodes of degree one 1 and degree two 2

int countLeafNodeDeg1(node *root)
{
  int leftNode, rightNode;

  while (root != NULL)
  {
    leftNode = countLeafNodeDeg1(root->lchild);
    rightNode = countLeafNodeDeg1(root->rchild);

    if (root->lchild == NULL || root->rchild == NULL)
    {
      return leftNode + rightNode + 1;
    }
    else
    {
      return leftNode + rightNode;
    }
  }
  return 0;
}

int main()
{
  node *root = NULL;
  root = treeCreate(root, 100);
  treeCreate(root, 200);
  treeCreate(root, 30);
  treeCreate(root, 70);
  treeCreate(root, 50);
  treeCreate(root, 100);

  printf("number of leaf nodes : %d", countLeafNodeDeg1(root));
  return 0;
}