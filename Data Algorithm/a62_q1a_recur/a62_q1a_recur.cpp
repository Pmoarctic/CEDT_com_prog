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
typedef priority_queue<pii, vector<pii> , greater<pii> > gpiiq;

#include <iostream>
#include <vector>

typedef vector<vector<int>> Matrix;

Matrix H(int a,int b)
{
    if(a==0)
    {
        return {{b}};
    }

    Matrix topleft = H(a-1,b);
    Matrix topright = H(a-1,b-1);
    Matrix botleft = H(a-1,b+1);
    Matrix botright = H(a-1,b);

    int n = topleft.size();
    Matrix res(2*n,vi(2*n));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            res[i][j] = topleft[i][j];
            res[i][j+n] = topright[i][j];
            res[i+n][j] = botleft[i][j];
            res[i+n][j+n] = botright[i][j];
        }
    }
    return res;
}


int main() {
    int a,b;
    cin >> a >> b;
    
    Matrix res = H(a,b);

    for(auto i:res)
    {
        for(auto j:i)
        {
            cout << j << " ";
        }
        cout << '\n';
    }

    return 0;
}
// divide && conquer
// like merge sort but simple recur and advance merge matrix (construct new matrix from sub matrix)