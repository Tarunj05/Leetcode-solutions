class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        if( k == 0 )return grid;
        int m = grid.size() ,  n = grid[0].size();

        vector<vector<int>> result ( m , vector<int> ( n , 0 ));

        while( k ){
            for( int i = 0 ; i < m ; ++i ){
                for( int j = 0 ; j <n ; ++j ){
                    if( j == n-1 ){
                        if( i == m-1) result[0][0] = grid[i][j];
                        else result[i+1][0] = grid[i][j];
                    }
                    else result[i][j+1] = grid[i][j];

                }
            }
            grid = result;
            k--;
        }
        return result;
    }
};