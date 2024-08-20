#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define st first
#define nd second
#define sz(x) x.size();
#define all(x) x.begin,x.end()
typedef pair<int,int> pii;
typedef vector<int> vi;


int main()
{
    string str;
    vector<string> res;
    while(getline(cin,str))
    {
        int n = sz(str);
        int pim = 0;
        char sign = '\0';
        string tmp = "";
        for(int i=0;i<n;i++)
        {
            if( !((isalpha(str[i])) || str[i]==' ' || str[i]=='-' || str[i]==',' || str[i]=='\'') && sign=='\0')
            {
                sign = str[i];
                pim = 1;
            }
            else if(str[i] == sign)
            {
                pim = (pim+1)%2;
            }
            else if(pim == 1 && ((isalpha(str[i])) || str[i]==' ' || str[i]=='-' || str[i]==',' || str[i]=='\''))
            {
                tmp += str[i];
            }
        }
        res.pb(tmp);
    }
    for(auto i:res)
    {
        cout << i << '\n';
    }
}