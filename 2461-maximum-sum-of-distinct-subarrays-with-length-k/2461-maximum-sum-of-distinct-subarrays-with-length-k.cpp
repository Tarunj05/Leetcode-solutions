class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> freq;

        int l = 0 , r = k ;

        long long windowSum = 0;
        long long maxSum = 0;
        for( int i=0 ; i<k ; i++){
            windowSum += nums[i];
            freq[nums[i]]++;
            if( freq.size() == k){
                maxSum = max(windowSum , maxSum);
            }
        }

        while( r < n){

            // slide the window

            windowSum += nums[r];
            freq[nums[r]]++;
            freq[nums[l]]--;
            if( freq[nums[l]] == 0) freq.erase(nums[l]);
            windowSum -= nums[l];
            if( freq.size() == k){
                maxSum = max( maxSum , windowSum);
            }
            l++;r++;
            

            
        }
        return maxSum;
    }
};