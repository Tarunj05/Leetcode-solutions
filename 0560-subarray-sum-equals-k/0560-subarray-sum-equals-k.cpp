class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        for ( int i=0 ; i<n ; i++){
            int subarraySum = 0;
            for( int j=i ; j<n ; j++){
                subarraySum += nums[j];
                if( subarraySum == k){
                    count++;
                }
            }
        }
        return count;
    }
};