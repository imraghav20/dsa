#include <bits/stdc++.h>
using namespace std;

typdef long long ll



void recur(vector<vector<char>> board, string word,int i, int j, int l, bool &flag){
    if(l==word.size()){
        flag=true;
        return;
    }
    if(i<0 or j<0 or i>=board.size() or j>=board[0].size())
        return;
    if(board[i][j] == word[l]){
        char c = board[i][j];
        board[i][j] = '-1';
        recur(board, word, i, j+1, l+1, flag);
        recur(board, word, i+1, j, l+1, flag);
        recur(board, word, i, j-1, l+1, flag);
        recur(board, word, i-1, j, l+1, flag);
        board[i][j] = c;
    }
}

bool wordSearch(vector<vector<char>> &board, string word){
    bool flag = false;
    for(int i=0; i<board.size(); i++ ){
        for(int j=0; j<board[0].size(); j++){
            if(board[i][j] == word[0]){
                recur(board,word,i,j,0,flag);
            }
            if(flag ) return flag;
        }
    }
    return flag;
}

int main(){
    
    return 0;
}
