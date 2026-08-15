class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        unordered_map<int,int> seenCount; // sumSeen -> freq
        seenCount[0] = 1;//sum=0 is seen, when no elements are taken
        int currPrefixSum = 0;
        int subarrayCount = 0;
        for( int i=0 ; i<n ; i++){
            //include the curr element
            currPrefixSum += nums[i];
            // record the no of subarrays with sum = goal , till ith index
            subarrayCount += seenCount[ currPrefixSum - goal ];
            // also store the currPrefixSum in the seenCount map
            seenCount[currPrefixSum]++;
        }
        return subarrayCount;
    }
};