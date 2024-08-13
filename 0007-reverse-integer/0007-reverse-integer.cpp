class Solution {        
public:
int reverse(int x)
{
    int rem = 0, ans = 0;

    if (x <= INT_MIN)
    {
        return 0;
    }

    bool isNeg = false;
    if (x < 0)
    {
        isNeg = true;
        x = -x;
    }

    while (x > 0)
    {
        if (ans > INT_MAX/10)
        {
            return 0;
        }
        rem = x % 10;
        ans = ans * 10 + rem;
        x /= 10;
    }
    return isNeg ? -ans : ans;
}

};