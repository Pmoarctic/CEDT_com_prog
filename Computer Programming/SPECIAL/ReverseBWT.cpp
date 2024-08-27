#include<bits/stdc++.h>
using namespace std;
string inverseBWT(string z)
{
    vector<string> y(z.size(),"");
    while(y[0].size()!=z.size())
    {
        for(int i=0;i<z.size();i++)
        {
            y[i] = z[i] + y[i];
        }

        sort(y.begin(),y.end());
    }
    string res = "";
    for(int i=1;i<y[0].size();i++)
    {
        res += y[0][i];
    }
    return res;
}

int main()
{
    string s;
    cin >> s;
    auto res = inverseBWT(s);
    cout << res;
}

//3.55 min;