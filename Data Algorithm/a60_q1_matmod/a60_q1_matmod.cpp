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
typedef vector<vector<int> > vvi;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef priority_queue<pii, vector<pii> , greater<pii> > gpiiq;

int n,k;

vector<vector<int> > multiplymat(vector<vector<int> > a,vector<vector<int> > b)
{
    vector<vector<int> > product = {{0,0},{0,0}};
    product[0][0] = (a[0][0]*b[0][0] + a[0][1]*b[1][0])%k;
    product[0][1] = (a[0][0]*b[0][1] + a[0][1]*b[1][1])%k;
    product[1][0] = (a[1][0]*b[0][0] + a[1][1]*b[1][0])%k;
    product[1][1] = (a[1][0]*b[0][1] + a[1][1]*b[1][1])%k;
    return product;
}

void printmat(vector<vector<int> > a)
{
    cout << a[0][0]%k << " " << a[0][1]%k << " ";
    cout << a[1][0]%k << " " << a[1][1]%k;
    return;
}

vector<vector<int> > powermatrix(vector<vector<int> > &a,int n)
{
    if(n==0)
    {
        return {{1,0},{0,1}};
    }
    else if(n==1)
    {
        return a;
    }
    else
    {
        vector<vector<int> > res = powermatrix(a,n/2);
        res = multiplymat(res,res);
        if(n%2==1)
        {
            res = multiplymat(res,a);
        }
        return res;
    }

}

int main()
{
    
    cin >> n >> k;

    vector<vector<int> > mat = {{0,0},{0,0}},og;
    cin >> mat[0][0] >> mat[0][1] >> mat[1][0] >> mat[1][1];
    og = mat;

    mat = powermatrix(mat,n);

    printmat(mat);

    return 0;
}

//power matrix algorithm