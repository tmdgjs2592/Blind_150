#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;


//Solved: Oct 6, 2023

void rec(int course, unordered_map<int, vector<int>> m, vector<int>& res, unordered_set<int>& visited, bool& possible){
    if(!possible)
        return;
    if(visited.find(course) != visited.end()){
        possible = false;
        return;
    }
    visited.insert(course);
    for(int i=0; i<m[course].size(); i++){
        rec(m[course][i], m, res, visited, possible);
    }
    visited.erase(course);
    m[course].clear();
    if(find(res.begin(), res.end(), course) == res.end())
        res.push_back(course);
    
}

vector<int> findOrder(int numCourses, vector<vector<int>>& pre){
    unordered_map<int, vector<int>> m;
    bool possible = true;
    vector<int> res;
    for(int i=0; i<pre.size(); i++){
        m[pre[i][0]].push_back(pre[i][1]);
    }
    unordered_set<int> visited;

    for(int i=0; i<numCourses; i++){
        possible = true;
        rec(i, m, res, visited, possible);
    }

    return res;
}