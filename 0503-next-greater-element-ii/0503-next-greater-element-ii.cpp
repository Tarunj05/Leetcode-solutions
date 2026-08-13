class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n  , -1);
        for( int i=0 ; i<n ; i++){
            int j = i+1;
            for( int k=0 ; k<n-1 ; k++){
                int idx = j % n;

                if( nums[idx] > nums[i]){
                    res[i] = nums[idx];
                    break;
                }
        


                j++;
            }
        }
        return res;
    }
};