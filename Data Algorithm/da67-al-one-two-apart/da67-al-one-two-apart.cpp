#include<bits/stdc++.h>
#define ll unsigned long long
#define pb push_back()
#define all(x) x.begin(),x.end()
#define pii pair<int,int>
#define MOD 100000007


using namespace std;

int main()
{
    ll n;
    cin >> n;
    if(n==1)
    {
        cout << 3;
        return 0;
    }

    ll n00=1;
    ll n_0=2;
    ll n_1=2;
    ll n_2=2;
    for(ll i=3;i<=n;i++)
    {
        ll new00=0,new_0=0,new_1=0,new_2=0;
        new00 = (new00 + n00)%MOD;
        new00 = (new00 + n_0%MOD);

        new_0 = (new_0 + n_1)%MOD;
        new_0 = (new_0 + n_2)%MOD;

        new_1 = (new_1 + n00)%MOD;
        new_1 = (new_1 + (n_0+1)/2)%MOD;
        new_1 = (new_1 + n_1)%MOD;

        new_2 = (new_2 + n00)%MOD;
        new_2 = (new_2 + n_0/2)%MOD;
        new_2 = (new_2 + n_2)%MOD;

        n00 = new00%MOD;
        n_0 = new_0%MOD;
        n_1 = new_1%MOD;
        n_2 = new_2%MOD;
        //cout << n00 << "\n" << n_0 << "\n" << n_1 << "\n" << n_2 << "\n\n";
    }
    //cout << n00 << "\n" << n_0 << "\n" << n_1 << "\n" << n_2 << "\n\n";
    ll res = 0;
    res = (res + n00)%MOD;
    res = (res + n_0)%MOD;
    res = (res + n_1)%MOD;
    res = (res + n_2)%MOD;
    cout << res << "\n";
}
