class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> hash;
        vector<int> res;
        for(int i : nums1){
            if(hash[i]==0){
                hash[i]++;
            }
        }
        for (int i:nums2){
            hash[i]--;
            if(hash[i]==0){
                res.push_back(i);
            }
        }
        return res;

    }
};
