class Solution {
public:

    bool checkDiagonals( int row , int col , int n ,  vector<string>& board){
        int r = row , c = col;
        // checking left diagonal
        while( row >= 0 && col >= 0){
            if( board[row][col] == 'Q')return false;
            row -= 1;
            col -=1;
        }
        // checking right diagonal
        row = r , col = c;
        while( row >=0 && col < n ){
            if( board[row][col] == 'Q') return false;
            row -=1;
            col += 1;
        }
        return true;

    }
    
    void backtrack( int row , int n , vector<int>& used , vector<string>& tempBoard , vector<vector<string>>& list){
        if( row == n){
            list.push_back( tempBoard );
            return ;
        }

        for( int col = 0 ; col < n ; col++ ){
            if( !used[col] && checkDiagonals(row , col , n , tempBoard ) ){
                used[col] = 1;
                tempBoard[row][col] ='Q';
                backtrack( row+1 , n , used , tempBoard , list );
                tempBoard[row][col] ='.';
                used[col] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> list;
        vector<string> tempBoard( n , string( n , '.'));
        vector<int> used( n , 0);

        backtrack( 0 , n , used, tempBoard , list );
        return list;
    }
};