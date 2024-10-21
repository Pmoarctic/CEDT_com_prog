#include<bits/stdc++.h>
using namespace std;
int m;
double c[40];
double summation(double irr)
{
    double sum=0.0;
    for(int i=0;i<=m;i++)
    {
        sum += c[i]/(pow((1.0+irr),(double)i));
    }
    return sum;
}

int main()
{
    
    cin >> m;
    
    for(int i=0;i<=m;i++)
    {
        cin >> c[i];
    }

    double l=-1.0,r=1.0;
    double mid = (l+r)/2.0;
    //while(abs(summation(mid)-mid) > pow(10,-8)*max(summation(mid),mid))
    while(abs(summation(mid)) > pow(10,-8))
    {
        mid = (l+r)/2.0;
        double sum = summation(mid);
        if(sum>0)
        {
            l=mid;
        }
        else if(sum<=0)
        {
            r=mid;
        }
        //cout << sum << "\n";
    }

    
    cout << setprecision(8) << mid << endl;
}