class Solution {
public:
    using p = vector<int>;
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size() , n = grid[0].size();
        vector<vector<int>> dist (m , vector<int> ( n , INT_MAX ));
        //cell no = m*r + c + 1;
        // r = cell N0 / m , c = cellno - m*r
        deque<p> dq;

        // start with 1 , reqHealth = 0;
        dq.push_front({grid[0][0],0,0});
        // starting cost
        dist[0][0] = grid[0][0];

        vector<int> dir = {1 , 0 , - 1 , 0 , 1};

        while( !dq.empty()){
            int cost = dq.front()[0] , r = dq.front()[1] , c = dq.front()[2];
            dq.pop_front();

            if(r == m-1 && c == n-1){
                return health > cost;
            }

            if( cost > dist[r][c]) continue;
            // push valid unvisited neighbours
            for(int i = 0 ; i<=3 ; i++ ){
                int nr = r + dir[i] , nc = c + dir[i+1];
                if( nr>=0 && nr<m && nc>=0 && nc<n){
                    
                    int newCost = cost + grid[nr][nc];

                    if( newCost < dist[nr][nc] ){
                        dist[nr][nc] = newCost;
                        if( grid[nr][nc]==0 )dq.push_front({newCost,nr,nc});
                        else dq.push_back({newCost,nr,nc});
                    }
                }
            }

        }
        return false;
    }
};