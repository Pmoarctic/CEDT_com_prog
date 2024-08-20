#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ull> vull;


unordered_map<string,vector<string> > mp;

int main()
{  
    int n;
    cin >> n;
    cin.ignore();
    string str;
    while(n--)
    {
        getline(cin,str);
        //cout << str << '\n';
        string song,art,tmp="";
        for(int i=0;i<str.size();i++)
        {
            if(str[i]==',')
            {
                song = tmp;
                i++;
                tmp = "";
            }
            else
            {
                tmp += str[i];
            }
        }
        art = tmp;
        //cout << art << song <<'\n';
        mp[song].pb(art);
    }
    getline(cin,str);

    string tmp="";
    for(int i=0;i<str.size();i++)
    {
        if(str[i]==',')
        {
            i++;
            cout << tmp << " -> ";
            if(mp[tmp].size()==0)
            {
                cout << "Not found\n";
                tmp="";
                continue;
            }
            for(int j=0;j<mp[tmp].size()-1;j++)
            {
                cout << mp[tmp][j] << ", ";
            }
            cout << mp[tmp][mp[tmp].size()-1] << '\n';

            
            tmp = "";
        }
        else
        {
            tmp += str[i];
        }
    }
    cout << tmp << " -> ";
    if(mp[tmp].size()==0)
    {
        cout << "Not found\n";
        tmp="";
        return 0;
    }
    for(int j=0;j<mp[tmp].size()-1;j++)
    {
        cout << mp[tmp][j] << ", ";
    }
    cout << mp[tmp][mp[tmp].size()-1] << '\n';

    return 0;
}
/*

*/
