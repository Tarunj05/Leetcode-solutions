class Solution {
public:
    int power( long long x, long long n , int mod){
        if( n == 0) return 1;

        if( n%2 == 0) return (power((x*x)%mod , n/2 , mod)%mod);
        else return (x * power(x,n-1,mod))%mod;

    }

    int countGoodNumbers(long long n) {
        int mod = (int)(1e9+7);

        return ((long long)(power(4,n/2,mod))%mod) *((power(5,n-n/2,mod))%mod)%mod
        ;
    }
};