class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n= nums.size();
        unordered_map<int,int> freq; // sumSeen -> freq
        freq[0] = 1;
        int count = 0;
        int prefixSum;
        for( int i=0 ; i<n ; i++){
            prefixSum += nums[i];
            count += freq[prefixSum-k];
            freq[prefixSum]++;
        }
        return count;
    }
};