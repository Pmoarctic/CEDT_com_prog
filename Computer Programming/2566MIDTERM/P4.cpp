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

bool isprime(ll n)
{
    if(n==2)return 1;
    if(n%2==0)return 0;

    double k = sqrt(n);
    bool res = 1;
    for(ll i=3;i<=k;i+=2)
    {
        if(n%i==0)
        {
            res=0;
            break;
        }
    }

    return res;
}

int main()
{  
    ll t;
    cin >> t;
    while(t--)
    {
        ll a,b,c,d;
        cin >> a >> b >> c >> d;
        ll num = 0;
        for(int i=1;i<=b;i++)
        {
            num*=10;
            num+=a;
        }

        for(int i=1;i<=d;i++)
        {
            num*=10;
            num+=c;
        }

        if(isprime(num))
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }

    }
}