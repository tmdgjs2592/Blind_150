#include <iostream>
#include <vector>

using namespace std;

//Solved: Sep 27, 2023

vector<vector<string>> solveNQueens(int n){
    vector<vector<string>> res;
    vector<string> ret(n, string(n, '.'));
    vector<vector<char>> board(n, vector<char>(n, '.'));
    int count = 0;
    rec(board, ret, count, 0, n, res);
    return res;
}
bool check(vector<vector<char>>& board, int index, int jndex){
        for(int i=0; i<board.size(); i++){
            if(board[i][jndex] == 'Q' || board[index][i] == 'Q')
                return false;
        }
        int row = index - min(index, jndex);
        int col = jndex - min(index, jndex);
        while(row < board.size() && col < board.size()){
            if(board[row][col] == 'Q')
                return false;
            row++;
            col++;
        }
        int num = board.size();
        row = index - min(index, num - 1 - jndex);
        col = jndex + min(index, num - 1 - jndex);
        while (row < board.size() && col >= 0) {
            if(board[row][col] == 'Q')
                return false;
            row++;
            col--;
        }

        return true;
}

void rec(vector<vector<char>>& board, vector<string>& ret, int& count, int index, int n, vector<vector<string>>& res){
    if(count == n){
        res.push_back(ret);
        return;
    }

    for(int j = 0; j<n; j++){
        if(check(board, index, j)){
            count++;
            board[index][j] = 'Q';
            ret[index][j] = 'Q';
            rec(board, ret, count, index+1, n, res);
            ret[index][j] = '.';
            board[index][j] = ' ';
            count--;
        }
    }
}