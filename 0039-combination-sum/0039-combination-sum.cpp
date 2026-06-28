class Solution {
public:
    
    void backtrack( int start ,vector<int>& nums , int target , vector<int>& templist , vector<vector<int>>& list){
        if( target == 0){
            list.push_back( templist );
            return;
        }

        for( int i = start ; i<nums.size() ; i++){
            if( nums[i] <= target){
                templist.push_back( nums[i] );
                backtrack( i , nums , target - nums[i] , templist , list);
                templist.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> list;
        vector<int> templist;

        backtrack(0 , candidates , target ,templist,list);

        return list;
    }
};