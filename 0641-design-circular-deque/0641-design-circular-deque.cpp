struct Node {
    int val;
    Node* next;
    Node* prev;
    Node(int val, Node* next = nullptr, Node* prev = nullptr)
        : val(val), next(next), prev(prev) {}
};

class MyCircularDeque {
private:
    Node* head;
    Node* rear;
    int size;
    int capacity;

public:
    MyCircularDeque(int k) : head(nullptr), rear(nullptr), size(0), capacity(k) {}

    ~MyCircularDeque() {
        while (!isEmpty()) {
            deleteFront();
        }
    }

    bool insertFront(int value) {
        if (isFull()) return false;

        Node* newNode = new Node(value, head, nullptr);
        if (isEmpty()) {
            head = rear = newNode; // First node
        } else {
            head->prev = newNode;
            head = newNode;
        }
        size++;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) return false;

        Node* newNode = new Node(value, nullptr, rear);
        if (isEmpty()) {
            head = rear = newNode; // First node
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) return false;

        Node* temp = head;
        if (size == 1) {
            head = rear = nullptr; // Empty deque
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
        size--;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) return false;

        Node* temp = rear;
        if (size == 1) {
            head = rear = nullptr; // Empty deque
        } else {
            rear = rear->prev;
            rear->next = nullptr;
        }
        delete temp;
        size--;
        return true;
    }

    int getFront() const { return isEmpty() ? -1 : head->val; }

    int getRear() const { return isEmpty() ? -1 : rear->val; }

    bool isEmpty() const { return size == 0; }

    bool isFull() const { return size == capacity; }
};
