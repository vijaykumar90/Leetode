class MyHashMap {
public:
    unordered_map<int, int> res;
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        res[key] = value;
    }
    
    int get(int key) {
        if(res.find(key) != res.end()){
            return res[key];
        }
        return -1;
    }
    
    void remove(int key) {
        res.erase(key);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
