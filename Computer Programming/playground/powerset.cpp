#include<bits/stdc++.h>
using namespace std;

set<int> st;

set<set<int> > res;
set<int> tmp={};

void recur(int siz)
{
    if(tmp.size() == siz)
    {
        res.insert(tmp);
        return;
    }
    else
    {
        for(auto i:st)
        {
            if(tmp.find(i) != tmp.end())
            {
                continue;
            }
            tmp.insert(i);
            recur(siz);
            tmp.erase(i);
        }
    }
}

bool sortsize(set<int> &a, set<int> &b)
{
    return a.size()<b.size();
}

int main()
{
    
    int n;
    cin >> n;
    while(n--)
    {
        int t;
        cin >> t;
        st.insert(t);
    }

    for(int i=1;i<=st.size();i++)
    {
        //cout << i << "\n";
        recur(i);
    }

    vector<set<int> > ans;
    for(auto i:res)
    {
        ans.push_back(i);
    }
    sort(ans.begin(),ans.end(),sortsize);

    for(auto i:ans)
    {
        cout << "{";
        for(auto j:i)cout << j << " ";
        cout << "}\n";
    }
}