class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int count = 0;
        for( auto pattern : patterns){
            if(word.contains( pattern )) count++;
        }
        return count;
    }
};