class Solution {
public:

    int dp[22][22];

    int maxDiff( int i , int j , vector<int>& nums){
        if( i==j) return nums[i];
        if(dp[i][j] != -1) return dp[i][j];
        int ans = nums[i] - maxDiff(i+1, j , nums);
        ans = max( ans , nums[j] - maxDiff(i,j-1,nums));

        return dp[i][j]=ans;
    }

    bool predictTheWinner(vector<int>& nums) {
        memset( dp , -1 , sizeof(dp));
        return maxDiff( 0 , nums.size()-1 , nums) >= 0;
    }
};