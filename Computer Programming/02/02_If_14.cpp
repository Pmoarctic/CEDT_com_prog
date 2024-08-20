#include<iostream>
using namespace std;

int main()
{
    string a,b;
    char arr[2][4];
    double grade[2];
    cin >> a >> grade[0] >> arr[0][1] >> arr[0][2] >> arr[0][3];
    cin >> b >> grade[1] >> arr[1][1] >> arr[1][2] >> arr[1][3];
    bool p[2];
    p[0] = ((arr[0][1]=='A') && (arr[0][2] <= 'C')) && (arr[0][3] <= 'C');
    p[1] = ((arr[1][1]=='A') && (arr[1][2] <= 'C')) && (arr[1][3] <= 'C');


    if(p[0] == p[1] && p[0] == 0)
    {
        cout << "None";
        return 0;
    }
    else if(p[0] != p[1])
    {
        if(p[0])
        {
            cout << a;
        }
        else if(p[1])
        {
            cout << b;
        }
        return 0;
    }


    if(grade[0] > grade[1])
    {
        cout << a;
    }
    else if(grade[0] < grade[1])
    {
        cout << b;
    }
    else if(arr[0][2] > arr[1][2])
    {
        cout << b;
    }
    else if(arr[0][2] < arr[1][2])
    {
        cout << a;
    }
    else if(arr[0][3] > arr[1][3])
    {
        cout << b;
    }
    else if(arr[0][3] < arr[1][3])
    {
        cout << a;
    }
    else
    {
        cout << "Both";
    }



    return 0;
}