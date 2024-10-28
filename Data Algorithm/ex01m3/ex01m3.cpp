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
    ull n,m;
    cin >> n >> m;

    vector<ull> num;
    for(ull i=0;i<n;i++)
    {
        ull t;
        cin >> t;
        num.pb(t);
    }

    vector<ull> que;
    ull mxq=0;
    while(m--)
    {
        ull t;
        cin >> t;
        que.pb(t);
        mxq = max(mxq,t);
    }
    //cout << "mxq : " << mxq << '\n';
    //find lcm
    ull lcm = num[0];
    for(ull i=1;i<n;i++)
    {
        lcm = (num[i]*lcm)/(__gcd(num[i],lcm));
    }
    //

    vector<ull> time;
    bool fg=0;
    for(ull t=1;t<=lcm;t++)
    {
        for(ull i:num)
        {
            if(t%i==0)
            {
                time.pb(t);
                //cout << time.size() << "\n";
            }
            if(time.size() > mxq)
            {
                fg=1;
                break;
            }
        }
        if(fg)
        {
            break;
        }
    }

    // for(auto i:time)
    // {
    //     cout << i << " ";
    // }
    // cout << "\n";

    ull len = time.size();
    ull q,r;
    for(ull c:que)
    {
        if(c<=n)
        {
            cout << "0\n";
            continue;
        }
        c-=n;
        
        r = c%len;
        q = c/len;
        //cout << r << " " << q << "\n";
        if(r==0)
        {
            q--;
            r = len;
        }

        cout << lcm*q + time[r-1] << "\n";
    }


    return 0;
}