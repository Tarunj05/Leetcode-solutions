class Solution {
public:

    void backtrack( int start , vector<int>& nums, vector<int>& templist , vector<vector<int>>& list ){
        list.push_back( templist );

        for( int i = start ; i<nums.size() ; i++){
            //pick
            templist.push_back( nums[i] );
            //explore all the next possibities
            backtrack( i+1 , nums , templist , list );
            //undo so that we get all the cases without nums[i]
            templist.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> list;
        vector<int> templist;

        backtrack(0,nums,templist, list);
        return list;
    }
};