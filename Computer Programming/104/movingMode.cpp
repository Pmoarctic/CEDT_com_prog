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


int main()
{
    int k,n,m;
    cin >> k >> n >> m;
    vector<int> day(n+1,INT_MAX);
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin >> a >> b;
        day[a] = b;
    }

    vector<int> res;
    for(int i=1;i<=n;i++)
    {
        int mx=0;
        int mode=0;
        unordered_map<int,int> cnt;
        for(int j=i-k;j<=i+k;j++)
        {
            if(j<1 || j>n || day[j]==INT_MAX)
            {
                continue;
            }
            else
            {
                cnt[day[j]]++;
                if(cnt[day[j]]>mx)
                {
                    mx = cnt[day[j]];
                    mode = day[j];
                }
                else if(cnt[day[j]]==mx && day[j]<mode)
                {
                    mode = day[j];
                }
            }
        }
        if(mode==0)
        {
            res.pb(INT_MAX);
        }
        else
        {
            res.pb(mode);
        }
       
    }

    for(auto i:res)
    {
        if(i==INT_MAX)
        {
            cout << "X ";
            continue;
        }
        cout << i << " ";
    }
}
/*
2 10 6
1 7
2 7
3 8
4 9
5 8
7 2

10 3 3
2 10
3 10
1 5
*/