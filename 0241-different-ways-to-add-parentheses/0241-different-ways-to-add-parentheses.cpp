class Solution {
public:
    unordered_map<string, vector<int>> memo;  // Memoization to store intermediate results
    
    vector<int> diffWaysToCompute(string expression) {
        // Check if result for the current expression is already computed
        if (memo.find(expression) != memo.end()) {
            return memo[expression];
        }
        
        vector<int> results;
        
        // Iterate through the expression to find operators
        for (int i = 0; i < expression.length(); i++) {
            char currentChar = expression[i];

            // If current character is an operator, split and recursively compute
            if (!isdigit(currentChar)) {
                vector<int> leftResults = diffWaysToCompute(expression.substr(0, i));
                vector<int> rightResults = diffWaysToCompute(expression.substr(i + 1));

                // Combine results from left and right parts
                for (int leftValue : leftResults) {
                    for (int rightValue : rightResults) {
                        int computedResult = 0;
                        if (currentChar == '+') {
                            computedResult = leftValue + rightValue;
                        } else if (currentChar == '-') {
                            computedResult = leftValue - rightValue;
                        } else if (currentChar == '*') {
                            computedResult = leftValue * rightValue;
                        }
                        results.push_back(computedResult);
                    }
                }
            }
        }

        // Base case: if the expression contains only a number
        if (results.empty()) {
            results.push_back(stoi(expression));
        }

        // Store the result in the memo map before returning
        memo[expression] = results;
        return results;
    }
};