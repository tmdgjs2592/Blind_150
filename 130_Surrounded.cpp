#include <iostream>
#include <vector>

using namespace std;

void solve(vector<vector<char>>& board) {
    for(int i=0; i<board.size(); i++){
        rec(board, i, 0);
        rec(board, i, board[0].size() - 1);
    }
    for(int j=0; j<board[0].size(); j++){
        rec(board, 0, j);
        rec(board, board.size()-1, j);
    }
    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[0].size(); j++){
            if(board[i][j] == 'O')
                board[i][j] = 'X';
            if(board[i][j] == 'B')
                board[i][j] = 'O';
        }
    }
}
void rec(vector<vector<char>>& board, int index, int jndex){
    if(index < 0 || index >= board.size() || jndex < 0 || jndex >= board[0].size() || board[index][jndex] != 'O')
        return;

    board[index][jndex] = 'B';
    rec(board, index+1, jndex);
    rec(board, index-1, jndex);
    rec(board, index, jndex+1);
    rec(board, index, jndex-1);
}