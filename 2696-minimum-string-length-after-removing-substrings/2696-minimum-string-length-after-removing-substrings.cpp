class Solution {
public:
    int minLength(string s) {
        // Use a stack to process the string
        stack<char> st;

        // Traverse each character in the string
        for (char c : s) {
            // Check if the current character forms a pair with the top of the stack
            if (!st.empty() && ((st.top() == 'A' && c == 'B') || (st.top() == 'C' && c == 'D'))) {
                // If it forms "AB" or "CD", pop the top element (remove the pair)
                st.pop();
            } else {
                // Otherwise, push the current character onto the stack
                st.push(c);
            }
        }

        // The remaining characters in the stack form the final string
        return st.size();
    }
};
