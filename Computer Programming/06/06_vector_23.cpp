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


int main()
{
    vector<tuple<double,int,double,double> > v;
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        double x,y;
        cin >> x >> y;

        v.pb({sqrt(x*x+y*y),i,x,y});
    }
    sort(all(v));
    
    auto [a,b,c,d]= v[2];

    cout << "#" << b << ": (" << c << ", " << d << ")";

}