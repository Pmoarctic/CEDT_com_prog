#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;

    char cur = s[0];
    int n=1;
    for(int i=1;i<s.size();i++)
    {
        if(s[i] != cur)
        {
            cout << cur << " " << n << " ";
            cur = s[i];
            n=1;
        }
        else
        {
            n++;
        }
    }
    cout << cur << " " << n << " ";

    return 0;
}