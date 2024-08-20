#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ull> vull;

struct VECT
{
    int sum=0;
    vi vec;

    bool operator<(const VECT &x) const
    {
        if(x.sum != sum)
        {
            return x.sum < sum;
        }
        else if(x.vec.size() != vec.size())
        {
            return x.vec.size() > vec.size();
        }
        else
        {
            for(int i=0;i<vec.size();i++)
            {
                return x.vec[i]>vec[i];
            }
        }
    }
};


vector<VECT> solve1(vector<int> arr)
{
    vector<VECT> s;
    for(auto i:arr)
    {
        bool fg=0;
        for(int j=0;j<s.size();j++)
        {
            if(s[j].sum + i <= 100)
            {
                fg=1;
                s[j].sum += i;
                s[j].vec.pb(i);
                break;
            }
        }
        if(fg)
        {
            continue;
        }
        else
        {
            s.pb({i,{i}});
        }
    }

    return s;
}

vector<VECT> solve2(vector<int> arr)
{
    vector<VECT> s;
    for(auto i:arr)
    {
        int idx = -1;
        int mn = INT_MAX;
        for(int j=0;j<s.size();j++)
        {
            if(s[j].sum + i <= 100)
            {
                if(100 - s[j].sum - i < mn)
                {
                    mn = 100 - s[j].sum - i;
                    idx = j;
                }
            }
        }
        if(idx != -1)
        {
            s[idx].sum += i;
            s[idx].vec.pb(i);
        }
        else
        {
            s.pb({i,{i}});
        }
    }

    return s;
}

int main()
{
    vi v;
    string cmd;
    cin >> cmd;
    int tmp;
    while(cin >> tmp)
    {
        v.pb(tmp);
    }

    vector<VECT> res;
    if(cmd=="first")
    {
        res = solve1(v);
    }
    else
    {
        res = solve2(v);
    }

    for(int i=0;i<res.size();i++)
    {
        sort(all(res[i].vec));
    }
    sort(all(res));

    for(auto i:res)
    {
        //cout << i.sum << '\n';
        for(auto j:i.vec)
        {
            cout << j << " ";
        }
        cout << "\n";
    }

}
