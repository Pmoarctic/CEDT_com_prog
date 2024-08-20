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


int main()
{  
    unordered_map<string,string> mp;
    int n;
    cin >> n;
    cin.ignore();
    while(n--)
    {
        string str;
        
        getline(cin,str);

        int st;
        for(int i=str.size()-1;i>=0;i--)
        {
            if(str[i] == ' ')
            {
                st = i+1;
                break;
            }
        }
        string tmp="";
        for(int i=st;i<str.size();i++)
        {
            tmp += str[i];
        }
        string tmp2="";
        for(int i=0;i<st-1;i++)
        {
            tmp2 += str[i];
        }
        mp[tmp] = tmp2;
        mp[tmp2] = tmp;
        //cout << tmp << tmp2;
    }


    int q;
    cin >> q;
    cin.ignore();
    while(q--)
    {
        string str;
        getline(cin,str);
        if(mp[str]=="")
        {
            cout << str << " --> Not found\n";
        }
        else
        {
            cout << str << " --> " << mp[str] << '\n';
        }
    }
    
}
/*
5
5
Anthony Stark 086-111-1111
Henry Pym 087-222-2222
Robert Banner 088-333-3333
Steven Rogers 089-444-4444
Natasha Romanoff 091-555-5555
*/
