// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
class Queue{
private:
    struct Node{
        int val;
        Node* nextaddr;
    };
    Node* front = new Node();
    Node* rear = new Node();
    
public:
    Queue(){
        front = nullptr;
        rear = nullptr;
    }
    
    // adds element to the last element
    void enqueue(int val){
        Node* newnode = new Node();
        newnode->val = val;
        newnode->nextaddr = nullptr;
        if (rear == nullptr){
            front = newnode;
            rear = newnode;
        }else{
            rear->nextaddr = newnode;
            rear = newnode;
        }
        
    }
    
    bool isEmpty(){
        if (front == nullptr){
            return true;
        }
        return false;
    }
    
    // remove element from top, returns the removed element.
    int dequeue(){
        if(isEmpty()){
            return -1;
        }
        Node* newnode = new Node();
        newnode = front;
        front = front->nextaddr;
        int res = newnode->val;
        if(front == nullptr){
            rear = nullptr;
        }
        delete newnode;
        return res;
    }
    
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }

        Node* temp = front;          // Start from the front
        cout << "Queue elements: ";
        while (temp != nullptr) {
            cout << temp->val << " ";
            temp = temp->nextaddr;       // Move to the next node
        }
        cout << endl;
    }
};
int main() {
    Queue q; // Create a queue

    q.enqueue(10); // Add elements
    q.enqueue(20);
    q.enqueue(30);

    q.display();   // Display the queue

    q.dequeue();   // Remove an element
    q.display();

    q.dequeue();
    q.dequeue();
    q.dequeue();   // Try removing from an empty queue

    return 0;
}
