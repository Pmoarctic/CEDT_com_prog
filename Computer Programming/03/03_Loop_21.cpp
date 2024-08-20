#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    while(cin >> s)
    {
        int cp=0,sm=0,num=0,sp=0;
        for(auto i:s)
        {
            if('a'<=i && i<='z')sm++;
            else if('A'<=i && i<='Z')cp++;
            else if('0'<=i && i<='9')num++;
            else sp++;
            
        }
        if(s.size()>=12 &&sm&&cp&&num&&sp)
        {
            cout << ">> strong\n";
        }
        else if(s.size()>=8 &&sm&&cp&&num)
        {
            cout << ">> weak\n";
        }
        else
        {
            cout << ">> invalid\n";
        }
    }
}