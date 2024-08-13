#include <iostream>
using namespace std;
const int R = 7, C = 7;
int x[R][C];
void floodfill(int r, int c, int e)
{
    if(x[r][c] != 0 || r>=7 || r<0 || c>=7 || c<0)
    {
        return;
    }
    else
    {
        x[r][c] = e;
        floodfill(r+1,c,e);
        floodfill(r-1,c,e);
        floodfill(r,c+1,e);
        floodfill(r,c-1,e);
    }
}
int main() {
 
 for (int r=0; r<R; ++r)
 for (int c=0; c<C; ++c)
 cin >> x[r][c];
 int row, col, e;
 cin >> row >> col >> e;
 floodfill(row, col, e);
 for (int r=0; r<R; ++r) {
 for (int c=0; c<C; ++c)
 cout << x[r][c] << ' ';
 cout << endl;
 }
}