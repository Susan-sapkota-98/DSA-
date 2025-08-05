#include <stdio.h>
#include <stdlib.h>
struct BinaryTree
{
    int data;
    struct BinaryTree *left;
    struct BinaryTree *right;
    struct BinaryTree *parent;
};
struct BinaryTree *root = NULL;
struct BinaryTree *create_node(int value)
{
    struct BinaryTree *NewNode;
    NewNode = (struct BinaryTree *)malloc(sizeof(struct BinaryTree));
    NewNode->data = value;
    NewNode->left = NULL;
    NewNode->right = NULL;
    NewNode->parent = NULL;
    return NewNode;
}

// DLR(Data,Left,Right)
void preorder(struct BinaryTree *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// LDR(Left,Data,Right)
void inorder(struct BinaryTree *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// LRD(Left,Right,Data)
void postorder(struct BinaryTree *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}
struct BinaryTree *insert(struct BinaryTree *root, int value)
{
    if (root == NULL)
        root = create_node(value);
    if (value < root->data)
    {
        root->left = insert(root->left, value);
        root->left->parent = root;
    }
    if (value > root->data)
    {
        root->right = insert(root->right, value);
        root->right->parent = root;
    }
    return root;
}
struct BinaryTree *search(struct BinaryTree *root, int key)
{
    if ((root == NULL) || (key == root->data))
        return root;
    else if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}
struct BinaryTree *find_min(struct BinaryTree *root)
{
    while (root->left != NULL)
        root = root->left;
    return root;
}
struct BinaryTree *find_max(struct BinaryTree *root)
{
    while (root->right != NULL)
        root = root->right;
    return root;
}
struct BinaryTree *delete_node(struct BinaryTree *root, int value)
{
    if (root == NULL)
        return root;
    if (value < root->data)
    {
        root->left = delete_node(root->left, value);
        if (root->left)
            root->left->parent = root;
    }
    else if (value > root->data)
    {
        root->right = delete_node(root->right, value);
        if (root->right)
            root->right->parent = root;
    }
    else
    {

        if (root->left == NULL)
        {
            struct BinaryTree *temp = root->right;
            if (temp)
                temp->parent = root->parent;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct BinaryTree *temp = root->left;
            if (temp)
                temp->parent = root->parent;
            free(root);
            return temp;
        }
        else
        {

            struct BinaryTree *temp = find_min(root->right);
            root->data = temp->data;
            root->right = delete_node(root->right, temp->data);
            if (root->right)
                root->right->parent = root;
        }
    }
    return root;
}

int main()
{
    int i, element, choice;
    struct BinaryTree *temp;
    int arr[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};
    do
    {
        printf("1.INSERT\n2.DELETE\n3.SEARCH\n4.INORDER\n");
        printf("5.PREORDER\n6.POSTORDER\n7.FIND MAX\n8.FIND MIN\n");
        printf("9.CREATE\n10.EXIT\nEnter your choice ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element to insert ");
            scanf("%d", &element);
            root = insert(root, element);
            printf("%d INSERTED!\n", element);
            break;

        case 2:
            printf("Enter the element to delete ");
            scanf("%d", &element);
            root = delete_node(root, element);
            printf("%d DELETED!\n", element);
            break;

        case 3:
            printf("Enter the element to search ");
            scanf("%d", &element);
            temp = search(root, element);
            if (temp == NULL)
                printf("%d NOT FOUND!\n", element);
            else
                printf("%d FOUND!\n", element);
            break;

        case 4:
            inorder(root);
            printf("\n");
            break;

        case 5:
            preorder(root);
            printf("\n");
            break;

        case 6:
            postorder(root);
            printf("\n");
            break;

        case 7:
            temp = find_max(root);
            if (temp != NULL)
                printf("%d IS THE LARGEST ELEMENT IN THE BST\n", temp->data);
            break;

        case 8:
            temp = find_min(root);
            if (temp != NULL)
                printf("%d IS THE SMALLEST ELEMENT IN THE BST\n", temp->data);
            break;

        case 9:
            for (i = 0; i < 9; i++)
                root = insert(root, arr[i]);
            printf("All elements inserted sucessfully!\n");
            break;

        case 10:
            printf("Bye!\n");
        }
    } while (choice != 10);
    return 0;
}
