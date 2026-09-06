class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if( n == 0 ) return 0;
        if( n==1 ) return 1;
        sort( nums.begin() , nums.end());
        int prev = nums[0];
        int maxLen = 1 , len = 1;
        for( int i=1 ; i<n ; i++){
            if( nums[i] == prev + 1 ){
                len ++;
                maxLen = max( len , maxLen);
            }else if( nums[i] == prev){

            }
            else{
                len = 1;
            }
            prev = nums[i];
        }
        return maxLen;
    }
};