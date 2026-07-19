class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.length();
        string result;
        vector<int> lastIndex( 26 );// this will track the last occurences of characters int the string 
        vector<bool> taken( 26 , false );// this will keep a track of chosen characters, so we avoid duplicates

        // populating the lastIndex
        for( int i=0 ; i<n ; ++i){
            lastIndex[s[i]-'a'] = i;
        }

        // parse the given string one by one 

        for( int i=0 ; i<n ; ++i){
            //if the ith character is already taken , continue
            if(taken[s[i]-'a']) continue;

            // pop all the larger characters that can come after ith character
            // this way we get the lexicographically smallest one
            while(!result.empty() &&  result.back() > s[i] && lastIndex[result.back()-'a'] > i){
                // mark it untaken
                taken[result.back()-'a'] = false;
                result.pop_back();
            }

            // push the current element and mark it taken
            result.push_back(s[i]);
            taken[s[i]-'a'] = true;
        }

        return result;
    }
};