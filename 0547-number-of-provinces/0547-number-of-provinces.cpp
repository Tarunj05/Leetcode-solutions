class Solution {
public:

    void dfs( int vertex , vector<int>& vis , vector<vector<int>>& adj ){
        vis[vertex] = 1;
        for( int child : adj[vertex]){
            if(!vis[child]){
                dfs(child , vis ,adj);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n);
        for( int i=0 ; i<n ; i++){
            for( int j=0 ; j<n ; j++){
                if( i==j)continue;
                if( isConnected[i][j] ){
                    adj[i].push_back(j);
                }
            }
        }
        vector<int> vis( n , 0);
        int  provinces = 0;
        for( int i=0 ; i<n ; i++){
            if(!vis[i]){
                provinces++;
                dfs( i , vis, adj);
            }
        }
        return provinces;
    }
};