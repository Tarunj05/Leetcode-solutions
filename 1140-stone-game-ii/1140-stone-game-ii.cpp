
class Solution {
public:
    int dp[110][220];

    int rec( int i ,int m,vector<int>& piles,vector<int>& suffix){
        // rec -> returns the max stones current player can collect
        // base case
        if( i == piles.size())return 0;

        //cache check
        if(dp[i][m] != -1) return dp[i][m];

        //compute
        int score = 0;
        for( int x=1 ; x <= 2*m ; x++){
            if(i+x > piles.size())break;
            // my score = remaining total - opponents best
            score = max( score , suffix[i]  - rec( i+x , max(m,x) , piles , suffix));
        }

        // save and return
        return dp[i][m] =  score;
    }

    int stoneGameII(vector<int>& piles) {
        memset(dp , -1 , sizeof(dp));
        int n = piles.size();
        vector<int> suffix(n);
        suffix[n-1] = piles[n-1];
        for( int i = n-2 ; i>=0 ; i--){
            suffix[i] = piles[i] + suffix[i+1];
        }
        return rec( 0 , 1 , piles , suffix );
    }
};