class Solution {
public:
    string shortestCommonSupersequence(string a, string b) {
        int n = a.length() , m = b.length();
        vector<vector<int>> dp( n+1 , vector<int> (m+1,0));
        for( int i=0 ; i<n ; i++){
            dp[i][m] = n-i;
        }
        for( int j=0 ; j<m ; j++){
            dp[n][j] = m-j;
        }

        for( int i=n-1 ; i>=0 ; i--){
            for( int j=m-1; j>=0 ; j--){
                if(a[i] == b[j]){
                    dp[i][j] = 1 + dp[i+1][j+1];
                }else{
                    dp[i][j] = 1 + min(dp[i+1][j] , dp[i][j+1]);
                }
            }
        }
        // dp table is formed
        int i =0 , j=0;
        string ans = "";
        while( i<n && j<m){
            if( a[i] == b[j]){
                ans += a[i];
                i++;j++;
            }else if(dp[i+1][j] < dp[i][j+1]){
                ans += a[i];
                i++;
            }
            else{
                ans += b[j];
                j++;
            }
        }
        while (i < n) {
            ans += a[i++];
        }
        while (j < m) {
            ans += b[j++];
        }
        return ans;
    }
};