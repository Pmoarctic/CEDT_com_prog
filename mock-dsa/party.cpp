#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long

vector<ull> mice;
ull sum(ull t)
{
    ull res=0;
    for(auto i:mice)
    {
        res += t/i;
    }
    return res;
}

int main()
{
    ull n,m;
    cin >> n >> m;

    while(m--)
    {
        ull k;
        cin >> k;
        mice.push_back(k);
    }

    ull l=0,r=LLONG_MAX;
    ull mid;//time
    ull ans = r;
    while(l<=r)
    {
        ull mid = (l+r)/2;
        //cout << sum(mid) << " <- " << mid << "\n";
        if(sum(mid)>=n)
        {
            r=mid-1;
            ans=mid;
        }
        else
        {
            l=mid+1;
        }
    }
    cout << ans;
}