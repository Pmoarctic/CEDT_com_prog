#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    char mp[4] = {'\0','K','M','B'}; 
    double n;
    cin >> n;

    if(n > 1000000000)
    {
        auto tmp = n;
        tmp /= 1000000000;
        if(tmp > 10)
        {
            cout << round(tmp) << "B";
        }
        else
        {
            tmp *= 10;
            tmp = round(tmp);
            tmp/=10;
            cout << tmp << "B";
        }
        return 0;
    }

    if(n > 1000000)
    {
        auto tmp = n;
        tmp /= 1000000;
        if(tmp > 10)
        {
            cout << round(tmp) << "M";
        }
        else
        {
            tmp *= 10;
            tmp = round(tmp);
            tmp/=10;
            cout << tmp << "M";
        }
        return 0;
    }

    if(n > 1000)
    {
        auto tmp = n;
        tmp /= 1000;
        if(tmp > 10)
        {
            cout << round(tmp) << "K";
        }
        else
        {
            tmp *= 10;
            tmp = round(tmp);
            tmp/=10;
            cout << tmp << "K";
        }
        return 0;
    }

    cout << n;

    return 0;
}