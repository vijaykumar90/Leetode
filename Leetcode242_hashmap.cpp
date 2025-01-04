class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> hash;
        if (s.size() != t.size()){
            return false;
        }
        for(char c : s){
            hash[c]++;
        }
        for(char c : t){
            hash[c]--;
            if(hash[c]<0){
                return false;
            }
        }
        return true;
    }
};
