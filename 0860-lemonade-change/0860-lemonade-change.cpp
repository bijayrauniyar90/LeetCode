class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fiveDollarBills = 0, tenDollarBills = 0;

        for (int bill : bills) {
            if (bill == 5) {
                fiveDollarBills++;
            } else if (bill == 10) {
                if (fiveDollarBills == 0) {
                    return false;
                }
                fiveDollarBills--;
                tenDollarBills++;
            } else {  // bill == 20
                if (tenDollarBills > 0 && fiveDollarBills > 0) {
                    tenDollarBills--;
                    fiveDollarBills--;
                } else if (fiveDollarBills >= 3) {
                    fiveDollarBills -= 3;
                } else {
                    return false;
                }
            }
        }

        return true;
    }
};
