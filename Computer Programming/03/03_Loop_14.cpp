#include<bits/stdc++.h>
using namespace std;

int main()
{
    string a,b;

    getline(cin,a);
    getline(cin,b);

    int n = a.size();
    int m = b.size();
    int res=0;
    if(n>m)
    {
        cout << "Incomplete answer";
        return 0;
    }

    for(int i=0;i<m;i++)
    {
        if(a[i]==b[i])res++;
    }
    

    cout <<res;
}