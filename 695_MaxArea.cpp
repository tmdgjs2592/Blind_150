#include <iostream>
#include <vector>

using namespace std;

//Solved: Sep 29, 2023
void rec(vector<vector<int>>& grid, int index, int jndex, int& count){
        if(index < 0 || index >= grid.size())
            return;
        if(jndex < 0 || jndex >= grid[0].size())
            return;
        if(grid[index][jndex] == 0)
            return;

        grid[index][jndex] = 0;
        count++;
        rec(grid, index+1, jndex, count);
        rec(grid, index-1, jndex, count);
        rec(grid, index, jndex+1, count);
        rec(grid, index, jndex-1, count);
    }

int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 1){
                    int count = 0;
                    rec(grid, i, j, count);
                    res = std::max(res, count);
                    
                }
            }
        }
        return res;
    }

    