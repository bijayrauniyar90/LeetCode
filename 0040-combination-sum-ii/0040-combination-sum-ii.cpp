class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> combination;
        findCombinations(result, combination, candidates, target, 0);
        return result;
    }

private:
    void findCombinations(vector<vector<int>> &result, vector<int> &combination, 
                          const vector<int> &candidates, int target, int start) {
        if (target == 0) {
            result.push_back(combination);
            return;
        }

        for (int i = start; i < candidates.size(); ++i) {
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue; // Skip duplicates
            }

            if (candidates[i] > target) {
                break; // No need to continue if the current number is greater than the target
            }

            combination.push_back(candidates[i]);
            findCombinations(result, combination, candidates, target - candidates[i], i + 1);
            combination.pop_back();
        }
    }
};
