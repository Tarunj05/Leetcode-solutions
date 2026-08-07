class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
      unordered_map<int,int> freq;
      freq[0] = 1;
    int n = nums.size();
      int currSum = 0,  ans = 0;
      for( int i=0 ; i<n ; i++){
        currSum+= nums[i];
        if( freq.find( currSum - k ) != freq.end()){
            ans += freq[currSum-k];
        }
        freq[currSum]++;
      }  
      return ans;
    }
};