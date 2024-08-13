#include<bits/stdc++.h>
using namespace std;

string str;
set<string> s;
vector<bool> use(10000,0);

void recur(string tmp)
{
    if(tmp.size() == str.size())
    {
        s.insert(tmp);
        return;
    }
    else
    {
        for(int i=0;i<str.size();i++)
        {
            if(use[i] == 0)
            {
                use[i] = 1;
                recur(tmp+str[i]);
                use[i] = 0;

            }
        }
    }
    return;
}




int main()
{
    cin >> str;
    recur("");
    //cout << s.size() <<"\n";
    for(auto i:s)
    {
        cout << i << " ";
    }
}