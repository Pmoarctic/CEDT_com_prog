#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s,p;

    getline(cin,p);
    getline(cin,s);

    int m = p.size();
    int n = s.size();
    int res=0;
    vector<string> word;

    string tmp = "";
    for(int i=0;i<n;i++)
    {   
        if(('a'<=s[i]&&s[i]<='z') || ('A'<=s[i]&&s[i]<='Z'))
        {
            tmp += s[i];
        }
        else
        {
            word.push_back(tmp);
            tmp = "";
        }
    }
    word.push_back(tmp);

    for(auto i:word)
    {
        if(p==i)res++;
        //cout << i << "\n";
    }

    cout <<res;
}