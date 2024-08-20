#include<bits/stdc++.h>
using namespace std;

unordered_map<string,string> mp =  {{"uuuu","0"},{"uuul","1"},{"uulu","2"},
                                    {"uull","3"},{"uluu","4"},{"ulul","5"},
                                    {"ullu","6"},{"ulll","7"},{"luuu","8"},
                                    {"luul","9"},{"lulu","-"},{"lull",","},
                                    {"0","uuuu"},{"1","uuul"},{"2","uulu"},
                                    {"3","uull"},{"4","uluu"},{"5","ulul"},
                                    {"6","ullu"},{"7","ulll"},{"8","luuu"},
                                    {"9","luul"},{"-","lulu"},{",","lull"}};

string encode(string str,string temp)
{
    string pattern = "";
    for(int i=0;i<str.size();i++)
    {
        string t = "";
        t += str[i];
        pattern += mp[t];
    }
    

    int nt=0;
    for(int i=0;i<temp.size();i++)
    {
        if((temp[i] >= 'a' && temp[i] <= 'z') || (temp[i] >= 'A' && temp[i] <= 'Z'))
        {
            nt++;
        }
    }

    int np = pattern.size();
    string pas = "";
    int npas = 0;

    while(npas+nt <=np)
    {
        pas += temp;
        npas += nt;
    }
    for(int i=0;i<temp.size();i++)
    {
        if(npas == np)
        {
            break;
        }
        if((temp[i] >= 'a' && temp[i] <= 'z') || (temp[i] >= 'A' && temp[i] <= 'Z'))
        {
            pas += temp[i];
            npas++;
        }
        else
        {
            pas += temp[i];
        }
        
    }
    /////////
    int i1=0,i2=0;
    for(;i1<pas.size();i1++)
    {
        if((pas[i1] >= 'a' && pas[i1] <= 'z') || (pas[i1] >= 'A' && pas[i1] <= 'Z'))
        {
            if(pattern[i2] == 'u')
            {
                pas[i1] = toupper(pas[i1]);
            }
            else
            {
                pas[i1] = tolower(pas[i1]);
            }
            i2++;
        }
    }

    return pas;
}

string decode(string str)
{
    string res = "";

    string tmp = "";
    for(int i=0;i<str.size();i++)
    {
        if(str[i]>='a' && str[i] <='z')
        {
            tmp += "l";
        }
        else if(str[i]>='A' && str[i] <='Z')
        {
            tmp += "u";
        }

        if(tmp.size() == 4)
        {
            res += mp[tmp];
            tmp = "";
        }
    }
    return res;
}



int main()
{
    string s;
    getline(cin,s);
    
    //cout << s <<endl;
    char cmd;

    
    while(cin >> cmd)
    {
        cin.ignore();
        string tmp;
        if(cmd == 'E')
        {
            getline(cin,tmp);
            cout << encode(tmp,s) << '\n';
        }
        else if(cmd == 'D')
        {
            getline(cin,tmp);
            cout << decode(tmp) << '\n';
        }
    }
}
/*
midterm-exam
E 1,2,1,3,2
E 2,4,3,2,4
E 2,3,2,1,1
E 2,3,2,3,4
D MIDteRm-eXAm-MiDteRM-ExaM-miDTerm-ExaM-MiD
D MIdTeRm-eXaM-MiDteRM-exaM-miDTeRm-ExaM-mID
D MIdTeRm-eXAm-miDteRM-eXaM-miDTErm-ExaM-MId
D MIdTeRm-eXAm-miDteRM-eXaM-miDTerm-ExaM-mID
*/