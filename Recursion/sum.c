#include <stdio.h>
long int sum(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else
    {
        return n + sum(n - 1);
    }
}
int main()
{
    int n;
    printf("enter value of n ");
    scanf("%d", &n);
    printf("The sum of natural number is : %ld \n", sum(n));
    return 0;
}