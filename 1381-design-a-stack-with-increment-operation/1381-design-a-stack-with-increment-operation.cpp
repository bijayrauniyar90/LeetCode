class CustomStack {
private:
    // Vector to store stack elements
    vector<int> stackVector;
    
    // Vector to store the incremental values for lazy propagation
    vector<int> incrementVector;

    // Index of the top element in the stack
    int topIndex;

public:
    // Constructor to initialize stack and increment vectors
    CustomStack(int maxSize) {
        stackVector.resize(maxSize);
        incrementVector.resize(maxSize, 0);  // Initialize incrementVector with 0
        topIndex = -1;
    }

    // Push an element onto the stack
    void push(int x) {
        if (topIndex < (int)(stackVector.size()) - 1) {
            stackVector[++topIndex] = x;
        }
    }

    // Pop the top element from the stack
    int pop() {
        if (topIndex >= 0) {
            int result = stackVector[topIndex] + incrementVector[topIndex];  // Apply pending increment
            if (topIndex > 0) {
                incrementVector[topIndex - 1] += incrementVector[topIndex];  // Propagate increment to the next
            }
            incrementVector[topIndex] = 0;  // Reset the increment at this level
            topIndex--;
            return result;
        }
        return -1;  // Return -1 if the stack is empty
    }

    // Increment the bottom k elements by val
    void increment(int k, int val) {
        if (topIndex >= 0) {
            int limit = min(k - 1, topIndex);  // We increment up to min(k, topIndex + 1)
            incrementVector[limit] += val;     // Only update the incrementVector at index limit
        }
    }
};
