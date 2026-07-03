class Solution {
public:
    using ll = long long ;
    using p = pair< ll ,int >;

    bool isPossible( ll mid ,int n  ,unordered_map< int , vector< pair<int,int> > >& mp , ll k){
        priority_queue< p , vector<p> , greater<p> > pq;
        vector<ll> dist ( n , 1e14 );
        pq.push( { 0 , 0 } );
        dist[0] = 0;

        while( !pq.empty()){

            ll dis = pq.top().first ; int u = pq.top().second;
            pq.pop();
            if( dis > dist[u])continue;

            // push neighbours
            for( auto it : mp[u] ){
                int w = it.first , v = it.second;

                if( w < mid ) continue;

                if( dist[v] > dist[u] + w ){
                    dist[v] = dist[u] + w;
                    pq.push({dist[v] , v});
                }
            }
        
        }
        return dist[dist.size()-1] <= k;
    
    }
    
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        unordered_map< int , vector< pair<int,int> > > mp;

        int n = online.size();


        ll low = 0, high = 0 ;
        

        for( auto it : edges ){
            int u = it[0] , v = it[1] , w = it[2];

            if( online[u] && online[v] ){
                mp[u].push_back({ w , v });
                high = max( high , (ll)w );
            }
        }

        ll ans = -1; 
        while( low <= high ){
            ll mid = low + ( high - low )/2;

            if( isPossible( mid ,n , mp, k )){
                ans = mid;
                low = mid + 1;
            }

            else high = mid - 1;
        }

        return (int) ans ;
    }
};