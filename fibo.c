#include <stdio.h>
long int table[100] = {0};
long int fibo(int n)
{
    if (n == 1 || n == 2)
        return 1;
    else
    {
        if (table[n] == 0)
        {
            table[n] = fibo(n - 1) + fibo(n - 2);
        }
        return table[n];
    }
}
    int main()
    {
        int n;
        printf("Enter n ");
        scanf("%d", &n);
        printf("The %dth term is %ld\n", n, fibo(n));
    }