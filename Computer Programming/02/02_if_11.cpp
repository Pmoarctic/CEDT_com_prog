#include<iostream>
#include<unordered_map>
using namespace std;

unordered_map<string,bool> mp = {{"01",1},
                                {"02",1},
                                {"20",1},
                                {"21",1},
                                {"22",1},
                                {"23",1},
                                {"24",1},
                                {"25",1},
                                {"26",1},
                                {"27",1},
                                {"28",1},
                                {"29",1},
                                {"30",1},
                                {"31",1},
                                {"32",1},
                                {"33",1},
                                {"34",1},
                                {"35",1},
                                {"36",1},
                                {"37",1},
                                {"38",1},
                                {"39",1},
                                {"40",1},
                                {"51",1},
                                {"53",1},
                                {"55",1},
                                {"58",1}};

int main()
{
    string s;
    cin >> s;

    if(mp[s])
    {
        cout << "OK";
    }
    else cout << "Error";
    //why lost
}