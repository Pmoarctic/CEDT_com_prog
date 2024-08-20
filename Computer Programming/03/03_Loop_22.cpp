#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> res;

    int num = 2;
    while(n!=1)
    {
        while(n%num==0)
        {
            res.push_back(num);
            n/=num;
        }
        num++;
    }

    int k=res.size();
    for(int i=0;i<k;i++)
    {
        if(i==k-1)
        {
            cout << res[i];
        }
        else
        {
            cout << res[i] <<"*";
        }
    }
}