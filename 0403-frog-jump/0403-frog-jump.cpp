class Solution {
public:
    int getStoneIndex(int pos ,unordered_map<int,int>& mp){
        if( mp.count(pos))return mp[pos];
        else return -1;
    }

    // can i reach to the last stone if i am standing at ith stone ans last jump was k
    bool f ( int i , int k , vector<int>& stones ,unordered_map<int,int>& mp , vector<vector<int>>& dp){
        if( i == stones.size()-1 ){
            return true;
        }
        if(dp[i][k] != -1) return dp[i][k];
        for( int jump : {k-1 , k , k+1}){
            if( jump > 0){
                // i can only jump i a stone exists at that position
                int nextPosition = stones[i] + jump ;
                int nextIndex = getStoneIndex( nextPosition , mp ) ;
                if(nextIndex != -1 && f( nextIndex , jump , stones , mp , dp))return dp[i][k] =  1 ;
            }
        }
        return dp[i][k] = 0 ;
    }

    bool canCross(vector<int>& stones) {

        if( stones[1] !=1 ) return false;
        unordered_map<int,int> mp;// position -> index
        int n = stones.size();
        for( int i = 0 ; i<n ; i++){
            int positionOfStone = stones[i];

            mp[positionOfStone] = i;
        }

        vector<vector<int>> dp( n , vector<int> ( n+1 , -1) );

        return f ( 1 , 1 , stones , mp , dp);
    }
};