#include <bits/stdc++.h>
using namespace std;
int F(int n) { // Fibonacci number
    vector<int> fibo(10000,0);
    fibo[0]=0;
    fibo[1]=1;
    for(int i=2;i<=n;i++)
    {
        fibo[i] = fibo[i-1] + fibo[i-2];
    }
    return fibo[n];
}
int M(int n) { // Motzkin number
    if(n==0 || n==1)
    {
        return 1;
    }
    else
    {
        int summation = 0;
        for(int k=0;k<=n-2;k++)
        {
            summation += M(k)*M(n-2-k);
        }
        return M(n-1) + summation;
    }
}
int S(int n) { // Schröder–Hipparchus Number
    if(n==1 || n==2)
    {
        return 1;
    }
    else
    {
        return ((6*n - 9)*S(n - 1) - (n - 3)*S(n - 2))/n;
    }
}
int D(int n) { // Derangement
    if(n==0)
    {
        return 1;
    }
    else
    {
        return n*D(n-1)+pow(-1,n);
    }
}
int main() {
 map<string, int(*)(int)> func = {{"F",F}, {"M",M}, {"S",S}, {"D",D}};
 string fn;
 int p;
 while (cin >> fn >> p) {
 if (func.find(fn) != func.end())
 cout << fn << '(' << p << ") = " << func[fn](p) << endl;
 }
 return 0;
}
