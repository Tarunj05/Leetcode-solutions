class Solution {
public:

    void backtrack( int start , int k , int target ,vector<int>& templist , vector<vector<int>>& list ){
        if( templist.size() == k ){
            if( target == 0 ) list.push_back( templist);
            return;
        }
        for( int i = start ; i < 10 ; i++ ){
            if( i <= target ){
                templist.push_back ( i );
                backtrack( i + 1, k , target - i , templist , list);
                templist.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum3(int k, int target) {
        vector<vector<int>> list;
        vector<int> templist;

        backtrack( 1 , k , target , templist ,list );
        return list;
    }
};