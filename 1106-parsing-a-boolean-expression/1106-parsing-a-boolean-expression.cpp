class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> ops;  // To store operators: !, &, |
        stack<vector<char>> vals;  // To store boolean values for current subexpression

        for (char ch : expression) {
            if (ch == 't' || ch == 'f') {
                if (!vals.empty()) vals.top().push_back(ch);  // Push 't' or 'f' into the current subexpression values
            } else if (ch == '!' || ch == '&' || ch == '|') {
                ops.push(ch);  // Push operator onto the stack
                vals.push(vector<char>());  // Prepare a new value vector for this subexpression
            } else if (ch == ')') {
                // Evaluate the subexpression
                char op = ops.top(); ops.pop();
                vector<char> cur_vals = vals.top(); vals.pop();

                char result = evaluate(op, cur_vals);  // Get the result of this subexpression
                if (!vals.empty()) vals.top().push_back(result);  // Add result to the parent expression
                else return result == 't';  // If no parent, return the final result
            }
        }
        return false;  // Control should never reach here
    }

private:
    char evaluate(char op, const vector<char>& vals) {
        if (op == '!') {
            return vals[0] == 't' ? 'f' : 't';  // Negation: only one value
        } else if (op == '&') {
            return all_of(vals.begin(), vals.end(), [](char v) { return v == 't'; }) ? 't' : 'f';
        } else if (op == '|') {
            return any_of(vals.begin(), vals.end(), [](char v) { return v == 't'; }) ? 't' : 'f';
        }
        return 'f';  // Should not reach here
    }
};
