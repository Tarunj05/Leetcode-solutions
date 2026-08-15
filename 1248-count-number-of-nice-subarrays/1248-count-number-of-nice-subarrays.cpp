class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> seenCount;
        seenCount[0] = 1;
        int currPrefixSum = 0;
        int count = 0;
        for( int i=0 ; i<n ; i++){
            if( nums[i] % 2 != 0){
                currPrefixSum ++;
            }
            count += seenCount[ currPrefixSum - k ];
            seenCount[ currPrefixSum ]++;
        }
        return count;        
    }
};