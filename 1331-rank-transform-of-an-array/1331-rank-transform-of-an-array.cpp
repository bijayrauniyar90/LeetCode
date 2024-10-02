class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if (arr.empty()) return arr;

        // Create a sorted copy of arr
        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());

        // Use unordered_map to store the rank for each number in arr
        unordered_map<int, int> numToRank;
        int rank = 1;

        // Assign ranks to the sorted array elements
        numToRank[sortedArr[0]] = rank;
        for (int i = 1; i < sortedArr.size(); i++) {
            if (sortedArr[i] != sortedArr[i - 1]) {
                rank++;
            }
            numToRank[sortedArr[i]] = rank;
        }

        // Transform the original array into ranks
        for (int i = 0; i < arr.size(); i++) {
            arr[i] = numToRank[arr[i]];
        }

        return arr;
    }
};
