#include<vector>
#include<iostream>

using namespace std;

int main()
{
    vector<int> v = {1,2,3,4,5,6};
    
    vector<int>::iterator a = v.begin();
    vector<int>::iterator b = v.end();

    //cout << *a << "\n";

    v.insert(b,0);
    //v.insert(a,0);


    cout << *b << '\n';
    for(auto i:v)
    {
        cout << i << " ";
    }
}