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

unordered_map<string,string> mp;
unordered_map<string,int> st;

int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        string l,r;
        cin >> l >> r;
        mp[l]=r;
        st[l]+=0;
        st[r]+=1;
    }

    string cur;
    for(auto i:st)
    {
        //cout << i.first << " " << i.second << "\n";
        if(i.second==0)
        {
            cur = i.first;
            break;
        }
    }

    //cout << cur << "<-\n";

    while(cur != "")
    {
        cout << cur << " ";
        cur = mp[cur];
    }
}