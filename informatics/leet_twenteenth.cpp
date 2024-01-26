#include <unordered_map>

class LRUCache {
private:
    struct Node {
        int key;
        int value;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };
    
    int capacity;
    std::unordered_map<int, Node*> cache;
    Node* head;
    Node* tail;

    void remove(Node* node) {
        cache.erase(node->key);
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
    }

    void addToFront(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next = node;
        node->next->prev = node;
        cache[node->key] = node;
    }

public:
    LRUCache(int capacity) : capacity(capacity), head(new Node(-1, -1)), tail(new Node(-1, -1)) {
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            node->prev->next = node->next;
            node->next->prev = node->prev;
            addToFront(node);
            return node->value;
        } else {
            return -1;
        }
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            cache[key]->value = value;
            get(key);
        } else {
            if (cache.size() >= capacity) {
                remove(tail->prev);
            }
            addToFront(new Node(key, value));
        }
    }
};
