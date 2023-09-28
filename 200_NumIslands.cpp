#include <iostream>
#include <vector>
using namespace std;

//Solved: Sep 28, 2023

void rec(vector<vector<char>>& grid, int index, int jndex){
        if(index < 0 || index >= grid.size())
            return;
        if(jndex < 0 || jndex >= grid[0].size())
            return;
        if(grid[index][jndex] == '0')
            return;

        grid[index][jndex] = '0';
        rec(grid, index + 1, jndex);
        rec(grid, index - 1, jndex);
        rec(grid, index, jndex + 1);
        rec(grid, index, jndex - 1);
    }

int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    rec(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }