#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b;
    cin >> a >> b;
    int sa=0,sb=0;
    int caa=0,cab=0;
    for(int i=0;i<a;i++)
    {
        string c;
        cin >> c;
        if(c[0] >= '0' && c[0] <= '9')
        {
            sa += stoi(c);
        }
        else if(c[0] == 'A')
        {
            caa++;
        }
        else
        {
            sa+=10;
        }
    }
    if(caa==1)
    {
        int t1=0,t2=0;
        if(sa+1 <= 21)
        {
            t1=sa+1;
        }
        if(sa+11 <= 21)
        {
            t2=sa+11;
        }
        sa = max(t1,t2);
    }
    else if(caa==2)
    {
        int t1=0,t2=0;
        if(sa+2 <= 21)
        {
            t1=sa+2;
        }
        if(sa+12 <= 21)
        {
            t2=sa+12;
        }
        sa = max(t1,t2);
    }
    else if(caa==3)
    {
        sa = 13;
    }


    for(int i=0;i<b;i++)
    {
        string c;
        cin >> c;
        if(c[0] >= '0' && c[0] <= '9')
        {
            sb += stoi(c);
        }
        else if(c[0] == 'A')
        {
            cab++;
        }
        else
        {
            sb+=10;
        }
    }
    if(cab==1)
    {
        int t1=0,t2=0;
        if(sb+1 <= 21)
        {
            t1=sb+1;
        }
        if(sb+11 <= 21)
        {
            t2=sb+11;
        }
        sb = max(t1,t2);
    }
    else if(cab==2)
    {
        int t1=0,t2=0;
        if(sb+2 <= 21)
        {
            t1=sb+2;
        }
        if(sb+12 <= 21)
        {
            t2=sb+12;
        }
        sb = max(t1,t2);
    }
    else if(cab==3)
    {
        sb = 13;
    }



    if(sa == sb)
    {
        cout << "Draw\n";
        cout << sa << " " << sb;
    }
    else if(sa>21 && sb > 21)
    {
        cout << "Draw\n";
        cout << sa << " " << sb;
    }
    else if(sa>21 && sb <=21)
    {
        cout << "B\n";
        cout << sa << " " << sb;
    }
    else if(sb>21 && sa <=21)
    {
        cout << "A\n";
        cout << sa << " " << sb;
    }
    else if(sa>sb)
    {
        cout << "A\n";
        cout << sa << " " << sb;
    }
    else if(sb>sa)
    {
        cout << "B\n";
        cout << sa << " " << sb;
    }
}