class Solution {
public:


    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> next(n+1 , 0) , curr(n+1,0);

        for( int i = n-1 ; i>=0 ; i--){
            for( int prev = i-1 ; prev>=-1 ; prev--){
                    //not take
                    int len =  0 + next[prev+1];
                    //take
                    if( prev == -1 || nums[i] > nums[prev] ){
                        len = max( len , 1 + next[i+1]);
                    }
                    curr[prev+1] = len;
            }
            next = curr;
        }
        return curr[-1+1];
    }
};