#include<bits/stdc++.h>
using namespace std;

int main()
{
    string a,n;
    while(cin >> a)
    {
        cin >> n;
        if(n=="0")
        {
            cout << ">> 1\n";
            continue;
        }
        
        int x = a[a.size()-1]-'0';
        int y;
        if(n.size()==1)
        {
            y = (n[n.size()-1]-'0');
        }
        else y = (n[n.size()-2]-'0')*10 + (n[n.size()-1]-'0');
        //cout << x << " " << y << "\n";
        
        y %= 4;

        int arr[4];

        arr[0] = ((int)pow(x,4))%10;
        arr[1] = ((int)pow(x,1))%10;
        arr[2] = ((int)pow(x,2))%10;
        arr[3] = ((int)pow(x,3))%10;

        cout << ">> " << arr[y] << "\n";

    }
    
    
}