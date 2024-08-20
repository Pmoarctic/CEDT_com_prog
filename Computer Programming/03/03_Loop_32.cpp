#include<bits/stdc++.h>
using namespace std;
#define ll long long

unordered_map<char,int> mp = {{'R',1},{'Y',2},{'G',3},{'N',4},{'B',5},{'P',6},{'K',7}};
vector<char> check = {'Y','G','N','B','P','K'};

int main()
{
    string tmp;
    getline(cin,tmp);
    int t=tmp[0]-'0';


    while(t--)
    {
        string s;
        getline(cin,s);
        vector<char> v;
        for(int i=0;i<s.size();i++)
        {
            if(i%2==0)
            {
                v.push_back(s[i]);
            }
        }
        ////////////////////////
        int score=0;
        int lastred=-1;
        for(int i=0;i<v.size();i++)
        {
            score += mp[v[i]];
            
            if(v[i]=='R')
            {
                lastred=i;
            }
        }


        /////////////////////
        bool fg=1;
        bool isred=0;
        
        for(int i=0;i<lastred+2;i++)
        {
            if(v[i]=='R' && isred==1)
            {
                fg=0;
            }
            if(v[i]!='R' && isred==0)
            {
                fg=0;
            }
            
            if(v[i]=='R')
            {
                isred = 1;
            }
            else
            {
                isred = 0;
            }
        }

        vector<char> tmp;
        
        for(int i=lastred+2;i<v.size();i++)
        {
            tmp.push_back(v[i]);
        }

        if(tmp.size() > 6)
        {
            cout << "WRONG_INPUT\n";
            continue;
        }
        for(int a=0,b=0; b<6;)
        {
            if(a>=tmp.size())
            {
                break;
            }
            if(tmp[a]!=check[b])
            {
                fg=0;
            }

            a++;
            b++;
        }



        if(fg)
        {
            cout << score << "\n";
        }
        else
        {
            cout << "WRONG_INPUT\n";
        }
    }
    
}
