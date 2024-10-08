class Solution {
public:
    int minSwaps(string s) {
        int unbalanced = 0, maxUnbalanced = 0;

        // Traverse the string and track the balance.
        for (char ch : s) {
            // If it's an opening bracket, increase balance.
            if (ch == '[') 
                unbalanced--;
            else {
                // If it's a closing bracket, increase the imbalance.
                unbalanced++;
                // Track the maximum imbalance we encounter.
                maxUnbalanced = max(maxUnbalanced, unbalanced);
            }
        }

        // The minimum number of swaps needed is half the maximum imbalance.
        return (maxUnbalanced + 1) / 2;
    }
};
