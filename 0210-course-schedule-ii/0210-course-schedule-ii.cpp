class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<int> indegree(n , 0);
        vector<vector<int>> adj( n );
        
        for( auto pre : prerequisites){
            adj[pre[0]].push_back(pre[1]);
            indegree[pre[1]]++;
        }
        queue<int> q;
        for( int i=0 ; i<n ; i++){
            if( indegree[i] == 0){
                q.push( i );
            }
        }
        vector<int> topoSort;
        while( !q.empty()){
            int vertex = q.front(); q.pop();
            topoSort.push_back(vertex);
            for( int child : adj[vertex]){
                indegree[child]--;
                if( indegree[child] == 0){
                    q.push( child );
                }
            }
        }
        reverse( topoSort.begin() , topoSort.end());
        if( topoSort.size() == n ) return topoSort;
        else return {};
    }
};