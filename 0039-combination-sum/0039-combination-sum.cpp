class Solution {
public:

    void backtrack( int i ,  int target , vector<int>& nums , vector<int>& templist , vector<vector<int>>& list){
        if( target == 0 ){list.push_back( templist );
            return;}
        if(i == nums.size()){
            if( target == 0 )list.push_back( templist );
            return;
        }
        if( nums[i] <= target ){
            templist.push_back(nums[i]);
            backtrack(i, target - nums[i] , nums , templist , list);
            templist.pop_back();
        }

        backtrack( i+1,target,nums,templist,list);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> list;
        vector<int> templist;

        backtrack ( 0 , target , nums , templist , list);
        return list;
    }
};