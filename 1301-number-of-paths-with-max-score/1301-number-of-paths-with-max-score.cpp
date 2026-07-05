class Solution {
public:

    const int mod = (int) (1e9+7);

    vector<int> f( int i , int j ,  vector<string>& board ,vector<vector<vector<int>>>& dp ){

        if( i == 0 && j == 0) return {0,1};

        if( i<0 || j<0) return{0,0};

        if( board[i][j] == 'X') return{ 0,0};

        if( dp[i][j][0] != -1) return dp[i][j];


        // we already know , 
        int upScore = 0 , upPaths = 0;
        vector<int> temp  = f(i-1 , j , board ,dp);
        upScore = temp[0] , upPaths = temp[1];
        int leftScore = 0 , leftPaths = 0;
        temp = f(i , j-1 , board , dp);
        leftScore = temp[0] , leftPaths = temp[1];
        int upLeftScore = 0 , upLeftPaths = 0;
        temp = f(i-1 , j-1 , board , dp);
        upLeftScore = temp[0], upLeftPaths = temp[1];


        // now include the ans in the
        int val = board[i][j] - '0';
        if( board[i][j] == 'S') val = board[i][j] - 'S'; 

        if( upPaths > 0 ){
            // means we can reach to end going up
            upScore += (val);
        }
        if( leftPaths > 0) leftScore += ( val);
        if( upLeftPaths > 0) upLeftScore += ( val);

        // now find the best score and paths for current cell

        int bestScore = 0 , paths = 0;
        
        // if all the paths give the best score, include all
        if( leftScore == upScore && leftScore == upLeftScore ){
            bestScore = upScore ;
            paths = upPaths + leftPaths + upLeftPaths;
        }
        //now if two of them are equal

        else if( upScore == leftScore ){
            if( upScore > upLeftScore ){
                bestScore = upScore;
                paths = upPaths + leftPaths;
            }
            else {
                bestScore = upLeftScore;
                paths = upLeftPaths;
            }
        }

        else if( upScore == upLeftScore ){
            if( upScore > leftScore ){
                bestScore = upScore;
                paths = upPaths + upLeftPaths;
            }else{
                bestScore = leftScore;
                paths = leftPaths;
            }
        }
        else if( leftScore == upLeftScore){
            if( upScore > leftScore){
                bestScore = upScore;
                paths = upPaths;
            }
            else {
                bestScore = leftScore;
                paths = leftPaths + upLeftPaths;
            }
        }
        // all three are different
        else{
            if( upScore > leftScore && upScore > upLeftScore){
                bestScore = upScore;
                paths = upPaths;
            }
            else if( leftScore > upScore && leftScore > upLeftScore){
                bestScore = leftScore;
                paths = leftPaths;
            }
            else{
                bestScore = upLeftScore;
                paths = upLeftPaths;
            }
        }

        return dp[i][j] = { bestScore , paths % mod };
    }

    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        vector<vector<vector<int>>> dp ( n , vector<vector<int>>( n , vector<int> ( 2 , -1 )));
        return f( n-1, n-1, board,dp);
    }
};