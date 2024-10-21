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

set<string> s[10];

void combine(int cur)
{
    for(auto i:s[cur-1])
    {
        for(auto j:s[cur-1])
        {
            string tmp1,tmp2 = "";
            tmp1 += i;
            tmp1 += j;
            s[cur].insert(tmp1);
            
            tmp2 += i;
            reverse(tmp2.begin(),tmp2.end());
            tmp2 += j;
            s[cur].insert(tmp2);
        }
    }
    return;
}

void staging(int ed, int cur)
{
    for(int i=cur;i<=ed;i++)
    {
        combine(i);
    }
    return;
}

int main()
{
    int n,k;
    cin >> n >> k;

    s[1].insert("01");
    staging(k,2);

    for(auto i:s[k])
    {
        cout << i << "\n";
    }

    vector<bool> res;
    int len = pow(2,k);
    while(n--)
    {
        string che="";
        for(int i=0;i<len;i++)
        {
            string t;
            cin >> t;
            che += t;
        }
        if(s[k].find(che) == s[k].end())
        {
            res.pb(0);
        }
        else res.pb(1);
    }

    for(auto i:res)
    {
        if(i)cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}