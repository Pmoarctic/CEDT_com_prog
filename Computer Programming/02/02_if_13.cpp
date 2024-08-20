#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    double n[4];

    double mn=INT_MAX,mx=INT_MIN;
    double sum = 0;
    for(int i=0;i<4;i++)
    {
        double tmp;
        cin >> tmp;
        sum += tmp;
        if(tmp>mx)
        {
            mx = tmp;
        }
        if(tmp<mn)
        {
            mn = tmp;
        }
    }

    double x = sum-mx-mn;
    x/=2.0;

    cout << round(x*100.0)/100.0;


}