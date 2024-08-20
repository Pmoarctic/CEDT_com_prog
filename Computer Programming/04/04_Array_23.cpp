#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    unordered_map<string,int> mp;
    while(n--)
    {
        string a;
        int b;
        cin >> a >> b;

        mp[a]=b;
    }
    string s;
    cin.ignore();
    getline(cin,s);

    vector<string> v;
    string tmp="";
    for(int i=0;i<s.size();i++)
    {
        if(s[i] ==' ')
        {
            v.push_back(tmp);
            tmp = "";
        }
        else if(i%7 == 4 || i%7 == 5)
        {
            tmp += s[i];
        }
    }
    v.push_back(tmp);

    int res=0;
    string cur = v[0];
    for(int i=1;i<v.size();i++)
    {
        if(v[i] == cur){continue;}

        //cout << v[i] << "->" << mp[v[i]] << "\n";
        res += mp[v[i]];
        cur = v[i];
        
    }
    cout << res;
}
//6 13