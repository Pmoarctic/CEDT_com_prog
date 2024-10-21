#include"bits/stdc++.h"
using namespace std;

int main()
{
    int n;
    cin >> n;
    int minl=INT_MAX,maxl=INT_MIN;
    int minr=INT_MAX,maxr=INT_MIN;

    bool bo=1;
    while(n--)
    {
        int a,b;
        cin >> a >> b;
        if(bo)
        {
            minl = min(minl,a);
            minr = min(minr,b);

            maxl = max(maxl,a);
            maxr = max(maxr,b);
        }
        else
        {
            minl = min(minl,b);
            minr = min(minr,a);

            maxl = max(maxl,b);
            maxr = max(maxr,a);
        }
        bo = !bo;
    }
    string cmd;
    cin >> cmd;
    if(cmd == "Zig-Zag")
    {
        cout << minl << " " << maxr;
    }
    else
    {
        cout << minr << " " << maxl;
    }
}

