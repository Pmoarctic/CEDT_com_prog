#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int n,s,m;
        cin >> n >> s >> m;
        int prev=0;
        bool fg=0;
        while(n--)
        {
            int l,r;
            cin >> l >> r;
            if(l-prev >= s)
            {
                fg=1;
            }
            prev = r;
        }
        if(m-prev>=s)fg=1;
        if(fg)
        {
            cout << "yes\n";
        }
        else cout << "no\n";
    }

    return 0;
}