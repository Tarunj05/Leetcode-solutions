class Solution {
public:
    using p = vector<int>;
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size() , n = grid[0].size();
        vector<vector<int>> dist (m , vector<int> ( n , INT_MAX ));
        //cell no = m*r + c + 1;
        // r = cell N0 / m , c = cellno - m*r
        priority_queue<p , vector<p> , greater<p>> pq;

        // start with 1 , reqHealth = 0;
        pq.push({grid[0][0],0,0});
        // starting cost
        dist[0][0] = grid[0][0];

        vector<int> dir = {1 , 0 , - 1 , 0 , 1};

        while( !pq.empty()){
            int cost = pq.top()[0] , r = pq.top()[1] , c = pq.top()[2];
            pq.pop();

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
                        pq.push({newCost,nr,nc});
                    }
                }
            }

        }
        return false;
    }
};