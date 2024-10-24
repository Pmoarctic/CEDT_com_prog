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

int n,m,k;
vector<int> A(500005,0);

int solve(int st,int ed,int budget)
{

    int l = st;
    int r = ed;
    int mid;
    int ans=n+1;
    //
    while(l<=r)
    {
        mid = (l+r)/2;
        int cost = A[mid]-A[st-1] + (mid-st+1)*k;
        if(cost > budget)
        {
            ans = mid;
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }

    // cout << "ans idx : "  << ans << "\n";
    // cout << "ans : "  << A[ans-1]-A[st-1] << "\n";
    return A[ans-1]-A[st-1];
}

int main()
{
    
    cin >> n >> m >> k;

    for(int i=1;i<=n;i++)
    {
        cin >> A[i];
        A[i] += A[i-1];
    }

    vector<int> res;
    while(m--)
    {
        int a,b;
        cin >> a >> b;
        a++;

        int tres = solve(a,n,b);
        res.pb(tres);
    }

    for(auto i:res)
    {
        cout << i << "\n";
    }


    return 0;
}