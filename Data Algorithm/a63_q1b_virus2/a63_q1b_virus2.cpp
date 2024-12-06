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

pair<string,string> split(string a)
{
    string a1="",a2="";
    int len = a.size()/2;
    for(int i=0;i<len;i++)
    {
        a1 += a[i];
        a2 += a[i+len];
    }
    return {a1,a2};
}

int count(string a)
{
    int res=0;
    for(auto i:a)
    {
        if(i=='1')res++;
    }
    return res;
}

bool solve(string cur)
{
    if(cur.size()==2)
    {
        return true;
    }
    else
    {
        auto [a,b] = split(cur);
        if(abs(count(a)-count(b)) > 1)return false;
        return solve(a) && solve(b);
    }
}

int main()
{
    int q,k;
    cin >> q >> k;

    vector<string> res;
    int len = pow(2,k);
    while(q--)
    {   
        string s = "";
        string tmp;
        for(int i=0;i<len;i++)
        {
            cin >> tmp;
            s += tmp;
        }

        res.pb(solve(s)?"yes\n":"no\n");
    }
    for(auto i:res)
    {
        cout << i;
    }

    return 0;
}