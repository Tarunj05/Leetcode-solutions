class Solution {
public:
    void solve( int i , vector<int>& nums , vector<int>& ds , vector<vector<int>>&result){
        if( i == nums.size()){
            result.push_back(ds);
            return;
        }
        //pick
        ds.push_back(nums[i]);
        solve(i+1,nums,ds,result);

        // undo
        ds.pop_back();

        solve( i+1, nums,ds,result);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> ds;

        solve(0,nums,ds,result);
        return result;
    }
};