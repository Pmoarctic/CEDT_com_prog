#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <string>

using namespace std;

void change_1(std::stack<std::vector<std::queue<int>>> &a, int from, int to)
{
    // your code here
    stack<vector<queue<int> > > tmp1 = a;
    stack<vector<queue<int> > > res1;
    while(!tmp1.empty())
    {
        vector<queue<int> > tmp2 = tmp1.top();
        vector<queue<int> > res2;
        for(auto tmp3: tmp2)
        {
            queue<int> res3;
            while(!tmp3.empty())
            {
                res3.push((tmp3.front()==from)?to:tmp3.front());

                tmp3.pop();
            }
            res2.push_back(res3);
        }
        res1.push(res2);

        tmp1.pop();
        a.pop();
    }

    
    while(!res1.empty())
    {
        a.push(res1.top());
        res1.pop();
    }
    return;
}

void change_2(std::map<string, std::pair<std::priority_queue<int>, int>> &a, int from, int to)
{
    // your code here
    map<string, pair<priority_queue<int>,int> > tmp1 = a;
    map<string, pair<priority_queue<int>,int> > res1;
    for(auto [key,val]:tmp1)
    {
        pair<priority_queue<int>,int> tmp2 = val;
        pair<priority_queue<int>,int> res2;
        priority_queue<int> tmp3 = tmp2.first;
        priority_queue<int> res3;
        while(!tmp3.empty())
        {
            res3.push((tmp3.top()==from)?to:tmp3.top());

            tmp3.pop();
        }
        res2 = {res3,(tmp2.second==from)?to:tmp2.second};

        res1[key] = res2;
    }

    a = res1;



    return;
}

void change_3(std::set<std::pair<std::list<int>, std::map<int, std::pair<int, string>>>> &a, int from, int to)
{
    set<pair<list<int>, map<int, pair<int, string> > > > tmp1 = a;
    set<pair<list<int>, map<int, pair<int, string> > > > res1;
    for(auto i:tmp1)
    {
        //list<int>
        list<int> part1 = i.first;
        for(auto &j:part1)
        {
            if(j==from)
            {
                j = to;
            }
        }
        //

        //map<int,pair<int,string> >
        map<int,pair<int,string> > part2;
        for(auto m:i.second)
        {
            int key = m.first;
            if(key==from)key=to;

            pair<int,string> val;
            if(m.second.first==from)
            {
                val = {to,m.second.second};
            }
            else
            {
                val = m.second;
            }

            part2[key] = val;  
        }
        //
        pair<list<int>, map<int, pair<int, string> > > item1 = {part1,part2};
        res1.insert(item1);
    }
}

#endif
