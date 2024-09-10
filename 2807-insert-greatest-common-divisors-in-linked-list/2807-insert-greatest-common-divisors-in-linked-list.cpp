class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        // If the list contains only one node, return the head as no insertion is needed
        if (!head || !head->next) return head;

        // Initialize pointers to traverse the list
        ListNode* node1 = head;

        // Traverse the linked list while there is a next pair
        while (node1->next) {
            ListNode* node2 = node1->next;
            
            // Calculate GCD between current pair of node values
            int gcdValue = calculateGCD(node1->val, node2->val);
            
            // Insert the GCD node between node1 and node2
            node1->next = new ListNode(gcdValue, node2);
            
            // Move to the next pair of nodes
            node1 = node2;
        }

        return head;
    }

private:
    // Helper method to calculate the greatest common divisor using the Euclidean algorithm
    int calculateGCD(int a, int b) {
        return b == 0 ? a : calculateGCD(b, a % b);
    }
};
