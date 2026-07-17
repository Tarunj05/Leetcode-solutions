class Solution {
public:

    int lis( int i , int prev , vector<vector<int>>& pairs , vector<vector<int>>& dp ){
        if( i == pairs.size()){
            return 0;
        }
        if( dp[i][prev+1] != -1 ) return dp[i][prev+1];
        // not take
        int len = 0 + lis(i+1 , prev , pairs , dp);
        // take
        if( prev == -1 || pairs[i][0] > pairs[prev][1]){
            len = max( len , 1 + lis(i+1 , i , pairs , dp));
        }
        return dp[i][prev+1] = len;
    }
    
    int findLongestChain(vector<vector<int>>& pairs) {
        sort( pairs.begin() , pairs.end() );

        int n = pairs.size();

        vector<vector<int>> dp( n , vector<int> ( n+1 , -1) );

        return lis( 0  , -1 , pairs ,dp );
    }
};