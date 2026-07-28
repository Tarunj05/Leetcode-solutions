class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();
        map<char,int> freq; // char , freq
        char oddFreqChar = '#';
        for( int i=0 ; i<n ; i++){
            freq[s[i]]++;
        }
        //reduce the freq to half and find any oddfreqchar
        for(auto [c , f] : freq){
            if(f % 2 != 0) oddFreqChar = c;

            freq[c] = freq[c]/2;
        }

        string res;

        for( auto [c,f]: freq){
            int fq = f;
            while(fq--){
                res +=c;
            }
        }
        string oldRes = res;
        reverse(oldRes.begin(),oldRes.end());
        if(oddFreqChar != '#'){
            res += oddFreqChar;
        }
        res += oldRes;
        return res;

    }
};