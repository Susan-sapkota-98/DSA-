#include <stdio.h>
#include <stdlib.h>

struct DLL
{
    struct DLL *prev;
    struct DLL *next;
    int data;
};

struct DLL *first = NULL, *last = NULL;

void display()
{
    struct DLL *temp;
    if (first == NULL)
        printf("List is empty\n");
    else
    {
        temp = first;
        while (temp != NULL)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void insert_at_beginning(int element)
{
    struct DLL *NewNode;
    NewNode = (struct DLL *)malloc(sizeof(struct DLL));
    NewNode->data = element;
    NewNode->prev = NULL;
    NewNode->next = NULL;
    if (first == NULL)
    {
        first = last = NewNode;
    }
    else
    {
        NewNode->next = first;
        first->prev = NewNode;
        first = NewNode;
    }
    printf("%d -> was inserted\n", NewNode->data);
}

void insert_at_end(int element)
{
    struct DLL *NewNode;
    NewNode = (struct DLL *)malloc(sizeof(struct DLL));
    NewNode->data = element;
    NewNode->prev = NULL;
    NewNode->next = NULL;
    if (first == NULL)
    {
        first = last = NewNode;
    }
    else
    {
        NewNode->prev = last;
        last->next = NewNode;
        last = NewNode;
    }
    printf("%d -> was inserted\n", NewNode->data);
}

void insert_at_specific(int element, int pos)
{
    struct DLL *NewNode, *temp, *tempp;
    int i;
    NewNode = (struct DLL *)malloc(sizeof(struct DLL));
    NewNode->data = element;
    if (pos <= 0)
    {
        printf("Invalid position \n");
    }
    else if (pos == 1 || first == NULL)
    {
        insert_at_beginning(element);
    }
    else
    {
        temp = first;
        for (i = 1; (i < pos - 1) && (temp->next != NULL); i++)
        {
            temp = temp->next;
        }
        if (temp == last)
        {
            insert_at_end(element);
        }
        else
        {
            tempp = temp->next;
            temp->next = NewNode;
            NewNode->prev = temp;
            tempp->prev = NewNode;
            NewNode->next = tempp;
            printf("%d -> was inserted \n", NewNode->data);
        }
    }
}
void delete_from_beginning()
{
    struct DLL *temp;
    if (first == NULL)
    {
        printf("List is emopty");
    }
    else if (first->next == NULL)
    {
        temp = first;
        first = last = NULL;
        free(temp);
    }
    else
    {
        temp = first;
        first = first->next;
        free(temp);
        first->prev = NULL;
        printf("%d -> was deleted\n", temp->data);
    }
}
void delete_from_end()
{
    struct DLL *temp;
    if (first == NULL)
    {
        printf("List is emopty");
    }
    else if (first->next == NULL)
    {
        temp = first;
        first = last = NULL;
        free(temp);
    }
    else
    {
        temp = last;
        last = temp->prev;
        last->next = NULL;
        free(temp);
        printf("%d -> was deleted\n", temp->data);
    }
}
void delete_from_specific(int pos)
{
    struct DLL *tempp, *temp;
    int i;
    if (pos <= 0 || first == NULL)
    {
        printf("Invalid Deletion !");
    }
    else if (pos == 1 || first->next == NULL)
    {
        delete_from_beginning();
    }
    else
    {
        temp = first;
        for (i = 1; (i < pos - 1) && (temp->next != last); i++)
        {
            temp = temp->next;
        }
        if (temp->next == last)
        {
            delete_from_end();
        }
        else
        {
            tempp = temp->next;
            temp->next = tempp->next;
            (tempp->next)->prev = temp;
            free(tempp);
            printf("%d -> was deleted ", tempp->data);
        }
    }
}

int main()
{
    insert_at_beginning(20);
    insert_at_beginning(40);
    insert_at_end(30);
    insert_at_specific(25, 2);
    display();
    delete_from_beginning();
    display();
    delete_from_end();
    display();
    delete_from_specific(2);
    display();
    return 0;
}