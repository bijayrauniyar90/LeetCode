class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        // Create an unordered_set for quick lookup of values to remove
        unordered_set<int> valuesToRemove(nums.begin(), nums.end());

        // Remove all the matching head nodes at the beginning
        while (head != nullptr && valuesToRemove.find(head->val) != valuesToRemove.end()) {
            ListNode* temp = head;
            head = head->next;
            delete temp;  // Free memory of the removed node
        }

        // If the list becomes empty, return nullptr
        if (head == nullptr) {
            return nullptr;
        }

        // Traverse the rest of the list to remove nodes with matching values
        ListNode* current = head;
        while (current->next != nullptr) {
            if (valuesToRemove.find(current->next->val) != valuesToRemove.end()) {
                ListNode* temp = current->next;
                current->next = current->next->next;
                delete temp;  // Free memory of the removed node
            } else {
                current = current->next;
            }
        }

        return head;
    }
};
