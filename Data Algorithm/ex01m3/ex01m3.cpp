#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ull> vull;

#define gpiiq(X) priority_queue<X, vector<X> , greater<X> >

int main()
{
    ll n,t;
    cin >> n >> t;

    vector<ll> time(n);
    for(auto &i:time)cin >> i;

    while(t--)
    {
        ll c;
        cin >> c;

        if(c<=n)
        {
            cout << "0\n";
            continue;
        }

        //Bsearch
        ll ans = -1;
        ll l = 0, r = -1;
        ll m;
        while(l<=r)
        {
            m = l + (r - l)/2;
            ll tt=0;
            for(auto i:time)
            {
                tt += (m/i + 1);
            }
            if(tt>=c)
            {
                ans = m;
                r = m-1;
            }
            else
            {
                l = m+1;
            }
        }
        cout << ans << "\n";
    }


    return 0;
}

/*
3 4
2 2 5
4 5 6 30
*/