#include<iostream>
using namespace std;

int main()
{
    string s;
    cin >> s;
    if(s.size() != 10)
    {
        cout << "Not a mobile number";
        return 0;
    }
    if(s[0] != '0')
    {
        cout << "Not a mobile number";
        return 0;
    }
    if(s[1] != '6' && s[1] != '8' && s[1] != '9' )
    {
        cout << "Not a mobile number";
        return 0;
    }

    cout << "Mobile number";
        return 0;
}