class Solution {
public:

    void backtrack( vector<int>& nums , vector<int>& templist , vector<vector<int>>& list , vector<bool>& used){
        if( templist.size() == nums.size()) list.push_back(templist);

        for( int i = 0 ; i < nums.size() ; i++){
            if( used[i] || ( i>0 && nums[i] == nums[i-1] && !used[i-1])) continue;
            else{
                templist.push_back( nums [ i ] );
                used[i] =1;
                backtrack( nums,templist ,list,used);

                used[i]=0;
                templist.pop_back();
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> list;
        vector<int> templist;
        vector<bool> used( nums.size() , 0 );

        sort( nums.begin() , nums.end());
        backtrack( nums , templist , list , used);

        return list;
    }
};