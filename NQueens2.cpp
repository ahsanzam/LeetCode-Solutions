// 52. N-Queens II
// https://leetcode.com/problems/n-queens-ii/

class Solution {
private:
    string buildString(int n, char c){
        string result = "";
        for(int i=0; i<n; i++)
            result += c;
        return result;
    }
    bool canPlace(const vector<string> &board, int x, int y){
        for(int i=0; i<board.size(); i++) //check column
            if(board[i][y] == 'Q') 
                return false;
        for(int i=0; i<board[x].length(); i++) //check row
            if(board[x][i] == 'Q')
                return false;
        for(int i=x, j=y; i<board.size() && j<board[i].size(); i++, j++) //check diagonal right down
            if(board[i][j] == 'Q')
                return false;
        for(int i=x, j=y; i>-1 && j>-1; i--, j--) //check diagonal left up
            if(board[i][j] == 'Q')
                return false;
        for(int i=x, j=y; i>-1 && j<board[i].size(); i--, j++) //check diagonal right up
            if(board[i][j] == 'Q')
                return false;
        for(int i=x, j=y; i<board.size() && j>-1; i++, j--) //check diagonal left down
            if(board[i][j] == 'Q')
                return false;
        return true;
    }
    bool recurse(vector<vector<string>> &solutions, vector<string>  &board, const int &stop, int it){
        if(it == stop) 
            solutions.push_back(board); //makes a copy here, so we're ok if we modify it further up the call stack 
        for(int i=0; i<stop; i++){
            if(!canPlace(board, it, i)) continue;
            board[it][i] = 'Q';
            recurse(solutions, board, stop, it+1);
            board[it][i] = '.';
        }
        return false;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> solutions;
        vector<string> board(n, buildString(n,'.'));
        recurse(solutions, board, n, 0);
        return solutions;
    }
public:
    int totalNQueens(int n) {
        return solveNQueens(n).size();
    }
};