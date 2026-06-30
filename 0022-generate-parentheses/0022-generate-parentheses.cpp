class Solution {
public:

    void backtrack( int i , int n , int nO , int nC , string& tempString, vector<string>& list){
        if(i == 2*n){
            if( tempString.length() == 2*n )list.push_back( tempString);
            return ;
        }

        if( nO < n){
            //choose opening
            tempString += '(';
            backtrack( i+1 , n , nO+1 , nC , tempString,list);
            tempString.pop_back();
        }
        if( nO > nC ){

            tempString += ')';
            backtrack( i+1 , n , nO , nC+1 , tempString , list);
            tempString.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> list;
        string tempString;

        backtrack( 0 , n , 0, 0 ,tempString, list );
        return list;
    }
};


