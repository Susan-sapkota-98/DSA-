#include <stdio.h>
#define true 1
#define false 0
#define MAX 5

struct STACK {
    int TOS;
    int data[MAX];
};

int isFull(struct STACK *s) {
    return s->TOS == MAX - 1 ? true : false;
}

int isEmpty(struct STACK *s) {
    return s->TOS == -1 ? true : false;
}

void push(struct STACK *s, int element) {
    s->data[++s->TOS] = element;
}

int pop(struct STACK *s) {
    return s->data[s->TOS--];
}

int peek(struct STACK *s) {
    return s->data[s->TOS];
}

int main() {
    int choice, value;
    struct STACK S;
    S.TOS = -1;

    do {
        printf("\n1. PUSH\n2. POP\n3. PEEK\n4. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (isFull(&S)) {
                    printf("STACK OVERFLOW\n");
                } else {
                    printf("Enter value to push: ");
                    scanf("%d", &value);
                    push(&S, value);
                    printf("%d was PUSHED\n", value);
                }
                break;

            case 2:
                if (isEmpty(&S)) {
                    printf("STACK UNDERFLOW\n");
                } else {
                    printf("%d was POPPED\n", pop(&S));
                }
                break;

            case 3:
                if (isEmpty(&S)) {
                    printf("STACK IS EMPTY\n");
                } else {
                    printf("%d is at the TOP\n", peek(&S));
                }
                break;

            case 4:
                printf("BYE\n");
                break;

            default:
                printf("Enter 1, 2, 3, or 4 only\n");
                break;
        }
    } while (choice != 4);

    return 0;
}
