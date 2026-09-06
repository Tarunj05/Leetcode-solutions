class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> res;
        vector<int> pos , neg ;
        for( int x : nums ){
            if( x > 0) pos.push_back( x );
            else neg.push_back(x);
        }
        int n = pos.size();
        int i = 0;

        while( i < n ){
            res.push_back( pos[i]);
            res.push_back( neg[i]);
            i++;
        }
        return res;
    }
};