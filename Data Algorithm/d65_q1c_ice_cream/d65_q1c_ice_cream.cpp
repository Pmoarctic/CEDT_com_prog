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

int lower(vi &v,int l,int r,int day,int target)
{
    int ans = r+1;
    int mid;

    int steal;
    if(day==-1){
        steal=0;
    }
    else{
        steal=v[day];
    }

    while(l<=r)
    {
        mid = (l+r)/2;

        
        if(v[mid]-steal >=target)
        {
            r=mid-1;
            ans=mid;
        }
        else l=mid+1;
    }

    return ans;
}

int main()
{
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);

    int n,m,start;
    cin >> n >> m >> start;

    int ch[100001]={};
    vector<int> v(100001,0);
    v[0] = start;
    while(n--)
    {
        int a,b;
        cin >> a >> b;
        ch[a]=b;
    }

    int cur = start;
    bool steal=0;
    for(int i=1;i<=100000;i++)
    {
        if(ch[i]!=0)
        {
            cur = ch[i];
        }
        v[i] = v[i-1]+cur;
    }

    vi res;
    while(m--)
    {
        int price,gotsteal;
        cin >> price >> gotsteal;

        int ans = lower(v,0,v.size()-1,-1,price);
        if(ans <= gotsteal)
        {
            res.pb(ans);
            continue;
        }

        ans = lower(v,0,v.size()-1,gotsteal,price);
        if(ans > gotsteal)
        {
            res.pb(ans);
            continue;
        }
    }

    for(auto i:res)
    {
        cout << i << " ";
    }


    return 0;
}