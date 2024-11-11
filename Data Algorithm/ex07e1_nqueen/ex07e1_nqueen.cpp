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

int n;
int res=0;
vector<vector<bool> > board(15,vector<bool>(15,false));

bool isSafe(int row,int col)
{
    for(int i=0;i<n;i++)
    {
        
        if(board[i][col]==true)
        {
            return false;
        }
        if(board[row][i]==true)
        {
            return false;
        }

        //diag
        if(row+i<n && col+i<n && board[row+i][col+i]==true)
        {
            return false;
        }
        if(row+i<n && col-i>=0 && board[row+i][col-i]==true)
        {
            return false;
        }
        if(row-i>=0 && col+i<n && board[row-i][col+i]==true)
        {
            return false;
        }
        if(row-i>=0 && col-i>=0 && board[row-i][col-i]==true)
        {
            return false;
        }
    }
    //cout << "place\n";
    
    return true;
}

void print()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout << board[i][j] << " ";
        }
        cout << '\n';
    }
    cout << "\n";
}

void recur(int cnt)
{
    
    if(cnt==n)
    {
        //print();
        res++;
        return;
    }
    else
    {
        for(int i=0;i<n;i++)
        {
            if(isSafe(cnt,i))
            {
                board[cnt][i]=true;
                recur(cnt+1);
                board[cnt][i]=false;
            }
        }
        return;
    }
}

int main()
{
    cin >> n;
    recur(0);
    cout <<res;

    return 0;
}