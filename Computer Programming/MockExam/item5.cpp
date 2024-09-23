#include<bits/stdc++.h>
using namespace std;

bool checkPermu(vector<int> &vec,int sz)
{
    unordered_map<int,int> mp;
    for(auto i:vec)
    {
        mp[i]++;
    }
    for(int i=1;i<=sz;i++)
    {
        if(mp[i]==0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        int t;
        cin >> t;
        v.push_back(t);
    }

    int res=0;
    for(int sz=1;sz<=n;sz++)
    {
        for(int i=0;i<n;i++)
        {
            if(i+sz > n)break;

            vector<int> tmp;
            for(int j=i;j<i+sz;j++)
            {
                tmp.push_back(v[j]);
            }

            if(checkPermu(tmp,sz))
            {
                res++;
            }
        }
    }
    cout << res;
}