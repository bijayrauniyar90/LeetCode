struct TrieNode {
    TrieNode* next[26] = {};  // Array of pointers to child nodes
    int prefixSum = 0;        // Sum of counts for prefixes ending at this node
};

class Solution {
    TrieNode root;  // Root of the Trie

public:
    // Insert a word into the trie while updating the prefix sums
    void insert(const string& word) {
        TrieNode* node = &root;
        for (char c : word) {
            int index = c - 'a';
            if (!node->next[index]) {
                node->next[index] = new TrieNode();
            }
            node = node->next[index];
            node->prefixSum++;  // Increment the count of words sharing this prefix
        }
    }

    // Retrieve the total prefix score for a given word
    int getPrefixScore(const string& word) {
        TrieNode* node = &root;
        int score = 0;
        for (char c : word) {
            int index = c - 'a';
            node = node->next[index];
            score += node->prefixSum;  // Accumulate the prefix sum at each node
        }
        return score;
    }

    // Main function to calculate prefix scores for each word in the list
    vector<int> sumPrefixScores(vector<string>& words) {
        // Insert all words into the trie
        for (const string& word : words) {
            insert(word);
        }

        // Calculate prefix scores for each word
        vector<int> scores(words.size());
        for (int i = 0; i < words.size(); i++) {
            scores[i] = getPrefixScore(words[i]);
        }

        return scores;
    }
};
