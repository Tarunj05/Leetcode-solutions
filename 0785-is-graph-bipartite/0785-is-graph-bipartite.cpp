class Solution {
public:

    bool bfs( int vertex , vector<int>&color , vector<vector<int>>& adj){
        queue<int> q;
        q.push(vertex);
        color[vertex] = 0;

        while(!q.empty()){
            int sz = q.size();
            for( int i = 0 ; i<sz ; i++){
                int currNode = q.front(); q.pop();
                for( int child : adj[currNode]){
                    if(color[child] == -1){
                        color[child] = 1-color[currNode];
                        q.push(child);
                    }else if( color[child] == color[currNode]){
                        return false;
                    }
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& adj) {
        int n =adj.size();
        vector<int>color(n , -1);

        for( int i=0 ; i<n ; i++){
            if(color[i] == -1){
                if(bfs( i , color , adj) == false)return false;
            }
        }
        return true;
    }
};