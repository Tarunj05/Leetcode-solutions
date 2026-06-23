class Solution {
public:
    int myAtoi(string s) {
        int sign = 1;
        int n = s.length();
        if( n == 0 ) return 0;

        //initialize the pointer
        int i = 0;
        // igonre white spaces
        while( i<n && s[i] == ' ') i++;

        //check the sign
        if(i<n && (s[i]=='+' || s[i] == '-')){
            sign = (s[i]=='-') ? -1 : 1;
            i++;
        }
        long long result = 0;
        //now start reading until we reach end or get a non-digit
        //also handle the overflows
        while( i<n && s[i] >= '0' && s[i] <= '9'){

            result = result * 10 + ( s[i] - '0' );

            //handle the overflows
            if(sign == 1 && result > INT_MAX ) return INT_MAX;
            if( sign == -1 && -result < INT_MIN ) return INT_MIN;

            i++;
        }

        return result*sign;
    }
};