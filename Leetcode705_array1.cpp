class MyHashSet {
private: 
    static const int size = 1000001;
    bool hashTable[size];
public:
    MyHashSet() {
        for (int i=0; i<size; i++){
            hashTable[i] = false;
        }
    }
    
    void add(int key) {
        int index = key % size ;
        hashTable[index] = true;
    }
    
    void remove(int key) {
        int index = key % size;
        if (hashTable[index]){
            hashTable[index] = false;
        }
    }
    
    bool contains(int key) {
        int index = key % size;
        if (hashTable[index]){
            return true;
        }else{
            return false;
        }
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
