class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n = candyType.size();
        unordered_set<int> st;

        for( int x : candyType ){
            st.insert( x );
        }
        int distinct = st.size();
        int toEat = n/2;

        if( toEat < distinct ) return toEat;
        else return distinct;
    }
};