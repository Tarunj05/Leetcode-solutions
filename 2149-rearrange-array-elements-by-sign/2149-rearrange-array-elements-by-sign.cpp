class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int sz = nums.size();
        vector<int> res( sz );
        int p = 0 , n = 1 ;
        for( int i=0 ; i<sz ; i++){
            if( nums[i] > 0){
                res[p] = nums[i];
                p +=  2 ;
            }else{
                res[n] = nums[i];
                n += 2 ;
            }
        }
        return res;
    }
};