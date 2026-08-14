class Solution {
public:
    string removeKdigits(string num, int k) {
        string res = "";
        
        for (char c : num) {
            // Greedily remove larger previous digits
            while (!res.empty() && k > 0 && res.back() > c) {
                res.pop_back();
                k--;
            }
            res.push_back(c);
        }
        
        // If k > 0, remove the remaining digits from the end
        while (k > 0 && !res.empty()) {
            res.pop_back();
            k--;
        }
        
        // Strip leading zeros
        int start = 0;
        while ( res[start] == '0') {
            start++;
        }
        res = res.substr(start);
        
        // If result is empty, return "0"
        return res.empty() ? "0" : res;
    }
};