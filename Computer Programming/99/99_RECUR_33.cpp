#include<bits/stdc++.h>
using namespace std;

vector<int> ans;
int w,a,b;

bool fn=0;

set<int> adj[1000000];
void dfs(int cur)
{
    if(cur == b)
    {
        fn=1;
        /*
        for(int i=0;i<ans.size()-1;i++)
        {
            cout << ans[i] << " -> ";
        }
        cout << ans[ans.size()-1] << "\n";
        */
        return; 
    }
    for(auto i:adj[cur])
    {
        ans.push_back(i);
        dfs(i);
        ans.pop_back();
    }
    return;
}

int main()
{   
    cin >> w >> a >> b;
    vector<int> tmp;
    while(w--)
    {
        int st,ed;
        cin >> st >> ed;
        tmp.push_back(st);
        adj[st].insert(ed);
    }
    /*
    for(auto i:tmp)
    {
        sort(adj[i].begin(),adj[i].end());
    }
    */

    ans.push_back(a);
    dfs(a);

    if(fn==0)
    {
        cout << "no";
    }
    else cout << "yes";

}
/*
10 1 5
1 2
4 5
1 3
1 5
2 3
1 4
2 4
2 5
3 5
3 4

*/