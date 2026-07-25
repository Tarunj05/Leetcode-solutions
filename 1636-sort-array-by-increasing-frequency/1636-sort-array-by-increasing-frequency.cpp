class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int x : nums) {
            freq[x]++;
        }

        sort(nums.begin(), nums.end(), [&](int a, int b) {
            // Primary condition: Sort by frequency in INCREASING order
            if (freq[a] != freq[b]) {
                return freq[a] < freq[b];
            }
            // Secondary condition: If frequencies match, sort by value in DECREASING order
            return a > b;
        });

        return nums;
    }
};