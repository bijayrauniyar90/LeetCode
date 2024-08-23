class Solution {
public:
    string fractionAddition(string expression) {
        int numerator = 0, denominator = 1; // Initialize as 0/1
        int i = 0, n = expression.size();

        while (i < n) {
            int currNumerator = 0, currDenominator = 0;
            int sign = 1; // default sign

            // Handle sign
            if (expression[i] == '-' || expression[i] == '+') {
                sign = (expression[i] == '-') ? -1 : 1;
                i++;
            }

            // Parse numerator
            while (isdigit(expression[i])) {
                currNumerator = currNumerator * 10 + (expression[i] - '0');
                i++;
            }

            currNumerator *= sign; // Apply sign to the numerator

            // Skip the '/' character
            i++;

            // Parse denominator
            while (i < n && isdigit(expression[i])) {
                currDenominator = currDenominator * 10 + (expression[i] - '0');
                i++;
            }

            // Calculate the new numerator and denominator using cross-multiplication
            numerator = numerator * currDenominator + currNumerator * denominator;
            denominator *= currDenominator;
        }

        // Reduce the fraction by their GCD
        int gcd = FindGCD(abs(numerator), denominator);
        numerator /= gcd;
        denominator /= gcd;

        return to_string(numerator) + "/" + to_string(denominator);
    }

private:
    int FindGCD(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
};
