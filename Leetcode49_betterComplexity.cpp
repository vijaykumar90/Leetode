class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> myMap;
        vector<vector<string>> res;
        for (int i=0;i<strs.size(); i++){
            vector<int> count(26, 0);
            string key = "";
            for (char c: strs[i]){
                count[c-'a']++;
            }
            for(int c:count){
                key = key + to_string(c) + '#';
            }
            myMap[key].push_back(strs[i]);
        }
        for (const auto& pair : myMap) {
            res.push_back(pair.second);
        }

        return res;
    }
};
