class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size() , n = grid[0].size();

        if( k == 0 || (m == 1 && n==1)) return grid;

        // assume it as a flattened array
        // so 1d index =  i*n + j

        // modulo the k by total elements
        // becase shifting it by total elements we get the same array
        int total = m*n;
        k %= total;

        // now we traverse the given grid one by one and put elements to the shifted array

        vector<vector<int>> result ( m , vector<int> (n  , 0));
        for( int i=0 ; i<m ; ++i){
            for( int j=0 ; j<n ; ++j){
                int oldIdx = i*n + j;
                int newIdx = (oldIdx + k) % total;
                int newRow = newIdx / n;
                int newCol = newIdx % n;

                result[newRow][newCol] = grid[i][j];
            }
        }
        return result;
    }
};