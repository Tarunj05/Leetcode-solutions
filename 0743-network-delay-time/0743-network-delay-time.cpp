
class Solution {
public:
    using p = pair<int,int>;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for( auto it : times ){
            int u = it[0] , v = it[1] , wt = it[2];
            adj[u].push_back({v,wt});
        }
        vector<int> dis( n+1 , 1e9);
        // push the source in the priortity queue
        priority_queue<p , vector<p> , greater<p>> pq;//min Heap , {dis , node};
        pq.push({0,k});
        dis[k] = 0;
        while(!pq.empty()){
            int u = pq.top().second;
            pq.pop();
            for( auto [v,wt] : adj[u]){
                if(dis[u]+wt < dis[v]){
                    dis[v] = dis[u] + wt;
                    pq.push({dis[v],v});
                }
            }
        }
        int ans = 0 ;
        for(int i = 1 ; i<=n ; ++i){
            ans = max( ans , dis[i]);
        }
        return ans == 1e9 ? -1 :ans;
    }
};
