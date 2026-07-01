class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> pq;
        vector<vector<int>> dis(n, vector<int>(m, -1));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    dis[i][j]=0;
                    pq.push({i,j});
                }
            }
        }

        int dr[]={-1,1,0,0};
        int dc[]={0,0,1,-1};

        while(!pq.empty()){

            auto el=pq.front();
            pq.pop();

            int row=el.first;
            int col=el.second;

            for(int i=0;i<4;i++){

                int nr=row+dr[i];
                int nc=col+dc[i];

                if(nr>=0 && nr<n && nc>=0 && nc<m && dis[nr][nc]==-1){

                    dis[nr][nc]=dis[row][col]+1;
                    pq.push({nr,nc});
                }
            }
        }

        priority_queue<pair<int,pair<int,int>>> pqq;
        vector<vector<int>> vis(n,vector<int>(m,-1));

        vis[0][0]=dis[0][0];
        pqq.push({dis[0][0],{0,0}});

        while(!pqq.empty()){

            auto el=pqq.top();
            pqq.pop();

            int score=el.first;
            int x=el.second.first;
            int y=el.second.second;

            if(x==n-1 && y==n-1)
                return score;

            if(score<vis[x][y])
                continue;

            for(int i=0;i<4;i++){

                int nx=x+dr[i];
                int ny=y+dc[i];

                if(nx>=0 && nx<n && ny>=0 && ny<m){

                    int newSafe=min(score,dis[nx][ny]);

                    if(newSafe>vis[nx][ny]){

                        vis[nx][ny]=newSafe;
                        pqq.push({newSafe,{nx,ny}});
                    }
                }
            }
        }

        return 0;
    }
};