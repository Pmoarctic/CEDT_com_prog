#include<bits/stdc++.h>
using namespace std;

int main()
{
    string a,b;

    getline(cin,a);

    int n = a.size();

    int res=0;

    for(int i=0;i<n;i++)
    {
        if(a[i]=='[')
        {
            a[i] = '(';
        }
        else if(a[i]=='(')
        {
            a[i] = '[';
        }
        else if(a[i]==')')
        {
            a[i] = ']';
        }
        else if(a[i]==']')
        {
            a[i] = ')';
        }
    }
    

    cout <<a;
}