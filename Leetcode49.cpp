class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int len = strs.size();
        map<string, vector<string>> myMap;
        vector<vector<string>> res;
        for(int i=0; i<len; i++){
            string str = strs[i];
            string sorted = str;
            sort(sorted.begin(), sorted.end());
            myMap[sorted].push_back(str);
        }
        for (const auto &pair : myMap) {
            res.push_back(pair.second);
        }
        return res;
    }
};
