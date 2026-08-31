class Solution {
public:
    string reverseWords(string s) {
        string reversed = "";
        string currWord = "";
        int n = s.length();

        for (int i = 0; i < n; i++) {
            if (s[i] != ' ') {
                currWord += s[i];
            } else if (!currWord.empty()) {
                // Prepend word to reversed
                if (reversed.empty()) reversed = currWord;
                else reversed = currWord + " " + reversed;
                currWord = "";
            }
        }

        // Add the last word if present
        if (!currWord.empty()) {
            if (reversed.empty()) reversed = currWord;
            else reversed = currWord + " " + reversed;
        }

        return reversed;
    }
};