#include<iostream>
using namespace std;

int mon[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

int main()
{
    int d,m,y;
    cin >> d >> m >> y;
    y-=543;
    int n=31;

    if(mon[m] == 30)
    {
        n=30;
    }
    else
    {
        if(m==2)
        {
            n=28;
            if(y%400 == 0)
            {
                n=29;
            }
            if(y%4==0 && y%100!=0)
            {
                n=29;
            }
        }
    }
    d+=15;
    if(d>n)
    {
        d-=n;
        m++;
    }
    if(m>12)
    {
        m-=12;
        y++;
    }
    y+=543;

    printf("%d/%d/%d",d,m,y);
}