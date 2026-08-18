class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int num = 0;
        sort( nums.begin() , nums.end());
        for( int i=0 ; i<n ; i++){
            if( num == nums[i]){
                num++;
                continue;
            }else{
                return num;
            }
        }
        return n;
    }
};