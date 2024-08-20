#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int i=0;
    int mn1=INT_MAX,mx1=INT_MIN;
    int mn2=INT_MAX,mx2=INT_MIN;

    while(true)
    {
        int arr[2];
        cin >> arr[0];
        if(arr[0] == -998)
        {
            cout << mn1 << " " << mx2;
            break;
        }
        else if(arr[0] == -999)
        {
            cout << mn2 << " " << mx1;
            break;
        }
        cin >> arr[1];

        mn1 = min(mn1,arr[i%2]);
        mn2 = min(mn2,arr[(i+1)%2]);

        mx1 = max(mx1,arr[i%2]);
        mx2 = max(mx2,arr[(i+1)%2]);

        i++;
    }
    
}
