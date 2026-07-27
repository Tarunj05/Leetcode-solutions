class Solution {
public:

    bool isCycleDfs( int vertex , vector<int>& vis , vector<vector<int>>& adj ){
        vis[vertex] = 1;
        for( int child : adj[vertex]){
            if(vis[child] ==1) return true;
            if(vis[child] == 0){
                if(isCycleDfs( child , vis ,adj)) return true;
            }
        }
        vis[vertex] = 2;
        return false;
    }

    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj( n);
        vector<int> vis( n , 0 );

        for( auto& pre : prerequisites){
            int u = pre[0] , v = pre[1];
            adj[u].push_back(v);
        }

        for( int i=0 ; i<n ; ++i){
            if( !vis[i]){
                if(isCycleDfs( i , vis , adj)) return false;
            }
        }
        return true;
    }
};