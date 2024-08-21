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


int main()
{  
    double u,o,t;
    cin >> u >> o >> t;

    o = (o/180)*M_PI;

    double h = (t-(u*sin(o))/10.0) * (u*sin(o) + 5.0*(t-(3.0*u*sin(o))/10.0));
    double r = u*cos(o)*t;

    cout << round(h*10)/10 << " " << round(r*10)/10;
}