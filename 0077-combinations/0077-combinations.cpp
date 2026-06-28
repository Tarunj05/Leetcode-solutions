class Solution {
public:
    void backtrack( int i ,int n, int k , vector<int>& templist, vector<vector<int>>& list ){
        if( i == n+1){
            if( templist.size() == k) list.push_back( templist );
            return;
        }
        
        //pick
        templist.push_back( i );
        // explore all possibilities
        backtrack( i+1 , n , k , templist , list );

        //undo
        templist.pop_back();

        backtrack( i+1 , n , k, templist , list);

    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> list;
        vector<int> templist;
        vector<bool> used( n+1 , 0 );

        backtrack( 1 , n , k , templist , list );
        return list;
    }
};