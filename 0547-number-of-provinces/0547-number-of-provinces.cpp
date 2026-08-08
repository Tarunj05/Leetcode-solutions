class disjointSet{
public:
    vector<int> parent , rank , size;
    disjointSet( int n ){
        parent.resize(n+1);
        for( int i=0 ; i<=n ; i++){
            parent[i] = i;
        }
        rank.resize( n+1 , 0);
        size.resize( n+1 , 1);
    }
    int findUPar( int x){
        if( parent[x] == x) return x;
        return parent[x] = findUPar(parent[x]);
    }
    void unionByRank( int u , int v){
        int ulp_u = findUPar(u) , ulp_v = findUPar(v);
        if( ulp_u == ulp_v) return;
        if( rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }else if( rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }else{
            parent[ulp_u] = ulp_v;
            rank[ulp_v]++;
        }
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        disjointSet ds(n);

        for( int i=0 ; i<n ; i++){
            for( int j =0 ; j<n ; j++){
                if( i==j)continue;
                if( isConnected[i][j]){
                    ds.unionByRank(i,j);
                }
            }
        }
        int province = 0;
        for( int i=0 ; i<n ; i++){
            if( ds.findUPar(i) == i){
                province++;
            }
        }
        return province;
    }
};