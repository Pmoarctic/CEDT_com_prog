#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;

    int a;
    char b1,b2;
    int c;
    a = s[0]-'0';

    b1 = s[1];
    b2 = s[2];

    c = (s[4]-'0')*100 + (s[5]-'0')*10 + (s[6]-'0');

    int n;
    cin >> n;
    c += n;
    int carry = c/1000;
    c%=1000;


    b2 += (carry)%26;
    carry = carry/26;
    if(b2 >'Z')
    {
        b2 -= 26;
        carry++;
    }
    

    b1 += (carry)%26;
    carry = carry/26;
    if(b1 >'Z')
    {
        b1 -= 26;
        carry++;
    }

    a += carry;

    char c1,c2,c3;
    c1 = (c/100)+'0';
    c%=100;
    c2 = (c/10)+'0';
    c%=10;
    c3 = (c)+'0';

    cout << a << b1 << b2 <<"-" << c1 << c2 << c3;
}
/*
4 X Y - 999

y z . . . .
115 + 1 =116
*/