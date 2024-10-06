class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        // Split the sentences into words
        vector<string> s1Words = splitWords(s1);
        vector<string> s2Words = splitWords(s2);

        // Ensure s1 is the shorter or equal in length
        if (s1Words.size() > s2Words.size()) 
            swap(s1Words, s2Words);

        int start = 0;
        int end1 = s1Words.size() - 1, end2 = s2Words.size() - 1;

        // Match the prefix
        while (start < s1Words.size() && s1Words[start] == s2Words[start]) 
            ++start;

        // Match the suffix
        while (end1 >= start && s1Words[end1] == s2Words[end2]) {
            --end1;
            --end2;
        }

        // If all words in s1 were matched either in the prefix or suffix
        return end1 < start;
    }

private:
    vector<string> splitWords(const string& s) {
        vector<string> words;
        stringstream ss(s);
        string word;
        while (ss >> word) words.push_back(word);
        return words;
    }
};
