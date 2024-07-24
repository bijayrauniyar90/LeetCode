class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int numCount = nums.size();
        vector<pair<int, int>> mappedNumAndIndex(numCount);

        for (int i = 0; i < numCount; ++i) {
            int originalNum = nums[i];
            int mappedNum = 0;
            int placeValue = 1;

            if (originalNum == 0) {
                mappedNum = mapping[0];
            } else {
                while (originalNum > 0) {
                    int digit = originalNum % 10;
                    mappedNum += mapping[digit] * placeValue;
                    placeValue *= 10;
                    originalNum /= 10;
                }
            }

            mappedNumAndIndex[i] = {mappedNum, i};
        }

        sort(mappedNumAndIndex.begin(), mappedNumAndIndex.end());

        vector<int> sortedNums(numCount);
        for (int i = 0; i < numCount; ++i) {
            sortedNums[i] = nums[mappedNumAndIndex[i].second];
        }

        return sortedNums;
    }
};