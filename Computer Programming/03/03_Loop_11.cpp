#include<bits/stdc++.h>
using namespace std;

int main()
{
    double sum=0;
    int n=0;
    
    while(true)
    {
        double tmp;
        cin >> tmp;
        if(tmp == -1)break;

        n++;
        sum+=tmp;
    }
    if(n)
    {
        cout << round((sum/n)*100)/100;
    }
    else cout << "No Data";
}