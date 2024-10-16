class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;

        // Add non-zero counts of characters to the priority queue.
        if (a > 0) pq.push({a, 'a'});
        if (b > 0) pq.push({b, 'b'});
        if (c > 0) pq.push({c, 'c'});

        string ans = "";
        
        while (!pq.empty()) {
            auto [count1, char1] = pq.top(); 
            pq.pop();
            
            // Check for three consecutive characters.
            if (ans.size() >= 2 && ans.back() == char1 && ans[ans.size() - 2] == char1) {
                // If the next most frequent character is unavailable, stop.
                if (pq.empty()) break;

                // Take the second most frequent character.
                auto [count2, char2] = pq.top(); 
                pq.pop();
                
                ans += char2;
                if (--count2 > 0) pq.push({count2, char2});

                // Reinsert the current most frequent character back into the queue.
                pq.push({count1, char1});
            } else {
                // Append the current most frequent character.
                ans += char1;
                if (--count1 > 0) pq.push({count1, char1});
            }
        }

        return ans;
    }
};
