class Solution {
public:
    long long sumAndMultiply(int n) {

        string num = to_string(n);
        long long sum = 0;
        string nonZero = "";
        for( auto ch : num ){
            if( ch != '0') nonZero += ch;
            sum += ( ch -'0');
        } 
        long long int x = 0 ;
        for(auto ch : nonZero){
            x = (x*10) + ( ch - '0');
        }

        long long ans = x*sum;

        return ans;


    }
};