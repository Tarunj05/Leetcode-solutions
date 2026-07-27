class Solution {
public:

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for( auto time : times){
            int u = time[0] , v = time[1] , wt = time[2];
            adj[u].push_back({v,wt});
        }
        priority_queue<pair<int,int>> pq;
        const int INF = 1e9;
        vector<int> dis( n+1 , INF );
        pq.push({0,k});
        dis[k]=0;

        while(!pq.empty()){
            int u = pq.top().second; pq.pop();
            for( auto [v , wt] : adj[u]){
                if( dis[u] + wt < dis[v]){
                    dis[v] = dis[u] + wt;
                    pq.push({dis[v] ,v});
                }
            }
        }
        int ans = 0;
        for( int i=1 ; i<=n ; ++i){
            ans = max( ans , dis[i]);
        }

        return ans==INF ? -1 : ans;
    }
};