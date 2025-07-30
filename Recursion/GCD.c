#include <stdio.h>
long int GCD(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        while (b != 0)
        {
            int r = a % b;
            a = b;
            b = r;
        }
        return a;
    }
}
int main()
{
    int a, b;
    printf("Enter the value of a and b :");
    scanf("%d%d", &a, &b);
    printf("The GCD result is : %ld", GCD(a, b));
}