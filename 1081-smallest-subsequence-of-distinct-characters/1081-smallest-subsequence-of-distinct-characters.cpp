class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.length();
        vector<int> lastIndex( 26 , 0);
        vector<bool> taken(26 , false);
        string st;

        for( int i = 0 ; i<n ; i++){
            lastIndex[s[i] - 'a'] = i;
        }

        for(int i=0 ; i<n ; i++){
            char ch = s[i];

            if( taken[ch - 'a'])continue;

            while( st.length() > 0 && st.back() > ch && lastIndex[st.back()-'a'] > i){
                taken[st.back()-'a'] = false;
                st.pop_back();
            }

            st.push_back(ch);
            taken[ch-'a'] = true;
            
        }

        return st;
    }
};