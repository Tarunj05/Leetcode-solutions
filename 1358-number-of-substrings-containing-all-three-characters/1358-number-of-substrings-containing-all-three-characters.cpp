class Solution {
public:


    int numberOfSubstrings(string s) {
        int n = s.length();
        int l = 0;
        int subStrCount = 0;
        int na = 0 , nb = 0 , nc = 0 ;
        for( int r = 0 ; r < n ;  r++){
            char ch = s[r];

            ch == 'a' ? na++ : ch == 'b' ?  nb++ : nc++;

            while( na > 0 && nb>0 && nc > 0){
                // window is valid
                subStrCount += ( n - r );
                s[l] == 'a' ? na-- : s[l] == 'b' ? nb-- : nc--;
                l++;
            }
        }
        return subStrCount;
    }
};