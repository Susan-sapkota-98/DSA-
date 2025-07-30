#include <stdio.h>
long int tail_fact(int n, long int a)
{
    if (n == 1)
    {
        return a;
    }
    else
    {
        return tail_fact(n - 1, a * n);
    }
}
int main()
{
    int n;
    printf("enter value of n ");
    scanf("%d", &n);
    printf("factorial using tail recursion is : %ld\n", tail_fact(n, 1));
}