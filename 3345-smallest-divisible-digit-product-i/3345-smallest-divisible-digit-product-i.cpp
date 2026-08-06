class Solution {
public:
    
    int digitProd( int x ){
        int prod = 1;
        while(x>0){
            int digit = x%10;
            prod *= digit;
            x/=10;
        }
        return prod;
    }

    int smallestNumber(int n, int t) {
        while(1){
            if( digitProd(n) % t == 0) return n;
            n++;
        }
    }
};