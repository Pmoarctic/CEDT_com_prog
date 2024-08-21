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

unordered_map<string,ll> mp;
vector<tuple<string,ll,ll> > vec;
//name money year

bool sorting(pair<ll,string> &a,pair<ll,string> &b)
{
    if(a.first != b.first)
    {
        return a.first > b.first;
    }
    return a.second < b.second;
}

int main()
{
    string s;
    while(cin >> s)
    {
        if('0'<=s[0] && s[0]<='9')break;

        ll money;
        cin >> money;

        string tmp="",tmp2="";
        int i=0;
        for(;i<s.size()-4;i++)
        {
            tmp += s[i];
        }
        tmp2 += s[i];
        tmp2 += s[i+1];
        //cout << tmp << " " << tmp2 << "\n";
        vec.pb({tmp,money,stoll(tmp2)});
    }
    ll m = stoll(s)%100;
    //cout << m;
    for(auto [a,b,c]:vec)
    {
       if(c<=m)
       {
            mp[a] += b;
       }
       //cout << a << " " << b << " " << c << "\n";
    }
    
    vector<pair<ll,string> > vec;
    for(auto i:mp)
    {
        vec.pb({i.second,i.first});
        //cout << i.first << " " << i.second << "\n";
    }
    sort(all(vec),sorting);
    for(auto i:vec)
    {
        cout << i.second << " " << i.first << "\n";
    }
}