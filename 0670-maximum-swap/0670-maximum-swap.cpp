class Solution {
public:
    int maximumSwap(int num) {
        string numStr = to_string(num);  // Convert num to string
        int n = numStr.size();
        
        vector<int> last(10, -1);  // Stores the last occurrence of each digit
        
        // Record the last occurrence of each digit in the number
        for (int i = 0; i < n; ++i) {
            last[numStr[i] - '0'] = i;
        }

        // Traverse the number and look for the first opportunity to swap
        for (int i = 0; i < n; ++i) {
            // Check if there's a larger digit that occurs later
            for (int d = 9; d > numStr[i] - '0'; --d) {
                if (last[d] > i) {
                    // Swap and return the result immediately
                    swap(numStr[i], numStr[last[d]]);
                    return stoi(numStr);  // Return the result as an integer
                }
            }
        }
        
        return num;  // Return original number if no swap is needed
    }
};
