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


int main()
{
    vull res;
    ull n;
    cin >> n;
    while(n>1)
    {
        res.pb(n);
        if(n%2)
        {
            n = 3*n + 1;
        }
        else
        {
            n/=2;
        }
        
    }
    //res.pb(1);


    if(sz(res)>=14)
    {
        for(int i=sz(res)-14;i<sz(res);i++)
        {
            cout << res[i] << "->";
        }
        cout << 1;
    }
    else
    {
        for(int i=0;i<sz(res);i++)
        {
            cout << res[i] << "->";
        }
        cout << 1;
    }
    

}