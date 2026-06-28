class Solution {
public:

    void backtrack( int i ,string digit , unordered_map<char,string>& mp , string& tempString , vector<string>& list){
        if( i == digit.length()){
            if( tempString.length() == digit.length()) list.push_back( tempString );
            return;
        }

            // choose ith digit
            for( char ch : mp[digit[i]]){

                // choose ch
                tempString += ch;
                backtrack( i+1 , digit , mp , tempString , list );
                tempString.pop_back();
            }

    }

    vector<string> letterCombinations(string digits) {
        unordered_map< char , string > mp;

        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        vector<string> list;
        string tempString;

        backtrack( 0 , digits , mp , tempString , list);

        return list;
        
    }
};