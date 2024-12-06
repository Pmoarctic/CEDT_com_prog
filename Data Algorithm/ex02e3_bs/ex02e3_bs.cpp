#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define in(x) != x.end()
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef priority_queue<pii, vector<pii> , greater<pii> > gpiiq;

int bsearch(vi &v,int tag)
{
    int l=0;
    int r=v.size()-1;
    int ans = v.size();
    int mid;
    while(l<=r)
    {
        mid = (l+r)/2;
        if(v[mid]<=tag)
        {
           ans = mid;
           l = mid+1;
        }
        else
        {
            r = mid-1;
        }
    }
    if(ans==v.size())return -1;
    return ans;
}

int main()
{
    int n,m;
    cin >> n >> m;
    vi v(n);
    for(auto &i:v)
    {
        cin >> i;
    }

    vi res;
    int t;
    while(m--)
    {
        cin >> t;
        res.pb(bsearch(v,t));
    }

    for(auto i : res)
    {
        cout << i << "\n";
    }


    return 0;
}