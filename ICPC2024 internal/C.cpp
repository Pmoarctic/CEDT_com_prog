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

set<int> U(vector<set<int> > vs)
{

}

int main()
{
    vector<set<int> > vecset;
    
    string str;
    while(getline(cin,str))
    {
        string tmp="";
        set<int> s;
        for(int i=0;i<str.size();i++)
        {
            if(str[i]==' ')
            {
                s.insert(stoi(tmp));
                tmp = "";
            }
            else
            {
                tmp += str[i];
            }
        }
        s.insert(stoi(tmp));
        vecset.pb(s);
    }

    for(auto i:vecset)
    {
        for(auto j:i)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
}
/*

*/
