class Solution {
public:
    void backtrack( int start , vector<int>&nums , vector<int>& templist , vector<vector<int>>& list){
        list.push_back( templist );

        for( int i = start ;  i < nums.size() ; i++ ){

            if( i > start &&  nums[i] == nums[i-1]) continue;

            templist.push_back(nums[i]);
            backtrack( i+1 , nums , templist , list );

            templist.pop_back();

        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> list;
        vector<int> templist;

        sort(nums.begin(),nums.end());
        backtrack( 0 , nums , templist , list );
        return list;
    }
};