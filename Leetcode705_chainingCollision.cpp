class MyHashSet {
private:
    vector<list<int>> res;
    int bucSize;

    int hash(int key){
        return key % bucSize;
    }
public:
    MyHashSet() {
        bucSize = 1000;
        res.resize(bucSize);
    }
    
    void add(int key) {
        int index = hash(key);
        for(int val : res[index]){
            if (val == key) return;
        }
        res[index].push_back(key);
    }
    
    void remove(int key) {
        int index = hash(key);
        res[index].remove(key);
    }
    
    bool contains(int key) {
        int index = hash(key);
        for (int val : res[index]){
            if (val == key) return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
