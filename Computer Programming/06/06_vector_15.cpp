#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back
#define st first
#define nd second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
typedef pair<int,int> pii;
typedef vector<ll> vll;
typedef vector<ull> vull;

string shift(string str)
{
    string tmp = "";
    for(int i=1;i<sz(str);i++)
    {
        tmp += str[i];
    }
    tmp += str[0];

    return tmp;
}

int main()
{
    vector<string> v;
    string x;
    cin >>x;
    string y = x + "$";

    int n = sz(y);
    while(n--)
    {
        v.pb(y);
        y = shift(y);
    }
    sort(all(v));

    for(auto i:v)
    {
        cout << i[i.size()-1];
    }

}