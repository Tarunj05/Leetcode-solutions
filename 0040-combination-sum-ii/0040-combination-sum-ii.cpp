class Solution {
public:
    void backtrack( int start , vector<int>& nums , int target , vector<int>& templist , vector<vector<int>>& list ){
        if( target == 0){
            list.push_back( templist );
            return;
        }
        for( int i = start ; i<nums.size() ; i++ ){
          if( nums[i] > target) break;

          if( i>start && nums[i] == nums[i-1])continue;

          //choose the element
          templist.push_back( nums[i]);

          // move to the next element
          backtrack( i+1 , nums,target - nums[i] , templist , list);

          // undo the choice ( backtrack )
          templist.pop_back();  
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> list;
        vector<int> templist;
        sort( candidates.begin() , candidates.end());
        backtrack( 0 , candidates , target , templist , list );

        return list;
    }
};