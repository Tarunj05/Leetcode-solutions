class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int minLen = INT_MAX;
        int l=0 ;
        int windowSum = 0;
        for( int r=0 ; r<n ; r++){
            windowSum += nums[r];
            while( windowSum >= target){
                minLen =  min( minLen , r-l+1);
                windowSum-= nums[l];
                l++;
            }
        }
        return minLen == INT_MAX ? 0 : minLen;
    }
};