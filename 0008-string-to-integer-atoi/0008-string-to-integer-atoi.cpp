class Solution {
private:
    // Helper function to process the string recursively
    long helper(string& s, int i, int sign, long result) {
        // Base case: reached the end of the string
        if (i >= s.length()) return result * sign;

        char ch = s[i];

        // Phase 3: Process digits
        if (ch >= '0' && ch <= '9') {
            result = result * 10 + (ch - '0');

            // Handle overflow/underflow on the fly
            if (sign == 1 && result > INT_MAX) return INT_MAX;
            if (sign == -1 && -result < INT_MIN) return INT_MIN;

            // Recurse for the next character
            return helper(s, i + 1, sign, result);
        }

        // If it's not a digit, we stop processing immediately
        return result * sign;
    }

public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.length();

        // 1. Skip leading whitespaces (Iterative or recursive, usually cleaner to skip initially)
        while (i < n && s[i] == ' ') {
            i++;
        }

        // 2. Check for sign
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // 3. Delegate the digit gathering to the recursive helper
        return helper(s, i, sign, 0);
    }
};