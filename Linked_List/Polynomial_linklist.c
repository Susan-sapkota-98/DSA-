// How can you solve polynomial equations using linked list.
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node
{
    float coeff;
    int expo;
    struct node *link;
};

// sorted order insertion function
struct node *insert(struct node *head, float coeff, int expo)
{
    struct node *temp = head;
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->coeff = coeff;
    newNode->expo = expo;
    newNode->link = NULL;

    if (head == NULL || expo > head->expo)
    {
        newNode->link = head;
        head = newNode;
    }
    else
    {
        temp = head;
        while (temp->link != NULL && temp->link->expo > expo)
        {
            temp = temp->link;
        }

        if (temp->link != NULL && temp->link->expo == expo)
        {
            temp->link->coeff += coeff;
            free(newNode);
        }
        else
        {
            newNode->link = temp->link;
            temp->link = newNode;
        }
    }

    return head;
}

struct node *create(struct node *head)
{
    int n, expo, i;
    float coeff;
    printf("Enter number of terms: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        printf("Enter coefficient for term %d: ", i);
        scanf("%f", &coeff);
        printf("Enter exponent for term %d: ", i);
        scanf("%d", &expo);
        head = insert(head, coeff, expo);
    }

    return head;
}

void display(struct node *head)
{
    if (head == NULL)
    {
        printf("Polynomial is empty\n");
    }
    else
    {
        struct node *temp = head;
        while (temp != NULL)
        {
            printf("(%.1f)x^%d", temp->coeff, temp->expo);
            temp = temp->link;
            if (temp != NULL)
            {
                printf(" + ");
            }
        }
        printf("\n");
    }
}

float evaluate(struct node *head, float x)
{
    float result = 0.0;
    struct node *temp = head;
    while (temp != NULL)
    {
        result += temp->coeff * pow(x, temp->expo);
        temp = temp->link;
    }
    return result;
}

int main()
{
    struct node *poly = NULL;
    float x, result;

    printf("Enter the polynomial:\n");
    poly = create(poly);

    printf("The polynomial is: ");
    display(poly);

    printf("Enter the value of x to evaluate: ");
    scanf("%f", &x);

    result = evaluate(poly, x);
    printf("Result of polynomial when x = %.2f is: %.2f\n", x, result);

    return 0;
}
