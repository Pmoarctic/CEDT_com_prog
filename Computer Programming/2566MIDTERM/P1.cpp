#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define in(x) != x.end()
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ull> vull;


int main()
{  
    int a,b,c;
    cin >> a >> b >> c;

    if(a<100)
    {
        while(b<c)
        {
            a += b*b + c*c;
            if(a%10==5)
            {
                break;
            }
            else if(a%2==0)
            {
                b++;
            }
            else
            {
                c--;
            }
            if(double(a)/(double(b*c)) > 20)
            {
                break;
            }
        }
    }
    else
    {
        if(a<b)
        {
            if(b<c)
            {
                a+=3;
                b=a+c;
                c=b+a;
            }
            else if(a<c)
            {
                a*=2;
                b+=a;
                c+=b;
            }
            else
            {
                a+=c;
                b+=a;
                c+=b;
            }
        }
        else
        {
            if(c>a)
            {
                a=3*b;
                b=c+a;
                c=a+b;
            }
            else if(b>c)
            {
                a=b+c;
                b=7*a;
                c=b-a;
            }
            else
            {
                a=c-5;
                b=a-b;
                c=3*b;
            }
        }
    }

    cout << a << " " << b << " " << c;
}