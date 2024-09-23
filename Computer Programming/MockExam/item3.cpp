#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long res=0;
    long long p;
    cin >> p;
    string s;
    while(cin >> s)
    {
        string tmp="";
        for(int i=1;i<s.size();i++)
        {
            tmp += s[i];
        }
        res += stoll(tmp);
    }

    cout << res*p;
}