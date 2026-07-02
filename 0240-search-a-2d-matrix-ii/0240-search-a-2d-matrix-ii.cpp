class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;

        int m = matrix.size(), n = matrix[0].size();
        int sr = 0, sc = 0, er = m - 1, ec = n - 1;

        // Fix 1: Loop until boundaries cross completely
        while (sr <= er && sc <= ec) {
            
            // Shrink from the bottom-left if elements are too large
            while (er >= sr && matrix[er][sc] >= target) {
                if (matrix[er][sc] == target) return true;
                er--;
            }
            
            // Shrink from the top-right if elements are too large
            while (ec >= sc && matrix[sr][ec] >= target) {
                if (matrix[sr][ec] == target) return true; // Fix 2: Changed sc to ec
                ec--;
            }
            
            // Fix 3: Safely advance the minimum boundaries only if the current 
            // corner values are confirmed to be smaller than the target
            if (sr <= er && matrix[sr][ec] < target) {
                sr++;
            }
            if (sc <= ec && matrix[er][sc] < target) {
                sc++;
            }
        }
        
        return false;
    }
};