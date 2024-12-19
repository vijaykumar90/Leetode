#include <iostream>
using namespace std;

class MyLinkedList {
private:
    struct Node {
        int val;
        Node* next; // Pointer to the next node
        Node(int x) : val(x), next(nullptr) {} // Constructor
    };

    Node* head; // Pointer to the head of the linked list
    int size;   // Size of the linked list

public:
    // Constructor
    MyLinkedList() : head(nullptr), size(0) {}

    // Get the value of the node at the given index
    int get(int index) {
        if (index < 0 || index >= size) {
            return -1; // Invalid index
        }
        Node* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next; // Traverse to the desired index
        }
        return current->val;
    }

    // Add a node with the given value at the head
    void addAtHead(int val) {
        Node* newNode = new Node(val); // Create a new node
        newNode->next = head;          // Link the new node to the current head
        head = newNode;                // Update the head to the new node
        ++size;
    }

    // Add a node with the given value at the tail
    void addAtTail(int val) {
        Node* newNode = new Node(val);
        if (!head) { // If the list is empty
            head = newNode;
        } else {
            Node* current = head;
            while (current->next) { // Traverse to the last node
                current = current->next;
            }
            current->next = newNode; // Link the last node to the new node
        }
        ++size;
    }

    // Add a node with the given value at the specified index
    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) {
            return; // Invalid index
        }
        if (index == 0) {
            addAtHead(val); // Add at head
        } else {
            Node* newNode = new Node(val);
            Node* current = head;
            for (int i = 0; i < index - 1; ++i) {
                current = current->next; // Traverse to the node before the index
            }
            newNode->next = current->next; // Link the new node to the next node
            current->next = newNode;       // Link the current node to the new node
            ++size;
        }
    }

    // Delete the node at the specified index
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) {
            return; // Invalid index
        }
        Node* current = head;
        if (index == 0) { // If deleting the head
            head = head->next; // Update the head to the next node
            delete current;
        } else {
            for (int i = 0; i < index - 1; ++i) {
                current = current->next; // Traverse to the node before the index
            }
            Node* toDelete = current->next; // Node to be deleted
            current->next = toDelete->next; // Link to the node after the one being deleted
            delete toDelete;
        }
        --size;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

