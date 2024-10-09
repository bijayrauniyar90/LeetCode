class Solution {
public:
    int minAddToMakeValid(string s) {
        int openBrackets = 0;
        int minAddsRequired = 0;

        for (char c : s) {
            if (c == '(') {
                openBrackets++;
            } else if (openBrackets > 0) {
                // Match the current closing bracket with an open bracket.
                openBrackets--;
            } else {
                // No open bracket to match, so we need an additional one.
                minAddsRequired++;
            }
        }

        // Return the number of unmatched open brackets + required additions.
        return minAddsRequired + openBrackets;
    }
};
