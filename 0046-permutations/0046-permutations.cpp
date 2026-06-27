class Solution {
public:

    void backtrack( int start ,vector<int>& nums , vector<int>& templist , vector<vector<int>>& list , vector<bool>& used ){
        if( templist.size() == nums.size()) list.push_back(templist);

        for( int i = 0 ; i < nums.size() ; i++){
            if( !used[i] ){
                templist.push_back(nums[i]);
                used[i] = 1;
                backtrack(i+1,nums , templist , list ,used );
                used[i] = 0;
                templist.pop_back();

            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> list;
        vector<int> templist ;
        vector<bool> used(nums.size(),0);

        backtrack( 0 , nums , templist , list ,used);
        return list;
    }
};