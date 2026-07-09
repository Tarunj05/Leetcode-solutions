class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int>parent(n,0);
        int component = 0;
        for( int i=1 ; i<n ; i++ ){
            if( nums[i] - nums[i-1] > maxDiff ) component++;
            parent[i] = component;
        }

        int nq = queries.size();
        vector<bool> answer(nq , false);

        for(int i=0 ; i<nq ; i++){
            int u = queries[i][0] , v = queries[i][1];
            if( parent[u] == parent[v]) answer[i] = true;
        }
        return answer;
    }
};