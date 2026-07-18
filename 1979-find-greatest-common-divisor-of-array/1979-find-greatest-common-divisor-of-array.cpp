class Solution {
public:

    int GCD( int a , int b){
        if( b == 0 )return a;
        return GCD( b , a%b);
    }

    int findGCD(vector<int>& nums) {
        int maxi = 1 , mini = 1000;

        for( auto num : nums ){
            maxi = max( maxi , num);
            mini = min ( mini , num);
        }

        return GCD(maxi , mini);
    }
};