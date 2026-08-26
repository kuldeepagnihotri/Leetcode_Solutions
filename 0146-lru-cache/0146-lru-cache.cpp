class LRUCache {
public:
    class Node {
    public:
        int key, val;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            val = v;
            prev = next = NULL;
        }
    };

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    unordered_map<int, Node*> m;
    int limit;

    void addNode(Node* newNode) { // O(1)
        Node* oldNext = head->next;

        head->next = newNode;
        oldNext->prev = newNode;

        newNode->next = oldNext;
        newNode->prev = head;
    }

    void delNode(Node* oldNode) { // O(1)
        Node* oldPrev = oldNode->prev;
        Node* oldNext = oldNode->next;

        oldPrev->next = oldNext;
        oldNext->prev = oldPrev;
    }

    LRUCache(int capacity) {
        limit = capacity;

        head->next = tail;
        tail->prev = head;
    }

    int get(int key) { //O(1)

        if (m.find(key) == m.end()) {
            return -1;
        }

        Node* ansNode = m[key];
        int ans = ansNode->val;

        // Move this node to front
        m.erase(key);
        delNode(ansNode);
        addNode(ansNode);
        m[key] = ansNode;

        return ans;
    }

    void put(int key, int value) { //o(1)

        // If key already exists
        if (m.find(key) != m.end()) {

            Node* oldNode = m[key];

            delNode(oldNode);
            m.erase(key);

            delete oldNode;
        }

        // Create new node and add at front
        Node* newNode = new Node(key, value);

        addNode(newNode);
        m[key] = newNode;

        // If capacity exceeded
        if (m.size() > limit) {

            Node* lruNode = tail->prev;

            delNode(lruNode);
            m.erase(lruNode->key);

            delete lruNode;
        }
    }
};