#include<iostream>
using namespace std;
#define N 505
int r,c,i,j,a=0,m=100000007;
int t[N][N],A[N][N],B[N][N],C[N][N];
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>r>>c;
    for(i=1;i<=r;++i){
        for(j=1;j<=c;++j){
            cin>>t[i][j];
            if(j&&!t[i][j])A[i][j]=B[i][j]=C[i][j]=1;
        }
    }
    for(i=2;i<=c;++i){
        for(j=1;j<=r;++j){
            if(t[j][i])continue;
            A[j][i]=(B[j][i-1]+C[j+1][i-1])%m;
            B[j][i]=(A[j-1][i-1]+C[j+1][i-1])%m;
            C[j][i]=(A[j-1][i-1]+B[j][i-1])%m;
            if(i==c)a=(a+A[j-1][i-1]+B[j][i-1]+C[j+1][i-1])%m;
        }
    }
    cout<<a;
}
