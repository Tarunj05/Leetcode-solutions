class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> mp; // Using long long prevents overflow naturally
        for(int x : nums) mp[x]++;

        int ans = 0;

        for(auto & [num, freq] : mp){
            long long x = num;

            if(x == 1) {
                // If odd, take all; if even, take freq - 1 to make it odd
                ans = max(ans, freq % 2 ? freq : freq - 1);
            } 
            else {
                int lenOfChain = 0;
                // Build the outer layers of the sandwich pattern
                while(mp.count(x) && mp[x] >= 2) {
                    lenOfChain++;
                    x *= x;
                }
                
                // If the top element exists at least once, it can be the peak
                if(mp.count(x) && mp[x] >= 1) {
                    ans = max(ans, 2 * lenOfChain + 1);
                } else {
                    ans = max(ans, 2 * lenOfChain - 1);
                }
            }
        } 
        return ans;
    }
};