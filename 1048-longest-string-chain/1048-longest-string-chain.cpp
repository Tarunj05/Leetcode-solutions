class Solution {
public:


    static bool cmp( string s1 , string s2){
        return s1.length() < s2.length();
    }

    bool isPred( string& a , string& b){
        int M = a.length() ,N = b.length(); 
        if(N - M != 1) return 0;        
        int i = 0 , j = 0 ; 
        while( i<M && j<N){
            if(a[i] == b[j]) i++;
            j++;
        }
        return i == M;
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort( words.begin() , words.end() , cmp );

        // changing parameters : i , prev , dp state : dp[n+1][n+1];

        vector<vector<int>> dp( n+1 , vector<int> ( n + 1 ,0 ));

        // base case , when i == n, dp[i][prev+1] = 0;
        // dp table is already initialized with 0 , so no need to specify it

        // changing parameters loop

        for( int i = n-1 ; i>=0 ; i--){
            for( int prev = -1  ; prev < i ; prev++){
                // not take
                int len = dp[i+1][prev+1];

                if( prev == -1 || isPred( words[prev] , words[i])){
                    len = max( len , 1 + dp[i+1][i+1]);
                }
                dp[i][prev+1] = len;
            }
        }

        // 



        return dp[0][0];
    }
};