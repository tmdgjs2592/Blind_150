#include <iostream>
#include <vector>

using namespace std;

bool rec(vector<vector<char> >& board, string word, int index, int jndex, int count){
    if(index < 0 || index > board.size()-1)
        return false;
    if(jndex <0 || jndex > board[0].size() -1)
        return false;

    if(count == word.size()-1)
        return true;

    char temp = board[index][jndex];
    board[index][jndex] = '.';

    if(rec(board, word, index-1, jndex, count+1) ||
    rec(board, word, index+1, jndex, count+1) ||
    rec(board, word, index, jndex-1, count+1) ||
    rec(board, word, index, jndex+1, count+1))
        return true;

    return false;
}


bool search(vector<vector<char> >& board, string word){
    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[0].size(); j++){
            if(rec(board, word, i,j, 0))
                return true;
        }
    }

    return false;
}