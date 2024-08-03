class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> freq;

        // Increment frequency for elements in target
        for (int num : target) {
            freq[num]++;
        }

        // Decrement frequency for elements in arr
        for (int num : arr) {
            freq[num]--;
            // Remove element if frequency reaches zero
            if (freq[num] == 0) {
                freq.erase(num);
            }
        }

        // Check if all frequencies are zero
        return freq.empty();
    }
};