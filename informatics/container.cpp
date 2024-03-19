#include <iostream>

template <typename T>
class Container {
private:
    struct Node {
        T data;
        Node* next;
    };

    Node* head;
    Node* tail;
    size_t count;

public:
    Container() : head(nullptr), tail(nullptr), count(0) {}

    void addFront(const T& element) {
        Node* newNode = new Node{element, head};
        if (isEmpty()) {
            tail = newNode;
        }
        head = newNode;
        count++;
    }

    void addBack(const T& element) {
        Node* newNode = new Node{element, nullptr};
        if (isEmpty()) {
            head = newNode;
        } else {
            tail->next = newNode;
        }
        tail = newNode;
        count++;
    }

    void removeFront() {
        if (!isEmpty()) {
            Node* temp = head;
            head = head->next;
            delete temp;
            count--;
            if (isEmpty()) {
                tail = nullptr;
            }
        }
    }

    void removeBack() {
        if (!isEmpty()) {
            Node* current = head;
            Node* previous = nullptr;
            while (current->next != nullptr) {
                previous = current;
                current = current->next;
            }
            delete current;
            if (previous) {
                previous->next = nullptr;
                tail = previous;
            } else {
                head = tail = nullptr;
            }
            count--;
        }
    }

    T& getFirst() {
        return head->data;
    }

    T& getLast() {
        return tail->data;
    }

    void iterate() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    size_t size() {
        return count;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    void swap(Container& other) {
        std::swap(head, other.head);
        std::swap(tail, other.tail);
        std::swap(count, other.count);
    }

    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;

        while (current) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        std::swap(head, tail);
    }

    void clear() {
        while (!isEmpty()) {
            removeFront();
        }
        tail = nullptr;
    }

    ~Container() {
        clear();
    }
};

int main() {
    Container<int> container;

    container.addBack(1);
    container.addBack(2);
    container.addBack(3);

    std::cout << "First element: " << container.getFirst() << std::endl;
    std::cout << "Last element: " << container.getLast() << std::endl;

    container.iterate();

    container.reverse();
    container.iterate();

    container.clear();

    std::cout << "Size after clearing: " << container.size() << std::endl;

    return 0;
}
