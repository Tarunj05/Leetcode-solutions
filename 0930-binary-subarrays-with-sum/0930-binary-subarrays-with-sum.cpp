class Solution {
public:

    int noOfSubarraysWithSumK( int k , vector<int>& nums){
        if(k<0)return 0;
        int n = nums.size();
        int l=0;
        int sum = 0 ;
        int subarrayCount = 0;
        for( int r=0 ; r<n ; r++){
            //include right
            sum += nums[r];
            //shrink while invalid
            while(sum > k ){
                sum -= nums[l];
                l++;
            }
            // here the window is valid
            //update ans
            subarrayCount += r - l + 1;
        }
        return subarrayCount;
    }

    int numSubarraysWithSum(vector<int>& nums, int k) {
        
        return noOfSubarraysWithSumK( k , nums ) - noOfSubarraysWithSumK( k-1 , nums );
    }
};