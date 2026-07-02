class Solution {
public:
    using p = vector<int>;
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size() , n = grid[0].size();
        vector<vector<int>> minCost (m , vector<int> ( n , INT_MAX ));
        deque<p> dq;


        dq.push_front({grid[0][0],0,0});
        // starting cost
        minCost[0][0] = grid[0][0];

        vector<int> dir = {1 , 0 , - 1 , 0 , 1};

        while( !dq.empty()){
            int cost = dq.front()[0] , r = dq.front()[1] , c = dq.front()[2];
            dq.pop_front();

            if(r == m-1 && c == n-1){
                return health > cost;
            }

            if( cost > minCost[r][c]) continue;

            for(int i = 0 ; i<=3 ; i++ ){
                int nr = r + dir[i] , nc = c + dir[i+1];
                if( nr>=0 && nr<m && nc>=0 && nc<n){
                    
                    int newCost = cost + grid[nr][nc];
                    //if we get a better path , then only update it
                    if( newCost < minCost[nr][nc] ){
                        minCost[nr][nc] = newCost;
                        if( grid[nr][nc]==0 )dq.push_front({newCost,nr,nc});
                        else dq.push_back({newCost,nr,nc});
                    }
                }
            }

        }
        return false;
    }
};