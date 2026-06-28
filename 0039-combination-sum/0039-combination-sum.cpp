class Solution {
public:
    
    void backtrack( int i ,vector<int>& nums , int target , vector<int>& templist , vector<vector<int>>& list){
        if( i == nums.size()){
            if( target == 0) list.push_back( templist );
            return;
        }
        if( target == 0){
            list.push_back( templist );
            return;
        }

        //choose 
        if( nums[i] <= target ){
            templist.push_back( nums[i]);
            //explore all 
            // *** you can choose ith element again ***
            backtrack( i ,  nums , target - nums[i] , templist , list );
            //undo
            templist.pop_back();
        }
        //don't choose , just explore next
        backtrack( i+1 , nums ,target , templist ,list);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> list;
        vector<int> templist;

        backtrack(0 , candidates , target ,templist,list);

        return list;
    }
};