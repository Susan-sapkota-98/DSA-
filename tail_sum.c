#include <stdio.h>
long int sum(int n, long int a)
{
    if (n == 0)
    {
        return a;
    }
    else
    {
        return sum(n - 1, a + n);
    }
}
int main()
{
    int n;
    printf("enter value of n ");
    scanf("%d", &n);
    printf("The sum of natural number is : %ld \n", sum(n, 0));
    return 0;
}