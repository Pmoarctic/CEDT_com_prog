#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    if(n>2000)
    {
        cout << "Reject";
        return 0;
    }
    else if(n>1000)
    {
        cout << 58;
        return 0;
    }
    else if(n>500)
    {
        cout << 38;
        return 0;
    }
    else if(n>250)
    {
        cout << 28;
        return 0;
    }
    else if(n>100)
    {
        cout << 22;
        return 0;
    }
    else
    {
        cout << 18;
        return 0;
    }
}