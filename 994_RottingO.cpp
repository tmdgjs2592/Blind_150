#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//Solved: Oct 3, 2023

int orangesRotting(vector<vector<int>>& grid) {
        int fresh = 0;
        int result = -1;
        vector<vector<int>> dirs = {{-1,0}, {1,0}, {0,1}, {0,-1}};
        queue<pair<int,int>> q;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 2)
                    q.push({i,j});
                else if(grid[i][j] == 1)
                    fresh++;
            }
        }
        q.push({-1,-1});

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            if(row == -1){
                result++;
                if(!q.empty())
                    q.push({-1,-1});
            }

            for(int i=0; i<dirs.size(); i++){
                int x = row + dirs[i][0];
                int y = col + dirs[i][1];
                if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size())
                    continue;
                if(grid[x][y] == 1){
                    fresh--;
                    grid[x][y] = 2;
                    q.push({x,y});
                } 

            }

        }
        if(fresh == 0)
            return result;
        return -1;
    }


