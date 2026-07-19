class Solution {
public:

    bool isPred( string prevWord , string currWord ){
        int M = prevWord.size() , N = currWord.size();
        if( N - M != 1)return 0;

        int i = 0 , j = 0;
        while( i<M && j<N){
            if( prevWord[i] == currWord[j])i++;
            j++;
        }
        return i == M;
    }

    int longestStrChain(vector<string>& words) {

        sort( words.begin() , words.end() , [](auto& a , auto& b){
            return a.length() < b.length();
        });
        int n = words.size();

        vector<int> dp( n , 1);
        int maxi = 1;

        for(int i = 0 ; i<n ; i++){
            for( int prev = 0 ; prev <  i ; prev++){
                if( isPred( words[prev] , words[i])){
                    dp[i]= max( dp[i] , dp[prev] + 1 );
                    maxi = max( dp[i] , maxi);
                }
            }
        }
        return maxi;
    }
};