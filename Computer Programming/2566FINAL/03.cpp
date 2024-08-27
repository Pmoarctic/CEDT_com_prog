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

struct DEPART
{
    string name;
    set<string> member;
    int num=0;
    bool have;
};

bool sortname(DEPART &a,DEPART &b)
{
    return a.name<b.name;
}

unordered_map<string,DEPART> com;
set<string> dept_name;
unordered_map<string,string> mp;

int main()
{  
    int n,m;
    cin >> n >> m;
    while(n--)
    {
        string a,b;
        cin >> a >> b;
        mp[a] = b;
        if(dept_name.find(b) == dept_name.end())
        {
            set<string> tmp;
            tmp.insert(a);
            dept_name.insert(b);
            com[b] = {b,tmp,1,1};
        }
        else
        {
            com[b].member.insert(a);
        }
    }

    while(m--)
    {
        int cmd;
        cin >> cmd;
        if(cmd==1)
        {
            string a,b;
            cin >> a >> b;
            string ain = mp[a];
            com[ain].member.erase(a);
            com[ain].num--;

            mp[a] = b;
            if(dept_name.find(b) == dept_name.end())
            {
                set<string> tmp;
                tmp.insert(a);
                dept_name.insert(b);
                com[b] = {b,tmp,1,1};
            }
            else
            {
                com[b].member.insert(a);
            }
        }
        else
        {
            string a,b;
            cin >> a >> b;
            dept_name.erase(a);
            com[a].have=0;
            if(dept_name.find(b) == dept_name.end())
            {
                set<string> tmp;
                dept_name.insert(b);
                com[b] = {b,tmp,0,1};
            }
            for(auto i:com[a].member)
            {
                com[b].member.insert(i);
            }
            com[a].member.clear();
        }
    }


    vector<DEPART> vec;
    for(auto i:com)
    {
        if(i.second.have==1)
        {
            vec.pb(i.second);
        }
    }
    sort(all(vec),sortname);
    for(auto i:vec)
    {
        cout << i.name << ":";
        for(auto j:i.member)
        {
            cout << " " << j;
        }
        cout << "\n";
    }
}

/*
4 2
MrA Dept1
MrB Dept2
MrC Dept3
MrD Dept4
1 MrA Dept4
1 MrA Dept2

4 3
MrA Dept1
MrB Dept2
MrC Dept3
MrD Dept4
1 MrA Dept4
1 MrA Dept2
2 Dept2 Dept4

4 4
MrA Dept1
MrB Dept2
MrC Dept3
MrD Dept4
1 MrA Dept4
1 MrA Dept2
2 Dept2 Dept4
1 MrC Dept2

3 4
Somchai Dept1
Somying Dept1
Somboon Dept1
1 Somchai NewDept
1 Somying Sales
2 Dept1 Service
2 Sales Service
*/