#ifndef __SPARSE_GRAPH_H__
#define __SPARSE_GRAPH_H__

// Your code here
#include<vector>
#include<set>
#include<algorithm>
#include<iostream>

using namespace std;

class SparseGraph{
public:
    SparseGraph() : adj(vector<vector<int> >(3)) {
        // Your code here
    }

    SparseGraph(int n_in) : adj(vector<vector<int> >(n_in)) {
        // Your code here
    }

    SparseGraph(const SparseGraph& G) {
        // Your code here
        adj.clear();
        adj = vector<vector<int>>(G.adj.size());
        for (int i=0;i<adj.size();i++){
            adj[i] = G.adj[i];
        }
    }

    void AddEdge(int a, int b) {
        // Your code here
        if(find(adj[a].begin(),adj[a].end(),b)!=adj[a].end())
        {
            return;
        }
        adj[a].push_back(b);
    }

    void RemoveEdge(int a, int b) {
        // Your code here
        auto itr = find(adj[a].begin(),adj[a].end(),b);
        if(itr==adj[a].end())
        {
            return;
        }
        adj[a].erase(itr);
    }

    bool DoesEdgeExist(int a, int b) const {
        if(find(adj[a].begin(),adj[a].end(),b)==adj[a].end())
        {
            return false;
        }
        return true;
    }

    SparseGraph Transpose() const {
        SparseGraph tmp(adj.size());
        for(int a=0;a<adj.size();a++)
        {
            for(auto b:adj[a])
            {
                tmp.AddEdge(b,a);
            }
        }
        return tmp;
    }

protected:
    // Your code here
    vector<vector<int> > adj;
};
#endif // __SPARSE_GRAPH_H__

