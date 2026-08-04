class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> missing;
        unordered_set<int> st ;
        int lar = nums[0] , sm = nums[0];

        for( int x : nums){
            lar = max( x , lar);
            sm = min( x , sm );
            st.insert(x);
        }

        for( int i= sm ; i<=lar ; i++){
            if( st.find(i) != st.end()) continue;
            else missing.push_back( i );
        }
        return missing;
    }
};