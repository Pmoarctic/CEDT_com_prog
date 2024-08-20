#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    int t;
    cin >> s >> t;
    int n=s.size();

    vector<bool> r(n,1);

    
    for(int i=0;i<n;)
    {
        int st = i;
        int ed = i;
        while(s[st] == s[ed])
        {
            ed++;
        }
        if(ed-st >= t)
        {
            for(int j=st;j<ed;j++)
            {
                r[j] = 0;
            }
        }
        i=ed;
    }

    string res = "";
    for(int i=0;i<n;i++)
    {
        if(r[i]==1)
        {
            res += s[i];
        }
    }

    cout << res;


    return 0;
}