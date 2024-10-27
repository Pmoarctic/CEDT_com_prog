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

int lower(vi &v,int target)
{
    int l=0;
    int r=v.size()-1;
    int ans = v.size();
    int mid;
    while(l<=r)
    {
        mid = (l+r)/2;
        if(v[mid]>=target)
        {
            ans =mid;
            r = mid-1;
        }
        else
        {
            l = mid+1;
        }
    }
    return ans;
}

int upper(vi &v,int target)
{
    int l=0;
    int r=v.size()-1;
    int ans = v.size();
    int mid;
    while(l<=r)
    {
        mid = (l+r)/2;
        if(v[mid]>target)
        {
            ans =mid;
            r = mid-1;
        }
        else
        {
            l = mid+1;
        }
    }
    return ans;
}

int main()
{
    int n,m,k;
    cin >> n >> m >> k;
    vi v;
    int t;
    for(int i=0;i<n;i++)
    {
        cin >> t;
        v.pb(t);
    }

    sort(all(v));

    vi res;

    int p;
    while(m--)
    {
        cin >> p;
        int a = lower(v,p-k);
        int b = upper(v,p+k);
        res.pb(b-a);
    }

    for(auto i:res)
    {
        cout << i << " ";
    }

    return 0;
}