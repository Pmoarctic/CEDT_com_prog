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
typedef priority_queue<pii, vector<pii> , greater<pii> > gpiiq;

unordered_map<string,vector<string> > adj;
unordered_map<string,string> anc;
unordered_map<string,int> indeg;

set<string> people;

struct STORE
{
    string id;
    string par1;
    string par2;
    int t;
};


void BFStree(string src)
{
    queue<STORE> q;
    q.push({src,"","",0});

    while(!q.empty())
    {
        auto [cur,p1,p2,gen] = q.front();
        q.pop();
        //cout << cur << "\n";
        
        //
        anc[cur] = p2;
        //

        for(auto i:adj[cur])
        {
            q.push({i,cur,p1,gen+1});
            // if(gen==0)
            // {
            //     q.push({i,cur,p1,gen+1});
            // }
            // else if(gen==1)
            // {
            //     q.push({i,cur,p1,gen+1});
            // }
            // else
            // {
            //     q.push({i,cur,p1,gen+1});
            // }
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n,m;
    cin >> n >> m;
    while(n--)
    {
        string a,b;
        cin >> a >> b;
        adj[a].pb(b);

        people.insert(a);
        people.insert(b);
        indeg[b]++;
    }

    vector<string> src;
    for(auto i:people)
    {
        if(indeg[i]==0)
        {
            src.push_back(i);
        }
    }
///////////////////////////////////////
//BFS

    for(auto i:src)
    {
        BFStree(i);
    }

    while(m--)
    {
        string a,b;
        cin >> a >> b;
        //if(anc[a]==anc[b] && a!=b && stoll(anc[a])>=1 && stoll(anc[b])>=1)
        if(anc[a]==anc[b] && a!=b && anc[a]!="" && anc[b]!="")
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

    // cout <<'\n';
    // for(auto i:anc)
    // {
    //     cout << i.first << " : " << i.second << '\n';
    // }

    return 0;
}
/*
10 1
1 2
1 3
2 4
2 5
3 6
4 7
4 8
5 9
6 10
6 11
*/