class Solution {
public:
    // (int square) -> (int i,int j)
    std::pair<int,int> convertSqtoIJ(int sq){
        int i = sq / 9;
        int j = sq - ( i * 9 );
        return std::pair<int, int>(i,j);
    }
    bool needsToBeFilled(vector<vector<char>>& board, int sq){
        std::pair<int,int> ij = convertSqtoIJ(sq);
        int i = ij.first, j = ij.second;
        if(board[i][j] == '.') 
            return true;
        return false;
    }
    std::pair<int, int> clampNearest(int sq){
        std::pair<int,int> ij = convertSqtoIJ(sq);
        int i = ij.first, j = ij.second;
        int reti, retj;
        if(i < 3) reti = 0;
        else if(i < 6) reti = 3;
        else reti = 6;
        if(j < 3) retj = 0;
        else if(j < 6) retj = 3;
        else retj = 6;
        return std::pair<int, int>(reti, retj);
    }
    bool validNum(vector<vector<char>>& board, int square, int num){
        std::pair<int,int> ij = convertSqtoIJ(square);
        int i_ = ij.first, j_ = ij.second;
        char num_char = std::to_string(num).c_str()[0];
        //check column
        for(int i=0; i<9; i++){
            if(board[i_][i] == num_char) return false;
        }
        //check row
        for(int i=0; i<9; i++){
            if(board[i][j_] == num_char) return false;
        }
        //check 3x3 square
        std::pair<int,int> ij_clamped = clampNearest(square);
        int starti = ij_clamped.first, startj = ij_clamped.second;
        for(int m=starti; m<starti+3; m++){
            for(int n=startj; n<startj+3; n++){
                if(board[m][n] == num_char) return false;
            }
        }
        return true;
    }
    bool backtrack(vector<vector<char>>& board, int square){
        if(square == (9*9)) //end condition
            return true;
        if(needsToBeFilled(board, square)){ //check if this spot already has a number 
            std::pair<int,int> ij = convertSqtoIJ(square);
            int i_ = ij.first, j_ = ij.second;
            for(int i=1; i<10; i++){ //try numbers 1-9 here 
                if(validNum(board, square, i)){ //if i can go in this spot, try putting it here 
                    board[i_][j_] = std::to_string(i).c_str()[0];
                    if(backtrack(board, square+1))//this number DOES work 
                        return true;
                    else{ //this number DOES NOT work 
                        board[i_][j_] = '.'; //reset this spot
                        if(i == 9) //if we can't try any more numbers in this spot 
                            return false;
                    }
                }
                else if(i == 9) //we can't try any more numbers in this spot 
                    return false;
            }
        }
        // else //this square already has a number, move on to next square 
            return backtrack(board, square+1);
    }
    void check(vector<vector<char>>& board){
        cout << "checking convertSqtoIJ..." << endl;
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                std::pair<int,int> p = convertSqtoIJ((i*9)+j);
                int i_ = p.first;
                int j_ = p.second;
                if(i_ != i || j_ != j)
                    cout << "Error at i: " << i << " j: " << j << " sq: " << (i*9)+j << " i_: " << i_ << " j_: " << j_ << endl ;
            }
        }
        cout << "test complete!" << endl;
        cout << "checking needstobefilled()..." << endl;
        if(!(needsToBeFilled(board, 0) == false && needsToBeFilled(board, 2) == true)){
            cout << "Test failed" << endl;
        }
        cout << "test complete!" << endl;
    }
    void solveSudoku(vector<vector<char>>& board) {
        // check(board);
        backtrack(board,0);
    }
};