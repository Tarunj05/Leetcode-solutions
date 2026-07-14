class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set <int> nums( arr.begin() , arr.end());
        unordered_map< int , int > rank;
        int r = 1;
        // n -> no of unique elements
        for( auto it: nums){
            rank.insert({it,r});
            r++;
        }
        vector<int> ans;
        for( auto it : arr){
            ans.push_back(rank[it]);
        }
        return ans;
    }
};