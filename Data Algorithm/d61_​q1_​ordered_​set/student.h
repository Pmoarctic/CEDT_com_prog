#include <vector>
#include <algorithm>
#include <set>
using namespace std;

template <typename T>
vector<T> Union(const vector<T>& A, const vector<T>& B) {
    vector<T> v;
    set<T> S;
    for(auto i:A)
    {
        S.insert(i);
        v.push_back(i);
    }
    for(auto i:B)
    {
        if(S.find(i) == S.end())
        {
            v.push_back(i);
        }
    }

    return v;
}

template <typename T>
vector<T> Intersect(const vector<T>& A, const vector<T>& B) {
    vector<T> v;
    set<T> S;
    for(auto i:B)S.insert(i);
    for(auto i:A)
    {
        if(S.find(i) != S.end())
        {
            v.push_back(i);
        }
    }


    return v;
}
