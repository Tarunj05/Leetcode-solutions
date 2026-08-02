class Solution {
public:

    int dp[510][510];

    bool rec( int i , int j ,vector<int>& piles){
        // rec-> if the player playing could win the game
        // base case
        if( i > j) return 0;
        if( dp[i][j] != -1) return dp[i][j];
        if( rec(i+1,j,piles) == 0 || rec(i,j-1,piles)==0) return dp[i][j] = true;
        return dp[i][j] = true;
    }

    bool stoneGame(vector<int>& piles) {
        memset( dp ,-1 , sizeof( dp));
        int i = 0, j = piles.size()-1;
        return rec( i , j ,piles);
    }
};