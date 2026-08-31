class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> frequencies;
        for( auto x : s) frequencies[x]++;

        priority_queue<pair<int,char>> pq;

        for(auto [ch , freq] : frequencies){
            pq.push({freq,ch});
        }
        string ans;
        while( !pq.empty()){
            auto [freq,ch] = pq.top();
            pq.pop();
            for( int i=0 ; i<freq ; i++){
                ans  += ch;
            }
        }
        return ans;
    }
};