class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        // sort the intervals in ascending order of their lengths
        sort( intervals.begin() , intervals.end() , [](auto i1 ,auto i2 ){
            return (i1[1] - i1[0]) < (i2[1]  - i2[0]);
        });
        int n = intervals.size();
        int removed = 0 ;
        
        for(int i=0 ; i<n ; i++){

            int a = intervals[i][0] , b = intervals[i][1];
            for(int j = i+1 ; j<n ; j++){
                int c = intervals[j][0] , d = intervals[j][1];

                if( c <= a && b <= d ){
                    // this intervals is covered
                    removed++;
                    break;                    
                }
            }
        }
        // now we copy the intervals into a result array , ignoring the removed ones
        return n-removed;
    }
};