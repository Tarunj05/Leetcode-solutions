class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = 0;
        int n = nums.size();
        for( int i= 0 ; i<n ; i++){
            for( int j=0 ; j < n ; j++){
                if( i == j) continue;
                maxi = max( maxi , (nums[i]-1)*(nums[j]-1));
            }
        }
        return maxi;
    }
};