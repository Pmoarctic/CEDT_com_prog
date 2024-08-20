#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;

    string tmp = "";
    tmp += s[0];

    int state;
    if((s[0] >= 'a' && s[0] <= 'z') || (s[0] >= 'A' && s[0] <= 'Z'))
    {
        state = 1;
    }
    else
    {
        state = 0;
    }
    for(int i=1;i<s.size();i++)
    {
        if(state==1 && ((s[i]>='0'&&s[i]<='9') || (s[i]>='A'&&s[i]<='Z')))
        {
            cout << tmp <<", ";
            tmp = "";
            tmp += s[i];
        }
        else if(state==0 && ((s[i]>='a'&&s[i]<='z') || (s[i]>='A'&&s[i]<='Z')))
        {
            cout << tmp <<", ";
            tmp = "";
            tmp += s[i];
        }
        else
        {
            tmp += s[i];
        }

        if((s[i]>='A'&&s[i]<='Z') || (s[i]>='a'&&s[i]<='z'))
        {
            state = 1;
        }
        else
        {
            state = 0;
        }

    }
    cout << tmp;
}