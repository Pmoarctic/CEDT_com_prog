#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin >> n >> k;

    if(n%2==0)
    {
        int s,t;
        cin >> s >> t;
        int x = s;
        int y = t;

        if(s>t)
        {
            x = s-t;
        }
        else if(s<t)
        {
            y = 2*(t-s);
        }

        if(x+y>k)
        {
            swap(x,y);
            x = y + s*s;
        }

        cout << x << " " << y;
    }
    else
    {
        int sum_a=0,sum_b=0,sum_c=0,m=0;
        while(m<k)
        {
            int a,b,c;
            cin >> a >> b >> c;
            if(a==b)
            {
                if(b==c)
                {
                    if(a+b>k)
                    {
                        sum_a += 1;
                        sum_b += 2;
                        sum_c -= 3;
                    }
                    else
                    {
                        sum_a -= 3;
                        sum_b -= 2;
                        sum_c += 1;
                    }
                }
                else
                {
                    sum_a += 2;
                    sum_b -= 3;
                }
            }

            m++;
        }

        cout << sum_a << " " << sum_b << " " << sum_c;
    }

    return 0;
}
/*
152 91
11 73
*/