class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        priority_queue<pair<int,int>> pq;// {dis , value };

        for(int i = 0 ; i < n ; ++i){
            int dis = abs( x - arr[i]);
            pq.push({dis , arr[i]});

            if( pq.size() > k){
                pq.pop();
            }
        }

        // now we have k closest elements in the maxheap

        vector<int> ans;
        while(!pq.empty()){
            int val = pq.top().second;
            pq.pop();
            ans.push_back(val);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};