class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixGcd ( n , 1 );
        int maxi = 0 ; 
        // O (n)
        for( int i = 0 ; i<n ; i++ ){
            maxi = max ( nums[i] , maxi );
            prefixGcd[i] = gcd( nums[i] , maxi ); 
        }

        sort( prefixGcd.begin() , prefixGcd.end()); // O ( nlog n)
        int l = 0 , r = n-1;

        long long sum = 0;
        // O(n)
        while( l<r ){
            sum += gcd( prefixGcd[l] , prefixGcd[r] );
            //mistake!!!!
            l++; r--;
        }

        return sum;
    }
};