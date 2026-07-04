class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        

        vector<vector<pair<int,int>>> adjLs( n+1 );

        for( auto& e : roads ){
            int u = e[0] , v = e[1] , w = e[2];

            adjLs[u].push_back({v,w});
            adjLs[v].push_back({u,w});
        }

        queue<int> q;
        vector<bool> vis( n+1 , 0 );

        int ans = 1e5;

        // put the source node in the queue
        q.push(1);
        vis[1] = 1;
        
        while( !q.empty() ){
            int curr = q.front();
            q.pop();



            // push the unvisited Neighbour

            for( auto& [ v , w ] : adjLs[curr]){
                // update the ans with the min dist in component connected to 1
                ans = min( ans , w );                
                
                if( !vis[v] ){
                    q.push(v);
                    vis[v] = 1;
                }
            }

        }
        return ans;
    }
};