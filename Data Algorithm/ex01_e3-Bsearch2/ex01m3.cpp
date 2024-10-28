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

int main()
{
    int n,m;
    cin >> n >> m;
    vi v;
    for(int i=0;i<n;i++)
    {
        int t;
        cin >> t;
        v.pb(t);
    }

    while(m--)
    {
        int tag;
        cin >> tag;
        int l=0;
        int r=n-1;
        int ans=n;
        int mid;
        while(l<=r)
        {
            mid = (l+r)/2;
            if(v[mid]>tag)
            {
                r=mid-1;
                ans=mid;
            }
            else l = mid+1;
        }
        if(ans==0)
        {
            cout << "-1\n";
            continue;
        }
        cout << v[ans-1] << "\n";
    }



    return 0;
}