#include<bits/stdc++.h>
using namespace std;

int main()
{
    char a;
    char b1,b2;
    char c1,c2,c3,t;
    cin >> a >> b1 >> b2 >> t >> c1 >> c2 >> c3;
    
    int sum,n;
    sum = a-'0';
    sum *= 10;
    sum += b1-'A';
    sum *= 26;
    sum += b2-'A';
    sum *= 26;
    sum += c1-'0';
    sum *= 10;
    sum += c2-'0';
    sum *= 10;
    sum += c3-'0';
    cout << sum << endl;
    cin >> n;
    
    sum += n;

    a = (sum / 676000)+'0';
    sum %= 6760000;
    
    b1 = (sum/67600)+'A';
    sum %= 67600;

    b2 = (sum/2600)+'A';
    sum %= 2600;
    
    c1 = (sum/100)+'0';
    sum %= 100;

    c2 = (sum/10)+'0';
    sum %= 10;

    c3 = sum+'0';

    if(c1>'9')
    {
        c1-=10;
    }
    if(b2>'Z')
    {
        b2-=26;
    }
    if(b1>'Z')
    {
        b1-=26;
    }
    if(a>'9')
    {
        a-=10;
    }

    cout << a << b1 << b2 << "-" << c1 << c2 << c3;
}
/*
4 X Y - 999

y z . . . .
115 + 1 =116
*/