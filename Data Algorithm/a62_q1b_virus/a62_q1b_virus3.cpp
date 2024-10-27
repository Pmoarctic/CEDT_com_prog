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
    // ios_base::sync_with_stdio(NULL);
    // cin.tie(NULL);

    int n,k;
    cin >> n >> k;

    int len = pow(2,k);
    int t;

    if(k==1)
    {
        int a,b;

        while(n--)
        {
            cin >> a >> b;
            if(a==0 && b==1)
            {
                cout << "yes\n";
            }
            else cout << "no\n";
        }
        
    }

    vector<string> res;
    while(n--)
    {
        vector<int> bit;
        bool fg=1;
        for(int i=0;i<len/2;i++)
        {
            int a,b;
            cin >> a >> b;
            if((a==0 && b==0) || (a==1 && b==1))
            {
                fg=0;
            }
        }
        if(fg)
        {
            res.pb("yes\n");
        }
        else res.pb("no\n");
    }

    for(auto i:res)
    {
        cout << i;
    }
    return 0;
}