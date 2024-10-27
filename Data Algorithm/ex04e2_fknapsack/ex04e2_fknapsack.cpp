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

struct ITEM
{
    double v;
    double w;
    double v_w;
    bool operator <(const ITEM &x) const{
        return x.v_w<v_w;
    };
};


int main()
{
    double mx;
    int n;
    cin >> mx >> n;

    vector<ITEM> v;
    for(int i=0;i<n;i++)
    {
        double a;
        cin >> a;
        v.pb({a,0,0.0});
    }
    for(int i=0;i<n;i++)
    {
        double a;
        cin >> a;
        v[i].w = a;
        v[i].v_w = v[i].v/a;
    }
    sort(all(v));

    double cur=0;
    double res=0;
    int i=0;
    while(cur+v[i].w <= mx)
    {
        if(i==n)
        {
        cout << setprecision(4) << fixed << res;
        return 0;
        }
        res += v[i].v;
        cur += v[i].w;
        i++;
    }
    double remain = mx-cur;
    if(i==n)
    {
        cout << setprecision(4) << fixed << res;
        return 0;
    }
    
    res += remain*(v[i].v_w);

    cout << setprecision(4) << fixed << res;
    return 0;
}