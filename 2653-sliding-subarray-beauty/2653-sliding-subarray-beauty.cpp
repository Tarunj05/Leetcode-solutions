class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {

        vector<int> freq(50, 0);

        // First window
        for (int i = 0; i < k; i++) {
            if (nums[i] < 0)
                freq[abs(nums[i] + 1)]++;
        }

        vector<int> beauty;

        auto findBeauty = [&]() {
            int count = 0;

            for (int i = 49; i >= 0; i--) {   // -50 to -1
                count += freq[i];

                if (count >= x)
                    return -(i + 1);
            }

            return 0;
        };

        beauty.push_back(findBeauty());

        int l = 0;
        int n = nums.size();

        for (int r = k; r < n; r++) {

            if (nums[r] < 0)
                freq[abs(nums[r] + 1)]++;

            if (nums[l] < 0)
                freq[abs(nums[l] + 1)]--;

            l++;

            beauty.push_back(findBeauty());
        }

        return beauty;
    }
};