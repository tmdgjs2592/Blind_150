#include <iostream>
#include <vector>

using namespace std;

//Solved: Sep 30, 2023

vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    vector<vector<bool>> visited(heights.size(), vector<bool> (heights[0].size(), false));
    vector<vector<int>> res;
    bool pac, atl;
    for(int i=0; i<heights.size(); i++){
        for(int j=0; j<heights[0].size(); j++){
            pac = false;
            atl = false;
            rec(heights, i, j, visited, pac, atl);
            if(pac && atl)
                res.push_back({i,j});
        }
    }
    return res;
}

void rec(vector<vector<int>>& heights, int index, int jndex, vector<vector<bool>>& visited, bool& pac, bool& atl){
    if(pac && atl)
        return;
    if(index <= 0 || jndex <= 0)
        pac = true;
    if(index >= heights.size()-1 || jndex >= heights[0].size() - 1)
        atl = true;

    visited[index][jndex] = true;
    if(index + 1 < heights.size() && !visited[index+1][jndex] && heights[index+1][jndex] <=heights[index][jndex])
        rec(heights, index+1, jndex, visited, pac, atl);
    if(index - 1 >= 0 && !visited[index-1][jndex] && heights[index-1][jndex] <=heights[index][jndex])
        rec(heights, index-1, jndex, visited, pac, atl);
    if(jndex + 1 < heights[0].size() && !visited[index][jndex+1] && heights[index][jndex+1] <=heights[index][jndex])
        rec(heights, index, jndex+1, visited, pac, atl);
    if(jndex - 1 >= 0 && !visited[index][jndex-1] && heights[index][jndex-1] <=heights[index][jndex])
        rec(heights, index, jndex-1, visited, pac, atl);

    visited[index][jndex] = false;
}