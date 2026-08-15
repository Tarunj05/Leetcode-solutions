class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int,int> freq;// type -> freq
        int l=0;
        int maxLen = 0;
        for( int r=0 ; r<n ; r++){
            //include right
            freq[fruits[r]]++;
            //shrink while invalid
            while( freq.size() > 2){
                //remove left
                freq[fruits[l]]--;
                if( freq[fruits[l]] == 0) freq.erase(fruits[l]);
                l++;
            }
            // here my window is valid
            maxLen = max( maxLen , r-l+1);
        }
        return maxLen;
    }
};