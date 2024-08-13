#include<bits/stdc++.h>
using  namespace std;

int main()
{
    float p;
    cin >> p;
    float k=1,t=1;

    while(true)
    {
        t = (t*(366-k))/365;

        if(1-t>=p)
        {
            break;
        }
        k++;
    }

    cout << k;

}