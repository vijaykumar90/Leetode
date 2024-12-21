class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;
        int len = nums.size();
        for(int i=0; i<len;i++){
            int other = target - nums[i];
            if (numMap.find(other) != numMap.end()){
                return {numMap[other],i};
            }
            int vectNum = nums[i];
            numMap[vectNum] = i;
        }
        return {-1};
    }
};
