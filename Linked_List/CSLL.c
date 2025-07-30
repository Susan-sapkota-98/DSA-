#include <stdio.h>
#include <stdlib.h>

struct CSLL
{
    int data;
    struct CSLL *next;
};

struct CSLL *last = NULL;

void display()
{
    if (last == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct CSLL *temp = last->next;
    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != last->next);
    printf("(head)\n");
}

void insert_at_beginning(int element)
{
    struct CSLL *NewNode;
    NewNode = (struct CSLL *)malloc(sizeof(struct CSLL));
    NewNode->data = element;
    if (last == NULL)
    {
        last = NewNode;
        last->next = last;
    }
    else
    {
        NewNode->next = last->next;
        last->next = NewNode;
    }
    printf("%d was inserted!\n", element);
}

int main()
{
    insert_at_beginning(20);
    insert_at_beginning(30);
    insert_at_beginning(40);
    insert_at_beginning(50);
    display();
    return 0;
}