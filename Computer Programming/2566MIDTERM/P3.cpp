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

unordered_map<string,double> mp = {{"A",4.0},{"B+",3.5},{"B",3.0},{"C+",2.5},{"C",2.0},{"D+",1.5},{"D",1.0},{"F",0.0}};

int main()
{  
    int n;
    cin >> n;

    double up=0,down=0;
    while(n--)
    {
        string a;
        int b;
        cin >> a >> b;

        up += (mp[a]*b);
        down += b;
    }

    cout << round(up/down*100)/100;

}