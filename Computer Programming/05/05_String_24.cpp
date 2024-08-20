#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    getline(cin,s);

    vector<string> v;
    string tmp = "";
    for(int i=0;i<s.size();i++)
    {
        if(s[i] ==' ')
        {
            v.push_back(tmp);
            tmp = "";
        }
        else
        {
            tmp += s[i];
        }
    }
    v.push_back(tmp);

    string a = v[0];
    string b = v[v.size()-1];

    string a1="",a2="",b1="",b2="";
    int i=0;
    for(;i<a.size();i++)
    {
        if(a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u')
        {
            break;
        }
        else
        {
            a1 += a[i];
        }
    }
    for(;i<a.size();i++)
    {
        a2 += a[i];
    }

    i=0;
    for(;i<b.size();i++)
    {
        if(b[i] == 'a' || b[i] == 'e' || b[i] == 'i' || b[i] == 'o' || b[i] == 'u')
        {
            break;
        }
        else
        {
            b1 += b[i];
        }
    }
    for(;i<b.size();i++)
    {
        b2 += b[i];
    }

    cout << a1 << b2 << " ";

    for(int i=1;i<v.size()-1;i++)
    {
        cout << v[i] << " ";
    }
    
    cout << b1 << a2;
}