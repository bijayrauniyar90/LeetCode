class Solution {
public:
    string largestNumber(vector<int> &nums) {
        vector<string> numStrings;
        numStrings.reserve(nums.size());  // Reserve space to avoid multiple allocations

        // Convert each integer to a string
        for (int num : nums) {
            numStrings.push_back(to_string(num));
        }

        // Sort strings based on concatenated values
        sort(numStrings.begin(), numStrings.end(),
             [](const string &a, const string &b) { return a + b > b + a; });

        // Handle the case where the largest number is zero
        if (numStrings[0] == "0") return "0";

        // Concatenate sorted strings to form the largest number
        string largestNum;
        for (const string &numStr : numStrings) {
            largestNum += numStr;
        }

        return largestNum;
    }
};