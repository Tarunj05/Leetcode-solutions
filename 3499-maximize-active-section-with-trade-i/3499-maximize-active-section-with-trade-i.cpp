class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        vector<int> inactiveBlocks;

        int n = s.length();
        for( int i = 0 ; i<n ; i++){
            if( s[i] == '1')continue;
            else{
                int startIdx = i;
                while( i<n && s[i] == '0'){
                    i++;
                }
                inactiveBlocks.push_back(i - startIdx);
            }
        }
        int maxExtraOnes = 0;
        int m =inactiveBlocks.size();
        for( int i = 0 ; i<m-1 ; ++i){
            maxExtraOnes = max( maxExtraOnes , inactiveBlocks[i] + inactiveBlocks[i+1]);
        }
        int noOfOnes = 0;
        for(int i = 0 ; i<n ; ++i){
            if(s[i] == '1')noOfOnes++;
        }
        return noOfOnes + maxExtraOnes;
    }
};