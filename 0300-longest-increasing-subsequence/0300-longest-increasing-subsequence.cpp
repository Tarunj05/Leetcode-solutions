class Solution {
public:


    int solve( int i , int prev , vector<int>&nums , vector<vector<int>>& dp){
        // this is a function the gives the maximun length of increasing subsequence 
        // starting from index i and previously chosen element's index as prev


        // so according to the question we need solve( 0 , -1 ) ,  here -1 tell that no element has been chosen previously

        // base case
        if( i == nums.size()){
            // we are out of bounds, so no subSeq. can be made now
            return 0;
        }

        if( dp[i][prev+1] != -1 ) return dp[i][prev+1] ;

        //choice 1 : Take the current element

        int take = 0;

        if( prev == -1 || nums[i] > nums[prev] ){
            take = 1 + solve ( i+1 , i , nums , dp );
        }

        // choice 2 : skip the current element

        int skip = solve( i+1 , prev , nums , dp );

        return dp[i][prev+1] = max( take , skip );
    }
    int lengthOfLIS(vector<int>& nums) {
        int n =  nums.size();

        vector<vector<int>> dp( n , vector<int>( n + 1 , -1 ));
        return solve( 0 , -1 , nums , dp );
    }
};