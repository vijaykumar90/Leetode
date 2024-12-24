class MyCircularQueue {
private: 
    struct Node{
        int val;
        Node* next;
        Node(int val): val(val), next(nullptr){}
    };
    int size;
    int capacity;
    Node* front;
    Node* rear;
public:
    
    MyCircularQueue(int k): front(nullptr), rear(nullptr), size(0), capacity(k){}

    ~MyCircularQueue(){
        while(!isEmpty()){
            deQueue();
        }
    }
    
    bool enQueue(int value) {
        if (isFull()){
            return false;
        }
        Node* newnode = new Node(value);
        if(isEmpty()){
            front = rear = newnode;
            rear->next = front;
        }else{
            rear->next = newnode;
            rear = newnode;
            rear->next = front;
        }
        size = size + 1;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()){
            return false;
        }
        Node* temp = front;
        if(front == rear){
            front = rear = nullptr;
        }else{
            front = front->next;
            rear->next = front;
        }
        delete temp;
        size--;
        return true;
    }
    
    int Front() {
        return isEmpty() ? -1 : front->val;
    }
    
    int Rear() {
        return isEmpty() ? -1 : rear->val;
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == capacity;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
