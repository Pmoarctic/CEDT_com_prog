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

pair<vi,vi> split(vi c)
{
    vi a,b;
    int len = c.size()/2;
    for(int i=0;i<len;i++)
    {
        a.pb(c[i]);
        b.pb(c[i+len]);
    }
    return {a,b};
}

void recur(bool &flag,vi a,vi b)
{
    if(flag==0)return;
    if(b.size()==2)
    {
        if(b[0]==b[1])
        {
            flag = 0;
        }
        if(a[0]==a[1])
        {
            flag = 0;
        }
        return;
    }
/////////////////////////////////////
    if(a[a.size()-2]==1 && a[a.size()-1]==0)
    {
        reverse(a.begin(),a.end());
        if(a[0]==0 && a[a.size()-1]==0)
        {
            flag = 0;
            return;
        }
    }
    auto [a1,a2] = split(a);
    recur(flag,a1,a2);

    if(b[b.size()-2]==1 && b[b.size()-1]==0)
    {
        reverse(b.begin(),b.end());
        if(b[0]==0 && b[b.size()-1]==0)
        {
            flag = 0;
            return;
        }
    }
    auto [b1,b2] = split(b);
    recur(flag,b1,b2);
    
    return;
}

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int t;

    int n,k;
    cin >> n >> k;

    int len = pow(2,k);

    if(k==1)
    {
        while(n--)
        {
            int a,b;
            cin >> a >> b;
            if(a==1 || b==0)
            {
                cout << "no\n";
            }
            else cout << "yes\n";
        }
        return 0;
    }
    else if(k==2)
    {
        while(n--)
        {
            int a,b,c,d;
            cin >> a >> b >> c >> d;
            if((a==0&&b==1&&c==0&&d==1) || (a==1&&b==0&&c==0&&d==1))cout << "yes\n";
            else cout << "no\n";
        }
        return 0;
    }
    
    vector<bool> res;
    while(n--)
    {
        vector<int> bit;
        for(int i=0;i<len;i++)
        {
            cin >> t;
            bit.pb(t);
        }
        auto tmp = split(bit);
        bool flag=1;
        recur(flag,tmp.first,tmp.second);
        res.pb(flag);
    }

    
    for(auto i:res)
    {
        if(i==1)cout << "yes\n";
        else cout << "no\n";
    }
    

    return 0;
}