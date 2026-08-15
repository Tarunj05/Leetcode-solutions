class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> seenIdx;// sumseen -> first occurance
        seenIdx[0]= -1;
        int currPrefixSum = 0;
        int maxLen = 0;

        for( int i=0 ; i<n ; i++){
            if( nums[i] == 0){
                currPrefixSum -= 1;
            }else{
                currPrefixSum += 1;
            }
            if( seenIdx.count( currPrefixSum ) ){
                maxLen = max( maxLen , i - seenIdx[ currPrefixSum ] );
            }else 
                seenIdx[currPrefixSum] = i;
        }
        return maxLen;
    }
};