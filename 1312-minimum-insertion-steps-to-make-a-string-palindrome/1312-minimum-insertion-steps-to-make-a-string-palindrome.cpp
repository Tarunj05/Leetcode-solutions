class Solution {
public:
int dp[1010][1010];
    
    int rec( int i , int j , string& s){
        if( i >=j ) return 0;
        if( dp[i][j] != -1) return dp[i][j];
        if( s[i] == s[j]) return dp[i][j] = rec( i+1 , j-1 , s);
        else return dp[i][j] = 1 + min( rec(i+1,j,s) , rec(i,j-1,s));
    }

    int minInsertions(string s) {
        memset(dp , -1 , sizeof(dp));
        int n = s.length();
        return rec( 0 , n-1 , s);
    }
};