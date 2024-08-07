#include<bits/stdc++.h>
using namespace std ;

int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        string a,b;
        cin >> a >> b;
        int n = a.size();
        int m = b.size();
        int i=0,j=0;
        bool fg=0;
        for(;i<n;i++)
        {
            if(a[i] == b[j])
            {
                j++;
            }
            else if(a[i] == '?')
            {
                a[i] = b[j];
                j++;
            }
            if(j >=m)
            {
                fg=1;
                break;
            }
        }
        for(;i<n;i++)
        {
            if(a[i]=='?')
            a[i] = 'a';
        }
        if(fg)
        {
            cout << "yes\n" << a << "\n";
        }
        else cout << "no\n";
    }

    return 0 ;
}