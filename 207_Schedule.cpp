#include <iostream>
#include <vector>

using namespace std;

bool canFinish(int num, vector<vector<int>>& pre){
    unordered_map<int, vector<int>> m;
    for(int i=0; i<pre.size(); i++){
        m[pre[i][0]].push_back(pre[i][0]);
    }
    unordered_set<int> visited;
    
    for(int i=0; i<num; i++){
        if(!rec(i, m, visited))
            return false;
    }

    return true;
}

bool rec(int num, unordered_map<int, vector<int>>& m, unordered_set<int>& visited){
    if(visited.find(num) != visited.end())
        return false;
    if(m[num].empty())
        return true;

    for(int i=0; i<m[num].size(); i++){
        if(!rec(m[num][i], m, visited)){
            return false;
        }
    }
    visited.erase(num);
    m[num].clear();

    return true;
}