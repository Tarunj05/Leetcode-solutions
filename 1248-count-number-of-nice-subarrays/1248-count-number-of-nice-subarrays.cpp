class Solution {
public:

    int subarrays( int k , vector<int>& nums ){
        if(k<0) return 0;
        int n = nums.size();
        int l=0;
        int subarraySum = 0;
        int subarrayCount = 0;
        for( int r=0 ; r<n ; r++){
            //include right
            if( nums[r] % 2 != 0)
                subarraySum += 1;
            // shrink while invalid
            while( subarraySum > k ){
                if (nums[l] % 2 != 0) subarraySum -= 1;
                l++;
            }
            //here the window is valid
            //so add the no of subarrays with sum <=k ending at index r , i.e. = r-l+1
            subarrayCount += r-l+1;
        }
        return subarrayCount;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return subarrays( k , nums ) - subarrays( k-1 , nums );
    }
};