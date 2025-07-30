#include <stdio.h>
#include <time.h>
long int TOH(int n, char src, char dst, char temp)
{
    if (n == 1)
    {
        printf("Move disk %d from %c to %c\n", n, src, dst);
    }
    else
    {
        TOH(n - 1, src, temp, dst);
        printf("Move disk %d from %c to %c\n", n, src, dst);
        TOH(n - 1, temp, dst, src);
    }
}
int main()
{
    int n;
    time_t start, end;
    double diff;
    printf("Enter the value of n ");
    scanf("%d", &n);
    start = time(NULL);
    TOH(n, 'A', 'C', 'B');
    end = time(NULL);
    diff = difftime(end, start);
    printf("The time taken is %.2lf seconds\n", diff);
    return 0;
}