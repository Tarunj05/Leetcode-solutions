class Solution {
public:
    int dp[1010][1010];

    int rec( int i , int j , string& a , string& b){
        //base case
        if( i >= a.length() || j >= b.length()){
            return 0;
        }
        // cache check
        if(dp[i][j] != -1) return dp[i][j];
        
        // compute
        int ans = 0;
        if( a[i] == b[j]){
            ans = max( 1 + rec( i+1 , j+1 , a , b) , ans);
        }
        ans = max(rec( i , j+1 , a , b) , ans);
        ans = max( rec( i+1 , j , a , b) , ans);

        return dp[i][j] = ans;
    }

    int longestCommonSubsequence(string text1, string text2) {
        memset(dp,-1,sizeof(dp));
        return rec( 0 , 0 , text1 ,text2);
    }
};