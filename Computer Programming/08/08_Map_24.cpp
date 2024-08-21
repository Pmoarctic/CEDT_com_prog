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



struct ICECREAM
{
    string name;
    double price;
    double total=0;
};
unordered_map<string,ICECREAM> mp;

bool sortname(ICECREAM &a,ICECREAM &b)
{
    if(a.price!=b.price)
    {
        return a.total>b.total;
    }
    return a.name < b.name;
}

int main()
{  
    int n;
    cin >> n;
    while(n--)
    {
        string a;
        double b;
        cin >> a >> b;
        mp[a]= {a,b,0};
    }

    double sell=0;
    int m;
    cin >> m;
    while(m--)
    {
        string tmp;
        double k;
        cin >> tmp >> k;
        mp[tmp].total += mp[tmp].price*k;
        sell += mp[tmp].price*k;
    }
    vector<ICECREAM> vec;
    for(auto i:mp)
    {
        vec.pb(i.second);
    }
    if(sell == 0)
    {
        cout << "No ice cream sales";
        return 0;
    }
    sort(all(vec),sortname);
    //out << '\n';
    double mx = vec[0].total;
    cout << "Total ice cream sales: " << sell << "\nTop sales: ";
    for(auto i:vec)
    {
        if(i.total==mx)cout << i.name << " ";
    }
    /*
    cout << '\n';
    for(auto i:vec)
    {
        cout << i.name << "\n";
    }
    */
}
/*

*/
