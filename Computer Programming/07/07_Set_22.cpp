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

unordered_map<string,int> mp = {{"A",1},{"B+",2},{"B",3},{"C+",4},{"C",5},{"D+",6},{"D",7},{"F",8}};
unordered_map<int,string> mp2 = {{1,"A"},{2,"B+"},{3,"B"},{4,"C+"},{5,"C"},{6,"D+"},{7,"D"},{8,"F"}};

set<int> U(vector<set<int> > vecset)
{
    for(int i=1;i<vecset.size();i++)
    {
        for(auto j:vecset[i])
        {
            vecset[0].insert(j);
        }
    }
    return vecset[0];
}

set<int> I(vector<set<int> > vecset)
{
    set<int> res;
    for(auto i:vecset[0])
    {
        bool fg=1;
        for(int j=1;j<vecset.size();j++)
        {
            if(vecset[j].find(i) == vecset[j].end())
            {
                fg=0;
            }
        }
        if(fg)
        {
            res.insert(i);
        }
    }
    return res;
}

set<int> D(vector<set<int> > vecset)
{
    for(int i=1;i<vecset.size();i++)
    {
        for(auto j:vecset[i])
        {
            vecset[0].erase(j);
        }
    }
    return vecset[0];
}

int main()
{  
    vector<set<int> > vs;
    string str;
    while(getline(cin,str))
    {
        set<int> s;
        string tmp="";
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

        vs.pb(s);
    }

    auto res1 = U(vs);
    auto res2 = I(vs);
    auto res3 = D(vs);

    if(res1.empty())
    {
        cout << "U: empty set\n";
    }
    else
    {
        cout << "U:";
        for(auto i:res1)
        {
            cout << " " << i;
        }
        cout << "\n";
    }
    
    if(res2.empty())
    {
        cout << "I: empty set\n";
    }
    else
    {
        cout << "I:";
        for(auto i:res2)
        {
            cout << " " << i;
        }
        cout << "\n";
    }

    if(res3.empty())
    {
        cout << "D: empty set\n";
    }
    else
    {
        cout << "D:";
        for(auto i:res3)
        {
            cout << " " << i;
        }
        cout << "\n";
    }


}
/*

*/
