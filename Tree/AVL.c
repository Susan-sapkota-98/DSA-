#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};

int getheight(struct Node *n)
{
    if (n == NULL)
        return 0;
    return n->height;
}

struct Node *createNode(int key)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1; // New node is initially at height 1
    return node;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int getBalanceFactor(struct Node *n)
{
    if (n == NULL)
        return 0;

    return getheight(n->left) - getheight(n->right);
}

struct Node *RightRotate(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(getheight(y->right), getheight(y->left)) + 1;
    x->height = max(getheight(x->right), getheight(x->left)) + 1;

    return x;
}

struct Node *LeftRotate(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    // Perform rotation
    x->right = T2;
    y->left = x;

    // Update heights
    y->height = max(getheight(y->right), getheight(y->left)) + 1;
    x->height = max(getheight(x->right), getheight(x->left)) + 1;

    return y;
}

struct Node *insert(struct Node *node, int key)
{
    
    if (node == NULL)
        return createNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + max(getheight(node->left), getheight(node->right));
    int bf = getBalanceFactor(node);

    // Left Left case
    if (bf > 1 && key < node->left->key)
    {
        return RightRotate(node);
    }

    // Right Right case
    if (bf < -1 && key > node->right->key)
    {
        return LeftRotate(node);
    }

    // Left Right case
    if (bf > 1 && key > node->left->key)
    {
        node->left = LeftRotate(node->left);
        return RightRotate(node);
    }

    // Right Left case
    if (bf < -1 && key < node->right->key)
    {
        node->right = RightRotate(node->right);
        return LeftRotate(node);
    }

    return node;
}
void preOrder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main()
{
    struct Node *root = NULL;
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 3);

    preOrder(root);
    printf("\n");

    return 0;
}
