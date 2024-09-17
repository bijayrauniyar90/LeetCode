class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        unordered_map<string, int> wordCount;
        stringstream ss(A + " " + B);
        string word;

        // Count occurrences of each word from both sentences
        while (ss >> word) {
            wordCount[word]++;
        }

        // Collect words that appear exactly once
        vector<string> result;
        for (const auto &entry : wordCount) {
            if (entry.second == 1) {
                result.push_back(entry.first);
            }
        }

        return result;
    }
};
