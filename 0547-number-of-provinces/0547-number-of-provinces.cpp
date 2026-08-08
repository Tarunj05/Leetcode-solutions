class Solution {
public:

    void bfs( int vertex , vector<int>& vis , vector<vector<int>>& adj ){
        queue<int> q;
        q.push(vertex);
        vis[vertex]=1;
        while(!q.empty()){
            int curr = q.front();q.pop();
            for( int child : adj[curr]){
                if( !vis[child]){
                    q.push(child);
                    vis[child]=1;
                }
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
                bfs( i , vis, adj);
            }
        }
        return provinces;
    }
};