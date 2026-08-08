class Solution {
public:

    bool dfs( int vertex ,int curColor , vector<int>&color , vector<vector<int>>& adj){
        color[vertex] = curColor;
        for( int child : adj[vertex]){
            if(color[child] == -1){
                if(dfs( child , !curColor , color , adj) == false)return false;
            }else if(color[child] == curColor){
                return false;
            }
        }
        return true; 
    }

    bool isBipartite(vector<vector<int>>& adj) {
        int n =adj.size();
        vector<int>color(n , -1);

        for( int i=0 ; i<n ; i++){
            if(color[i] == -1){
                if(dfs( i , 0 ,color , adj) == false)return false;
            }
        }
        return true;
    }
};