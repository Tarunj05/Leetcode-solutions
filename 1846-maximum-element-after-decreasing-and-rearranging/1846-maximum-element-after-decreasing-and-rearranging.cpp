class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort( arr.begin() , arr.end());
        int n = arr.size();
        int ans = 1;
        arr[0] = 1;
        for ( int i = 1 ; i<n ; i++){
            int diff = arr[i] - arr[i-1];
            if( diff > 1) arr[i] = arr[i-1] + 1;
        }
        return arr[n-1];
    }
};