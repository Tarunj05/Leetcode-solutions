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

    int lis( int i , int prev , vector<string>& words , vector<vector<int>>& dp ){
        if( i == words.size()) return 0;

        if( dp[i][prev + 1] != -1) return dp[i][prev+1];
        // not take
        int len = lis(i+1, prev , words , dp);
        // take
        if( prev == -1 || isPred( words[prev] , words[i] )){
            len = max( len , 1 + lis(i+1 , i , words , dp ));
        }
        return dp[i][prev + 1] = len;
    }



    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort( words.begin() , words.end() , cmp );

        // changing parameters : i , prev , dp state : dp[n+1][n+1];

        vector<vector<int>> dp( n+1 , vector<int> ( n + 1 , -1 ));

        return lis( 0 , -1 , words ,dp);
    }
};