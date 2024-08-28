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

vector<pair<int,string> > vec;

bool sorting(pair<int,string> &a, pair<int,string> &b)
{
    if(a.first!=b.first)
    {
        return a.first>b.first;
    }
    else
    {
        return a.second<b.second;
    }
}

int main()
{  
    int n;
    cin >> n;
    while(n--)
    {
        string a;
        int b;
        cin >> a >> b;
        vec.pb({b,a});
    }
    sort(all(vec),sorting);

/*
    for(auto i:vec)
    {
        cout << i.first << " " << i.second << endl;
    }
    */


    set<string> s;

    int m;
    cin >> m;
    int order = 0;
    int cur_score = 0;
    for(int i=0;i<vec.size();i++)
    {
        if(cur_score != vec[i].first)
        {   
            if(order >= m)
            {
                break;
            }
            if(cur_score!=0)
            {
                cout << '\n';
            }
            cout << vec[i].first;
            cur_score = vec[i].first;
            order++;
            
        }
        if(vec[i].first==cur_score && s.find(vec[i].second) == s.end())
        {
            s.insert(vec[i].second);
            cout << " " << vec[i].second;
        }
    }
    
}
/*
5
B 50
A 10
C 50
A 100
D 80
2

9
D 50
A 80
C 50
E 10
K 20
E 20
A 10
AA 50
D 100
3
*/