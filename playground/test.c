#include<stdio.h>

int a(int t)
{
    t = t+1;
    return t;
}

int main()
{
    int y,b;
    scanf("%d", &y);
    b = a(y);
    printf("%d", b);

    return 0;
}