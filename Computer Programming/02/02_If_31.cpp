#include<iostream>
#include<cmath>
using namespace std;

int mon[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

int main()
{
    int d,m,y,d2,m2,y2;
    cin >> d >> m >> y;

    int sum=0,sum2=0,sum3=0;

    if((y-543)%4==0 && m == 2)
    {
        sum += 29 - d;
    }
    else
    {
        sum += (mon[m] - d);
    }
    m++;

    while(m!=13)
    {
        if(m == 2 && (y-543)%4 == 0)
        {
            sum += 29;
        }
        else
        {
            sum += mon[m];
        }
        m++;
    }
    ////////////////
    cin >> d2 >> m2 >> y2;
    
    sum2 += (y2-1-y)*365;


    int stm=1;
    while(stm!=m2)
    {
        if(stm == 2 && (y2-543)%4 == 0)
        {
            sum3 += 29;
        }
        else
        {
            sum3 += mon[stm];
        }
        stm++;
    }
    sum3 += d2;

    sum += sum2 + sum3;
    double tmp = 2*M_PI*sum;

    cout << sum << " " << round(sin(tmp/23.0)*100.0)/100.0  << " " << round(sin(tmp/28.0)*100.0)/100.0 << " " << round(sin(tmp/33.0)*100.0)/100.0;
}