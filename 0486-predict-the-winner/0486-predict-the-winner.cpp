class Solution {
public:

    int dp[22][22];

    int solve( int i , int j , vector<int>& nums){
        // gives the max score of p1
        if( i>j) return 0;

        if( dp[i][j] != -1) return dp[i][j];

        // choice 1 : take i
        int score = nums[i] + min( solve(i+2,j,nums) , solve(i+1,j-1,nums) );
        //choice 2 : take j
        score = max( score , nums[j] + min( solve(i+1,j-1,nums) , solve(i,j-2,nums)));

        return dp[i][j] = score;
    }

    bool predictTheWinner(vector<int>& nums) {
        memset(dp,-1,sizeof( dp ));
        int n = nums.size();
        int p1 = solve( 0 , n-1 , nums);
        int total = accumulate( nums.begin() , nums.end() , 0);
        int p2 = total - p1;
        return p1 >= p2;
    }
};