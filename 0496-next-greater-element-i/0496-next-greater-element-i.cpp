class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        vector<int> nge(n);
        vector<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.back() < nums2[i])
                st.pop_back();
            if (st.empty())
                nge[i] = -1;
            else
                nge[i] = st.back();
            st.push_back(nums2[i]);
        }

        // nge has all the next greater elements of nums2

        vector<int> ans(m);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (nums1[i] == nums2[j]) {
                    ans[i] = nge[j];
                }
            }
        }

        return ans;
    }
};
