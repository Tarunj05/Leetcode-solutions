class Solution {
public:

void dfs( int u , int& ans ,vector<bool>& vis , vector<vector<pair<int,int>>>& adjLs){
        vis[u] = 1;

        for( auto [v,w] : adjLs[u] ){
            
            // update the ans for every neighbour
            // as you can get to the nth city by crossing through this edge
            // even when you have to cross some edges twice
            // because they are on same connected component

            ans = min ( ans , w );

            if( !vis[v] ){
                dfs( v , ans , vis , adjLs );
            }
        }

    }

    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adjLs ( n + 1 );
        vector<bool> vis ( n + 1 , 0 );

        for( auto& e : roads ){
            int u = e[0] , v = e[1] , w = e[2];

            adjLs[u].push_back({v , w});
            adjLs[v].push_back({u , w});// undirected graph
        }

        // now we do a dfs traversal as it traverses the connected component and track the min weight edge in it
        int ans = 1e5 ;

        dfs( 1 , ans , vis , adjLs );

        return ans ;
    }
};