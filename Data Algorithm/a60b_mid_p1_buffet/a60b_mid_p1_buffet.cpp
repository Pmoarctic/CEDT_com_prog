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
    int f,w,n;
    cin >> f >> w >> n;
    vector<int> table;
    for(int i=0;i<f;i++)
    {
        int a;
        cin >> a;
        table.pb(a);
    }
    if(w==0)
    {
        cout << table.size();
        return 0;
    }

    sort(all(table));

    int res=0;
    int mx=-1;
    for(int i=0;i<table.size();i++)
    {
        if(table[i]<=mx)
        {
            continue;
        }
        else
        {
            mx = table[i]+(w*2);
            res++;
        }
    }
    cout << res;

    return 0;
}

//greedy